//Numpy array shape [4, 4]
//Min -0.811604360289
//Max 1.046217203769
//Number of zeros 0

#ifndef DECODER_EDGE_W2_H_
#define DECODER_EDGE_W2_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w2[16];
#else
ap_fixed<16,6> decoder_edge_w2[16] = {0.339041, 0.000876, -0.177097, -0.491772, 0.553085, -0.489727, -0.009234, -0.811604, 0.815429, 0.296187, 1.046217, 0.235136, 0.600367, 0.794897, 0.000159, -0.414872};
#endif

#endif
