//Numpy array shape [4]
//Min -0.000031500230
//Max 1.477006636749
//Number of zeros 2

#ifndef DECODER_EDGE_B2_H_
#define DECODER_EDGE_B2_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_b2[4];
#else
ap_fixed<16,6> decoder_edge_b2[4] = {0.000000, 0.000000, -0.000032, 1.477007};
#endif

#endif
