//Numpy array shape [8]
//Min -0.109457304848
//Max 0.203482369102
//Number of zeros 0

#ifndef ENCODER_EDGE_B1_H_
#define ENCODER_EDGE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_b1[8];
#else
ap_fixed<16,6> encoder_edge_b1[8] = {0.011875, -0.104674, -0.021011, 0.016115, -0.109457, 0.203482, 0.002821, 0.060777};
#endif

#endif
