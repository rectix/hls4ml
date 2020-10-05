//Numpy array shape [4]
//Min -0.042715245874
//Max 0.299285734531
//Number of zeros 0

#ifndef DECODER_EDGE_B0_H_
#define DECODER_EDGE_B0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_b0[4];
#else
ap_fixed<16,6> decoder_edge_b0[4] = {0.299286, 0.108972, 0.126978, -0.042715};
#endif

#endif
