//Numpy array shape [4]
//Min -0.004639149827
//Max 0.353624400372
//Number of zeros 0

#ifndef ENCODER_EDGE_B0_H_
#define ENCODER_EDGE_B0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_b0[4];
#else
ap_fixed<16,6> encoder_edge_b0[4] = {0.346769, -0.004639, 0.353624, 0.054547};
#endif

#endif
