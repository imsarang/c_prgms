#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

void enter(int data,node **front,node **rear);
int delete(node **front,node **rear);
void display(node **front,node **rear);
void initialize(node **p)
{
    (*p)=NULL;
}
int main()
{
    node *front;
    initialize(&front);
    node *rear;
    rear = NULL;
    int choice,c=1,data;
    while(c==1)
    {
        printf("\n1.Enter queue\n2.Delete \n3.Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                printf("\nEnter info : ");
                scanf("%d",&data);
                enter(data,&front,&rear);
                break;
            case 2: printf("Element deleted : %d",delete(&front,&rear));
                break;
            case 3: display(&front,&rear);
                break;
            default : exit(0);
        }
        printf("\nWant to enter more?(0/1)");
        scanf("%d",&c);
    }
    return 0;
}

void enter(int data,node **front,node **rear)
{
    node *new;
    new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    if((*front)==NULL)
    {
        (*front)=new;
    }
    
    else
    {
        *rear = *front;
        while((*rear)->next != NULL)
        {
            (*rear) = (*rear)->next;
        }
        (*rear)->next = new;
        *rear = new;
    }   
}

int delete(node **front,node **rear)
{
    int x;
    if((*rear)==(*front))
    {
        printf("UNDERFLOW!!");
        return 0;
    }
    else
    {
        x = (*front)->data;
        (*front)=(*front)->next;
        return x;
    }
}

void display(node **front,node **rear)
{
    node *ptr;
    if(*front==*rear)
    {
        printf("NO NODES TO DISPLAY!!!");
    }
    else
    {
        ptr = *front;
        while(ptr!=(*rear))
        {
            printf("%d->",ptr->data);
            ptr = ptr->next;
        }
        printf("%d",ptr->data);
    }
}