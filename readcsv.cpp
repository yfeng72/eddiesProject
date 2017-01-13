//
// Created by sheny on 2017/1/2.
//

#include "readcsv.h"

readcsv::readcsv( string csvname ) {
    string line;
    ifstream myfile(csvname);
    stringstream iss; //the stringstream to parse the line for commas
    string value; //individual values
    int i=0;
    if(myfile.is_open()){
        while(getline(myfile, line)){
            /*while(getline(myfile,line,',')){
                //cout << line << endl;
                if (i % 2 == 0) {
                    int value=atoi(line.c_str());
                    newcomplex->re = value;
                } else {
                    int value=atoi(line.c_str());
                    newcomplex->im = value;
                }
                i++;
                if ( i == 2 ) {
                    allcomplex.push_back( *newcomplex );
                    i = 0;
                    complex *newcomplex = new complex;
                }
                */
            complex *newcomplex=new complex;
            iss << line;
            while(getline(iss, value, ',')){//parse for commas
                if(i==0){
                    int number = atoi(value.c_str());
                    //cout << number << endl;
                    newcomplex->re = number;
                }
                else{
                    int number = atoi(value.c_str());
                    //cout << number << endl;
                    newcomplex->im = number;
                }
                i++;
                if(i==2){
                    i=0;
                }
            }
            iss.clear();
            allcomplex.push_back(*newcomplex);
        }
        myfile.close();
    } else {
        cout << "Unable to open the file" << endl;
    }

}