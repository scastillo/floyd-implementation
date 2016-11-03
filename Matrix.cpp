/**
 * Matrix.cpp
 * Implements Matrix Class
 *
 * PRIVATE STUFF:
 *   unsigned int numCols
 *   unsigned int* matrix
 **/

#include <iostream>
#include <stdexcept>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(unsigned int _numCols){
        
    if(_numCols <= 0)
        throw domain_error("Matrix: the number of columns value is invalid");
    
    numCols = (_numCols*(_numCols + 1))/2;
    matrix = new unsigned int[numCols];

    for(int i = 0; i < numCols; i++)
        matrix[i] = INF;
}


Matrix::Matrix(const Matrix & src)
    :numCols(src.getNumCols()){
    matrix = new unsigned int[numCols];
    
    for(int i = 0; i < numCols; i++){
        matrix[i] = src.matrix[i];
    }
}

Matrix::~Matrix(){
    delete [] matrix;
}

unsigned int Matrix::getItem(unsigned int i, unsigned int j)const{
    
    if (i < 0 || i > numCols)
        throw domain_error("getItem: the i value is invalid");
    
    if(j < 0 || j > numCols)
        throw domain_error("getItem: the j value is invalid");
    
    if(i < j){
        int aux = i;
        i = j;
        j = aux;
    }

    if(i == j)
        return 0;

    return matrix[ ((i * (i - 1)) / 2) + j ];
}

void Matrix::setItem(unsigned int i, unsigned int j, unsigned int item){

    if (i < 0 || i > numCols)
        throw domain_error("setItem: the i value is invalid");

    if(j < 0 || j > numCols)
        throw domain_error("setItem: the j value is invalid");

    if(item < 0)
        throw domain_error("setItem: the item value is invalid");
    
    if(i < j){
        // cout << "setItem::Matrix --> entre al if: i < j" << endl;
        int aux = i;
        i = j;
        j = aux;
    }

    if(i == j){
        // cout << "setItem::Matrix --> entre al if: i == j" << endl;
        return;
    }

    matrix[ ((i * (i - 1)) / 2) + j ] = item;
    /*cout << "i: " << i << "j: " << j << endl
         << "setItem::Matrix --> " << "matrix[" << ((i * (i - 1)) / 2) + j << "]: "
         << matrix[ ((i * (i - 1)) / 2) + j ] << " = " << item << endl;
    */
         
}

unsigned int Matrix::getNumCols() const{
    return numCols;
}


/*
int main(int argsc, char* agrsv[]){
    Matrix m(8);
    m.setItem(0,0,2);
    m.setItem(4,6,67);
    m.setItem(3,2,3);
    cout << "item(0,0): " <<m.getItem(0,0) << endl
         << "item(4,6): " <<m.getItem(4,6) << endl
         << "item(3,2): " <<m.getItem(3,2) << endl;
    return 0;
    }*/
