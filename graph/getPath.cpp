  #include <bits/stdc++.h>
  using namespace std;

  vector<int> getPath(int **edges, int n, int start, int end,bool *visited){
      
      if(start==end){
          vector<int> v;
          v.push_back(end);
          return v;
      }

      visited[start] = true;

      for(int i=0; i<n; i++){
          if(edges[start][i] == 1 && !visited[i]){
              vector<int> smallOutput =getPath(edges,n,i,end,visited);
              if(smallOutput.size()!=0){
                  smallOutput.push_back(start);
                  return smallOutput;
              }
          }
      }
      return vector<int> ();
  }

  int main() {
      // Write your code here
      int n;
      int e;
      cin >> n >> e;
      int **edges = new int *[n];
      for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
          edges[i][j] = 0;
        }
      }

      for (int i = 0; i < e; i++) {
        int firstEdge, secondEdge;
        cin >> firstEdge >> secondEdge;
        edges[firstEdge][secondEdge] = 1;
        edges[secondEdge][firstEdge] = 1;
      }

      int v1, v2;
      cin >> v1 >> v2;

      bool *visited = new bool[n]();

      vector<int> ans = getPath(edges, n, v1, v2, visited);
      for(int i=0; i<ans.size() ; i++){
        cout<<ans[i]<<" ";

      }
      
  }