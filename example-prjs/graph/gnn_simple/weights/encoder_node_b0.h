//Numpy array shape [4]
//Min -0.199256414070
//Max 0.251650329678
//Number of zeros 0

#ifndef ENCODER_NODE_B0_H_
#define ENCODER_NODE_B0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_b0[4];
#else
ap_fixed<16,6> encoder_node_b0[4] = {0.142062, 0.129553, 0.251650, -0.199256};
#endif

#endif
