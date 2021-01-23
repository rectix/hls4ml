//Numpy array shape [8]
//Min -0.020567647316
//Max 0.158172382865
//Number of zeros 0

#ifndef ENCODER_NODE_B1_H_
#define ENCODER_NODE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_b1[8];
#else
ap_fixed<16,6> encoder_node_b1[8] = {0.055769, 0.024249, 0.158172, 0.078701, -0.020568, 0.091713, -0.009654, 0.030699};
#endif

#endif
