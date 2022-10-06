#include<iostream>
using namespace std;
void test(int x)
{
    try{
        if(x > 0)
        {
            throw(x);
        }
        else{
            throw('x');
        }
    }
    catch(int a)
    {
        cout<<"integer "<<endl;
    }
    catch(char b)
    {
        cout<<"chracter "<<endl; 
    }
}
int main()
{
    test(5);
    test(-5);

    return 0;
}