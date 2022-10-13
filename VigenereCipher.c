#include <stdio.h>
#include<string.h>

char arr[32];
char ary[32];
char arx[32];

void encrypt(char a[],char b[])
{
    int i,j;
    int l1 = strlen(a);
    int l2 = strlen(b);
    int l3 =  l1-l2;
    for(int m1=0;a[m1]!='\0';m1++)
{
        if(a[m1]>65&&a[m1]<90)
{
            a[m1]+=32;
        }
    }
    for( i=0;i<l2;i++)
{
        arr[i]=b[i];
     }
     for(int m2=0;arr[m2]!='\0';m2++)
{
        if(arr[m2]>65&&arr[m2]<90)
{
            arr[m2]+=32;
        }
    }
     
     for( j=i;j<l1;j++)
{
         arr[j]=b[j%l2];
     }
     arr[j]='\0';
     for(int k=0;k<l1;k++)
{
         int sum1 = (int)a[k];
         int sum2 = (int)arr[k];
         sum1-=97;
         int sum3=(sum1 +sum2-97)%26;
         sum3+=97;
         ary[k] =  (char)sum3;
     }
    
    
}


void decrypt(){
 for(int i=0;arr[i]!='\0';i++)
{
     int sum1 =(int)ary[i];
     sum1-=97;
     int sum2  = (int)arr[i];
     sum2-=97;
     int  sum3=sum1-sum2;
     for(int j=0;sum3<0;j++)
    {
         sum3+=26;
     }
     sum3 = sum3%26;
     sum3+=97;
     arx[i] = (char)sum3;
     
     
 }
    
}
int main()
{
    int n1,n2;
    printf("Enter the length of Plain Text: ");
    scanf("%d",&n1);

    char ab[n1+1];
    printf("\nEnter the Plain Text: ");
    scanf("%s",&ab);
    ab[n1] = '\0';

    printf("\nEnter the length of Key: ");
    scanf("%d",&n2);
    char bc[n2+1];

    printf("\nEnter the Key: ");
    scanf("%s",&bc);
    bc[n2] = '\0';
     printf("\n");

    encrypt(ab,bc);
    printf("\nUpdated Key: ");
    printf("%s",arr);
    printf("\n");

    printf("\nPlain Text After Encryption: ");
    printf("%s",ary);

    printf("\nCipher Text After Decryption: ");
    decrypt();
    printf("%s",arx);
    return 0;
}
