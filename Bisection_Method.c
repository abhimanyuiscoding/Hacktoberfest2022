#include<stdio.h>
#include<conio.h>
double f(double x)
{ 
    return ((x*x*x)-(x*x)+2);
}
double calc(double a,double b)
{
    if(f(a)*f(b)>0)
    {
        printf("root out of bound");
        return 0.0;
    }
    else if(f(a)==0)
    {
        printf("%f",a);
        return 0.0;
    }
    else if(f(b)==0)
    {
        printf("%f",b);
        return 0.0;
    }
    double c=a;
    while((b-a)>=0.001)
    {
        
        c=(a+b)/2.0;
        if(f(c)==0.0)
        {
            break;
        }
        else if(f(c)*f(a)<0)
        {
            b=c;
        }
        else{
            a=c;
        }
    }
    return c;
}
int main()
{   
    double a,b;
    scanf("%lf %lf",&a,&b);
    double x=calc(a,b);
    printf("%lf",x);
    return 0;
}

