
#include "Calculator.hpp"
#include <iostream>
#include<cmath>
using namespace std;


Calculator::Calculator() {
    
}

double Calculator::multiply(int numCount) {
    double product=1, num;
    for(int i = 1; i <= numCount; i++) {
        cout << "Enter number " << i << ": ";
        cin >> num;
        product *= num;
    }
    return product;
}

double Calculator::add(int numCount) {
    double sum = 0, num;
    for (int i = 1; i <= numCount; i++) {
        cout << "Enter number " << i << ": ";
        cin >> num;
        sum += num;
    }
    return sum;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::divide(double c, double d){

     if (d == 0) {
        cout << "Error: Division by zero is not allowed!" << endl;
        return NAN;  
    }

    return c/d;
}
 
double Calculator::square(double e){
return e*e;

}

double Calculator::exponentiation(double f, double g){
 return static_cast<double>(pow(f, g));
}

int Calculator::mod(int h,int j){

return h % j;

}