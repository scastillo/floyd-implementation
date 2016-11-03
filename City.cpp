/**
 * City.cpp
 * Implements City class
 *
 * PRIVATE STUFF:
 *   Matrix* distances
 *   string* corners
 *   int* ambulances
 */

#include <iostream> //@TODO: Quitar .Solo para pruebas
#include <fstream>
#include <stdexcept>
#include "Matrix.cpp"
#include "City.h"

//@TODO: quitar??
using namespace std;

City::City(unsigned int _numCorners, unsigned int _numAmbulances){
    numCorners = _numCorners;
    numAmbulances = _numAmbulances;
    distances = new Matrix(numCorners);
    corners = new string[numCorners];
    ambulances = new int[numAmbulances];
    
    for(int i = 0; i < numCorners; i++)
        corners[i] = "";
        
    for(int i = 0; i < numAmbulances; i++)
        ambulances[i] = numCorners+1;
}

City::~City(){
    delete distances;
    delete [] corners;
    delete [] ambulances;
}

unsigned int City::getDistance(string cName1, string cName2) const{
    return distances->getItem(getIndex(cName1), getIndex(cName2));
}

unsigned int City::getDistance(unsigned int cIndex1, unsigned int cIndex2) const{
    return distances->getItem(cIndex1, cIndex2 );
}

/**
 * @return: numCorners - The city number of corners
 */
unsigned int City::getNumCorners()const{
    return numCorners;
}

void City::setDistance(string cName1, string cName2, unsigned int distance){
    //cout << "set distance: " << cName1 << " " << cName2 << " " << distance << endl;
    distances->setItem(getIndex(cName1),getIndex(cName2),distance);
}

void City::setDistance(unsigned int cIndex1, unsigned int cIndex2, unsigned int distance){
    //cout << "setDistance: " << cIndex1 << " " << cIndex2 << " " << distance << endl;
    distances->setItem(cIndex1,cIndex2,distance);
}

/**
 * Puts an ambulance in a corner
 * @param: cIndex - Corner index
 *         aIndex - Ambulance index
 */
void City::setAmbulance(unsigned int cIndex, unsigned int aIndex){
    ambulances[aIndex] = cIndex;
}

void City::setCorners(string cName, unsigned int index){
    corners[index] = cName;  
}

/**
 * Distribute ambulances in the city
 * @param: numAmbulances
 */
void City::distributeAmbulances(){

    unsigned int solution = 0;
    unsigned int contAmbulances = 0;

    for(unsigned int k = 0; k < numAmbulances; k++){
        for(unsigned int p = 1; p < numCorners; p++){
            if(corners[p] != ""){
                if(miuD(p) > miuD(solution)){
                    solution = p;
                }
            }
        }
        corners[solution] = "";
        ambulances[contAmbulances]  = solution;
        contAmbulances++;
    }
}

unsigned int City::miuD(unsigned int p){
    
    unsigned int b = numCorners;
    unsigned int solution = 0;
    unsigned int newSolution = 0;
    
    for(unsigned int a = 0; a < numCorners/2; a++){
        newSolution = distances->getItem(a,p) - distances->getItem(b,p);
        if(newSolution > solution){
            solution = newSolution; 
        }
        b--;
    }

    return solution;
        
}

void City::printCorners(int beg, int end) const{
    if(beg >= 0 && end < numCorners && end >= beg ){
        for(int i = beg; i <= end; i++)
            cout << corners[i] << endl;
    }else{
        cerr << "1MP0SIBL3 TO PriN7 C0rn3rs 0ut0fBound5" << endl
             << "begin: " << beg << " - end: " << end << endl;
    }
}

void City::printAmbulances() const{
    cout << "Ambulances: " << endl;
    for(int i = 0; i < numAmbulances; i++){ 
        cout << ambulances[i] << " ";
    }

}


/**
 * @param: cName - The corner name
 * @return: i - The index assoc. with the corner name
 */
unsigned int City::getIndex(string cName) const{
    //cout << "City::getIndex" << endl;
    for(int i = 0; i < distances->getNumCols(); i++){
        if(corners[i] == cName){
            //cout << "<<voy a retornar el i: " << i << endl;
            return i;
        }
    }
    throw domain_error("Th4t corn3r is N0T in th3 c1ty!");
}

           


