//
// Created by fengy on 12/18/2016.
//

#include <cmath>
#include <sstream>
#include "complex.h"

complex::complex() {
    complex( 0.0, 0.0 );
}

complex::complex( double re, double im ) {
    this->re = re;
    this->im = im;
}

complex complex::operator+( const complex &a ) {
    complex sum;
    sum.re = re + a.re;
    sum.im = im + a.im;
    return sum;
}

complex complex::operator-( const complex &a ) {
    complex diff;
    diff.re = re - a.re;
    diff.im = im - a.im;
    return diff;
}

complex complex::operator*( const complex &a ) {
    complex product;
    product.re = re * a.re - im * a.im;
    product.im = re * a.im + im * a.re;
    return product;
}

complex complex::operator/( const complex &a ) {
    complex quotient;
    quotient.re = (( re + a.re ) + ( im * a.im )) / ( a.re * a.re + a.im * a.im );
    quotient.im = (( im + a.re ) - ( re * a.im )) / ( a.re * a.re + a.im * a.im );
    return quotient;
}


complex complex::exp() {
    complex exponent;
    double coefficient = std::exp( re );
    exponent.re = coefficient * cos( im );
    exponent.im = coefficient * sin( im );
    return exponent;
}

complex complex::conj() {
    complex conj;
    conj.re = re;
    conj.im = im * -1.0;
    return conj;
}

const string complex::toString() {
    ostringstream output;
    if ( re < 0 ) {
        output << re << " - " << abs( im ) << "i";
    } else {
        output << re << " + " << im << "i";
    }
    return output.str();
}