#include <bits/stdc++.h>
#include <string>
#include <limits>
#include <cmath>
#include <vector>

#include "binaryTree.h"
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// check if given tree is a BST
int maximum(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int> *root)
{
    if (!root)
        return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (!root)
        return true;
    int lmax = maximum(root->left);
    int rmin = minimum(root->right);
    bool output = (root->data > lmax) && (root->data <= rmin) && isBST(root->left) && isBST(root->right);
    return output;
}

// contruct BST from a sorted Array
BinaryTreeNode<int> *constructBSTHelper(int *input, int start, int end)
{
    // Base Condition
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
    root->left = constructBSTHelper(input, 0, mid - 1);
    root->right = constructBSTHelper(input, mid + 1, end);
    return root;
}
BinaryTreeNode<int> *constructBST(int *input, int size)
{
    return constructBSTHelper(input, 0, size - 1);
}

// BST to sorted LL
class PAIR
{
public:
    Node *head;
    Node *tail;
};

PAIR BstToLL(BinaryTreeNode<int> *root)
{

    // Base Condition
    if (!root)
    {
        PAIR ans;
        ans.head = NULL;
        ans.tail = NULL;
    }

    Node *head = new Node(root->data);

    // Recursion Calls
    PAIR leftans = BstToLL(root->left);
    PAIR rightans = BstToLL(root->right);

    PAIR ans;

    // Conditions for inserting nodes to LL
    if (!leftans.head && !rightans.head)
    {
        ans.head = head;
        ans.tail = head;
    }
    else if (!leftans.head && rightans.head)
    {
        ans.head = head;
        head->next = rightans.head;
        ans.tail = rightans.tail;
    }
    else if (leftans.head && !rightans.head)
    {
        ans.head = leftans.head;
        leftans.tail->next = head;
        ans.tail = head;
    }
    else
    {
        ans.head = leftans.head;
        leftans.tail->next = head;
        head->next = rightans.head;
        ans.tail = rightans.tail;
    }
    return ans;
}

Node *contructLLFromBST(BinaryTreeNode<int> *root)
{
    return BstToLL(root).head;
}

// get path from root to given number
vector<int> *getPath(BinaryTreeNode<int> *root, int k)
{
    if (!root)
        return NULL;

    if (root->data == k)
    {
        vector<int> *v = new vector<int>();
        v->push_back(root->data);
        return v;
    }

    vector<int> *v = getPath(root->left, k);

    if (v)
    {
        v->push_back(root->data);
        return v;
    }
    else
    {
        vector<int> *r = getPath(root->right, k);
        if (r)
        {
            r->push_back(root->data);
            return r;
        }
    }
    return NULL;
}

// BST CLASS FOR INSERT DELETE PRINT
class BST
{
    BinaryTreeNode<int> *root;

private:
    BinaryTreeNode<int> *insertNode(BinaryTreeNode<int> *root, int data)
    {
        if (!root)
        {
            BinaryTreeNode<int> *ptr = new BinaryTreeNode<int>(data);
            return ptr;
        }
        if (root->data < data)
        {
            root->right = insertNode(root->right, data);
        }
        else
            root->left = insertNode(root->left, data);
        return root;
    }

    void printTree(BinaryTreeNode<int> *root)
    {
        if (!root)
            return;

        cout << root->data << " : ";

        if (root->left)
            cout << "L : " << root->left->data;
        if (root->right)
            cout << "R : " << root->right->data;
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

    BinaryTreeNode<int> *deleteNode(BinaryTreeNode<int> *root, int k)
    {
        if (!root)
            return NULL;

        if (root->data < k)
        {
            root->right = deleteNode(root->right, k);
            return root;
        }
        else if (root->data > k)
        {
            root->left = deleteNode(root->left, k);
            return root;
        }
        else
        {

            // leaf Node
            if (!root->left && !root->right)
            {
                delete (root);
                return NULL;
            }
            // in between nodes
            else if (!root->right)
            {
                BinaryTreeNode<int> *ptr = root->right;
                root->right = NULL;
                delete (root);
                return ptr;
            }
            else if (!root->left)
            {
                BinaryTreeNode<int> *ptr = root->left;
                root->left = NULL;
                delete (root);
                return ptr;
            }

            // root for deletion
            else
            {
                BinaryTreeNode<int> *minNode = root->right;
                while (minNode->left)
                    minNode = minNode->left;
                int rightMin = minNode->data;
                root->data = rightMin;
                root->right = deleteNode(root->right, rightMin);
                return root;
            }
        }
    }

public:
    void insert(int data)
    {
        this->root = insertNode(this->root, data);
    }

    void print()
    {
        printTree(this->root);
    }
    void remove(int data)
    {
        this->root = deleteNode(this->root, data);
    }
};

// create and insert duplicate nodes
void insertDup(BinaryTreeNode<int> *root)
{
    // Base Condition
    if (!root)
        return;

    BinaryTreeNode<int> *duplicate = new BinaryTreeNode<int>(root->data);
    duplicate->left = root->left;
    root->left = duplicate;

    // Recursion Calls
    insertDup(duplicate->left);
    insertDup(root->right);
}

// get LCA of two nodes (Binary Tree)
int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    if (!root)
        return -1;

    if (root->data == a || root->data == b)
        return root->data;

    int l = getLCA(root->left, a, b);
    int r = getLCA(root->right, a, b);

    if (l == -1 && r == -1)
        return -1;
    if (l == -1 && r != -1)
        return r;
    if (l != -1 && r == -1)
        return l;
    else
        root->data;
}

// LCA of 2 nodes (BST)

int getLCABST(BinaryTreeNode<int> *root, int val1, int val2)
{
    // Write your code here
    if (!root)
        return -1;
    if (root->data == val1 || root->data == val2)
        return root->data;

    int l = getLCABST(root->left, val1, val2);
    int r = getLCABST(root->right, val1, val2);

    if (l == -1 && r == -1)
        return -1;
    else if (l == -1 && r != -1)
        return r;
    else if (l != -1 && r == -1)
        return l;
    else
        return root->data;
}

// get path upto sum k
void getKPathHelper(BinaryTreeNode<int> *root, int k, vector<int> output)
{
    // Base Condition
    if (root == NULL)
        return;

    output.push_back(root->data);
    k = k - root->data;

    // leaf node
    if (!root->left && !root->right)
    {
        if (k == 0)
        {
            for (int i : output)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        output.pop_back();
        return;
    }

    getKPathHelper(root->left, k, output);
    getKPathHelper(root->right, k, output);
}
void getKPath(BinaryTreeNode<int> *root, int k)
{
    vector<int> v;
    getKPathHelper(root, k, v);
}

// print node at k distance from another node
void printKDistDown(BinaryTreeNode<int> *root, int target)
{
    if (root == NULL || target < 0)
        return;

    if (target == 0)
    {
        cout << root->data << endl;
        return;
    }

    printKDistDown(root->left, target - 1);
    printKDistDown(root->right, target - 1);
}

int printKDistNode(BinaryTreeNode<int> *root, int target, int k)
{

    // if root is NULL
    if (root == NULL)
        return -1;

    // if target is same as root : print all the nodes at distance k downwards
    if (root->data == k)
    {
        printKDistDown(root, k);
        return;
    }

    // Recursion for left subtree
    int dl = printKDistNode(root->left, target, k);

    if (dl != -1)
    {
        // If root is at distance k from target, print root
        // Note that dl is Distance of root's left child from target
        if (dl + 1 == k)
            cout << root->data << endl;

        // Else go to right subtree and print all k-dl-2 distant nodes
        // Note that the right child is 2 edges away from left child
        else
            printKDistDown(root->right, k - dl - 2);

        // Add 1 to the distance and return value for parent calls
        return 1 + dl;
    }

    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
    // Note that we reach here only when node was not found in left subtree
    int dr = printKDistNode(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
            cout << root->data << endl;
        else
            printKDistDown(root->left, k - dr - 2);
        return 1 + dr;
    }

    // If target was neither present in left nor in right subtree
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    int x = printKDistNode(root, node, k);
}