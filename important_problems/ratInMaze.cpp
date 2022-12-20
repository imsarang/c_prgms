/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;

void printSolution(int **solution, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << solution[i][j] << " ";
    }
  }
  cout << endl;
}
void mazeHelp(int maze[][20], int n, int **solution, int x, int y) {
  if (x == n - 1 && y == n - 1) {
    solution[x][y] = 1;
    printSolution(solution, n);
    return;
  }
  // cout<<"Helper"<<endl;
  if (x >= n || x < 0 || y >= n || y < 0 || solution[x][y] == 1 ||
      maze[x][y] == 0) {
    return;
  }
  solution[x][y] = 1;
  mazeHelp(maze, n, solution, x - 1, y);
  mazeHelp(maze, n, solution, x + 1, y);
  mazeHelp(maze, n, solution, x, y - 1);
  mazeHelp(maze, n, solution, x, y + 1);
  solution[x][y] = 0;
}
void ratInMaze(int maze[][20], int n) {

  // number of rows
  int **solution = new int *[n];

  // number of columns
  for (int i = 0; i < n; i++) {
    solution[i] = new int[n];
  }
//   cout << "ratInMaze" << endl;
  mazeHelp(maze, n, solution, 0, 0);
}

int main() {
	int n;
	cin>>n;
	int arr[n][20];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	ratInMaze(arr,n);
	// findPath(n,arr);/
	// Write your code here
	return 0;
}
