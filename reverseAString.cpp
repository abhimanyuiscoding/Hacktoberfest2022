/*

Problem Link : https://leetcode.com/problems/reverse-string/

*/

#include<iostream> 
using namespace std;

int getLength(char name[]) {
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }

    return count;
}

void reverse(char name[], int n) {
    int s=0;
    int e = n-1;

    while(s<e) {
        swap(name[s++], name[e--]);
    }
}

int main( ) {

    char name[20];

    cout << "Enter your name " << endl;
    cin >> name;

    cout << "Your name is ";
    cout << name << endl;
    int len = getLength(name);
    reverse(name, len);
    cout << "Reverse name is ";
    cout << name << endl;
}