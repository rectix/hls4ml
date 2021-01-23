//Numpy array shape [8]
//Min -0.035665901854
//Max 0.253218205073
//Number of zeros 0

#ifndef ENCODER_NODE_B0_H_
#define ENCODER_NODE_B0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_b0[8];
#else
ap_fixed<16,6> encoder_node_b0[8] = {-0.000955, 0.027715, 0.253218, 0.085226, 0.105190, -0.035666, 0.199279, 0.158689};
#endif

#endif
