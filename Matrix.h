/**
 * Matrix.h
 * Interface of Matrix class
 */

#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
 public:
    
    Matrix  (unsigned int numCols);
    Matrix  (const Matrix & src);
    ~Matrix ();
    
    inline void         setItem    (unsigned int i, unsigned int j, unsigned int item);

    inline unsigned int getItem    (unsigned int i, unsigned int j)const;

    inline unsigned int getNumCols ()const;

    
 private:
    
    unsigned int numCols;
    unsigned int* matrix;

    static const unsigned int INF = 2147483647;
};
#endif // MATRIX_H
