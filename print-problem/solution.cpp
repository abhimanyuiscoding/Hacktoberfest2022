#include <iostream>

int main()
{
    std::cout<<"Enter value of n:\t";   
    int n;  std::cin>>n;                //Taking input from user
    for(int i=1;i<=n;++i){              //For loop from 1 to n
        std::cout<<i;                   //priting value of i
    }
    return 0;
}
