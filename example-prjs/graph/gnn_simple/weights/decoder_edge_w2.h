//Numpy array shape [4, 4]
//Min -0.676681188031
//Max 0.893178243047
//Number of zeros 0

#ifndef DECODER_EDGE_W2_H_
#define DECODER_EDGE_W2_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w2[16];
#else
ap_fixed<16,6> decoder_edge_w2[16] = {-0.193278, 0.748060, -0.253098, -0.248169, 0.169744, -0.234026, 0.565884, -0.676681, 0.893178, 0.462186, -0.080816, -0.328028, -0.128601, 0.413731, 0.133158, -0.053451};
#endif

#endif
