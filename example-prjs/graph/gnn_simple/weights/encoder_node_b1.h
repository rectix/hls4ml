//Numpy array shape [4]
//Min -0.063935033929
//Max 0.216719436447
//Number of zeros 0

#ifndef ENCODER_NODE_B1_H_
#define ENCODER_NODE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_b1[4];
#else
ap_fixed<16,6> encoder_node_b1[4] = {0.216719, -0.021885, -0.063935, 0.209430};
#endif

#endif
