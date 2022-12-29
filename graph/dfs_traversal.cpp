
#include <iostream>

using namespace std;

// print() for printing the graph
// sv : starting vertex
void print(int **edges,int n,int sv,bool *visited){
    
    cout<<sv<<endl;
    visited[sv] = true;
    for(int i = 0 ;i<n;i++){
        
        if(i==sv) continue;
        
        if(edges[sv][i] == 1){
            if(visited[i]){ 
                continue;
            }
            
            print(edges,n,i,visited);
        }
    }
}

int main()
{   
    int n,e;
    cin>>n>>e;
    
    // inititalize edge adjacancy matrix
    int **edges = new int*[n];
    for(int i = 0;i<n;i++){
        edges[i] = new int[n];
        for(int j = 0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    // take input form user for the edges and fill the matrix accordingly
    for(int i;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    // visited array
    bool *visited = new bool[n];
    for(int i = 0;i<n;i++){
        visited[i] = false;
    }
    print(edges,n,0,visited);
    
    // free memory
    
    for(int i = 0;i<n;i++){
        visited[i] = NULL;
    }
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            edges[i][j] = NULL;
        }
    }
    free(visited);
    free(edges);
    return 0;
}
