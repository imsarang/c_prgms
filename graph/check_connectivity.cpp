#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void initialize(int **edges,int n){
    for(int i = 0;i<n;i++){
        edges[i] = new int[n];
        for(int j = 0;j<n;j++){
            edges[i][j] = 0;
        }
    }
}
void checkPath(int **edges,int n,int start,int *visited){
    visited[start] = true;
    for(int i = 0;i<n;i++)
    {
        if(edges[start][i]==1 && !visited[i]){
            checkPath(edges,n,i,visited);
        }
    }
}
void DFS(int **edges,int n){
    int *visited = new int[n];
    for(int i = 0;i<n;i++){
        visited[i] = false;
    }

    checkPath(edges,n,0,visited);
    for(int i = 0;i<n;i++){
        if(!visited[i]){
             cout<<"false";
             return;
        }
    }
    cout<<"true";
}
int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    int **edges = new int*[n];
    // memset(edges,0,sizeof edges);
    
    initialize(edges,n);

    for(int i = 0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

   DFS(edges,n);

}