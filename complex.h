//
// Created by fengy on 12/18/2016.
//

#ifndef EDDIESPROJECT_COMPLEX_H
#define EDDIESPROJECT_COMPLEX_H

#include <iostream>

using namespace std;

class complex {

public:
    double re;
    double im;

    complex();

    complex( double re, double im );

    complex operator+( const complex &a );

    complex operator-( const complex &a );

    complex operator*( const complex &a );

    complex operator/( const complex &a );

    complex exp();

    complex conj();

    const string toString();

};


#endif //EDDIESPROJECT_COMPLEX_H
