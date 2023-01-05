/*#include<vector>
using namespace std;

void initialize(bool **visited, int N, int M) {

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      visited[i][j] = false;
  }
}
bool dfs(vector<vector<char>> graph,char c[],int i,int j,int n,int m,bool **visited){
  if(graph[i][j]=='A') return true;

  // boolean value for checking whether req character reached
  bool ans = false;

  // visited or not
  visited[i][j] = true;
  // cout<<"output "<<c[1];
  // cout<<"row "<<i<<"col "<<j<<endl;
  // recursive statements

  // upward left diagonal
  if(i-1>=0 && j-1>=0 && graph[i-1][j-1]==c[0] &&!visited[i-1][j-1]) ans = ans || dfs(graph,c+1,i-1,j-1,n,m,visited);
  
  // up
  if(i-1>=0 && graph[i-1][j]==c[0] &&!visited[i-1][j]) ans = ans || dfs(graph,c+1,i-1,j,n,m,visited);
  
  // upward right diagonal
  if(i-1>=0 && j+1<m && graph[i-1][j+1]==c[0] &&!visited[i-1][j+1]) ans = ans || dfs(graph,c+1,i-1,j+1,n,m,visited);
  
  // downward left diagonal
  if(i+1<n && j-1>=0 && graph[i+1][j-1]==c[0] &&!visited[i+1][j-1]) ans = ans || dfs(graph,c+1,i+1,j-1,n,m,visited);
  
  // downward right diagonal
  if(i+1<n && j+1<m && graph[i+1][j+1]==c[0] &&!visited[i+1][j+1]) ans = ans || dfs(graph,c+1,i+1,j+1,n,m,visited);
  
  // down
  if(i+1<n && graph[i+1][j]==c[0] &&!visited[i+1][j]) ans = ans || dfs(graph,c+1,i+1,j,n,m,visited);
  
  // left
  if(j-1>=0 && graph[i][j-1]==c[0] &&!visited[i][j-1]) ans = ans || dfs(graph,c+1,i,j-1,n,m,visited);
  
  // right
  if(j+1<m && graph[i][j+1]==c[0] &&!visited[i][j+1]) ans = ans || dfs(graph,c+1,i,j+1,n,m,visited);

  // return ans at end of recursive calls
  return ans;
}

int hasPath(vector<vector<char>> Graph,int N,int M){
  char c[] = "CODINGNINJA";
  bool **visited = new bool*[N];
  for(int i=  0;i<N;i++){
    visited[i] = new bool[M];
  }

  initialize(visited,N,M);

  // Find "C" in graph
  for(int i = 0;i<N;i++){
    for(int j=0;j<M;j++){
      // New ans for every iteration
      bool ans = false;
      if(Graph[i][j]=='C'){
        ans = dfs(Graph,c+1,i,j,N,M,visited);
        if(ans) return 1;

        // after every failed iteration, ans = false,visited array is initailized
        initialize(visited,N,M);
      }
    }
  }
  return 0;
}
*/
#include <iostream>
#include <vector>
using namespace std;

string value = "CODINGNINJA";
int shifter[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                     {0, 1},   {1, -1}, {1, 0},  {1, 1}};

bool validIndex(int i, int j, int n, int m) {
  if (i < 0 || i >= n || j < 0 || j >= m) {
    return false;
  }
  return true;
}

bool hasPathHelper(vector<vector<char>> &board, int n, int m, int i, int j,
                   int current_index, bool **visited) {
  if (value[current_index] == '\0') {
    return true;
  }
  visited[i][j] = true;
  bool answer = false;
  for (int x = 0; x < 8; x++) {
    int newX = i + shifter[x][0];
    int newY = j + shifter[x][1];
    if (validIndex(newX, newY, n, m) && !visited[newX][newY] &&
        board[newX][newY] == value[current_index]) {
      answer = answer || hasPathHelper(board, n, m, newX, newY,
                                       current_index + 1, visited);
    }
  }
  visited[i][j] = false;
  return answer;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
  bool **visited = new bool *[n];
  for (int i = 0; i < n; i++) {
    visited[i] = new bool[m];
    for (int j = 0; j < m; j++) {
      visited[i][j] = false;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board.at(i).at(j) == 'C') {
        bool answer = hasPathHelper(board, n, m, i, j, 1, visited);
        if (answer) {
          return true;
        }
      }
    }
  }
  return false;
}