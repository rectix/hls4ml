//Numpy array shape [4]
//Min -0.073552035579
//Max -0.000032093494
//Number of zeros 0

#ifndef DECODER_EDGE_B1_H_
#define DECODER_EDGE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_b1[4];
#else
ap_fixed<16,6> decoder_edge_b1[4] = {-0.023564, -0.019506, -0.000032, -0.073552};
#endif

#endif
