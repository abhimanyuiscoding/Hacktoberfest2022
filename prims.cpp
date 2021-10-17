#include<bits/stdc++.h>
using namespace std;

void primsAlgorithm(int **G, int v){

    int selected[v];
    memset(selected, false, sizeof(selected));
    selected[0] = true;

    int x,y, no_edge = 0;

    cout << "Edge : Weight"<<endl;

    while (no_edge < v - 1){
        int min = INT_MAX;
        x = 0;
        y = 0;

        for(int i=0; i<v; i++){
            if(selected[i]){
                for(int j=0; j<v; j++){
                    if(!selected[j] && G[i][j]){
                        if(min > G[i][j]){
                            min = G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " :  " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
    }
}


int main() {
  int v;
  cout<<"Enter the number of verices: ";
  cin>>v;

  int **G = new int *[v];

  for(int i=0; i<v; i++)
    G[i] = new int[v];

  cout<<"Enter the adjency Matrix:\n";

  for(int i=0; i<v; i++){
      for(int j=0; j<v; j++){
          cin>>G[i][j];
      }
  }

  primsAlgorithm(G, v);

  return 0;
}