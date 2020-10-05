//Numpy array shape [4]
//Min -0.016418345466
//Max 0.206275993242
//Number of zeros 0

#ifndef ENCODER_EDGE_B1_H_
#define ENCODER_EDGE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_b1[4];
#else
ap_fixed<16,6> encoder_edge_b1[4] = {-0.002199, 0.206276, -0.016418, 0.049240};
#endif

#endif
