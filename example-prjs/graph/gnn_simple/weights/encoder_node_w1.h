//Numpy array shape [4, 4]
//Min -0.586812572044
//Max 0.640963133022
//Number of zeros 0

#ifndef ENCODER_NODE_W1_H_
#define ENCODER_NODE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_w1[16];
#else
ap_fixed<16,6> encoder_node_w1[16] = {0.410253, -0.586813, 0.087428, 0.311484, 0.138031, -0.269604, 0.201190, -0.417576, -0.169176, -0.079115, 0.014005, -0.577397, 0.640963, -0.058714, 0.376009, -0.310876};
#endif

#endif
