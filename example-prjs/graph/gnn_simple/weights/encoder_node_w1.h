//Numpy array shape [4, 4]
//Min -0.937142611355
//Max 0.705381902686
//Number of zeros 0

#ifndef ENCODER_NODE_W1_H_
#define ENCODER_NODE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_w1[16];
#else
ap_fixed<16,6> encoder_node_w1[16] = {0.094451, 0.046605, -0.149785, 0.271232, -0.041930, -0.139892, -0.937143, -0.437176, 0.705382, -0.624242, -0.133392, -0.568288, 0.158921, -0.188286, 0.052644, -0.497774};
#endif

#endif
