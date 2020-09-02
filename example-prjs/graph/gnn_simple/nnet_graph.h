//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef NNET_GRAPH_H_
#define NNET_GRAPH_H_

#include "nnet_common.h"
#include "nnet_dense.h"
#include "nnet_dense_large.h"
#include "nnet_activation.h"
#include "nnet_conv.h"
#include "hls_stream.h"
#include <math.h>

namespace nnet {
  
  struct graph_config
  {
    // Internal data type definitions
    typedef float bias_t;
    typedef float weight_t;
    
    // Layer Sizes
    static const unsigned n_node = 10;
    static const unsigned n_edge = 20;
    static const unsigned n_batch = 20;
    static const unsigned n_in = 7;
    static const unsigned n_hidden = 4;
    static const unsigned n_out = 4;
    
    // Resource reuse info
    static const unsigned io_type = io_parallel;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
  };

  template<class data_T, class index_T, class res_T, typename CONFIG_T>
    void IN_edge_module(
			data_T    Re[CONFIG_T::n_edge][CONFIG_T::n_hidden],
			data_T    Rn[CONFIG_T::n_node][CONFIG_T::n_hidden],
			index_T    receivers[CONFIG_T::n_edge][1],
			index_T    senders[CONFIG_T::n_edge][1],
			res_T     L[CONFIG_T::n_edge][CONFIG_T::n_hidden],
			typename CONFIG_T::dense_config1::weight_t  core_edge_w0[3*CONFIG_T::n_hidden*CONFIG_T::n_hidden],
			typename CONFIG_T::dense_config1::bias_t    core_edge_b0[CONFIG_T::n_hidden],
			typename CONFIG_T::dense_config2::weight_t  core_edge_w1[CONFIG_T::n_hidden*CONFIG_T::n_hidden],
			typename CONFIG_T::dense_config2::bias_t    core_edge_b1[CONFIG_T::n_hidden])
  {
    for(int i = 0; i < CONFIG_T::n_edge; i++) {
      #pragma HLS PIPELINE II=CONFIG_T::dense_config1::reuse_factor
      #pragma HLS UNROLL
      index_T r = receivers[i][0];
      #pragma HLS STREAM variable=r
      index_T s = senders[i][0];
      #pragma HLS STREAM variable=s
      data_T l_logits[2*CONFIG_T::n_hidden];
      #pragma HLS ARRAY_PARTITION variable=l_logits complete dim=0
      nnet::merge<data_T, CONFIG_T::n_hidden, CONFIG_T::n_hidden>(Re[i], Rn[r], l_logits);
      data_T l[3*CONFIG_T::n_hidden];
      #pragma HLS ARRAY_PARTITION variable=l complete dim=0
      nnet::merge<data_T, 2*CONFIG_T::n_hidden, CONFIG_T::n_hidden>(l_logits, Rn[s], l);

      data_T L0_logits[CONFIG_T::dense_config1::n_out];
      #pragma HLS ARRAY_PARTITION variable=L0_logits complete dim=0
      nnet::dense_large_basic<data_T, data_T, typename CONFIG_T::dense_config1>(l, L0_logits, core_edge_w0, core_edge_b0);
      data_T L0[CONFIG_T::relu_config1::n_in];
      #pragma HLS ARRAY_PARTITION variable=L0 complete dim=0
      nnet::relu<data_T, data_T, typename CONFIG_T::relu_config1>(L0_logits, L0);

      data_T L_logits[CONFIG_T::dense_config2::n_out];
      #pragma HLS ARRAY_PARTITION variable=L_logits complete dim=0
      nnet::dense_large_basic<data_T, data_T, typename CONFIG_T::dense_config2>(L0, L_logits, core_edge_w1, core_edge_b1);
      nnet::relu<data_T, res_T, typename CONFIG_T::relu_config2>(L_logits, L[i]);
    }
  }

  template<class data_T, class res_T, typename CONFIG_T>
    void IN_node_module(
			data_T    Rn[CONFIG_T::n_node][CONFIG_T::n_hidden],
			data_T    L[CONFIG_T::n_edge][CONFIG_T::n_hidden],
			res_T     P[CONFIG_T::n_node][CONFIG_T::n_hidden],
			typename CONFIG_T::dense_config1::weight_t  core_node_w0[2*CONFIG_T::n_hidden*CONFIG_T::n_hidden],
			typename CONFIG_T::dense_config1::bias_t    core_node_b0[CONFIG_T::n_hidden],
			typename CONFIG_T::dense_config2::weight_t  core_node_w1[CONFIG_T::n_hidden*CONFIG_T::n_hidden],
			typename CONFIG_T::dense_config2::bias_t    core_node_b1[CONFIG_T::n_hidden])
  {
    for(int i = 0; i < CONFIG_T::n_node; i++){
      #pragma HLS PIPELINE II=CONFIG_T::dense_config1::reuse_factor
      #pragma HLS UNROLL
      data_T p[2*CONFIG_T::n_hidden];
      #pragma HLS ARRAY_PARTITION variable=p complete dim=0
      nnet::merge<data_T, CONFIG_T::n_hidden, CONFIG_T::n_hidden>(L[i], Rn[i], p);
      
      data_T P0_logits[CONFIG_T::dense_config1::n_out];
      #pragma HLS ARRAY_PARTITION variable=P0_logits complete dim=0
      nnet::dense_large_basic<data_T, data_T, typename CONFIG_T::dense_config1>(p, P0_logits, core_node_w0, core_node_b0);
      data_T P0[CONFIG_T::relu_config1::n_in];
      #pragma HLS ARRAY_PARTITION variable=P0 complete dim=0
      nnet::relu<data_T, data_T, typename CONFIG_T::relu_config1>(P0_logits, P0);
      
      data_T P_logits[CONFIG_T::dense_config2::n_out];
      #pragma HLS ARRAY_PARTITION variable=P_logits complete dim=0
      nnet::dense_large_basic<data_T, data_T, typename CONFIG_T::dense_config2>(P0, P_logits, core_node_w1, core_node_b1);
      nnet::relu<data_T, res_T, typename CONFIG_T::relu_config1>(P_logits, P[i]);
    }
  }

  template<class data_T, class res_T, typename CONFIG_T>
    void graph_independent(
			   data_T    X[CONFIG_T::dense_config1::n_batch][CONFIG_T::dense_config1::n_in],
			   res_T     R[CONFIG_T::dense_config2::n_batch][CONFIG_T::dense_config2::n_out],
			   typename CONFIG_T::dense_config1::weight_t  w0[CONFIG_T::dense_config1::n_in*CONFIG_T::dense_config1::n_out],
			   typename CONFIG_T::dense_config1::bias_t    b0[CONFIG_T::dense_config1::n_out],
			   typename CONFIG_T::dense_config2::weight_t  w1[CONFIG_T::dense_config2::n_in*CONFIG_T::dense_config2::n_out],
			   typename CONFIG_T::dense_config2::bias_t    b1[CONFIG_T::dense_config2::n_out])
  {
    data_T R0_logits[CONFIG_T::dense_config1::n_batch][CONFIG_T::dense_config1::n_out];
    #pragma HLS ARRAY_PARTITION variable=R0_logits complete dim=0
    nnet::dense_batch<data_T, data_T, typename CONFIG_T::dense_config1>(X, R0_logits, w0, b0);
    data_T R0[CONFIG_T::relu_config1::n_batch][CONFIG_T::relu_config1::n_in];
    #pragma HLS ARRAY_PARTITION variable=R0 complete dim=0
    nnet::relu_batch<data_T, data_T, typename CONFIG_T::relu_config1>(R0_logits, R0);

    data_T R_logits[CONFIG_T::dense_config2::n_batch][CONFIG_T::dense_config2::n_out];
    #pragma HLS ARRAY_PARTITION variable=R_logits complete dim=0
    nnet::dense_batch<data_T, data_T, typename CONFIG_T::dense_config2>(R0, R_logits, w1, b1);
    nnet::relu_batch<data_T, res_T, typename CONFIG_T::relu_config2>(R_logits, R);
  }

  template<class data_T, class res_T, typename CONFIG_T>
    void compute_edge_net_features(
		   data_T    X[CONFIG_T::n_node][CONFIG_T::n_input_dim],
		   ap_uint<1> Ri[CONFIG_T::n_node][CONFIG_T::n_edge],
		   ap_uint<1> Ro[CONFIG_T::n_node][CONFIG_T::n_edge],
		   res_T     B[CONFIG_T::n_edge][2*CONFIG_T::n_input_dim])
  {
    data_T bo[CONFIG_T::n_edge][CONFIG_T::n_input_dim];
    data_T bi[CONFIG_T::n_edge][CONFIG_T::n_input_dim];
    
    if (CONFIG_T::io_type == io_parallel){
      // For parallel inputs:
      //   - completely partition arrays -- target fabric
      //   - if we have an unroll factor, limit number of multipliers
    	#pragma HLS PIPELINE II=CONFIG_T::reuse_factor
		#pragma HLS ARRAY_PARTITION variable=bo complete
		#pragma HLS ARRAY_PARTITION variable=bi complete
    }
    else if (CONFIG_T::io_type == io_serial){
		#pragma HLS DATAFLOW
		#pragma HLS STREAM variable=bo depth=1
		#pragma HLS STREAM variable=bi depth=1
    }

    // Multiply bo = Ro^T X
    // Multiply bi = Ri^T X
    for(int ii = 0; ii < CONFIG_T::n_edge; ii++) {
      if (CONFIG_T::io_type == io_serial){
    	  #pragma HLS PIPELINE
      }
      for(int jj = 0; jj < CONFIG_T::n_input_dim; jj++) {
    	  bi[ii][jj] = 0;
    	  bo[ii][jj] = 0;
    	  for(int kk = 0; kk < CONFIG_T::n_node; kk++) {
    		  bi[ii][jj] += Ri[kk][ii] * X[kk][jj];
    		  bo[ii][jj] += Ro[kk][ii] * X[kk][jj];
    	  }
    	  // Concatenate M = [bo, bi]
    	  B[ii][jj] = (res_T) bo[ii][jj];
    	  B[ii][CONFIG_T::n_input_dim+jj] = (res_T) bi[ii][jj];
      }
    }
  }

  template<class data_T, class res_T, typename CONFIG_T>
  void compute_node_net_features(
		  data_T    X[CONFIG_T::n_node][CONFIG_T::n_input_dim],
		  data_T    e[CONFIG_T::n_edge][1],
		  ap_uint<1> Ri[CONFIG_T::n_node][CONFIG_T::n_edge],
		  ap_uint<1> Ro[CONFIG_T::n_node][CONFIG_T::n_edge],
		  res_T     M[CONFIG_T::n_node][3*CONFIG_T::n_input_dim])
  {
	  data_T bo[CONFIG_T::n_edge][CONFIG_T::n_input_dim];
	  data_T bi[CONFIG_T::n_edge][CONFIG_T::n_input_dim];
	  data_T mo[CONFIG_T::n_node][CONFIG_T::n_input_dim];
	  data_T mi[CONFIG_T::n_node][CONFIG_T::n_input_dim];
	  data_T Rwo[CONFIG_T::n_node][CONFIG_T::n_edge];
	  data_T Rwi[CONFIG_T::n_node][CONFIG_T::n_edge];

	  if (CONFIG_T::io_type == io_parallel){
      // For parallel inputs:
      //   - completely partition arrays -- target fabric
      //   - if we have an unroll factor, limit number of multipliers
		  #pragma HLS PIPELINE II=CONFIG_T::reuse_factor
		  #pragma HLS ARRAY_PARTITION variable=bo complete
		  #pragma HLS ARRAY_PARTITION variable=bi complete
		  #pragma HLS ARRAY_PARTITION variable=mo complete
		  #pragma HLS ARRAY_PARTITION variable=mi complete
		  #pragma HLS ARRAY_PARTITION variable=Rwo complete
		  #pragma HLS ARRAY_PARTITION variable=Rwi complete

		  int multiplier_limit  = ceil(float(2*CONFIG_T::n_node*CONFIG_T::n_edge*CONFIG_T::n_input_dim) / float(CONFIG_T::reuse_factor));
		  #pragma HLS ALLOCATION instances=mul limit=multiplier_limit operation
	  }
	  else if (CONFIG_T::io_type == io_serial)
	  {
		  #pragma HLS DATAFLOW
		  #pragma HLS STREAM variable=bo depth=1
		  #pragma HLS STREAM variable=bi depth=1
		  #pragma HLS STREAM variable=mo depth=1
		  #pragma HLS STREAM variable=mi depth=1
		  #pragma HLS STREAM variable=Rwo depth=1
		  #pragma HLS STREAM variable=Rwi depth=1
	  }

	  // Multiply bo = Ro^T X
	  // Multiply bi = Ri^T X
	  for(int ii = 0; ii < CONFIG_T::n_edge; ii++)
	  {
		  if (CONFIG_T::io_type == io_serial)
		  {
			  #pragma HLS PIPELINE
		  }
		  for(int jj = 0; jj < CONFIG_T::n_input_dim; jj++)
		  {
			  bi[ii][jj] = 0;
			  bo[ii][jj] = 0;
			  for(int kk = 0; kk < CONFIG_T::n_node; kk++)
			  {
				  bi[ii][jj] += Ri[kk][ii] * X[kk][jj];
				  bo[ii][jj] += Ro[kk][ii] * X[kk][jj];
			  }
		  }
	  }

	  // Hadamard Multiply Rwo = Ro * e
	  // Hadamard Multiply Rwi = Ri * e
	  for(int ii = 0; ii < CONFIG_T::n_node; ii++)
	  {
		  if (CONFIG_T::io_type == io_serial)
		  {
			  #pragma HLS PIPELINE
			  }
		  for(int jj = 0; jj < CONFIG_T::n_edge; jj++)
		  {
			  Rwo[ii][jj] = Ro[ii][jj] * e[jj][0];
			  Rwi[ii][jj] = Ri[ii][jj] * e[jj][0];
		  }
	  }

	  // Multiply mi = Rwi bo
	  // Multiply mo = Rwo bi
	  int counter = 0;
	  for(int ii = 0; ii < CONFIG_T::n_node; ii++)
	  {
		  if (CONFIG_T::io_type == io_serial)
		  {
			  #pragma HLS PIPELINE
			  }
		  for(int jj = 0; jj < CONFIG_T::n_input_dim; jj++)
		  {
			  mi[ii][jj] = 0;
			  mo[ii][jj] = 0;
			  for(int kk = 0; kk < CONFIG_T::n_edge; kk++)
			  {
				  counter+=1;
				  mi[ii][jj] += Rwi[ii][kk] * bo[kk][jj];
				  mo[ii][jj] += Rwo[ii][kk] * bi[kk][jj];
			  }
			  // Concatenate M = [mi, mo, X]
			  M[ii][jj] = (res_T) mi[ii][jj];
			  M[ii][CONFIG_T::n_input_dim+jj] = (res_T) mo[ii][jj];
			  M[ii][2*CONFIG_T::n_input_dim+jj] = (res_T) X[ii][jj];
		  }
	  }
  }
}

#endif
