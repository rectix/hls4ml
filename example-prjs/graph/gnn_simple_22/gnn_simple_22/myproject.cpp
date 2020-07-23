#include <iostream>
#include "parameters.h"
#include "myproject.h"

#include "nnet_dense.h"
#include "nnet_activation.h"
#include "nnet_dense_large.h"
#include "nnet_common.h"

//insert weights from training
#include "weights/w1.h"
#include "weights/b1.h"
#include "weights/w2.h"
#include "weights/b2.h"
#include "weights/w3.h"
#include "weights/b3.h"
#include "weights/w4.h"
#include "weights/b4.h"
#include "weights/w5.h"
#include "weights/b5.h"
#include "weights/w6.h"
#include "weights/b6.h"
#include "weights/w7.h"
#include "weights/b7.h"
#include "weights/w8.h"
#include "weights/b8.h"
#include "weights/w9.h"
#include "weights/b9.h"
#include "weights/w10.h"
#include "weights/b10.h"
#include "weights/w11.h"
#include "weights/b11.h"
#include "weights/w12.h"
#include "weights/b12.h"

/* Weight Matrices Dimensions
Encoder (3,128)
Core (256,128) Then concatenate first encoded features for 128 --> 256
Decoder (256,128)
Output (128,1)


//parameters
#define N_NODES 2714
#define N_FEATURES 3
#define N_EDGES 24758
#define E_FEATURES 4
#define latent_dim 128
*/

void myproject(
	       input_t      N[N_NODES][N_FEATURES],
	       input_t      E[N_EDGES][E_FEATURES],
           ap_uint<16>  receivers[N_EDGES][1],
           ap_uint<16>  senders[N_EDGES][1],
	       result_t     e[N_EDGES][1],
	       unsigned short &const_size_in,
	       unsigned short &const_size_out)
{

  //hls-fpga-machine-learning insert IO
#pragma HLS ARRAY_RESHAPE variable=N complete dim=0
#pragma HLS ARRAY_RESHAPE variable=E complete dim=0
#pragma HLS ARRAY_RESHAPE variable=receivers complete dim=0
#pragma HLS ARRAY_RESHAPE variable=senders complete dim=0
#pragma HLS ARRAY_RESHAPE variable=e complete dim=0
#pragma HLS INTERFACE ap_vld port=N,E,receivers,senders,e
#pragma HLS DATAFLOW

  const_size_in	= N_NODES*N_FEATURES+N_EDGES*E_FEATURES+2*N_EDGES*1;
  const_size_out = N_EDGES*1;

  //encode nodes features
  std::cout<<"Node Encoding Network Dense Batch"<<std::endl;
  input_t Rn0_logits[N_NODES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=Rn0_logits complete dim=0
  nnet::dense_batch<input_t, input_t, dense_config1>(N, Rn0_logits, w1, b1);
  input_t Rn0[N_NODES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=Rn0 complete dim=0
  nnet::relu_batch<input_t, input_t, relu_config1>(Rn0_logits, Rn0);
  
  input_t Rn_logits[N_NODES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=Rn_logits complete dim=0
  nnet::dense_batch<input_t, input_t, dense_config2>(Rn0, Rn_logits, w2, b2);
  input_t Rn[N_NODES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=Rn complete dim=0
  nnet::relu_batch<input_t, input_t, relu_config1>(Rn_logits, Rn);
  
  
  
  //encode edge features
  std::cout<<"Edge Encoding Network Dense Batch"<<std::endl;
  input_t Re0_logits[N_EDGES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=Re0_logits complete dim=0
  nnet::dense_batch<input_t, input_t, dense_config3>(E, Re0_logits, w3, b3);
  input_t Re0[N_EDGES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=Re0 complete dim=0
  nnet::relu_batch<input_t, input_t, relu_config2>(Re0_logits, Re0);
  
  input_t Re_logits[N_EDGES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=Re_logits complete dim=0
  nnet::dense_batch<input_t, input_t, dense_config4>(Re0, Re_logits, w4, b4);
  input_t Re[N_EDGES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=Re complete dim=0
  nnet::relu_batch<input_t, input_t, relu_config2>(Re_logits, Re);
  
  
  
  //consider simplifying redundant layers down the line
  //core networks
  input_t L[N_EDGES][latent_dim];
  input_t P[N_NODES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=L complete dim=0
  #pragma HLS ARRAY_PARTITION variable=P complete dim=0

  for(int i = 0; i < N_ITERS; i++){
    //concatenations for after each core layer
    input_t Cn[N_NODES][2*latent_dim];
    #pragma HLS ARRAY_PARTITION variable=Cn complete dim=0
    nnet::merge2d<input_t, N_NODES, latent_dim, latent_dim>(Rn, Rn, Cn);
    
    input_t Ce[N_EDGES][2*latent_dim];
    #pragma HLS ARRAY_PARTITION variable=Ce complete dim=0
    nnet::merge2d<input_t, N_EDGES, latent_dim, latent_dim>(Re, Re, Ce);
    
    //core edge updates
    for(int j = 0; j < N_EDGES; j++){
      ap_uint<16> r = receivers[j];
      ap_uint<16> s = senders[j];
      input_t l_logits[4*latent_dim];
      #pragma HLS ARRAY_PARTITION variable=l_logits complete dim=0
      nnet::merge<input_t, 2*latent_dim, 2*latent_dim>(Ce[j], Cn[r], l_logits);
      input_t l[6*latent_dim];
      #pragma HLS ARRAY_PARTITION variable=l complete dim=0
      nnet::merge<input_t, 4*latent_dim, 2*latent_dim>(l_logits, Cn[s], l);
      
      std::cout<<"Core Edge Network Dense Batch"<<std::endl;
      input_t L0_logits[latent_dim];
      #pragma HLS ARRAY_PARTITION variable=L0_logits complete dim=0
      nnet::dense_large<input_t, input_t, dense_config5>(l, L0_logits, w5, b5);
      input_t L0[latent_dim];
      #pragma HLS ARRAY_PARTITION variable=L0 complete dim=0
      nnet::relu<input_t, input_t, relu_config3>(L0_logits, L0);
      
      input_t L_logits[latent_dim];
      #pragma HLS ARRAY_PARTITION variable=L_logits complete dim=0
      nnet::dense_large<input_t, input_t, dense_config6>(L0, L_logits, w6, b6);
      
      nnet::relu<input_t, input_t, relu_config3>(L_logits, L[j]);
    }
    
    //core node updates
    for(int j = 0; j < N_NODES; j++){
      input_t p[3*latent_dim];
      #pragma HLS ARRAY_PARTITION variable=p complete dim=0
      nnet::merge<input_t, latent_dim, 2*latent_dim>(L[j], Cn[j], p);
      
      input_t P0_logits[latent_dim];
      #pragma HLS ARRAY_PARTITION variable=P0_logits complete dim=0
      nnet::dense_large<input_t, input_t, dense_config7>(p, P0_logits, w7, b7);
      input_t P0[latent_dim];
      #pragma HLS ARRAY_PARTITION variable=P0 complete dim=0
      nnet::relu<input_t, input_t, relu_config3>(P0_logits, P0);
      
      input_t P_logits[latent_dim];
      #pragma HLS ARRAY_PARTITION variable=P_logits complete dim=0
      nnet::dense_large<input_t, input_t, dense_config6>(P0, P_logits, w8, b8);
      
      nnet::relu<input_t, input_t, relu_config3>(P_logits, P[j]);
    }
  }
  
  //decode edge features
  std::cout<<"Edge Decoding Network Dense Batch"<<std::endl;
  input_t Ro0_logits[N_EDGES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=Ro0_logits complete dim=0
  nnet::dense_batch<input_t, input_t, dense_config4>(L, Ro0_logits, w9, b9);
  input_t Ro0[N_EDGES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=Ro0 complete dim=0
  nnet::relu_batch<input_t, input_t, relu_config2>(Ro0_logits, Ro0);
  
  input_t Ro_logits[N_EDGES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=Ro_logits complete dim=0
  nnet::dense_batch<input_t, input_t, dense_config4>(Ro0, Ro_logits, w10, b10);
  input_t Ro[N_EDGES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=Ro complete dim=0
  nnet::relu_batch<input_t, input_t, relu_config2>(Ro_logits, Ro);
  
  //output
  input_t e0_logits[N_EDGES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=e0_logits complete dim=0
  nnet::dense_batch<input_t, input_t, dense_config4>(Ro, e0_logits, w11, b11);
  input_t e0[N_EDGES][latent_dim];
  #pragma HLS ARRAY_PARTITION variable=e0 complete dim=0
  nnet::relu_batch<input_t, input_t, relu_config2>(e0_logits, e0);
  input_t e1_logits[N_EDGES][1];
  #pragma HLS ARRAY_PARTITION variable=e1_logits complete dim=0
  nnet::dense_batch<input_t, input_t, dense_config8>(e0, e1_logits, w12, b12);
  input_t e_logits[N_EDGES][1];
  #pragma HLS ARRAY_PARTITION variable=e_logits complete dim=0
  nnet::relu_batch<input_t, input_t, relu_config4>(e1_logits, e_logits);
  
  nnet::sigmoid_batch<input_t, input_t, sigmoid_config1>(e_logits, e);
}
