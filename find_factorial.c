#include <stdio.h>

int factorial(int);

int main(){
	int n;

	scanf("%d", &n);
	
	printf("Factorial is : %d\n", factorial(n));
	return 0;
}

int factorial(int n){
	if(n > 1){
		return n * factorial(n-1);
		
	}else if(n == 1){
		return 1;
		
	}else{
		printf("Invalid Input. Try Again.\n");
	}
}
