//Numpy array shape [8]
//Min -0.434109782579
//Max 0.208594881200
//Number of zeros 0

#ifndef DECODER_EDGE_B0_H_
#define DECODER_EDGE_B0_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_b0[8];
#else
ap_fixed<16,6> decoder_edge_b0[8] = {0.195037, 0.043983, 0.060431, 0.146445, 0.208595, -0.127926, -0.434110, 0.144648};
#endif

#endif
