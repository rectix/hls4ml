//Numpy array shape [8]
//Min -0.028598512689
//Max 0.309919575701
//Number of zeros 0

#ifndef DECODER_EDGE_B1_H_
#define DECODER_EDGE_B1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_b1[8];
#else
ap_fixed<16,6> decoder_edge_b1[8] = {0.295410, -0.028599, 0.153718, -0.008658, 0.309920, 0.167970, 0.063277, 0.148589};
#endif

#endif
