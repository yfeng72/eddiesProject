
#ifndef EDDIESPROJECT_THREADEDFFT_H
#define EDDIESPROJECT_THREADEDFFT_H


#include <vector>
#include "complex.h"

class threadedFFT {
public:
    vector<complex> firstHalf;
    vector<complex> secondHalf;
    vector<complex> transformedList;
    vector<complex> theList;
    vector<complex> halfList;

    threadedFFT( int N );

    void generateList( int N, bool firstHalf );
    void partialTransform( int N, bool firstHalf );
    void merge( int N, bool firstPart );

    void run( vector<complex> &list );
};


#endif //EDDIESPROJECT_THREADEDFFT_H
