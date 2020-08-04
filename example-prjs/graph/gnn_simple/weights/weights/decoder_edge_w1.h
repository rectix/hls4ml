//Numpy array shape [4, 4]
//Min -0.980888802979
//Max 0.980085389240
//Number of zeros 0

#ifndef DECODER_EDGE_W1_H_
#define DECODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w1[16];
#else
ap_fixed<16,6> decoder_edge_w1[16] = {-0.980889, -0.548195, -0.531869, -0.962293, 0.212363, 0.324455, 0.564625, -0.262512, 0.573824, -0.568195, 0.289400, -0.218263, -0.777131, 0.889901, 0.980085, -0.743645};
#endif

#endif
