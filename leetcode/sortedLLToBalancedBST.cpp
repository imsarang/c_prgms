using namespace std;

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
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
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

int length(Node<int> *head)
{
    if (head == NULL)
        return 0;
    int count = 0;
    Node<int> *ptr = head;
    while (ptr)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}
TreeNode<int> *helper(Node<int> **head, int n)
{
    if (n <= 0)
        return NULL;

    TreeNode<int> *left = helper(head, n / 2);

    TreeNode<int> *root = new TreeNode<int>((*head)->data);
    root->left = left;
    (*head) = (*head)->next;
    root->right = helper(head, n - n / 2 - 1);
    return root;
}
TreeNode<int> *sortedListToBST(Node<int> *head)
{
    // Write your code here.
    int n = length(head);
    return helper(&head, n);
}