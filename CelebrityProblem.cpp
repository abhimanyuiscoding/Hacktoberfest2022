// In a party of N people, only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. Find the stranger (celebrity) in the minimum number of questions.
// We can describe the problem input as an array of numbers/characters representing persons in the party. We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, false otherwise. How can we solve the problem.
 
// Examples: 
 
// Input:
// 4
// MATRIX =           { {0, 1, 1, 0},  
//                  	{0, 0, 1, 0},
//                  	{0, 0, 0, 0},
//                  	{1, 1, 1, 0} }
// Output:id = 2
// Explanation: The person with ID 2 does not
// know anyone but everyone knows him

#include<iostream>
#include<deque>

using namespace std;

int main(){
    
    int n;
    cin>>n;

    int ** matrix = new int*[n];

    for(int i=0;i<n;i++){
        matrix[i] = new int[n];

        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    deque<int> stackk;

    for(int i=0;i<n;i++){
        stackk.push_back(i);
    }

    while(stackk.size()!=1){
        int top1 = stackk.front();
        stackk.pop_front();
        int top2 = stackk.front();
        stackk.pop_front();

        if(matrix[top1][top2]==1){
            stackk.push_front(top2);
        }else{
            stackk.push_front(top1);
        }
    }

    int last1 = stackk.front();

    bool isCeleb = true;

    for(int i=0;i<n;i++){

        if(i==last1){
            continue;
        }

        if(matrix[i][last1]==0){
            isCeleb = false;
            break;
        }

        if(matrix[last1][i]==1){
            isCeleb = false;
            break;
        }
    }

    if(isCeleb){
        cout<<"Celebrity is : "<<last1<<endl;
    }else{
        cout<<"No Celebrity found!!"<<endl;
    }


    return 0;
}

