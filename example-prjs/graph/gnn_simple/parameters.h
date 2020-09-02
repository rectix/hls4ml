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

//hls-fpga-machine-learning insert numbers
typedef ap_fixed<16,6> accum_default_t;
typedef ap_fixed<16,6> weight_default_t;
typedef ap_fixed<16,6> bias_default_t;
typedef ap_fixed<16,6> input_t;
typedef ap_fixed<16,6> result_t;
typedef ap_uint<16> index_t;
#define REUSE 4
#define N_ITERS 1
#define latent_dim 4
#define N_FEATURES 3
#define E_FEATURES 4
//2x2 example:
//#define N_NODES 4
//#define N_EDGES 4
//3x3 example:
//#define N_NODES 9
//#define N_EDGES 18
//4x4 example:
//#define N_NODES 16
//#define N_EDGES 48
//5x5 example:
//#define N_NODES 25
//#define N_EDGES 100
//ExatrkX by-hand example:
//#define N_NODES 2714
//#define N_EDGES 24758
//graph_nets simple example:
#define N_NODES 130
#define N_EDGES 224

//hls-fpga-machine-learning insert layer-config

struct graph_config1 : nnet::graph_config {
 struct dense_config1 : nnet::dense_config {
    static const unsigned n_batch = N_NODES;
    static const unsigned n_in = N_FEATURES;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config1 : nnet::activ_config {
    static const unsigned n_batch = N_NODES;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
  };
  struct dense_config2 : nnet::dense_config {
    static const unsigned n_batch = N_NODES;
    static const unsigned n_in = latent_dim;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config2 : nnet::activ_config {
    static const unsigned n_batch = N_NODES;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
  };
};

struct graph_config2 : nnet::graph_config {
  struct dense_config1 : nnet::dense_config {
    static const unsigned n_batch = N_EDGES;
    static const unsigned n_in = E_FEATURES;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config1 : nnet::activ_config {
    static const unsigned n_batch = N_EDGES;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
  };
  struct dense_config2 : nnet::dense_config {
    static const unsigned n_batch = N_EDGES;
    static const unsigned n_in = latent_dim;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config2 : nnet::activ_config {
    static const unsigned n_batch = N_EDGES;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
  };
};

struct graph_config3 : nnet::graph_config {
  static const unsigned n_edge = N_EDGES;
  static const unsigned n_node = N_NODES;
  static const unsigned n_hidden = latent_dim;

  struct dense_config1 : nnet::dense_config {
    static const unsigned n_in = 3*n_hidden;
    static const unsigned n_out = n_hidden;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
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
    static const unsigned reuse_factor = REUSE;
  };
  struct dense_config2 : nnet::dense_config {
    static const unsigned n_in = n_hidden;
    static const unsigned n_out = n_hidden;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
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
    static const unsigned reuse_factor = REUSE;
  };
};

struct graph_config4 : nnet::graph_config {
  static const unsigned n_edge = N_EDGES;
  static const unsigned n_node = N_NODES;
  static const unsigned n_hidden = latent_dim;

  struct dense_config1 : nnet::dense_config {
    static const unsigned n_in = 2*n_hidden;
    static const unsigned n_out = n_hidden;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
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
    static const unsigned reuse_factor = REUSE;
  };
  struct dense_config2 : nnet::dense_config {
    static const unsigned n_in = n_hidden;
    static const unsigned n_out = n_hidden;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
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
    static const unsigned reuse_factor = REUSE;
  };
};

struct graph_config5 : nnet::graph_config {
  struct dense_config1 : nnet::dense_config {
    static const unsigned n_batch = N_EDGES;
    static const unsigned n_in = latent_dim;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config1 : nnet::activ_config {
    static const unsigned n_batch = N_EDGES;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
  };
  struct dense_config2 : nnet::dense_config {
    static const unsigned n_batch = N_EDGES;
    static const unsigned n_in = latent_dim;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config2 : nnet::activ_config {
    static const unsigned n_batch = N_EDGES;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
  };
};

struct graph_config6 : nnet::graph_config {
  struct dense_config1 : nnet::dense_config {
    static const unsigned n_batch = N_EDGES;
    static const unsigned n_in = latent_dim;
    static const unsigned n_out = latent_dim;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config1 : nnet::activ_config {
    static const unsigned n_batch = N_EDGES;
    static const unsigned n_in = latent_dim;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
  };
  struct dense_config2 : nnet::dense_config {
    static const unsigned n_batch = N_EDGES;
    static const unsigned n_in = latent_dim;
    static const unsigned n_out = 1;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
    typedef accum_default_t accum_t;
    typedef bias_default_t bias_t;
    typedef weight_default_t weight_t;
  };
  struct relu_config2 : nnet::activ_config {
    static const unsigned n_batch = N_EDGES;
    static const unsigned n_in = 1;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = REUSE;
  };
};

struct sigmoid_config1 : nnet::activ_config {
  static const unsigned n_batch = N_EDGES;
  static const unsigned n_in = 1;
  static const unsigned table_size = 1024;
  static const unsigned io_type = nnet::io_parallel;
  static const unsigned reuse_factor = REUSE;
};

#endif 
