//Numpy array shape [4, 4]
//Min -0.402849373983
//Max 0.772782491574
//Number of zeros 0

#ifndef DECODER_EDGE_W1_H_
#define DECODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w1[16];
#else
ap_fixed<16,6> decoder_edge_w1[16] = {0.070719, 0.274851, -0.185474, -0.169666, 0.079282, -0.381363, -0.391755, 0.065434, -0.377190, -0.037921, 0.772782, 0.587944, -0.402849, 0.174955, 0.477598, 0.179757};
#endif

#endif
