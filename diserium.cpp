#include<bits/stdc++.h>

using namespace std;

bool isDiserium(int n){
    int count = 0;
    int num = 0;
    for(int i=n;i>0;i/=10) count++;
    for(int i=n;i>0;i/=10){
        num += pow((i%10),count);
        count--;
    }
    if(num==n) return true;
    else return false;
}
int main(){
    int n;
    cout << "Enter a Number to check Diserium ->> ";
    cin >> n;
    if(isDiserium(n)){
        cout << n << " is Diserium.\n";
    }
    else{
        cout << n << " is not Diserium.\n";
    }
}