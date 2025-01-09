#include "matrix.h"


namespace MatrixNamespace {


Matrix::Matrix(float rows, float cols, float initialValue) : rows(rows), cols(cols) {
    data.resize(rows, std::vector<float>(cols, initialValue)); //
}

Matrix::Matrix(const std::vector<std::vector<float>>& data) : data(data), rows(data.size()), cols(data[0].size()) {}

float Matrix::get(float row, float col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[row][col];
}

void Matrix::set(float row, float col, float value) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    data[row][col] = value;
}


float Matrix::getRows() const {
    return rows;
}

float Matrix::getCols() const {
    return cols;
}


Matrix Matrix::inverse() const {
 
  

    if(rows==3 && cols==3){

        float det= determinant();
    
    if (det == 0) {
        throw std::invalid_argument("Matrix is not invertible");
    }



    float a = data[0][0], b = data[0][1], c = data[0][2];
    float d = data[1][0], e = data[1][1], f = data[1][2];
    float g = data[2][0], h = data[2][1], i = data[2][2];

    float invDet = 1.0 / det; 
    Matrix inv(3, 3);
    inv.set(0, 0, (e*i - f*h) * invDet); 
    inv.set(0, 1, (c*h - b*i) * invDet);
    inv.set(0, 2, (b*f - c*e) * invDet);
    inv.set(1, 0, (f*g - d*i) * invDet);
    inv.set(1, 1, (a*i - c*g) * invDet);
    inv.set(1, 2, (c*d - a*f) * invDet);
    inv.set(2, 0, (d*h - e*g) * invDet);
    inv.set(2, 1, (b*g - a*h) * invDet);
    inv.set(2, 2, (a*e - b*d) * invDet);

    return inv;
} 


else if(rows==2&& cols==2){
    float det=determinant();
    if (det == 0) {
        throw std::invalid_argument("Matrix is not invertible");
    }


float a = data[0][0], b = data[0][1];
    float c = data[1][0], d = data[1][1];

float invDet = 1.0 / det;
    Matrix inv(2, 2);
    inv.set(0, 0, d * invDet);      
    inv.set(0, 1, -b * invDet);     
    inv.set(1, 0, -c * invDet);     
    inv.set(1, 1, a * invDet);      

    return inv;

}


else  if(rows==1 && cols==1){

    float det=determinant();

    float invDet = 1.0 / det;

    Matrix inv(1, 1);
    inv.set(0, 0, invDet);
    return inv;
}

else{
    throw std::invalid_argument("Inverse is only defined for square matrices");}
}


float Matrix::trace() const {
    float trace = 0;
    for (int i = 0; i < std::min(rows, cols); i++) {
        trace += data[i][i];
    }
    return trace;
}

float Matrix::determinant() const { 
  if(rows==3 && cols==3){

float a = data[0][0], b = data[0][1], c = data[0][2];
    float d = data[1][0], e = data[1][1], f = data[1][2];
    float g = data[2][0], h = data[2][1], i = data[2][2];

    return a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g) ;
    

}

else if(rows==2 && cols==2){

float a = data[0][0], b = data[0][1];
    float c = data[1][0], d = data[1][1];
return a*d - b*c;
   
}

else if(rows==1 && cols==1){


    return  data[0][0];
}
else{
    throw std::invalid_argument("Determinant is only defined for square matrices");

}


}

Matrix Matrix::transpose() const {
    Matrix transposed(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; j++) {
            transposed.set(j, i, data[i][j]);
        }
    }
    return transposed;
}

Matrix Matrix::add(const Matrix& other) const {
    if (rows != other.getRows() || cols != other.getCols()) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.set(i, j, data[i][j] + other.get(i, j));
        }
    }
    return result;
}

Matrix Matrix::subtract(const Matrix& other) const {
    if (rows != other.getRows() || cols != other.getCols()) {
        throw std::invalid_argument("Matrix dimensions must match for subtraction");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.set(i, j, data[i][j] - other.get(i, j));
        }
    }
    return result;
}

Matrix Matrix::neg() const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.set(i, j, -data[i][j]);
        }
    }
    return result;
}

Matrix Matrix::multiply(const Matrix& other) const {
    if (cols != other.getRows()) {
        throw std::invalid_argument("Matrix multiplication requires matching dimensions");
    }

    Matrix result(rows, other.getCols());
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.getCols(); j++) {
            int sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += data[i][k] * other.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

float Matrix::dot(const Matrix& other) const {
    if (rows != 1 || other.getRows() != 1 || cols != other.getCols()) {
        throw std::invalid_argument("Dot product is only defined for 1xN matrices");
    }

    float result = 0;
    for (int i = 0; i < cols; i++) {
        result += data[0][i] * other.get(0, i);
    }
    return result;
}

float Matrix::magnitude() const {
   float sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += data[i][j] * data[i][j];
        }
    }
    return std::sqrt(sum);
}


Matrix Matrix::zeroes(float rows, float cols) {
    return Matrix(rows, cols, 0);
}

Matrix Matrix::ones(float rows, float cols) {
    return Matrix(rows, cols, 1);
}

Matrix Matrix::identity(float size) {
    Matrix identity(size, size);
    for (int i = 0; i < size; i++) {
        identity.set(i, i, 1);
    }
    return identity;
}


void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    return add(other);
}

Matrix Matrix::operator-(const Matrix& other) const {
    return subtract(other);
}

} 
