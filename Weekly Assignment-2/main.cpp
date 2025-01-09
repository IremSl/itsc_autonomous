#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main(){

/* there are no such types as short float, long long float,
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
cout<<"pointer int-->"<<sizeof(pointerInt)<<endl;

short int b=10;
short int *pointerShortInt= &b;
cout<<"pointer short int-->"<<sizeof(pointerShortInt)<<endl;

long long int c=10;
long long int *pointerlonglongInt = &c;
cout<<"pointer long long int-->"<<sizeof(pointerlonglongInt)<<endl;

unsigned int d=10;
unsigned int *pointerunsignedInt= &d;
cout<<"pointer unsigned int-->"<<sizeof(pointerunsignedInt) <<endl;

float e=10;
float *pointerFloat= &e;
cout<<"pointer float-->"<<sizeof(pointerFloat)<<endl;

double f=10;
double *pointerDouble=&f;
cout<<"pointer double-->"<<sizeof(pointerDouble)<<endl;

long double g=10;
long double *pointerlongDouble= &g;
cout<<"pointer long double-->"<< sizeof(pointerlongDouble)<<endl<<endl;




cout<<"Lower limit of int: "
    << numeric_limits<int>::min()<<endl;
    cout<<"Upper limit of int: "
    << numeric_limits<int>::max()<<endl;
    cout<<"Lower limit of short int: "
    << numeric_limits<short int>::min()<<endl;
    cout<<"Upper limit of int: "
    << numeric_limits<short int>::max()<<endl;
    cout<<"Lower limit of long long int: "
    << numeric_limits<long long int>::min()<<endl;
    cout<<"Upper limit of int: "
    << numeric_limits<long long int>::max()<<endl;
    cout<<"Lower limit of unsigned int: "
    << numeric_limits<unsigned int>::min()<<endl;
    cout<<"Upper limit of int: "
    << numeric_limits<unsigned int>::max()<<endl;
    cout<<"Lower limit of float: "
    << numeric_limits<float>::min()<<endl;
    cout<<"Upper limit of float: "
    << numeric_limits<float>::max()<<endl;
    cout<<"Lower limit of double: "
    << numeric_limits<double>::min()<<endl;
    cout<<"Upper limit of double: "
    << numeric_limits<double>::max()<<endl;
    cout<<"Lower limit of long double: "
    << numeric_limits<long double>::min()<<endl;
    cout<<"Upper limit of long double: "
    << numeric_limits<long double>::max()<<endl;
}