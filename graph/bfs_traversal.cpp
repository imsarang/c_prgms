#include<queue>
#include <iostream>
using namespace std;

void print(int**edges,long long n,long long start,bool* visited){
    // visited array
   
    queue<long long> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        long long x = q.front();
        cout<<x<<" ";
        for(long long i = 0;i<n;i++){
           
           
            if(edges[x][i]==1 and !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
    }
    // cout << start << " ";
}
int main() {
    // Write your code here
    long long n,e;
    cin>>n>>e;
    // cout << 0;

    // initialize adjacency matrix
    int **edges  = new  int*[n];
    for(long long i = 0;i<n;i++){
        edges[i] = new int[n];
        for(long long j = 0;j<n;j++){
            edges[i][j] = 0;
        }
    }

    // set up matrix
    for(long long i = 0;i<e;i++){
        long long f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

   

    // free memory
    // for(int i = 0;i<n;i++){
    //     visited[i] = NULL;
    // }
    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<n;j++){
    //         edges[i][j] = NULL;
    //     }
    // }

    // free(visited);
       bool *visited = new bool[n];
    for (long long i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (long long i = 0; i < n; i++)
    {
        if (!visited[i])
            print(edges, n, i,visited);
    }
    delete[] visited;
    free(edges);
    return 0;
}