//
// Created by fengy on 1/1/2017.
//

#include <cmath>
#include <thread>
#include "threadedFFT.h"
#include "fft.h"

threadedFFT::threadedFFT( int N ) {
    firstHalf = vector<complex>((unsigned int) N >> 1 );
    secondHalf = vector<complex>((unsigned int) N >> 1 );
    transformedList = vector<complex>((unsigned int) N );
    theList = vector<complex>((unsigned int) N >> 1 );
    halfList = vector<complex>((unsigned int) N );
}

void threadedFFT::merge( int N, bool firstPart ) {
    if ( firstPart ) {
        for ( int i = 0; i < N; i++ ) {
            transformedList[i] = firstHalf[i] + secondHalf[i] * halfList[i];
        }
    } else {
        for ( int i = 0; i < N; i++ ) {
            transformedList[N + i] = firstHalf[i] - secondHalf[i] * halfList[i];
        }
    }
}

void threadedFFT::partialTransform( int N, bool firstHalf ) {
    if ( firstHalf ) {
        fft transform( N, true, theList );
        this->firstHalf = transform.ditfft2( this->firstHalf, N );
    } else {
        fft transform( N, true, theList );
        this->secondHalf = transform.ditfft2( this->secondHalf, N );
    }
}

void threadedFFT::generateList( int N, bool firstHalf ) {
    if ( firstHalf ) {
        for ( int i = 0; i < N; ++i ) {
            halfList[i] = complex( 0.0, -2.0 * M_PI * (double) i / (double) N ).exp();
        }
    } else {
        for ( int i = 0; i < N; ++i ) {
            theList[i] = complex( 0.0, -2.0 * M_PI * (double) i / (double) N ).exp();
        }
    }
}

void threadedFFT::run( vector<complex> &list ) {
    int totalLength = list.size();
    int halfLength = totalLength >> 1;
    for ( int i = 0; i < halfLength; i++ ) {
        firstHalf[i] = list[i << 1];
        secondHalf[i] = list[( i << 1 ) | 1];
    }
    std::thread thread1( [=] { generateList( totalLength, true ); } );
    std::thread thread2( [=] { generateList( halfLength, false ); } );
    thread1.join();
    thread2.join();

    thread1 = thread( [=] { partialTransform( halfLength, true ); } );
    thread2 = thread( [=] { partialTransform( halfLength, false ); } );
    thread1.join();
    thread2.join();

    thread1 = thread( [=] { merge( halfLength, true ); } );
    thread2 = thread( [=] { merge( halfLength, false ); } );
    thread1.join();
    thread2.join();
}
