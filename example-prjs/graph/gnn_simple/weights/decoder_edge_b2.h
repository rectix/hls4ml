//Numpy array shape [8]
//Min -1.241187612562
//Max 0.285819856968
//Number of zeros 0

#ifndef DECODER_EDGE_B2_H_
#define DECODER_EDGE_B2_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_b2[8];
#else
ap_fixed<16,6> decoder_edge_b2[8] = {-1.241188, 0.125366, -0.574702, 0.098287, 0.110675, 0.280448, 0.107422, 0.285820};
#endif

#endif
