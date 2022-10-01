/*

Problem Link : https://leetcode.com/problems/valid-palindrome/

*/

#include<iostream>
using namespace std;

bool isValid(char ch) {
    if ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
        return true;
    else
        return false;
}

char toLower(char ch) {
    if ((ch>='a' && ch<='z') || (ch>='0' && ch<='9')) {
        return ch;
    }
    else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(string s) {
    int start = 0;
    int end = s.length()-1;
    
    while(start < end) {
        if(s[start] != s[end]) 
            return false;
        else {
            start++;
            end--;
        }        
    } 
    return true;
}

bool isPalindrome(string s) {
        // Removing all non-alphanumeric characters
        string temp = "";
        for(int i = 0; i < s.length(); i++) {
            if(isValid(s[i])) {
                temp.push_back(s[i]);
            }
        }
        
        // Convert to lowercase
        for(int i = 0; i< temp.length(); i++) {
            temp[i] = toLower(temp[i]);
        }
        
        // Checking for palindrome
        return checkPalindrome(temp);
}

int main() {
    string s;
    getline(cin, s);     // For inputing a string with spaces, use getline 
    if(isPalindrome(s))
        cout << "It is palindrome" << endl;
    else
        cout << "It is not palindrome" << endl;
}