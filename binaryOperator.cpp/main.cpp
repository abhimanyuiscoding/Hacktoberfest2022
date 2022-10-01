//binary operator overloading of equality(==) using member function
#include<iostream>
using namespace std;
class integer
{
    int a,b;
public:
    void input()
    {
        cout<<"\n enter the value of a and b";
        cin>>a>>b;
    }
    void operator ==(integer & i1)
    {
        if(a==(i1).a&&b==(i1).b)
            cout<<"\n both of them are equal";
        else
            cout<<"\n both of them are not equal";
    }
};
int main()
{
    integer i2,i3;
    i2.input();
    i3.input();
    i2==i3;
    return 0;
}
