//Numpy array shape [4, 4]
//Min -0.821224357210
//Max 0.828368752038
//Number of zeros 0

#ifndef CORE_EDGE_W1_H_
#define CORE_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> core_edge_w1[16];
#else
ap_fixed<16,6> core_edge_w1[16] = {0.224521, 0.051267, -0.821224, 0.614841, -0.795629, -0.488068, 0.097079, 0.828369, 0.464901, 0.566742, -0.335988, 0.003298, -0.230002, 0.125694, -0.192815, -0.049347};
#endif

#endif
