#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>

namespace MatrixNamespace {

class Matrix {
private:
    std::vector<std::vector<float>> data;
    float rows;
    float cols;

public:
    
    Matrix(float rows, float cols, float initialValue = 0); 
    Matrix(const std::vector<std::vector<float>>& data); 

    
    float get(float row, float col) const;
    void set(float row, float col, float value);

    
   float getRows() const;
   float getCols() const;

    
    Matrix inverse() const;
    float trace() const;
    float determinant() const;
    Matrix transpose() const;
    Matrix add(const Matrix& other) const;
    Matrix subtract(const Matrix& other) const;
    Matrix neg() const;
    Matrix multiply(const Matrix& other) const;
    float dot(const Matrix& other) const;
    float magnitude() const;

   
    static Matrix zeroes(float rows, float cols);
    static Matrix ones(float rows,float cols);
    static Matrix identity(float size);

    
        void print() const;  






    
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix& operator=(const Matrix& other);
};

} 

#endif 
