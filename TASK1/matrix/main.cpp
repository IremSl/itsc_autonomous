#include <iostream>
#include "matrix.h"

using namespace std;
using namespace MatrixNamespace;

int main() {
    
    Matrix m1(3, 3);
    m1.print();
    cout << endl;
    std::cout << "m1 printed "<< std::endl;

    
    vector<vector<float>> mat_data = {{1, 2, 3}, {5, 5, 6}, {4, 8, 9}};
    Matrix m2(mat_data);
    m2.print();
    
    cout << endl;
    cout << "m2 printed "<< endl;

    
    Matrix m3 = m2.transpose();
    m3.print();
    cout << "Trace: " << m2.trace() << endl;
    cout << "Determinant: " << m2.determinant() << endl;
    cout << "m3 printed "<< endl;

    
    Matrix m4 = m2.add(m1);
    m4.print();
    cout << endl;
    cout << "m4 printed "<< endl;

    
    Matrix m5 = m2.neg();
    m5.print();
    cout << endl;
    cout << "m5 printed "<<endl;

    
    Matrix m6 = m2.multiply(m1);
    m6.print();
    cout << endl;
    cout<< "m6 printed "<<endl;

    Matrix m7 = m2.subtract(m1);
    m7.print();
    cout << endl;
    cout<< "m7 printed "<< endl;

     try {
        Matrix m8 = m2.inverse();
        cout << "Inverse of m2 (m8):" << endl;
        m8.print();  
        cout << endl;
        cout << "m8 printed "<< endl;
    } catch (const std::invalid_argument& e) {
        cout << "Error calculating inverse: " << e.what() << endl;
    }



    Matrix m9 = m2.ones(3, 3);  
    m9.print();
    cout << endl;
    cout<< "m9 printed "<<endl;

    Matrix m10 = m2.zeroes(3, 3);
    m10.print();
    cout << endl;
    cout<< "m10 printed "<<endl;

    Matrix m11 = m2.identity(3);
    m11.print();
    cout << endl;
    cout<< "m11 printed "<<endl;

    cout << "Dot product: " << m2.dot(m1) << endl;
    cout << "Magnitude: " << m2.magnitude() << endl;

   


    return 0;
}

