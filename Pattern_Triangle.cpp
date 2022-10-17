//Pattern :
//    *
//   ***
//  *****
// *******

#include <iostream>
using namespace std;

// Function to demonstrate printing pattern
void triangle(int n,int p)
{
	// number of spaces
	if(p==0){
	 int k = 2 * n - 2;
	// Outer loop to handle number of rows
	// n in this case
	for (int i = 0; i<n; i++) {

		// Inner loop to handle number spaces
		// values changing acc. to requirement
		for (int j = 0; j < k; j++)
			cout << " ";

		// Decrementing k after each loop
		k = k-1;

		// Inner loop to handle number of columns
		// values changing acc. to outer loop
		for (int j = 0; j <= i; j++) {
			// Printing stars
			cout << "* ";
		}

		// Ending line after each row
		cout << endl;
	}}
	else if (p==1){
	    int k =n-2;

	
	for (int i =n-1; i >= 0; i--) {

	
		for (int j = 0; j < k; j++)
			cout << " ";

		
		k = k+1;

		
		for (int j = 0; j <= i; j++) {
			
			
			cout << "* ";
		
		}

		// Ending line after each row
		cout << endl;
	}
	    
	}
	else{
	    cout<<"INVALID INPUT"<<endl;
	}
}

// Driver Code
int main()
{
	int n;
	cout<<"Enter the no. of rows of the triangle"<<endl;
	cin>>n;
	int p;
	cout<<"Enter 0 for solid triangle and 1 for reverse triangle"<<endl;
	cin>>p;

	// Function Call
	triangle(n,p);
	return 0;
}
