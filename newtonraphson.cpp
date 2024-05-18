#include<bits/stdc++.h>
using namespace std;
double f(double x0) {
    return pow(x0, 3)-x0-1.0;
}

double f_prime(double x0) {
    return 3*pow(x0,2)-1.0;
}

int main()
{
   double x0=1.5,x1;
    double error;
    int itr=0;

    do{
       x1 = x0 - (f(x0) / f_prime(x0));
        error = fabs((x1 - x0) / x1);
        x0=x1;
        cout<<" iteration number="<<itr<<" new root= "<<setprecision(10)<<x0<<" error= "<<error<<endl;
        itr++;
    }while(error >0.001);

    
  cout << "Root = " << setprecision(10) << x0 << endl;
  cout << "Itaration number : " << itr << endl;
}