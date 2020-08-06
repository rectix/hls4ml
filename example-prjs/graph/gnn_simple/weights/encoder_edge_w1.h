//Numpy array shape [4, 4]
//Min -0.929962298832
//Max 0.953894551464
//Number of zeros 0

#ifndef ENCODER_EDGE_W1_H_
#define ENCODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> encoder_edge_w1[16];
#else
ap_fixed<16,6> encoder_edge_w1[16] = {-0.282514, 0.239682, -0.303818, 0.004506, -0.929962, -0.584740, -0.345827, 0.255265, 0.115856, 0.120872, 0.874578, 0.712751, 0.192912, 0.953895, -0.223986, 0.062338};
#endif

#endif
