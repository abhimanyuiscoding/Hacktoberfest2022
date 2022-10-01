//binary operator overloading of add equal(+=) using member function and using constructor
#include<iostream>
using namespace std;
class integer
{
    int a;
public:
      integer(int x)
      {
          a=x;
      }
      integer(){}
      void operator +=(integer &o1);
};
void integer ::operator +=(integer&o1){
a=a+o1.a;
cout<<a;
}
int main()
{
    integer o2(10),o3(5);
    o2+=o3;
    return 0;
}
