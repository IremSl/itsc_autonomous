#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main(){

/* there are no such types as short float,
unsigned float, or unsigned double. */

cout<< setw(10)<<left<<"======================";
cout<< setw(10)<<right<<"======================"<<endl;
cout<< setw(10)<<left<<"Type";
cout<< setw(2)<<right<<" ";
cout<< setw(14)<<right<<"Size"<<endl;
cout<< setw(10)<<left<<"======================";
cout<< setw(10)<<right<<"======================"<<endl;

cout<< setw(10)<<left<<"int";
cout<< setw(2)<<right<<" ";
cout<< setw(12)<<right<<sizeof(int)<<endl;

cout<< setw(10)<<left<<"short int";
cout<< setw(2)<<right<<" ";
cout<< setw(12)<<right<<sizeof(short int)<<endl;

cout<< setw(10)<<left<<"long long int";
cout<< setw(2)<<right<<" ";
cout<< setw(9)<<right<<sizeof(long long int)<<endl;

cout<< setw(10)<<left<<"unsigned int";
cout<< setw(2)<<right<<" ";
cout<< setw(10)<<right<<sizeof(unsigned int)<<endl;

cout<< setw(10)<<left<<"float int";
cout<< setw(2)<<right<<" ";
cout<< setw(12)<<right<<sizeof(float)<<endl;

cout<< setw(10)<<left<<"double";
cout<< setw(2)<<right<<" ";
cout<< setw(12)<<right<<sizeof(double)<<endl;

cout<< setw(10)<<left<<"long double";
cout<< setw(2)<<right<<" ";
cout<< setw(12)<<right<<sizeof(long double)<<endl;

cout<< setw(10)<<left<<"======================";
cout<< setw(10)<<right<<"======================"<<endl<<endl;



int a=10;
int *pointerInt= &a;
short int b=10;
short int *pointerShortInt= &b;
long long int c=10;
long long int *pointerlonglongInt = &c;
unsigned int d=10;
unsigned int *pointerunsignedInt= &d;
float e=10;
float *pointerFloat= &e;
double f=10;
double *pointerDouble=&f;
long double g=10;
long double *pointerlongDouble= &g;

cout<< setw(30)<<left<<"===============================";
cout<< setw(30)<<right<<"==============================="<<endl;
cout<< setw(12)<<left<<"Type";
cout<< setw(15)<<right<<" ";
cout<< setw(12)<<right<<"Size"<<endl;
cout<< setw(30)<<left<<"===============================";
cout<< setw(30)<<right<<"==============================="<<endl;

cout<< setw(12)<<left<<"pointer int";
cout<< setw(15)<<right<<" ";
cout<< setw(10)<<right<<sizeof(pointerInt)<<endl;

cout<< setw(12)<<left<<"pointer short int";
cout<< setw(15)<<right<<" ";
cout<< setw(5)<<right<<sizeof(pointerShortInt)<<endl;

cout<< setw(12)<<left<<"pointer long long int";
cout<< setw(15)<<right<<" ";
cout<< setw(1)<<right<<sizeof(pointerlonglongInt)<<endl;

cout<< setw(12)<<left<<"pointer unsigned int";
cout<< setw(15)<<right<<" ";
cout<< setw(2)<<right<<sizeof(pointerunsignedInt)<<endl;

cout<< setw(12)<<left<<"pointer float int";
cout<< setw(15)<<right<<" ";
cout<< setw(5)<<right<<sizeof(pointerFloat)<<endl;

cout<< setw(12)<<left<<"pointer double";
cout<< setw(15)<<right<<" ";
cout<< setw(8)<<right<<sizeof(pointerDouble)<<endl;

cout<< setw(12)<<left<<"pointer long double";
cout<< setw(15)<<right<<" ";
cout<< setw(3)<<right<<sizeof(pointerlongDouble)<<endl;

cout<< setw(30)<<left<<"===============================";
cout<< setw(30)<<right<<"==============================="<<endl<<endl;



cout<< setw(30)<<left<<"====================================";
cout<< setw(30)<<right<<"===================================="<<endl;
cout<< setw(12)<<left<<"Type";
cout<< setw(15)<<right<<" ";
cout<< setw(12)<<right<<"Lower Limit                Upper Limit"<<endl;
cout<< setw(30)<<left<<"====================================";
cout<< setw(30)<<right<<"===================================="<<endl;

cout<< setw(12)<<left<<"int";
cout<< setw(15)<<right<<" ";
cout<< setw(10)<<right<<numeric_limits<int>::min()
<<"                "<< numeric_limits<int>::max()<<endl;

cout<< setw(12)<<left<<"short int";
cout<< setw(15)<<right<<" ";
cout<< setw(5)<<right<<numeric_limits<short int>::min()
<<"                     "<<numeric_limits<short int>::max()<<endl;

cout<< setw(12)<<left<<"long long int";
cout<< setw(14)<<right<<" ";
cout<< setw(0)<<right<<numeric_limits<long long int>::min()
<<"       "<< numeric_limits<long long int>::max()<<endl;

cout<< setw(12)<<left<<"unsigned int";
cout<< setw(15)<<right<<" ";
cout<< setw(0)<<right<<numeric_limits<unsigned int>::min()
<<"                          "<< numeric_limits<unsigned int>::max()<<endl;

cout<< setw(12)<<left<<"float int";
cout<< setw(15)<<right<<" ";
cout<< setw(5)<<right<<numeric_limits<float>::min()
<<"                "<< numeric_limits<float>::max()<<endl;

cout<< setw(12)<<left<<"double";
cout<< setw(15)<<right<<" ";
cout<< setw(8)<<right<< numeric_limits<double>::min()
<<"               "<< numeric_limits<double>::max()<<endl;

cout<< setw(12)<<left<<"long double";
cout<< setw(15)<<right<<" ";
cout<< setw(3)<<right<<numeric_limits<long double>::min()
<<"               "<<numeric_limits<long double>::max() <<endl;

cout<< setw(30)<<left<<"====================================";
cout<< setw(30)<<right<<"===================================="<<endl<<endl;

}