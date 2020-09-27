//Numpy array shape [4]
//Min -0.005558713109
//Max 0.204643261068
//Number of zeros 0

#ifndef DECODER_EDGE_B0_H_
#define DECODER_EDGE_B0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_b0[4];
#else
ap_fixed<16,6> decoder_edge_b0[4] = {0.194410, 0.007130, -0.005559, 0.204643};
#endif

#endif
