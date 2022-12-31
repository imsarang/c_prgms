#include <iostream>
#include<queue>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

void initialize(int **edges,int n){
    for(int i = 0;i<n;i++){
        edges[i] = new int[n];
        for(int j = 0;j<n;j++){
            edges[i][j] = 0;
        }
    }
}

void checkConn(int **edges,int n,int start,bool *visited,vector<int> &ans){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    // cout<<start<<" ";
    while(!q.empty()){
        int num = q.front();
        ans.push_back(num);
        for(int i = 0;i<n;i++){
            if(edges[num][i]==1 && !visited[i]){
              visited[i] = true;
              q.push(i);
            }
        }
        q.pop();
    }
    cout<<endl;
}
void BFS(int **edges,int n,int s,bool* visited){
  vector<int> ans;

  checkConn(edges, n, s, visited, ans);

  sort(ans.begin(),ans.end());

  for(auto i :ans){
      cout<< i << " ";
  }

}
int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    int **edges = new int*[n];
    initialize(edges,n);

    for(int i = 0;i<n;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for(int i = 0;i<n;i++){
        visited[i] = false;
    }

    // checkConn(edges,n,0,visited,ans);
    // BFS(edges,n,0,visited);
    for(int i = 0;i<n;i++){
        if(!visited[i]) BFS(edges,n, i,visited);
        cout<<endl;
    }
}