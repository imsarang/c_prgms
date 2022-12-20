#include<stdio.h>
#include<stdlib.h>

typedef struct Snode
{
    struct Snode *next;
    int data;
}node;

void initialize(node **p)
{
    *p = NULL;
}


void push(node **p,int info);
int pop(node **p);
// int count(node *p);
void display(node *p);
// int peek(node **p);

int main()
{
    node *head;
    initialize(&head);
    int choice,c=1,info,ele;
    while(c==1)
    {
        printf("\nMENU : ");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.Display\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter info : ");
        scanf("%d",&info); 
        push(&head,info);
            break;
        case 2:
            ele = pop(&head);
            printf("\nElement popped : %d",ele);
            break;
        case 3:
            display(head);
            break;
        
        default:exit(0);
            break;
        }
        printf("\nMENU AGAIN?(0/1)");
        scanf("%d",&c);
    }
    return 0;
}

void push(node **p,int info)
{
    
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = info;
    newnode->next = NULL;
   
    node *ptr;
    
    if(*p == NULL)
    {
        *p = newnode;
    }
    else
    {
        newnode->next = (*p);
        *p = newnode;
    }
    
}

int pop(node **p)
{
    node *ptr;
    int x;
    if(*p == NULL)
    {
        printf("UNDERFLOW!!");
        return ;
    }
    else
    {
        ptr = *p;
        *p = ptr->next;
        ptr->next = NULL;
        x = ptr->data;
        free(ptr);
        return x;
    }
}

void display(node *p)
{
    node *ptr;
    ptr = p;
    if(p == NULL)
    {
        printf("No element to display!!");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d - ",ptr->data);
            ptr = ptr->next;
        }
    }
    
}