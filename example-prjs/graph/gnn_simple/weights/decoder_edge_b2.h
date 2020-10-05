//Numpy array shape [8]
//Min -0.228818141508
//Max 0.119805979850
//Number of zeros 1

#ifndef DECODER_EDGE_B2_H_
#define DECODER_EDGE_B2_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_b2[8];
#else
ap_fixed<16,6> decoder_edge_b2[8] = {-0.228818, 0.000000, 0.108988, -0.006003, -0.000216, 0.119806, 0.026647, 0.000075};
#endif

#endif
