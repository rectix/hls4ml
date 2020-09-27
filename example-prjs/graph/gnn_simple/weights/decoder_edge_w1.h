//Numpy array shape [4, 4]
//Min -0.962005123091
//Max 0.936657422980
//Number of zeros 0

#ifndef DECODER_EDGE_W1_H_
#define DECODER_EDGE_W1_H_

#ifndef __SYNTHESIS__
ap_fixed<16,6> decoder_edge_w1[16];
#else
ap_fixed<16,6> decoder_edge_w1[16] = {-0.530215, 0.158722, -0.227602, 0.127341, -0.962005, 0.203086, -0.125108, 0.177867, 0.936657, -0.061169, -0.798282, 0.679414, 0.399611, -0.220603, -0.391908, 0.609929};
#endif

#endif
