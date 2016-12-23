//
// Created by sheny on 2016/12/20.
//

#include "fft.h"

vector<complex> fft::ditfft2(vector<complex> x, int N) {
    recursivefft(x, N, thelist);
    vector<complex> ret = x;
    return ret;
}

void fft::recursivefft(vector<complex> &x, int N, vector<complex> prevlist){
    if(N==1){
        return;
    }
    int halflength=N/2;
    vector<complex> firsthalf;
    vector<complex> secondhalf;

    //initialization of the recursive vector
    for(int i=0; i<halflength; i++){
        complex t1(x[2*i], x[2*i]);
        complex t2(x[2*i-1], x[2*i-1]);
        firsthalf.push_back(t1);
        secondhalf.push_back(t2);
    }
    
    recursivefft(firsthalf, halflength, prevlist);
    recursivefft(secondhalf, halflength, prevlist);
    for(int i=0; i<halflength; i++){
        complex temp=firsthalf[i];

    }

}

void fft::createthelist(int size) {
    for(int i=0; i<size; i++){
        complex temp=complex(0.0, -2.0*M_PI*i/size);
        temp=temp.exp();
        thelist.push_back(temp);
    }
}
