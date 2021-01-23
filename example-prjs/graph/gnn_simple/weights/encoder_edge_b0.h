//Numpy array shape [8]
//Min -0.071225869894
//Max 0.171979333079
//Number of zeros 0

#ifndef ENCODER_EDGE_B0_H_
#define ENCODER_EDGE_B0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_b0[8];
#else
ap_fixed<16,6> encoder_edge_b0[8] = {0.171979, 0.021091, -0.015397, -0.071226, 0.127835, -0.022244, 0.139032, 0.055047};
#endif

#endif
