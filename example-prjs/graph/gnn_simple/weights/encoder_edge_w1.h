//Numpy array shape [4, 4]
//Min -1.025407323669
//Max 1.654130932928
//Number of zeros 0

#ifndef ENCODER_EDGE_W1_H_
#define ENCODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_w1[16];
#else
ap_fixed<16,6> encoder_edge_w1[16] = {-0.339800, -0.110672, 0.001793, -0.426137, 0.956578, -0.943039, -1.025407, 0.773536, 0.686930, -0.234370, -0.408917, 0.521112, 0.265351, -0.492422, -0.028999, 1.654131};
#endif

#endif
