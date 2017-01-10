#include <iostream>
#include <vector>
#include "complex.h"
#include "fft.h"
#include <cmath>
#include "readcsv.h"

int main() {
    readcsv read("try.txt");
    for(int i=0; i<read.allcomplex.size(); i++){
        cout << read.allcomplex[i].re << endl;
        cout << read.allcomplex[i].im << endl;
    }
    vector<complex> list;
    list.push_back( complex( 1.0, 0.0 ) );
    list.push_back( complex( 2.0, 0.0 ) );
    list.push_back( complex( 3.0, 0.0 ) );
    list.push_back( complex( 4.0, 0.0 ) );
    list.push_back( complex( 5.0, 0.0 ) );
    list.push_back( complex( 6.0, 0.0 ) );
    list.push_back( complex( 7.0, 0.0 ) );
    list.push_back( complex( 8.0, 0.0 ) );
    fft transform( 8, false, NULL );
    vector<complex> transformedList = transform.ditfft2( list, 8 );
    std::cout << "Scaled Transformed List:" << std::endl;
    for ( complex item : transformedList ) {
        std::cout << item.re / sqrt( 8.0 ) << " + " << item.im / sqrt( 8.0 ) << "i" << std::endl;
    }
    return 0;
}