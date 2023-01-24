#include<iostream>
#include "./ll.h"

using namespace std;

void printLL(Node *head){
    Node *ptr = head;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }