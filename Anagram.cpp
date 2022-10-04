#include<iostream>
#include<algorithm>
using namespace std;
//Anagram strings
//TC = O(n^2), SC = O(1)
bool approach1(string f1, string f2) {
	if(f1.length() != f2.length())
		return false;
	for (int i = 0; i < f1.length(); i++) {
		char c = f1[i];
		bool found = false;
	    for(int j = 0; j < f2.length(); j++) {
	        char d = f2[j];
		    if(c == d) {
			    f2[j]='#';
			    found = true;
			    break;
		    }
	    }
	    if(!found) {
	        return false;
	    }
	} 
	return true;
}

//TC = O(nlogn), SC = O(1)
bool approach2(string f1, string f2) {
    if(f1.length() != f2.length())
        return false;
    sort(f1.begin(), f1.end());
    sort(f2.begin(),f2.end());
    for(int i = 0; i<f1.length(); i++) 
        if(f1[i] != f2[i]) 
            return false;
    return true;
}
int main() {
	string f1 = "abc";
	string f2 = "cbb";
	cout<<approach1(f1,f2)<<endl;
	return 0;
}
