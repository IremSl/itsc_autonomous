
#include <iostream>
#include <string>
#include "Calculator.hpp"
#include<cmath>

using namespace std;

int main() {

    int action;
    char continueCalculation;

    do{
    cout << "What would you like to do (multiplication (1), addition (2), subtraction (3), division (4), square (5), exponentiation (6), modulus (7))? ";
    cin >> action;

    Calculator calc;

    if (action == 1) {
        int numCount;
        cout << "How many numbers do you want to multiply? ";
        cin >> numCount;
        double product = calc.multiply(numCount);
        cout << "The total product is: " << product << endl;
    }


    else if (action == 2) {
        int numCount;
        cout << "How many numbers do you want to add? ";
        cin >> numCount;
        double sum = calc.add(numCount);
        cout << "The total sum is: " << sum << endl;
    }


    else if (action == 3) {
        double a, b;
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;
        double result = calc.subtract(a, b);
        cout << "The subtraction of " << a << " - " << b << " is " << result << endl;
    }



    else if(action== 4){
        double c, d;
        cout<<"Enter first number: ";
        cin>>c;
        cout<<"Enter second number: ";
        cin>>d;
        double result = calc.divide(c, d);
        cout<<"The division of "<<c<<"/" << d<< " is "<< result<<endl;

    }



    else if(action== 5){
       double e;
       cout<<"Enter the number: ";
       cin>>e;
       double result= calc.square(e);
       cout<<"The square of "<<e<<" is "<< result<<endl;

    }


    else if(action== 6){
       double f, g;
       cout<<"Enter the base";
       cin>>f;
       cout<<"Enter the exponent";
       cin>>g;
       double result= calc.exponentiation(f, g);
       cout << f << " raised to the power of " << g << " is " << result << endl;


    }


    else if(action== 7 ){
       int h, j;
       cout << "Enter the first number: ";
       cin >> h;
       cout << "Enter the second number: ";
       cin >> j;
       int remainder=calc.mod(h,j);
       cout << "The remainder when " << h << " is divided by " << j << " is: " << remainder << endl;

}


    else {
       cout << "Invalid action!" << endl;
    }



       cout << "Would you like to perform another calculation? (y/n): ";
        cin >> continueCalculation;

    }



    while(continueCalculation=='y'||continueCalculation=='Y');


       cout<<"Have a nice day!";
    

    return 0;
}
