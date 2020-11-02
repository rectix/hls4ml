//Numpy array shape [4]
//Min -0.369082420372
//Max 0.003667652844
//Number of zeros 0

#ifndef ENCODER_NODE_B0_H_
#define ENCODER_NODE_B0_H_

#ifndef __SYNTHESIS__
ap_fixed<12,6> encoder_node_b0[4];
#else
ap_fixed<12,6> encoder_node_b0[4] = {0.003668, -0.369082, -0.163093, -0.003372};
#endif

#endif
