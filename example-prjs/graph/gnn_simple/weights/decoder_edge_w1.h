//Numpy array shape [4, 4]
//Min -0.659540249762
//Max 1.280202084231
//Number of zeros 0

#ifndef DECODER_EDGE_W1_H_
#define DECODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<12,6> decoder_edge_w1[16];
#else
ap_fixed<12,6> decoder_edge_w1[16] = {1.280202, 0.983363, 1.169576, -0.412490, 0.196897, 0.389899, -0.029273, 0.464949, -0.078032, 0.058232, -0.659540, -0.200696, 0.724375, 0.566985, 1.116842, -0.074896};
#endif

#endif
