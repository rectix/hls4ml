#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "parameters.h"
#include "myproject.h"
#include "nnet_helpers.h"


int main(int argc, char **argv)
{

  //hls-fpga-machine-learning insert data

  input_t      N_str[N_NODES][N_FEATURES] = {0.03186538815498352, 0.4396468997001648, 0.027646400034427643, 0.07125214487314224, 0.41369643807411194, 0.06305709481239319, 0.0314718633890152, 0.7407453060150146, 0.01103190053254366, 0.0716928243637085, 0.7647077441215515, 0.028442300856113434};//random number list
  input_t      E_str[N_EDGES][E_FEATURES] = {0.03147043660283089, 0.7434012293815613, 0.011526799760758877, 0.07184796035289764, 0.7261484265327454, 0.02459540031850338, 0.11492523550987244, 0.7084840536117554, 0.0385465994477272, 0.17096249759197235, 0.6859502196311951, 0.056630197912454605, 0.03172731027007103, 0.513180136680603, 0.02495879866182804, 0.0710737556219101};
  ap_uint<16>  receivers_str[N_EDGES][1] = {2,3,2,3};
  ap_uint<16>  senders_str[N_EDGES][1] = {0,0,1,1};
  result_t     e_expected[N_EDGES][1] = {0.9993053674697876, 0.0009232835145667195, 0.0008830277365632355, 0.9996999502182007};


  result_t e_str[N_EDGES][1];
  for(int i=0; i<N_EDGES; i++){
    e_str[i][0]=0;
  }
  
  unsigned short size_in, size_out;
  myproject(N_str, E_str, receivers_str, senders_str, e_str, size_in, size_out);
    
  std::cout << "e = " << std::endl;
  for(int i=0; i<N_EDGES; i++){
    //std::cout << e_str[i][0] << " ";
    if (e_str[i][0]==0 && e_expected[i][0]==0){
      std::cout << e_str[i][0] << " (expected " << e_expected[i][0] << ", 0 percent difference)" << std::endl;
    }
    else {
      std::cout << e_str[i][0] << " (expected " << e_expected[i][0] << ", " << 100.*((float)e_str[i][0]-(float)e_expected[i][0])/(float)e_expected[i][0] << " percent difference)" << std::endl;
    }
  }
  std::cout << std::endl;
  
  return 0;
}

