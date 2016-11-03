#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "City.h"
#include "City.cpp"

void   floyd (City &c)throw(domain_error);

int main(int argsc, char *argsv[]){
  try{
        ifstream fCorners("nodos.txt", ios::in);
        ifstream fStreets("arcos.txt", ios::in);
        //ifstream fAmbulances("ambulances.txt", ios::in);
        
        if(!fCorners || !fStreets){
          cerr << "3rr0r L04diNg Fil35 !!";
          exit(1);
        }
        
        unsigned int numCorners = 0;
        fCorners >> numCorners;
        unsigned int numAmbulances = 50;// LEER DESDE ARCHIVO
        
        City city(numCorners,numAmbulances);
   
        string corner = "";
        
        for(unsigned int i = 0; fCorners >> corner; i++){
          city.setCorners(corner,i);
        }
        city.printCorners(numCorners-11,numCorners-1);
        cout << "NumCorners: " << numCorners << endl;
        city.printCorners(0,10);

        string cName1 = "", cName2 = "";
        string trash = "";
        unsigned int distance = 0;
        
        unsigned int numStreets = 0;
        fStreets >> numStreets;
        cout << "numStreets: " << numStreets << endl;
                
        for(int i = 0; i < numStreets; i++){           
            fStreets >> cName1 >> cName2 >> distance >> trash >> trash;
            city.setDistance(cName1, cName2, distance);
           
        }
        /*cout << "distancia entre el uno y el otro:(66)" << city.getDistance("10002","9896") << endl
             << "distancia entre el uno y el otro:(INF)" << city.getDistance("7520","7487") << endl
             << "distancia entre el uno y el otro:(80)" << city.getDistance("9994","9964") << endl
             << "distancia entre el uno y el otro:(inf)" << city.getDistance("9994","10002") << endl;*/
        floyd(city);
        city.distributeAmbulances();
        city.printAmbulances();
        cout << "\ntermine HP!!!" << endl/*
             << "distancia entre el uno y el otro:(26)" << city.getDistance("7520","7560") << endl
             << "distancia entre el uno y el otro:(INF)" << city.getDistance("7520","7487") << endl
             << "distancia entre el uno y el otro:(80)" << city.getDistance("9994","9964") << endl
             << "distancia entre el uno y el otro:(inf)" << city.getDistance("9994","10002") << endl*/;
             
        
                      
  }catch(domain_error& e) {
      cerr << e.what() << endl;
  }
  return 0;
}


void floyd(City &c)throw(domain_error){

    unsigned int numCorners = c.getNumCorners();
    int newPathLength = 0;
    
    for (unsigned int k = 0; k < numCorners; k++){
        for (unsigned int i = 0; i < numCorners; i++){
            for (unsigned int j = 0; j < numCorners; j++){
                newPathLength = c.getDistance(i,k) + c.getDistance(k,j); 
                if(newPathLength < c.getDistance(i,j))
                    c.setDistance(i,j,newPathLength);
            }
        }
    }
    };

/*string split(string str,string token){
    
    string sln[3] = {"","",""};
    string trash = "";
    int last = str.find("(");

    int lo = 0;
    int hi = str.find_first_of(token);
    sln[0] = str.substr(lo,hi);
    trash  = str.substr(hi+1,last);

    lo     = hi;
    hi     = trash.find_first_of(token);
    sln[1] = str.substr(lo+1,hi-(lo+1));
    trash  = str.substr(hi+1,last);

    sln[2] = str.substr(hi+1,last-1);

    return *sln;
    }*/
