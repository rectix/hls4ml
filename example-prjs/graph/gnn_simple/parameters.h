#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include <complex>
#include "ap_int.h"
#include "ap_fixed.h"
#include "nnet_dense.h"
#include "nnet_conv.h"
#include "nnet_activation.h"
#include "nnet_graph.h"
#include "nnet_common.h"
#include "nnet_helpers.h"

//insert weights from training
#include "weights/encoder_node_w0.h"
#include "weights/encoder_node_b0.h"
#include "weights/encoder_node_w1.h"
#include "weights/encoder_node_b1.h"
#include "weights/encoder_edge_w0.h"
#include "weights/encoder_edge_b0.h"
#include "weights/encoder_edge_w1.h"
#include "weights/encoder_edge_b1.h"
#include "weights/core_edge_w0.h"
#include "weights/core_edge_b0.h"
#include "weights/core_edge_w1.h"
#include "weights/core_edge_b1.h"
#include "weights/core_node_w0.h"
#include "weights/core_node_b0.h"
#include "weights/core_node_w1.h"
#include "weights/core_node_b1.h"
#include "weights/decoder_edge_w0.h"
#include "weights/decoder_edge_b0.h"
#include "weights/decoder_edge_w1.h"
#include "weights/decoder_edge_b1.h"
#include "weights/decoder_edge_w2.h"
#include "weights/decoder_edge_b2.h"
#include "weights/decoder_edge_w3.h"
#include "weights/decoder_edge_b3.h"

//hls-fpga-machine-learning insert numbers
typedef ap_fixed<16,6> accum_default_t;
typedef ap_fixed<16,6> weight_default_t;
typedef ap_fixed<16,6> bias_default_t;
typedef ap_fixed<16,6> model_default_t;
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> result_t;
typedef ap_uint<16> index_t;
#define REUSE_GRAPH 8
#define REUSE_DENSE 1
#define N_ITERS 1
#define latent_dim 8
#define N_FEATURES 3
#define E_FEATURES 4
//graph_nets simple example:
#define N_NODES_MAX 10//112
#define N_EDGES_MAX 20//148

//hls-fpga-machine-learning define weights
#ifndef __SYNTHESIS__
  static bool loaded_weights = false;
 if (!loaded_weights) {
  //hls-fpga-machine-learning insert load weights
  /*
  struct encoder_node_w {
    nnet::load_weights_from_txt<model_default_t, N_FEATURES*latent_dim>(encoder_node_w0, "encoder_node_w0.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim*latent_dim>(encoder_node_w1, "encoder_node_w1.txt");
  };
  struct encoder_node_b {
    nnet::load_weights_from_txt<model_default_t, latent_dim>(encoder_node_b0, "encoder_node_b0.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim>(encoder_node_b1, "encoder_node_b1.txt");
  };
  struct encoder_edge_w {
    nnet::load_weights_from_txt<model_default_t, E_FEATURES*latent_dim>(encoder_edge_w0, "encoder_edge_w0.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim*latent_dim>(encoder_edge_w1, "encoder_edge_w1.txt");
  };
  struct encoder_edge_b {
    nnet::load_weights_from_txt<model_default_t, latent_dim>(encoder_edge_b0, "encoder_edge_b0.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim>(encoder_edge_b1, "encoder_edge_b1.txt");
  };
  */
  struct core_edge_w {
    nnet::load_weights_from_txt<model_default_t, 3*latent_dim*latent_dim>(core_edge_w0, "core_edge_w0.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim*latent_dim>(core_edge_w1, "core_edge_w1.txt");
  };
  struct core_edge_b {
    nnet::load_weights_from_txt<model_default_t, latent_dim>(core_edge_b0, "core_edge_b0.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim>(core_edge_b1, "core_edge_b1.txt");
  };
  struct core_node_w {
    nnet::load_weights_from_txt<model_default_t, 2*latent_dim*latent_dim>(core_node_w0, "core_node_w0.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim*latent_dim>(core_node_w1, "core_node_w1.txt");
  };
  struct core_node_b {
    nnet::load_weights_from_txt<model_default_t, latent_dim>(core_node_b0, "core_node_b0.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim>(core_node_b1, "core_node_b1.txt");
  };
  /*
  struct decoder_edge_w {
    nnet::load_weights_from_txt<model_default_t, latent_dim*latent_dim>(decoder_edge_w0, "decoder_edge_w0.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim*latent_dim>(decoder_edge_w1, "decoder_edge_w1.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim*latent_dim>(decoder_edge_w2, "decoder_edge_w2.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim*1>(decoder_edge_w3, "decoder_edge_w3.txt");
  };
  struct decoder_edge_b {
    nnet::load_weights_from_txt<model_default_t, latent_dim>(decoder_edge_b0, "decoder_edge_b0.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim>(decoder_edge_b1, "decoder_edge_b1.txt");
    nnet::load_weights_from_txt<model_default_t, latent_dim>(decoder_edge_b2, "decoder_edge_b2.txt");
    nnet::load_weights_from_txt<model_default_t, 1>(decoder_edge_b3, "decoder_edge_b3.txt");
  };
  */
  loaded_weights = true;
 }
#endif

//hls-fpga-machine-learning insert layer-config

struct graph_config1 : nnet::graph_config {
  static const bool io_stream = true;
  static const bool activate_final = true;
  static const unsigned reuse_factor = REUSE_GRAPH;

  struct dense_config1 : nnet::dense_config {
    static const unsigned n_batch = N_NODES_MAX;
    static const unsigned n_in = N_FEATURES;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE_DENSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config1 : nnet::activ_config {
    static const unsigned n_batch = N_NODES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
  };
  struct dense_config2 : nnet::dense_config {
    static const unsigned n_batch = N_NODES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE_DENSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config2 : nnet::activ_config {
    static const unsigned n_batch = N_NODES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
  };
};

struct graph_config2 : nnet::graph_config {
  static const bool io_stream = true;
  static const bool activate_final = true;
  static const unsigned reuse_factor = REUSE_GRAPH;

  struct dense_config1 : nnet::dense_config {
    static const unsigned n_batch = N_EDGES_MAX;
    static const unsigned n_in = E_FEATURES;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE_DENSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config1 : nnet::activ_config {
    static const unsigned n_batch = N_EDGES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
  };
  struct dense_config2 : nnet::dense_config {
    static const unsigned n_batch = N_EDGES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE_DENSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config2 : nnet::activ_config {
    static const unsigned n_batch = N_EDGES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
  };
};

struct graph_config3 : nnet::graph_config {
  static const unsigned n_edge = N_EDGES_MAX;
  static const unsigned n_node = N_NODES_MAX;
  static const unsigned n_hidden = latent_dim;
  static const bool io_stream = true;
  static const bool activate_final = true;
  static const unsigned reuse_factor = REUSE_GRAPH;
  static const unsigned n_layers = 2;


  struct dense_config1 : nnet::dense_config {
    static const unsigned n_in = 3*n_hidden;
    static const unsigned n_out = n_hidden;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE_DENSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config1 : nnet::activ_config {
    static const unsigned n_in = n_hidden;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
  };
  struct dense_config2 : nnet::dense_config {
    static const unsigned n_in = n_hidden;
    static const unsigned n_out = n_hidden;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE_DENSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config2 : nnet::activ_config {
    static const unsigned n_in = n_hidden;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
  };
};

struct graph_config4 : nnet::graph_config {
  static const unsigned n_edge = N_EDGES_MAX;
  static const unsigned n_node = N_NODES_MAX;
  static const unsigned n_hidden = latent_dim;
  static const bool activate_final = true;
  static const unsigned reuse_factor = REUSE_GRAPH;
  static const unsigned n_layers = 2;


  struct dense_config1 : nnet::dense_config {
    static const unsigned n_in = 2*n_hidden;
    static const unsigned n_out = n_hidden;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE_DENSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config1 : nnet::activ_config {
    static const unsigned n_in = n_hidden;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
  };
  struct dense_config2 : nnet::dense_config {
    static const unsigned n_in = n_hidden;
    static const unsigned n_out = n_hidden;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE_DENSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config2 : nnet::activ_config {
    static const unsigned n_in = n_hidden;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
  };
};

struct graph_config5 : nnet::graph_config {
  static const bool io_stream = false;
  static const bool activate_final = true;
  static const unsigned reuse_factor = REUSE_GRAPH;


  struct dense_config1 : nnet::dense_config {
    static const unsigned n_batch = N_EDGES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE_DENSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config1 : nnet::activ_config {
    static const unsigned n_batch = N_EDGES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
  };
  struct dense_config2 : nnet::dense_config {
    static const unsigned n_batch = N_EDGES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE_DENSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config2 : nnet::activ_config {
    static const unsigned n_batch = N_EDGES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
  };
};

struct graph_config6 : nnet::graph_config {
  static const bool io_stream = false;
  static const bool activate_final = false;
  static const unsigned reuse_factor = REUSE_GRAPH;

  struct dense_config1 : nnet::dense_config {
    static const unsigned n_batch = N_EDGES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE_DENSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config1 : nnet::activ_config {
    static const unsigned n_batch = N_EDGES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
  };
  struct dense_config2 : nnet::dense_config {
    static const unsigned n_batch = N_EDGES_MAX;
    static const unsigned n_in = latent_dim;
    static const unsigned n_out = 1;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE_DENSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config2 : nnet::activ_config {
    static const unsigned n_batch = N_EDGES_MAX;
    static const unsigned n_in = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
  };
};

struct sigmoid_config1 : nnet::activ_config {
  static const unsigned n_batch = N_EDGES_MAX;
  static const unsigned n_in = 1;
  static const unsigned table_size = 1024;
  static const unsigned io_type = nnet::io_parallel;
  static const unsigned reuse_factor = REUSE_DENSE;
};

#endif 
