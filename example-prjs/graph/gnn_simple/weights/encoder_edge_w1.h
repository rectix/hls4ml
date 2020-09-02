//Numpy array shape [4, 4]
//Min -0.964470751332
//Max 0.729676784974
//Number of zeros 0

#ifndef ENCODER_EDGE_W1_H_
#define ENCODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_w1[16];
#else
ap_fixed<16,6> encoder_edge_w1[16] = {0.463921, -0.143520, 0.249893, 0.729677, -0.908648, -0.292170, 0.627889, 0.107863, -0.071497, 0.242867, -0.923998, 0.150560, -0.964471, 0.085469, 0.515480, -0.899024};
#endif

#endif
