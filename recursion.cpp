#include<bits/stdc++.h>
using namespace std;

void printDecreasing(int n) {
    if(n == 0) {
        return;
    }
    cout << n << " ";
    printDecreasing(n-1);
}

void printIncreasing(int n) {
    if(n == 0) {
        return;
    }
    printIncreasing(n-1);
    cout << n << " ";
}

void printDecreasingIncreasing(int n) {
    if(n == 0) {
        return;
    }
    cout << n << " ";
    printDecreasingIncreasing(n-1);
    cout << n << " ";
}

void factorial(int n, int &ans) {
    if(n == 0) {
        return;
    }
    factorial(n-1, ans);
    ans =  n * ans;
}

int powerLinear(int n, int x) {
    if(n == 0) {
        return 1;
    }
    return x * powerLinear(n-1, x);
}

int powerLinearLog(int n, int x) {
    if(n == 0) {
        return 1;
    }
    int y = powerLinearLog(n/2,x);
    if(n %2 == 0) {
        return y * y;
    }
    else {
        return y * y * x;
    }
}

int main() {
    // printDecreasing(5);
    cout << powerLinear(3, 2);
}


