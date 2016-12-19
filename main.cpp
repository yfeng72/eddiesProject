#include <iostream>
#include "complex.h"

int main() {
    complex a( 1.0, 1.0 );
    complex b( 2.0, 3.0 );
    std::cout << a.toString() << std::endl;
    std::cout << ( a + b ).toString() << std::endl;
    std::cout << a.exp().toString() << std::endl;
    return 0;
}