//Numpy array shape [4, 4]
//Min -0.408095980580
//Max 0.688536596849
//Number of zeros 0

#ifndef DECODER_EDGE_W2_H_
#define DECODER_EDGE_W2_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w2[16];
#else
ap_fixed<16,6> decoder_edge_w2[16] = {0.223931, -0.080143, 0.180560, 0.004869, 0.329183, -0.232106, -0.080347, 0.386235, 0.688537, 0.018392, -0.144996, -0.408096, 0.208768, 0.313669, -0.114467, -0.149731};
#endif

#endif
