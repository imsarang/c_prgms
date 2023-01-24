#include <bits/stdc++.h>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        if(left) delete(left);
        if(right) delete(right); 
    }
};

BinaryTreeNode<int> *takeInputBT()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *current = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            current->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            current->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// Print Tree
void printBinaryTree(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *current = q.front();
        cout << current->data << " : ";
        q.pop();
        if (current->left)
        {
            q.push(current->left);
            cout << "L : " << current->left->data;
        }
        else
            cout << "L: -1 ,";
        if (current->right)
        {
            q.push(current->right);
            cout << " R : " << current->right->data;
        }
        else
            cout << "R: -1 ";
        cout << endl;
    }
}

// Construct tree from preorder and inorder
BinaryTreeNode<int> *buildTreePreInHelper(int *inOrder, int *preOrder, int inOrderStart, int inOrderEnd, int preOrderStart, int preOrderEnd)
{
    if (inOrderStart > inOrderEnd)
        return NULL;

    int rootData = preOrder[preOrderStart];

    int rootIndex = -1;
    // for finding root index
    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        if (inOrder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    // left child
    int leftInOrderStart = inOrderStart;
    int leftInOrderEnd = rootIndex - 1;
    int leftPreOrderStart = preOrderStart + 1;
    int leftPreOrderEnd = leftInOrderEnd - leftInOrderStart + leftPreOrderStart;

    // right child
    int rightPreOrderStart = leftPreOrderEnd + 1;
    int rightPreOrderEnd = preOrderEnd;
    int rightInOrderStart = rootIndex + 1;
    int rightInOrderEnd = inOrderEnd;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreePreInHelper(inOrder, preOrder, leftInOrderStart, leftInOrderEnd, leftPreOrderStart, leftPreOrderEnd);
    root->right = buildTreePreInHelper(inOrder, preOrder, rightInOrderStart, rightInOrderEnd, rightPreOrderStart, rightPreOrderEnd);
    return root;
}

BinaryTreeNode<int> *buildTreePreIn(int *preOrder, int prelength, int *inOrder, int inlength)
{
    return buildTreePreInHelper(inOrder, preOrder, 0, inlength - 1, 0, prelength - 1);
}

// Construct tree from postorder and inorder
BinaryTreeNode<int> *buildTreePostInHelper(int *inorder, int *postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd)
{
    if (inorderStart > inorderEnd)
        return NULL;

    int rootData = postorder[postorderEnd];
    int rootIndex = -1;

    // finding the root
    for (int i = inorderStart; i <= inorderEnd; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    // left child
    int leftInorderStart = inorderStart;
    int leftInorderEnd = rootIndex - 1;
    int leftPostorderStart = postorderStart;
    int leftPostorderEnd = leftInorderEnd - leftInorderStart + leftPostorderStart;

    // right child
    int rightInorderStart = rootIndex + 1;
    int rightInorderEnd = inorderEnd;
    int rightPostorderStart = leftPostorderEnd + 1;
    int rightPostorderEnd = postorderEnd - 1;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreePostInHelper(inorder, postorder, leftInorderStart, leftInorderEnd, leftPostorderStart, leftPostorderEnd);
    root->right = buildTreePostInHelper(inorder, postorder, rightInorderStart, rightInorderEnd, rightPostorderStart, rightPostorderEnd);
    return root;
}

BinaryTreeNode<int> *buildTreePostIn(int *postorder, int postlength, int *inorder, int inlength)
{
    return buildTreePostInHelper(inorder, postorder, 0, inlength - 1, 0, postlength - 1);
}

// get height of the tree
int getHeight(BinaryTreeNode<int> *root, int h)
{
    if (!root)
        return h;
    return max(getHeight(root->left, h + 1), getHeight(root->right, h + 1));
}
// Check if tree is balanced

bool isBalanced(BinaryTreeNode<int> *root)
{
    if (!root)
        return true;
    int l = getHeight(root->left, 0);
    int r = getHeight(root->right, 0);

    if (abs(l - r) == 1 || abs(l - r) == 0 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
}

// Remove leaf Nodes
BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (!root)
        return NULL;
    if (!root->left && !root->right)
    {
        delete (root);
        return NULL;
    }
    if (root->left)
    {
        root->left = removeLeafNodes(root->left);
        if (root->right)
            root->right = removeLeafNodes(root->right);
    }
    return root;
}

// print leaf Nodes
void printLeafNodes(BinaryTreeNode<int> *root)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        cout << root->data << " ";
        return;
    }

    if (root->left)
        printLeafNodes(root->left);
    if (root->right)
        printLeafNodes(root->right);
}

// print a zig zag tree
// use 2 stacks in this problem
// for alternate reverse priting
void zigzag(BinaryTreeNode<int> *root)
{
    if (!root)
        return;

    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;
    s1.push(root);
    while (!s1.empty())
    {
        while (!s1.empty())
        {
            BinaryTreeNode<int> *top = s1.top();
            s1.pop();
            cout << top->data << " ";
            if (top->left)
                s2.push(top->left);
            if (top->right)
                s2.push(top->left);
        }
        cout << endl;
        while(!s2.empty()){
            BinaryTreeNode<int> *top = s2.top();
            s2.pop();
            cout<<top->data<<" ";
            if(top->left)
                s1.push(top->right);
            if(top->right)
                s1.push(top->left);
        }
        cout<<endl;
    }
}