#include <iostream>
#include <string>
#include "tree.h"
#include "binaryTree.h"
#include "bst.h"
using namespace std;

int main()
{
    // TreeNode<int> * root = takeInput();

    // cout<<"TREE : "<<endl;
    // printLevelWise(root);

    // cout<<"SUM OF NODES : "<<sumNodes(root)<<endl;
    // cout<<"MAX VALUE NODE IN TREE : "<<getMaxDataNode(root)<<endl;
    // cout<<"HEIGHT OF THE TREE : "<<getHeight(root)<<endl;
    // cout<<"NUMBER OF LEAF NODES : "<<getLeafNodes(root)<<endl;
    // cout<<"POST ORDER TRAVERSAL : "<<endl;
    // postOrder(root);cout<<endl;
    // cout<<"NODE WITH MAXIMUM CHILD SUM : "<<getMaxChildSum(root)->data<<endl;
    // cout<<"SECOND LARGEST ELEMENT : "<<secondLargest(root)<<endl;

    BinaryTreeNode<int> *root = takeInputBT();

    // use (preorder or postorder) and inorder  to build a tree
    // int size;
    // cout<<"Size : "<<endl;
    // cin>>size;
    // cout<<"PREORDER : "<<endl;
    // int *preOrder = new int[size];
    // for(int i = 0;i<size;i++){
    //     cin>>preOrder[i];
    // }

    // cout<<"\nPOSTORDER : "<<endl;
    // int *postOrder = new int[size];
    // for(int i = 0;i<size;i++){
    //     cin>>postOrder[i];
    // }

    // cout<<"\nINORDER : "<<endl;
    // int *inOrder = new int[size];
    // for(int i = 0;i<size;i++){
    //     cin>>inOrder[i];
    // }

    // BinaryTreeNode<int> *root = buildTreePreIn(preOrder,size,inOrder,size);
    // BinaryTreeNode<int>*root = buildTreePostIn(postOrder,size,inOrder,size);
    
    // string ans = isBalanced(root) ? "true" : "false";
    // cout << "Is the tree Balanced : " << ans << endl;
    
    // cout<<"LEAF NODES : "<<endl;
    // printLeafNodes(root);
    // cout<<endl;

    printBinaryTree(root);
    

    // Remove leaf nodes : 
    // BinaryTreeNode<int> *newRoot = removeLeafNodes(root);

    // cout<<"\nAfter Edit : "<<endl;
    // printBinaryTree(newRoot); 

    // print zigzag
    zigzag(root);
    return 0;
}