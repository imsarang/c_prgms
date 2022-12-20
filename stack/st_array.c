#include<stdio.h>
#include<stdlib.h>

//Array method:
void push(int *,int *,int);
int pop(int *,int *);
void display(int *,int *);
int main()
{
    int choice,c=1,ele,info;
    int stk[100];
    int top = -1;
    while(c==1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Element to be inserted : ");
                    scanf("%d",&ele);
                    push(stk,&top,ele);break;
            case 2: info = pop(stk,&top);
                    printf("Popped element : %d",info);break;
            case 3: display(stk,&top);break;
            default : printf("Enter valid option number!!");break;
        }
        printf("\nWant to do more stack operations?(0/1)\n");
        scanf("%d",&c);
    }
    return 0;
}

void push(int *stk,int *top,int ele)
{
    stk[++(*top)] = ele;
}

int pop(int *stk,int *top)
{
    if((*top)==-1)
        printf("UNDERFLOW!! CANNOT POP!!");
    else
    {
        int x = stk[(*top)];
        --(*top);
        return x;
    }
    
}

void display(int *stk,int *top)
{

    if((*top)==-1)
        printf("No elements to display!!");
    else
    {
        for(int i = 0;i<=(*top);i++)
        {
            printf("%d - ",stk[i]);
        }
    }
    
}