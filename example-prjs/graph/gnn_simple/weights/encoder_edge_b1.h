//Numpy array shape [4]
//Min 0.000000000000
//Max 0.334081388967
//Number of zeros 1

#ifndef ENCODER_EDGE_B1_H_
#define ENCODER_EDGE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_b1[4];
#else
ap_fixed<16,6> encoder_edge_b1[4] = {0.332709, 0.334081, 0.288051, 0.000000};
#endif

#endif
