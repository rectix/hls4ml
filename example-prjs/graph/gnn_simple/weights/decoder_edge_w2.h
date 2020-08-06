//Numpy array shape [4, 4]
//Min -0.951649240769
//Max 0.965948914308
//Number of zeros 0

#ifndef DECODER_EDGE_W2_H_
#define DECODER_EDGE_W2_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w2[16];
#else
ap_fixed<16,6> decoder_edge_w2[16] = {0.055024, 0.068699, 0.625865, 0.965949, 0.466400, -0.037811, -0.315672, 0.070303, -0.951649, 0.128512, 0.157135, -0.312311, -0.338464, 0.285682, -0.046961, 0.122895};
#endif

#endif
