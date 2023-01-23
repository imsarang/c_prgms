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
    createLL(&head,30);
    createLL(&head,40);
    createLL(&head,50);
    createLL(&head,20);
    createLL(&head,10);
    cout<<"Original List : "<<endl;
    printLL(head);

    cout<<"Edited List : "<<endl;
    // Node *headRev = reverseLL(head);
    // Node *headRevRec = reverseLLRecursion(head);
    // printLL(headRev);
    // printLL(head);
    // printLL(headRevRec);
    // Node *headKRev = reverseKNodes(head,2);
    // printLL(headKRev);

    Node *bubbleSortLL = bubbleSort(head);
    printLL(bubbleSortLL);

    return 0;
}