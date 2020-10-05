//Numpy array shape [4]
//Min -0.321409697649
//Max 0.106201486327
//Number of zeros 1

#ifndef ENCODER_NODE_B1_H_
#define ENCODER_NODE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_b1[4];
#else
ap_fixed<16,6> encoder_node_b1[4] = {-0.236229, 0.106201, 0.000000, -0.321410};
#endif

#endif
