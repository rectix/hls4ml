//Numpy array shape [4, 4]
//Min -0.602678860630
//Max 0.864324585772
//Number of zeros 0

#ifndef ENCODER_NODE_W1_H_
#define ENCODER_NODE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_node_w1[16];
#else
ap_fixed<16,6> encoder_node_w1[16] = {0.843748, 0.864325, 0.067112, 0.747243, -0.053738, 0.279876, 0.225589, 0.806275, 0.038597, -0.152081, 0.322626, 0.741551, -0.602679, 0.446926, -0.512274, 0.324542};
#endif

#endif
