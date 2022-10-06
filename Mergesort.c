#include <stdio.h>
#include <time.h>
void merge(int arr[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1 + j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
}
else {
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
while (j < n2) {
arr[k] = R[j];
j++;
k++;
} }
void mergeSort(int arr[], int l, int r)
{
if (l < r) {
int m = l + (r - l) / 2;
mergeSort(arr, l, m);
mergeSort(arr, m + 1, r);
merge(arr, l, m, r);
} }
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
int i;
for (i = 0; i < size; i++)
printf("%d ", A[i]);
printf("\n");
}
int main()
{
int size;
scanf("%d", &size);
int data[size];
for(int i=0; i<size; i++)
{
scanf("%d",&data[i]);
}
clock_t t;
t= clock();
 mergeSort(data, 0, size - 1);
t= clock()- t;
double time_taken = ((double)t);
 printArray(data, size); 
printf("CPU TIME FOR Merge Sort= %f seconds \n", time_taken); 
return 0;
}
