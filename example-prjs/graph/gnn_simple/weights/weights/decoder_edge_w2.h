//Numpy array shape [4, 4]
//Min -0.959705228548
//Max 0.651741611132
//Number of zeros 0

#ifndef DECODER_EDGE_W2_H_
#define DECODER_EDGE_W2_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w2[16];
#else
ap_fixed<16,6> decoder_edge_w2[16] = {0.314694, -0.460470, 0.075340, -0.260712, -0.297037, -0.517073, -0.852789, 0.259200, -0.522347, -0.959705, 0.534157, -0.351125, 0.212786, -0.281085, 0.651742, 0.090814};
#endif

#endif
