//Numpy array shape [4]
//Min -0.524071239268
//Max -0.011780865822
//Number of zeros 0

#ifndef DECODER_EDGE_B1_H_
#define DECODER_EDGE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<12,6> decoder_edge_b1[4];
#else
ap_fixed<12,6> decoder_edge_b1[4] = {-0.055541, -0.524071, -0.011781, -0.049948};
#endif

#endif
