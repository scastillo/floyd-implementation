/**
 * City.h
 * Interface of City class
 */

#ifndef CITY_H
#define CITY_H

#include <string>
#include "Matrix.h"

using namespace std;

class City{

 public:

    City  (unsigned int _numCorners, unsigned int _numAmbulances);
    ~City ();

    
    inline unsigned int getDistance     (unsigned int cIndex1, unsigned int cIndex2) const;
    inline unsigned int getNumCorners   ()const;  
    inline void         setDistance     (unsigned int cIndex1,unsigned int cIndex2,unsigned int distance);
    inline void         setCorners      (string cName, unsigned int index);  
    unsigned int        getDistance     (string cName1, string cName2) const;
    void                setDistance     (string cName1, string cName2, unsigned int distance);
    void                setAmbulance    (unsigned int cIndex, unsigned int aIndex); 
    void                printCorners    (int beg, int end)const;
    void                printAmbulances ()const;
    
    void         distributeAmbulances ();
    unsigned int miuD                 (unsigned int p);
    
 private:

    Matrix*      distances;
    string*      corners;
    int*         ambulances;
    unsigned int numCorners;
    unsigned int numAmbulances;

    
    unsigned int getIndex(string cName) const; // Helpful Member
};

#endif
