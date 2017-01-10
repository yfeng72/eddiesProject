#include <iostream>
#include <vector>
#include "complex.h"
#include "fft.h"
#include "threadedFFT.h"
#include <cmath>

int main() {
    vector<complex> list;
    list.push_back( complex( 1.0, 0.0 ) );
    list.push_back( complex( 2.0, 0.0 ) );
    list.push_back( complex( 3.0, 0.0 ) );
    list.push_back( complex( 4.0, 0.0 ) );
    list.push_back( complex( 5.0, 0.0 ) );
    list.push_back( complex( 6.0, 0.0 ) );
    list.push_back( complex( 7.0, 0.0 ) );
    list.push_back( complex( 8.0, 0.0 ) );
    fft transform( 8, false, list );
    vector<complex> transformedList = transform.ditfft2( list, 8 );
    std::cout << "Scaled Transformed List:" << std::endl;
    for ( complex item : transformedList ) {
        std::cout << item.re / sqrt( 8.0 ) << " + " << item.im / sqrt( 8.0 ) << "i" << std::endl;
    }
    std::cout << std::endl << std::endl;
    threadedFFT threaded( 8 );
    threaded.run( list );
    vector<complex> threadedTransform = threaded.transformedList;
    std::cout << "Scaled Transformed List:" << std::endl;
    for ( complex item : threadedTransform ) {
        std::cout << item.re / sqrt( 8.0 ) << " + " << item.im / sqrt( 8.0 ) << "i" << std::endl;
    }
    return 0;
}