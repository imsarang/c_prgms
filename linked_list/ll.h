#include<bits/stdc++.h>
using namespace std;
class Node{
    public : 
    int data;
    Node *next;
    Node (int data){
        this->data = data;
        this->next = NULL;
    }
};

void createLL(Node **head,int data){
    if(*head==NULL){
        Node *ptr = new Node(data);
        *head = ptr;
        return;
    }
    Node *newNode = new Node(data);
    Node *ptr = *head;
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

Node* reverseLL(Node *head){
    Node *r=NULL,*q=NULL,*p = head;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    return q;
}

Node *reverseLLRecursion(Node *head){
    if(head==NULL || head->next==NULL) return head;

    Node *ptr = reverseLLRecursion(head->next);
    Node *temp = head->next;
    temp->next = head;
    head->next = NULL;
    return ptr;
}

// Reverse after every k nodes
Node *reverseKNodes(Node *head){
    
}