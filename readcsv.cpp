//
// Created by sheny on 2017/1/2.
//

#include "readcsv.h"

readcsv::readcsv( string csvname ) {
    string line;
    ifstream myfile( csvname );
    int i = 0;
    if ( myfile.is_open()) {
        complex *newcomplex = new complex;
        while ( getline( myfile, line )) {
            while ( getline( myfile, line, ',' )) {
                //cout << line << endl;
                if ( i % 2 == 0 ) {
                    newcomplex->re = std::stod( line );
                } else {
                    newcomplex->im = std::stod( line );
                }
                i++;
                if ( i == 2 ) {
                    allcomplex.push_back( *newcomplex );
                    i = 0;
                    complex *newcomplex = new complex;
                }
            }
        }
        myfile.close();
    } else {
        cout << "Unable to open the file" << endl;
    }

}