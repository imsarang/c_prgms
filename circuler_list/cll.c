#include<stdio.h>
#include<stdlib.h>

typedef struct cll
{
    int data;
    struct cll *next;
}node;

void init(node **p)
{
    *p = NULL;
}

void insert(node **,node **,int);
void delete(node **,node **);
void display(node *,node *);

int main()
{
    node *front,*rear;
    init(&front);init(&rear);
    int c=1,choice,ele;
    while(c==1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter element to insert : ");
                    scanf("%d",&ele);
                    insert(&front,&rear,ele);break;
            case 2: delete(&front,&rear);break;
            case 3: display(front,rear);break;
            default : printf("\nEnter a valid option!");break;
        }
        printf("\nWant to perform more operations?(0/1)");
        scanf("%d",&c);
    }
    return 0;
}

void insert(node **front,node **rear,int ele)
{
    node *new,*ptr;
    new = (node*)malloc(sizeof(node));
    new->data = ele;
    new->next = NULL;
    if((*front) == NULL)
    {
        *front = *rear = new;
        new->next = *front;        
    }
    else
    {
        (*rear)->next = new;
        (*rear) = (*rear)->next;
        new->next = *front;
    }
}

void display(node *front,node *rear)
{
    node *ptr;
    if(front==NULL)
        printf("\nNO ELEMENTS TO DISPLAY!!!");
    else
    {
        ptr = front;
        do
        {
            printf("%d ->",ptr->data);
            ptr = ptr->next;
        } while (ptr != front);    
    }
}

void delete(node **front,node **rear)
{
    if((*front)==NULL)
        printf("\nUNDERFLOW!!");
    else
    {
        (*rear)->next = NULL;
        int x;
        x = (*front)->data;
        node *ptr;
        ptr = (*front);
        (*front) = ptr->next;
        free(ptr);
        (*rear)->next = *front;
        printf("\nElement deleted : %d",x);
    }
    
}