//Numpy array shape [4, 4]
//Min -1.423175808017
//Max 1.593038787364
//Number of zeros 0

#ifndef DECODER_EDGE_W2_H_
#define DECODER_EDGE_W2_H_

#ifndef __SYNTHESIS__
ap_fixed<12,6> decoder_edge_w2[16];
#else
ap_fixed<12,6> decoder_edge_w2[16] = {1.001723, -1.423176, -0.111751, 1.593039, -0.905015, -0.205330, 0.057152, -0.642746, -0.344840, -0.078049, 0.647755, 0.095186, -0.314188, -0.335452, -0.033033, -0.430242};
#endif

#endif
