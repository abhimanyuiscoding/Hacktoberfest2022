//binary operator overloading of assign operator
//using member function and constructor
#include<iostream>
using namespace std;
class distance
{
private:
    int feet;
    int inches;
public:
    distance()//default constructor
    {
        feet=0;
        inches=0;

    }
    distance(int f,int i)
    {//parametrized constructor
    feet=f;
    inches=i;
    }
    void operator =(distance &d)
    {
        feet=d.feet;
        inches=d.inches;
    }
    void displayDistance()
    {
        cout<<"f:"<<feet<<"i:"<<inches<<endl;
    }
};
int main()
    {
        distance d1; //default call
        distance d2(5,11); //parametrized call
        cout<<"first distance :";
        d1.displayDistance;
        cout<<"second distance:";
        d2.displayDistance;
        d1.operator=(d2);
        cout<<"first distance:";
        d1.displayDistance();
        return 0;
    }
