#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<fstream>
using namespace std;
double f1(double x, double y1, double y2, double y3)
{
    double a = y2;
    return a;
}
double f2(double x, double y1, double y2, double y3)
{
  double a = y3;
  return a;
}
double f3(double x, double y1, double y2, double y3)
{
  double a = -0.5*y1*y3;
  return a;
}


int main()
{
    ofstream outdata;
    outdata.open("values.dat");
    if(!outdata)
    {
      cerr<<"Error : File not found"<<endl;
      exit(1);
    }
    int n;
    double x0,y0[3],x,y[3],k1[4],k2[4],k3[4],h;
    cout.precision(5);
    cout.setf(ios::fixed);
    cout<<"\nEnter the initial values of x, y, y' and y'' respectively:\n";
    cin>>x0>>y0[0]>>y0[1]>>y0[2];
    cout<<"\nFor what value of x do you want to find the value of y\n";
    cin>>x;
    cout<<"\nEnter the width of the sub-interval:\n";
    cin>>h;
    // cout<<setw(4)<<"x"<<setw(15)<<"y"<<setw(19)<<"dy/dx"<<setw(18)<<"y_new_1"<<setw(17)<<"y_new_2\n";
    cout<<setw(3)<<"x"<<setw(12)<<"y1"<<setw(12)<<"y2"<<setw(12)<<"y3"<<setw(15)<<"y1_new"<<setw(15)<<"y2_new"<<setw(13)<<"y3_new"<<endl;
    cout<<"---------------------------------------------------------------------------------------\n";
    while(fabs(x-x0)>0.0000001)
    {

        k1[0] = h*f1(x0,y0[0],y0[1],y0[2]);
        k2[0] = h*f2(x0,y0[0],y0[1],y0[2]);
        k3[0] = h*f3(x0,y0[0],y0[1],y0[2]);
        k1[1] = h*f1(x0+0.5*h,y0[0]+0.5*k1[0],y0[1]+0.5*k2[0],y0[2]+0.5*k3[0]);
        k2[1] = h*f2(x0+0.5*h,y0[0]+0.5*k1[0],y0[1]+0.5*k2[0],y0[2]+0.5*k3[0]);
        k3[1] = h*f3(x0+0.5*h,y0[0]+0.5*k1[0],y0[1]+0.5*k2[0],y0[2]+0.5*k3[0]);
        k1[2] = h*f1(x0+0.5*h,y0[0]+0.5*k1[1],y0[1]+0.5*k2[1],y0[2]+0.5*k3[1]);
        k2[2] = h*f2(x0+0.5*h,y0[0]+0.5*k1[1],y0[1]+0.5*k2[1],y0[2]+0.5*k3[1]);
        k3[2] = h*f3(x0+0.5*h,y0[0]+0.5*k1[1],y0[1]+0.5*k2[1],y0[2]+0.5*k3[1]);
        k1[3] = h*f1(x0+h,y0[0]+k1[2],y0[1]+k2[2],y0[2]+k3[2]);
        k2[3] = h*f2(x0+h,y0[0]+k1[2],y0[1]+k2[2],y0[2]+k3[2]);
        k3[3] = h*f3(x0+h,y0[0]+k1[2],y0[1]+k2[2],y0[2]+k3[2]);

        y[0] = y0[0]+(1.0/6)*(k1[0]+2*k1[1]+2*k1[2]+k1[3]);
        y[1] = y0[1]+(1.0/6)*(k2[0]+2*k2[1]+2*k2[2]+k2[3]);
        y[2] = y0[2]+(1.0/6)*(k3[0]+2*k3[1]+2*k3[2]+k3[3]);

        cout<<x0<<setw(11)<<y0[0]<<setw(11)<<y0[1]<<setw(13)<<y0[2]<<setw(13)<<y[0]<<setw(14)<<y[1]<<setw(14)<<y[2]<<endl;
        outdata<<x0<<","<<y[0]<<","<<y[1]<<","<<y[2]<<endl;
        y0[0]=y[0];
        y0[1]=y[1];
        y0[2]=y[2];
        x0=x0+h;
    }
    cout<<"The approximate value of y at x = "<<x<<" is "<<y[0]<<endl;
    outdata.close();
    return 0;
}
