//Numpy array shape [4, 4]
//Min -1.694821877916
//Max 1.037897478804
//Number of zeros 0

#ifndef ENCODER_EDGE_W1_H_
#define ENCODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_w1[16];
#else
ap_fixed<16,6> encoder_edge_w1[16] = {0.085861, -0.804912, 1.037897, -0.740202, 0.389819, -1.271284, 0.424559, -0.761312, 0.540786, -1.694822, 0.435053, -0.748278, -0.744134, -0.294481, -0.152048, -0.089852};
#endif

#endif
