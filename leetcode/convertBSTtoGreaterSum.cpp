template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->val = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void helper(TreeNode<int>*root, int *sum){
    if(!root) return;

    if(root->right)
    helper(root->right,sum);
    (*sum)+=root->val;
    root->val = *sum - root->val;
    if(root->left)
    helper(root->left,sum);
    // return root;
}
TreeNode<int> *convertBstToGreaterSum(TreeNode<int> *root)
{
    // Write your code here.
    int sum = 0;
    helper(root,&sum);
    return root;
}