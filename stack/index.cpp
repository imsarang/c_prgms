#include <iostream>
#include "./stack.h"

using namespace std;

void print(Node *top)
{
    Node *ptr = top;
    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    Stack *s = new Stack();
    s->push(10);
    s->push(20);
    s->push(30);
    s->push(50);
    print(s->top);

    // Stack *b = new Stack();
    // cout<<checkBalanced("{{}}");

    // int *input = new int[5];
    // for(int i = 0;i<5;i++){
    //     cin>>input[i];
    // }
    // int *output = stockSpan(input,5);
    // cout<<"OUTPUT : "<<endl;
    // for(int i=0;i<5;i++){
    //     cout<<output[i]<<" ";
    // }

    // cout<<minBracketRev("{{{{{{}}");

    cout<<checkRedundantBrackets("()");
    
}