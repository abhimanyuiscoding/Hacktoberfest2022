// C program for the Driver Function of the Bug Tracking System

#include <stdio.h>

// Driver Code
void main()
{
	printf("***************");
	printf("BUG TRACKING SYSTEM");
	printf("***************\n");

	int number, i = 1;

	// Id initialised to 0
	int id = 0;

	// while loop to run
	while (i != 0) {
		printf("\n1. FILE A NEW BUG\n");
		printf("2. CHANGE THE STATUS OF THE BUG\n");
		printf("3. GET BUG REPORT\n4. EXIT");
		printf("\n\n ENTER YOUR CHOICE:");

		scanf("%d", &number);

		// Using switch to go case by case
		switch (number) {
		case 1:
			id++;

			// Creating a New Bug
			filebug(id);
			break;
		case 2:

			// Change Status of Bug
			changestatus();
			break;
		case 3:

			// Report the Bug
			report();
			break;
		case 4:
			i = 0;
			break;
		default:
			printf("\ninvalid entry");
			break;
		}
	}
}
