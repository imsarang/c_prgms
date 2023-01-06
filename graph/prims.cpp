#include <iostream>
#include<climits>

using namespace std;

// take minimum weight unvisited neighbour in every iteration
// weight,parent,visited array used
// adjacency matrix is used

// Complexity : 
// findMinVertex : O(n)
// the main code : including finding the unvisited neightbour to the minVertex with minimum weight : O(n * (n-1)) = O(n square)

// min heap can be used to improve time complexity of finding the minimum vertex since : min heap/ min priority queue : O(log n) < current findMinVertex time complexity i.e O(n)

// E = number of edges
// time complexity if priority queue(min heap) + adjacency matrix = (E+n)log n
int findMinVertex(int *weights,bool *visited,int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}
void prims(int **graph,int n){
    bool *visited = new bool[n];
    int *parent = new int[n];
    int *weights = new int[n];

    for(int i=0;i<n;i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }

    parent[0] = -1;
    weights[0] = 0;

    // out of all unvisited vertices pick the minimum weight
    for(int i=0;i<n;i++){
        int minVertex = findMinVertex(weights,visited,n);
        visited[minVertex] = true;
        // Explore unvisited neighbours
        for(int j=0;j<n;j++){
            if(graph[minVertex][j] != 0 && !visited[j]){
                if(graph[minVertex][j] < weights[j]){
                    weights[j] = graph[minVertex][j];
                    parent[j] = minVertex;
                } 
            }
        }
    }

    // print the output
    for(int i = 1;i<n;i++){
        if(parent[i] < i){
            cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
        }
    }

}
int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    int **graph = new int*[n];
    for(int i =0;i<n;i++){
        graph[i] = new int[n];
        for(int j = 0;j<n;j++){
            graph[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        graph[f][s] = w;
        graph[s][f] = w;
    }
    // prims(graph,n,0);
    prims(graph,n);

    // dealocating memory occupied by 2D array
    for(int i=0;i<n;i++){
        delete [] graph[i];
    }
    delete [] graph;
}