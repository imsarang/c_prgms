#include <bits/stdc++.h>
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

void createLL(Node **head, int data)
{
    if (*head == NULL)
    {
        Node *ptr = new Node(data);
        *head = ptr;
        return;
    }
    Node *newNode = new Node(data);
    Node *ptr = *head;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

Node *reverseLL(Node *head)
{
    Node *r = NULL, *q = NULL, *p = head;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

Node *reverseLLRecursion(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *ptr = reverseLLRecursion(head->next);
    Node *temp = head->next;
    temp->next = head;
    head->next = NULL;
    return ptr;
}

// Reverse after every k nodes
Node *reverseKNodes(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    int count = 1;
    Node *head1 = head, *tail = head;

    while (count < k && tail->next)
    {
        tail = tail->next;
        count++;
    }
    Node *head2 = tail->next;
    tail->next = NULL;

    head1 = reverseLL(head1);
    tail = head1;

    while (count > 1 && tail)
    {
        tail = tail->next;
        count--;
    }

    head2 = reverseKNodes(head2, k);

    tail->next = head2;

    return head1;
}

// Bubble Sort
int len(Node *head)
{
    Node *ptr = head;
    int c = 0;
    while (ptr)
    {
        ptr = ptr->next;
        c++;
    }
    return c;
}
Node *bubbleSort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    for (int i = 0; i < len(head); i++)
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr->next)
        {
            if (curr->data > curr->next->data)
            {
                // swap if prev exists
                if (prev)
                {
                    Node *t = curr->next->next;
                    curr->next->next = curr;
                    prev->next = curr->next;
                    curr->next = t;
                    prev = prev->next;
                }
                else{
                    head = curr->next;
                    curr->next = head->next;
                    head->next = curr;
                    prev = head;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return head;
}
