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
    delete [] visited;
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
    //   delete [] visited;
      for(int i = 0;i<n;i++){
        delete [] edges[i];
      }
      delete[] edges;
    return 0;
}