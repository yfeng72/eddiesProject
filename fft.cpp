//
// Created by sheny on 2016/12/20.
//

#include "fft.h"

vector<int> fft::ditfft2(vector<int> x, int N, int s) {
    vector<int> y;
    if(N==1){
        y.push_back(x[0]);
    }
    else{
        ditfft2(x,N/2, 2*s);
        ditfft2(x[s], N/2, 2*s);
        for(int i=0; i<(N/2)-1; i++){
            int t = y[k];
            y[k] = t+x[(k+N)/2];
            y[k+N/2] = t-x[(k+N)/2];

        }
    }
}

