#include <iostream>
#include<bits/stdc++.h>

using namespace std;

// E : number of edges , V : number of vertices
// time complexity:
// sorting : O(E logE)
// pick n-1 edges(also performs cycle detection) : EV : union-find algo
// total : E logE + EV
// worst case : all the vertices have to be checked and all the edges have to be checked for cyclicity : EV (E = V sqaure (Worst Case))

// using union-rank algo(union by rank method) : EV => E logV
class edge{
    public:
        int src;
        int dest;
        int w;

        // contructor for initializing the input and output array
        edge(){};

        // contructor for taking in input
        edge(int src, int dest, int w){
            this-> src = src;
            this->dest = dest;
            this->w = w;
        }
};

bool compare(edge const & e1,edge const & e2){
    return e1.w < e2.w;
}

int findParent(int node,int *parent){
    
    // Base Condition
    if(parent[node] == node) return node;

    // Recursion Call
    return findParent(parent[node],parent);
}

void kruskals(edge *input,int n,int e){
    // sort the input array in ascending order
    // go from first to last element
    // sort based on weights
    sort(input,input+e,compare);

    edge *output = new edge[n-1];

    // checking for cyclicity using union-find algo by using a parent array
    int *parent = new int[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    int count = 0;
    int i=0;
    while(count != n-1){
        edge currentEdge = input[i];

        // check if we can add current edge in MST or not
        int srcParent = findParent(currentEdge.src,parent);
        int destParent = findParent(currentEdge.dest,parent);

        if(srcParent!=destParent){
            output[count] = currentEdge;
            count++;

            // taking union of parents of src and dest for updating in the parent array as new parent
            parent[srcParent] = destParent; 
        }
        i++;
    }

    // print the output
    for(int i=0;i<n-1;i++){
        if(output[i].src < output[i].dest)
          cout << output[i].src << " " << output[i].dest << " " << output[i].w << endl;
        else
          cout << output[i].dest << " " << output[i].src << " " << output[i].w << endl;
    }
}
int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    edge *input = new edge[e];
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;

        input[i] = edge(s, d, w);
        // input[i].src = s;
        // input[i].dest = d;
        // input[i].w = w; 
    }

    kruskals(input,n,e);
}