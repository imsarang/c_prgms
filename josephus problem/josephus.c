#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

void init(node **p)
{
    *p = NULL;
}

void insert(node **,node **,int,int);
int josephus(node **,node **,int,int);
void display(node *,node *);

int main()
{
    int n,skip;
    node *front,*rear;
    init(&front);init(&rear);
    printf("\nEnter number of soldiers : ");
    scanf("%d",&n);
    printf("\nSoldier to be shot everytime : ");
    scanf("%d",&skip);
    printf("\nSoldier that is shot is always %d from the next surviving soldier!\n",skip);
    insert(&front,&rear,n,skip);
    display(front,rear);
    
    printf("\n%d survives",josephus(&front,&rear,n,skip));
    return 0;
}

void insert(node **f,node **r,int n,int skip)
{
    node *new;int i = 0;
    while(i<n)
    {
        new = (node*)malloc(sizeof(node));
        printf("Enter soldier number : ");
        scanf("%d",&(new->data));
        new->next = NULL;

        if(*f==NULL)
        {
            *f = *r = new;
            new->next = *f;
        }
        else
        {
            (*r)->next = new;
            (*r) = (*r)->next;
            new->next = *f;
        }

        i++;
    }
}

void display(node *f,node *r)
{
    node *ptr;
    if(f==NULL)
        printf("NO ELEMENT TO DISPLAY !");
    else
    {
        ptr = f;
        do
        {
            printf("%d - ",ptr->data);
            ptr = ptr->next;
        } while (ptr!=f);
        
    }
}

int josephus(node **f,node **r,int n,int skip)
{
    node *p,*q;int i;
    p = *f;
    while(p!=p->next)
    {
        for(i=0;i<skip;i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        free(p);
        p=p->next;
    }

    *f = p;
    int ele = p->data;
    return ele;
}