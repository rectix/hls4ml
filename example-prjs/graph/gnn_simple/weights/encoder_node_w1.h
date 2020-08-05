//Numpy array shape [4, 4]
//Min -0.957064116438
//Max 0.683855173064
//Number of zeros 0

#ifndef ENCODER_NODE_W1_H_
#define ENCODER_NODE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_w1[16];
#else
ap_fixed<16,6> encoder_node_w1[16] = {0.574948, 0.066996, -0.168200, -0.254799, -0.191288, -0.019778, -0.321443, -0.957064, -0.293583, 0.473680, 0.007686, 0.683855, 0.163283, 0.332474, -0.288464, -0.638281};
#endif

#endif
