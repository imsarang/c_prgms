#include<iostream>
#include "./ll.h"

using namespace std;

void printLL(Node *head){
    Node *ptr = head;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
    Node *head = NULL;
    createLL(&head,10);
    createLL(&head,20);
    createLL(&head,30);
    createLL(&head,40);
    createLL(&head,50);
    printLL(head);
    // Node *headRev = reverseLL(head);
    Node *headRevRec = reverseLLRecursion(head);
    // printLL(headRev);
    // printLL(head);
    printLL(headRevRec);
    return 0;
}