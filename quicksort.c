#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void swap(int * arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(int * arr, int left, int right) {
  int start = left + 1;
  int pivot = left;
  int end = right;
  while (1) {
    opcount++;
    while (arr[start] <= arr[pivot]) {
      opcount++;
      start++;
    }
    opcount++;
        while (arr[end] > arr[pivot]) {
     opcount++;
      end--;
    }
    opcount++;

    //opcount++; //for while
    //opcount++; //for if statement comp
    if (start >= end) {
      break;
    }
    swap(arr, start, end);
  }
  swap(arr, pivot, end);
  return end;
}

void quicksort(int * arr, int left, int right) {
  opcount++;
  if (left < right) {
    int split = partition(arr, left, right);
    quicksort(arr, left, split - 1);
    quicksort(arr, split + 1, right);
  }
}

int main() {
  printf("Enter the number of elements : ");
  int n;
  scanf("%d", & n);
  printf("Enter the array : ");
  int * arr = (int * ) calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) 
    scanf("%d", & arr[i]);
  quicksort(arr, 0, n - 1);
  printf("The sorted array is : ");
  for (int i = 0; i < n; i++) 
    printf("%d ", arr[i]);
  printf("\nThe Operation Count is : %d", opcount);
  printf("\n");
  return 0;
}