#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct nhead{
    node *head;
}start;

//basic methods:

void init(start **);
int count(start *);
void insert_front(start **,int);
void insert_rear(start **,int);
void insert_pos(start **,int);
void display(start *);
void delete_front(start **);
void delete_rear(start **);
void delete_pos(start **,int);

node *create_node(node *p,int ele)
{
    p = (node*)malloc(sizeof(node));
    p->data = ele;
    p->next = NULL;
    return p;
}

//extra methods :
// void sort(start **p);
void alt_delete(start **);  

int main()
{
    start *head;
    init(&head);
    
    int choice,ele,cat,pos;int ch=1;
    while(ch==1)
    {
        printf("\n1.Front Insertion\n2.Rear Insertion\n3.Middle Insertion\n4.Front Deletion\n5.Rear Deletion\n6.Middle Deletion\n");
        printf("7.Display\n8.Count the nodes\n9.Alternate deletion\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter element to be inserted : ");
                    scanf("%d",&ele);
                    insert_front(&head,ele);
                    break;
            case 2: printf("Enter element to be inserted : ");
                    scanf("%d",&ele);
                    insert_rear(&head,ele);
                    break;
            case 3: printf("Enter element to be inserted : ");
                    scanf("%d",&ele);
                    insert_pos(&head,ele);
                    break;
            case 4: delete_front(&head);
                    break;
            case 5: delete_rear(&head);
                    break;
            case 6: printf("Enter position to delete the node : ");
                    scanf("%d",&pos);
                    delete_pos(&head,pos);break;
            case 7: display(head);break;
            case 8: printf("Number of nodes : %d",count(head));break;
            case 9: alt_delete(&head);break;
            default : exit(0);
        }
        printf("\nWant to perform more operations?(0/1)\n");
        scanf("%d",&ch);
    }
    return 0;
}


void init(start **p)
{
    (*p) = (start*)malloc(sizeof(start));
    (*p)->head = NULL;
}

int count(start *p)
{
    node *ptr;
    int count = 0;
    if(p->head==NULL) return 0;
    else
    {
        ptr = p->head;
        while(ptr!=NULL)
        {
            ptr = ptr->next;
            count++;
        }
        return count;
    }
}

void insert_front(start **p,int ele)
{
    node *new;
    new = create_node(new,ele);
    if((*p)->head==NULL)
    {
        (*p)->head=new;
    }
    else
    {
        new->next = (*p)->head;
        (*p)->head = new;
    }
}

void insert_rear(start **p,int ele)
{
    node *new,*ptr;
    new = create_node(new,ele);
    if((*p)->head==NULL) (*p)->head = new;
    else
    {
        ptr = (*p)->head;
        while(ptr->next!= NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
}

void insert_pos(start **p,int ele)
{
    node *new,*ptr;
    new = create_node(new,ele);
    int pos,i=1;
    printf("Enter position to enter new node : ");
    scanf("%d",&pos);
    if(pos<=count(*p))
    {
        ptr = (*p)->head;
        while(ptr->next!=NULL && i<pos-1)
        {
            ptr=ptr->next;
            i++;
        }
        new->next = ptr->next;
        ptr->next = new;
    }
    else
    {
        printf("Invalid position!!!");
    }
   
}

void display(start *p)
{
    node *ptr;
    ptr = p->head;
    if(p->head == NULL) printf("EMPTY!!");
    else
    {
        while(ptr!=NULL)
        {
            printf("%d -> ",ptr->data);
            ptr = ptr->next;
        }
    }
}

void delete_front(start **p)
{
    node *ptr;
    if((*p)->head == NULL) printf("UNDERFLOW!!");
    else
    {
        ptr = (*p)->head;
        (*p)->head = (*p)->head->next;
        free(ptr);
    }
}

void delete_rear(start **p)
{
    node *ptr;
    if((*p)->head == NULL) printf("UNDERFLOW!!");
    else
    {
        ptr = (*p)->head;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        free(ptr);
    }
} 

void delete_pos(start **p,int pos)
{
    node *ptr,*prev;
    prev=NULL;
    int i = 1;
    if((*p)->head == NULL) printf("UNDERFLOW!!!");
    else
    {
        if(pos<=count(*p))
        {
            ptr = (*p)->head;
            while(ptr->next!=NULL&&i<pos)
            {
                prev=ptr;
                ptr=ptr->next;
                i++;
            }
            prev->next = ptr->next;
            free(ptr);
        }
        else
        {
            printf("Invalid Position!!");
        }
        
    }
}

void alt_delete(start **p)
{
    node *ptr,*prev;
    prev = NULL;
    if((*p)->head == NULL) printf("UNDERFLOW!!!");
    else
    {
        ptr = (*p)->head;
        printf("Hello");
        while(ptr!=NULL)
        {
            prev = ptr->next;
            ptr = prev->next;
            free(prev);
        }
    }
}