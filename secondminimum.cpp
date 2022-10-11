#include <stdio.h>
int main()
{
int n,i;
int arr[10],min,smin;
printf("\nEnter 10 values");
for(i = 0; i < 10; i++)
{
scanf("%d",&arr[i]);
}
min=arr[0];
smin=arr[0];
for(i = 0; i < 10; i++)
{
if(arr[i] < min)
{
smin = min;
min = arr[i];
}
}
for(i = 0; i < 10; i++)
{
if(arr[i] < smin && arr[i] != min)
{
smin = arr[i];
}
}
printf("\nThe second smallest element is %d \n", smin);

}
