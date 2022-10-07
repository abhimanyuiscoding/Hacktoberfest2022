#include<iostream>
using namespace std;

int main(){

    freopen("input.txt","r",stdin);
    freopen("Output.txt","w",stdout);

    int n;
    cin>>n;
    int arr[n][n];

    //Input Matric Elements
    for (int i = 0; i < n; i++)
    {
        for (int j =0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    //Swaping Matrix Elements
    for (int i = 0; i < n; i++)
    {   for (int j = i; j < n; j++)
    {
      int temp = arr[i][j];
      arr[i][j]= arr[j][i];
      arr[j][i]=temp;
    }
    }
    
    //Output Matric Elemets
    for (int i = 0; i < n; i++)
    {   for (int j = 0; j < n; j++)
        {
        cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}