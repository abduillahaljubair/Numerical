#include<bits/stdc++.h>
using namespace std;

const double PI = 3.1416;
const double V = 800.0;
const double R = 10.0;
double f(double h)
{
    return (PI * h * h * (3 * R - h) / 3.0) - V;
}
int main()
{
    double x0=1,x1=18;
    double x2;
    double error;
    int itr=0;
    do{
        itr++;
        x2=(x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
        error=fabs((x2-x1)/x2);
        cout<<"iteration= "<<itr<<"root = "<<setprecision(10)<<x2<<"x1= "<<setprecision(10)<<x1<<"error = "<<setprecision(10)<<error<<endl;
        x0=x1;
        x1=x2;


}