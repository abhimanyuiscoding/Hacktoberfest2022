#include <stdio.h>
void heapSort(int a[], int n);
void heapify(int a[], int n, int i);

int main()
{
    int arr[20], i, n;
    printf("enter array size\n");
    scanf("%d", &n);
    printf("\nenter array values\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    heapSort(arr, n);
    printf("sorted array is\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    return 0;
}

void heapSort(int arr[], int n)
{
    int temp, i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i)

{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    int swap;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        heapify(arr, n, largest);
    }
}