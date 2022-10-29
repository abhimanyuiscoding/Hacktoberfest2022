#include<type_traits>
#include<iostream>
#include<array>
#include<string>
using namespace std;
int main(){
   cout<<"Checking if int is an array ? : ";
   is_array<int>::value?cout<<"True":cout<<"False";
   cout<<"
Checking if int[] is an array? : ";
   is_array<int[6]>::value?cout<<"True":cout<<"False";
   cout<<"
Checking if 2D Array is an array? : ";
   is_array<int[2][3]>::value?cout<<"True":cout<<"False";
   cout<<"
Checking if String is an array? : ";
   is_array<string>::value?cout<<"True":cout<<"False";
   cout<<"
Checking if Character Array is an array? : ";
   is_array<char[4]>::value?cout<<"True":cout<<"False";
   cout << endl;
   return 0;
}
