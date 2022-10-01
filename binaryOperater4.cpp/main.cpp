//binary operator overloading of adding complex operator
#include<iostream>
using namespace std;
class complex
{
   int x;
   int y;
   public:
       complex()
       {

       }
       complex(int a,int b)
       {
           x=a;
           y=b;
       }
       complex operator +(complex &);
       void display();

} ;
complex complex::operator +(complex &d)
{
    complex temp;
    temp.x=x+d.x;
    temp.y=y+d.y;
    return temp;
}
void complex::display()
{
    cout<<x<<"+i"<<y<<endl;
}
int main()
{
    complex c1,c2,c3;
    c1=complex(2,6);
    c2=complex(8,9);
    c3=c1.operator+(c2);
    cout<<" c1 = ";
    c1.display();
    cout<<"c2= ";
    c2.display();
    cout<<"sum = ";
    c3.display();
    return 0;
}
