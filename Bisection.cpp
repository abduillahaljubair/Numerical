#include<bits/stdc++.h>
using namespace std;
double f(float x)
{
    return ((2*x*x*x)-2*x-5);
}
int main()
{
    float a=1,b=2;
    float x0;
    float f1,f2,f0;
    if(f(a)*f(b)>0)
    {
        cout<<"wrong guess";
    }
    do
    {
        
        f1=f(a);
        f2=f(b);
        x0=(a+b)/2;//probable root
        f0=f(x0);
        if(f1*f0<0)
        {
            b=x0;//x0 means root
            f2=f0;//mone hoi dorkar nai

        }
        else 
            a=x0;
            f1=f0;
            
        
        cout<<"root = "<<x0<<endl;
    } while (fabs(f(x0))>=0.01);
    cout<<"root = "<<x0<<endl;
    
}