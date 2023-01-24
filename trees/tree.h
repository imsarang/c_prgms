#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
    }
    ~TreeNode(){
        for(int i = 0;i<children.size();i++){
            delete children[i];
        }
    }
};

// Take input level wise
TreeNode<int>* takeInput(){
    int rootData;
    cin>>rootData;
    TreeNode <int> *root = new TreeNode<int>(rootData);

    queue <TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin>>numChild;
        for(int i = 0;i<numChild;i++){
            int childData;
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);  
        }
    } 

    return root;
}

// print level wise
void printLevelWise(TreeNode<int> *root){
    queue <TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" : ";
        for(int i = 0;i<front->children.size();i++){
            cout<<front->children[i]->data<<" ";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}

// sum of nodes
int sumNodes(TreeNode<int> *root){
    queue <TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    int sum = root->data;
    while(pendingNodes.size()!=0){
        TreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();
        for(int i = 0 ;i<front->children.size();i++){
            sum+=front->children[i]->data;
            pendingNodes.push(front->children[i]);
        }
    }
    return sum;
}

// getMaxDataNode
int getMaxDataNode(TreeNode<int> *root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    int max = root->data;
    while(pendingNodes.size()!=0){
        TreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();
        for(int i = 0 ;i<front->children.size();i++){
            if(max<front->children[i]->data) max = front->children[i]->data;
            pendingNodes.push(front->children[i]);
        }
    }
    return max;
}

// Height of the tree
int getHeight(TreeNode<int>*root){
    int h =1;
    if(root->children.size()==0){
        return h;
    }
    int arr[root->children.size()];
    for(int i=0;i<root->children.size();i++){
        arr[i] = getHeight(root->children[i]);
    }
    sort(arr,arr+root->children.size(),greater<int>());
    h+=arr[0];
    return h;
}

// Count leaf nodes
int getLeafNodes(TreeNode<int> *root){
    int c = 0;
    if(root==NULL) return 0;
    if(root->children.size()==0) return c+1;

    for(int i = 0;i<root->children.size();i++){
        c+=getLeafNodes(root->children[i]);
    }
    return c;
}

// Post Order
void postOrder(TreeNode<int> *root){
    if(root==NULL) return;
    for(int i=0;i<root->children.size();i++){
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}

// return Node with max child sum
TreeNode<int> *getMaxChildSum(TreeNode<int>*root){
    
    TreeNode<int> *ans = root;

    int sum = root->data;
    for(int i = 0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }

    for(int i = 0;i<root->children.size();i++){
        TreeNode <int> *childmax = getMaxChildSum(root->children[i]);
        int small = childmax->data;
        for(int j = 0;j<childmax->children.size();j++){
            small+=childmax->children[i]->data;
        }
        if(sum<small){
            ans = childmax;
            sum = small;
        }
    }

    return ans;
}

// are identitcal trees
bool areIdentical(TreeNode<int> *root1,TreeNode<int>*root2){
    if(root1->data != root2->data) return false;
    if(root1->children.size() != root2->children.size()) return false;
    bool ans = true;
    for(int i = 0;i<root1->children.size();i++){
        bool res = areIdentical(root1->children[i],root2->children[i]);
        if(res==false){
            ans = false;
            return ans;
        }
    }
    return ans;
}

// Second largest element in tree
void secondLargestHelper(TreeNode<int> *root,TreeNode<int> **first,TreeNode<int> **second){
    if(root==NULL) return;
    else if(!(*first)) *first = root;
    else if(root->data > (*first)->data){
        *second = *first;
        *first = root;
    }
    else if (!(*second) || (*second)->data <root->data)
        *second = root;

    for(int i = 0;i<root->children.size();i++){
        secondLargestHelper(root->children[i],first,second);
    }
}
int secondLargest(TreeNode<int>*root){
    TreeNode<int>*first = NULL,*second = NULL;
    secondLargestHelper(root,&first,&second);
    if(second==NULL) return -1;
    if(second->data == first->data) return -1;
    return second->data;
}