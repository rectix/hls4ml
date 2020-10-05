//Numpy array shape [8]
//Min -0.269198188774
//Max 0.178036214848
//Number of zeros 0

#ifndef DECODER_EDGE_B0_H_
#define DECODER_EDGE_B0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_b0[8];
#else
ap_fixed<16,6> decoder_edge_b0[8] = {0.054459, -0.005441, -0.269198, 0.000343, 0.178036, -0.008132, 0.057309, 0.171758};
#endif

#endif
