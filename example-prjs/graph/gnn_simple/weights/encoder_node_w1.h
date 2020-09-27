//Numpy array shape [4, 4]
//Min -0.670670911513
//Max 0.698010556923
//Number of zeros 0

#ifndef ENCODER_NODE_W1_H_
#define ENCODER_NODE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_w1[16];
#else
ap_fixed<16,6> encoder_node_w1[16] = {0.332589, 0.447133, 0.520120, -0.373393, -0.519422, -0.066019, 0.014081, -0.109804, 0.168616, 0.698011, 0.237286, -0.252965, 0.321809, -0.670671, 0.616584, -0.068445};
#endif

#endif
