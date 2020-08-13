//Numpy array shape [4, 4]
//Min -0.571677449788
//Max 0.926185435591
//Number of zeros 0

#ifndef ENCODER_EDGE_W1_H_
#define ENCODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_w1[16];
#else
ap_fixed<16,6> encoder_edge_w1[16] = {-0.226862, 0.926185, -0.100733, -0.571677, -0.105625, 0.606803, 0.622315, 0.042307, -0.007175, -0.302818, 0.168220, 0.795329, -0.400146, 0.108956, 0.475551, 0.503108};
#endif

#endif
