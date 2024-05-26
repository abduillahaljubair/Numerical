#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double V = 800.0;
const double R = 10.0;
const double PI = 3.141592653589793;
const double tolerance = 1e-6;

// Function f(h)
double f(double h) {
    return (PI * h * h * (3 * R - h) / 3.0) - V;
}

// Fixed Point function g(h)
double g(double h) {
    return sqrt((3 * V) / (PI * (3 * R - h)));
}


int main() {
    double x0=16.0,x1,error;
    int itr=0;
   
   do{
    x1=g(x0);
   error=fabs((x1-x0)/x1);
    itr++;
    cout<<"iteration=  "<<itr<<"  g(x)= "<<g(x1)<<" root= "<<x1<<endl;
    x0=x1;
   }while(error>0.000001);
       cout<<"iteration=  "<<" root= "<<x1<<endl;
}
