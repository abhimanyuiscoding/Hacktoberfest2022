#include<iostream>
#include<string.h>

using namespace std;

int main(){
    int i,j,key,len,count,k=-1,row=0,col=0;
    char rf[20][20],pt[20];

    cout<<"Enter key\n";
    cin>>key;
    cout<<"Enter text\n";
    cin>>pt;
    len = strlen(pt);
    count = 100;
    for(i=0;i<key;i++){
        for(j=0;j<len;j++){
            rf[i][j] = '*';          
        }   
    }
    for(i=0;i<len;i++){
        rf[row][col++] = pt[i];
        if(row==0 || row==key-1)
        k = k * (-1);
        row = row + k;
    }
    
    cout<<"\nEncrypted message :\n";
    for(i=0;i<key;i++){
        for(j=0;j<len;j++){
            if(rf[i][j] != '*')
            cout<<rf[i][j];         
        }   
    }   
}
