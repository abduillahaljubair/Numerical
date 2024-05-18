#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return pow(x,4)-4.0;
}
int main()
{
    double x0=1,x1=2;
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

    }while (fabs(error) != 0);

 cout<<"iteration= "<<itr<<"root = "<<setprecision(10)<<x2<<endl;

}