//Program for bubble sort
#include<iostream>
using namespace std;
int main()
{
    int array[100],size,y,x,temp;
    cout<<"Enter size of array"<<endl;
    cin>>size;
    cout<<"Enter the elements"<<endl;
    for(x=0;x<size;x++)
    {
        cin>>array[x];
    } 
    for(x=0;x<size;x++)
    {
        for(y=0;y<size-x-1;y++)
        {
          if(array[y]>array[y+1])
          {
            temp=array[y];
            array[y]=array[y+1];
            array[y+1]=temp;
          }
        }
    }
    cout<<"Sorted array by using bubble sort is "<<endl;
    for(x=0;x<size;x++)
    {
        cout<<array[x]<<" ";
    }
    return 0;
}
