/*

Problem Link : https://leetcode.com/problems/permutation-in-string/

*/

#include<iostream>
using namespace std;


bool isEqual(int count1[], int count2[]) {
    for(int i=0; i<26; i++) {
        if (count1[i] != count2[i]) {
            return 0;
        }
    }
    return 1;
}

bool checkInclusion(string s1, string s2) {
        // Create count array for s1 string
        int count1[26] = {0};
        for(int i = 0; i < s1.length(); i++) {
            count1[s1[i] -'a']++;
        }
    
        // Traverse over s2 string in window of length equalto s1 string
        
        int count2[26] = {0};
        int windowSize = s1.length();
        int i = 0;
        
        // Running for first window
        while(i < windowSize && i < s2.length()) {
            count2[s2[i] - 'a']++;
            i++;
        }
        
        // Check if both count array are equal 
        // If yes, return true else move window 
        if(isEqual(count1, count2)) {
            return 1;
        }
        
        // Moving window and adding count of new character 
        // and removing count of old character 
        // (which moved out of window) in count2 array
        while(i < s2.length()) {
            char newChar = s2[i];
            count2[newChar - 'a']++;
            
            char oldChar = s2[i-windowSize];
            count2[oldChar - 'a']--;
            
            // Every time window is move forward, 
            // check if both count array are equal 
            // If yes, return true else move window 
            if(isEqual(count1, count2)) {
                return 1;
            }
            
            i++;
        }
        // Return false
        return 0;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << checkInclusion(s1, s2) << endl;
}