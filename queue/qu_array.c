#include<stdio.h>
#include<stdlib.h>

void insert (int *,int *,int *,int);
int delete(int *,int *,int *);
void display(int *,int *,int *);

int main()
{
    int c=1,choice,ele;
    int front, rear;
    front = rear = -1;
    int queue[100];
    while(c==1)
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Element to be inserted : ");
                scanf("%d",&ele);
                insert(queue,&front,&rear,ele);
                break;
        case 2: printf("%d",delete(queue,&front,&rear));break;
        case 3: display(queue,&front,&rear);break;
        
        default:printf("Enter relevant option!");
            break;
        }
        printf("Want to do more operations?(0/1)");
        scanf("%d",c);
    }
    return 0;
}

void insert(int *queue,int *front,int *rear,int ele)
{
    *front = 0;
    queue[++(*rear)] = ele;
}
int delete(int *queue,int *front,int *rear)
{
    if(*front == -1)
    {
        printf("UNDERFLOW!!");
        return -1;
    }
    else
    {
        int x = queue[*front];
        ++(*front);
        return x;
    }
    
}
void display(int *queue,int *front,int *rear)
{
    int i;
    if(*front == -1)
    {
        printf("No element to display!!");
    }
    else
    {
        for(i=*front;i<=(*rear);i++)
        {
            printf("%d - ",queue[i]);
        }
    }
   
}