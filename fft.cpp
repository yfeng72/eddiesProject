//
// Created by sheny on 2016/12/20.
//

#include <vector>
#include <math.h>
#include "fft.h"

fft::fft( int N ) {
    for ( int i = 0; i < N; i++ ) {
        complex temp = complex( 0.0, -2.0 * M_PI * i / N ).exp();
        thelist.push_back( temp );
    }
}

vector<complex> fft::ditfft2( vector<complex> &x, int N ) {
    vector<complex> ret = recursivefft( x, N, N );
    return ret;
}

vector<complex> fft::recursivefft( const vector<complex> &x, int N, int curr ) {
    if ( curr == 1 ) {
        return x;
    }
    int halflength = curr / 2;
    vector<complex> firsthalf;
    vector<complex> secondhalf;

    //initialization of the recursive vector
    for ( int i = 0; i < halflength; i++ ) {
        complex t1( x[2 * i].re, x[2 * i].im );
        complex t2( x[2 * i + 1].re, x[2 * i + 1].im );
        firsthalf.push_back( t1 );
        secondhalf.push_back( t2 );
    }

    firsthalf = recursivefft( firsthalf, N, halflength );
    secondhalf = recursivefft( secondhalf, N, halflength );
    vector<complex> transformedVector( (unsigned int) curr );
    for ( int i = 0; i < halflength; i++ ) {
        complex temp = firsthalf[i];
        complex product = secondhalf[i] * thelist[( N / curr ) * i];
        complex sum = temp + product;
        complex diff = temp - product;
        transformedVector[i] = sum;
        transformedVector[halflength + i] = diff;
    }
    return transformedVector;
}
