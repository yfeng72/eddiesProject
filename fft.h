//
// Created by sheny on 2016/12/20.
//
#include "complex.h"

#ifndef EDDIESPROJECT_FFT_H
#define EDDIESPROJECT_FFT_H


class fft {
public:
    fft( int N, bool isThreaded, vector<complex> list );

    vector<complex> thelist;

    vector<complex> ditfft2( vector<complex> &x, int N );

    vector<complex> recursivefft( const vector<complex> &x, int N, int curr );

};


#endif //EDDIESPROJECT_FFT_H
