//Numpy array shape [4, 4]
//Min -0.686860088426
//Max 0.970351316698
//Number of zeros 0

#ifndef ENCODER_NODE_W1_H_
#define ENCODER_NODE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_w1[16];
#else
ap_fixed<16,6> encoder_node_w1[16] = {-0.165536, -0.165793, -0.323704, 0.509196, -0.686860, 0.633066, -0.366354, -0.323916, 0.970351, 0.049859, 0.330143, 0.405815, 0.963725, 0.261335, -0.424565, -0.368166};
#endif

#endif
