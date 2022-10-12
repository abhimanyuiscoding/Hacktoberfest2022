#include<iostream>
#include <math.h>
using namespace std;
 double sum(int k)
 {
     if(k==0)
     {
         return 1;
     }
     
     double ans;
     ans=(1/pow(2,k)) + sum(k-1);

 }
 
 int main()
 {
     int k;
     cin>>k;
     cout<<sum(k)<<endl;
     return 0;
 }