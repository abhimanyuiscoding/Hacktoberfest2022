#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

int findparent(int node,vector<long long int> &parent){
    if(parent[node]==node)
    return node;
    return parent[node]=findparent(parent[node],parent);
}

void merge(int node1,int node2,vector<long long int> &parent,vector<long long int> &rank){
    
    
    long long int p1=findparent(node1,parent);
    long long int p2=findparent(node2,parent);
    if(p1==p2){
    return ;
    }
    else if(rank[p1]>rank[p2]){
    parent[p2]=p1;
    }
    else {
    parent[p1]=p2;
    }
    if(rank[p1]==rank[p2])
    rank[p2]++;
    
    
    
    
    
}


long long int journeyToMoon(int n, vector<vector<int>> astronaut) {

vector<long long int> parent(n);
vector<long long int> rank(n,1);

for(int i=0;i<n;i++)
parent[i]=i;
for(int i=0;i<astronaut.size();i++){
    
    merge(astronaut[i][0],astronaut[i][1],parent,rank);
}
for(int i=0;i<astronaut.size();i++){
    
    merge(astronaut[i][0],astronaut[i][1],parent,rank);
}

vector<long long int> temparr(n,0),stemp(n,0);
for(int i=0;i<n;i++)

{
    temparr[parent[i]]++;
    cout<<parent[i]<<" ";
}
stemp[n-1]=temparr[n-1];
for(int i=n-2;i>=0;i--){
    stemp[i]=temparr[i]+stemp[i+1];
}
long long int ans=0;
for(int i=0;i<n-1;i++)
ans+=temparr[i]*stemp[i+1];
return ans;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

