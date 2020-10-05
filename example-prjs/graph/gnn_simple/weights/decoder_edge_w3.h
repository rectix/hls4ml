//Numpy array shape [1, 8]
//Min -1.044962820095
//Max 0.578858593176
//Number of zeros 0

#ifndef DECODER_EDGE_W3_H_
#define DECODER_EDGE_W3_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w3[8];
#else
ap_fixed<16,6> decoder_edge_w3[8] = {0.578859, 0.053594, -0.747716, 0.413253, -0.796918, -1.044963, -0.521197, -0.595514};
#endif

#endif
