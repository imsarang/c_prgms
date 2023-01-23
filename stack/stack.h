#include <bits/stdc++.h>
#include<string.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        this->next = NULL;
    }
};

class Stack
{
public:
    Node *top;
    int size;

    Stack()
    {
        size = 0;
        this->top = NULL;
    }
    ~Stack()
    {
        size = 0;
    }

    bool isEmpty(){
        return size == 0;
    }
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (top == NULL)
        {
            top = newNode;
            size++;
            return;
        }
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop(){
        if(isEmpty()) return -1;
        Node *ptr = top;
        top = top->next;
        int x = ptr->data;
        delete ptr;
        size--;
        return x;
    }

    int getSize(){
        return size;
    }

    int getTop(){
        return top->data;
    }
};

bool checkBalanced(string expr){
    
    stack<char> s;
    char x;
    int i = 0;
    while(i<expr.length()){
        
        if(expr[i] == '{' || expr[i] == '(' || expr[i] == '['){
            s.push(expr[i]);
        }

        if(s.empty()) return false;

        if(expr[i]==']' || expr[i] == '}' || expr[i] == ')'){
            x = s.top();
            switch (expr[i])
            {
            case '}' : if(x=='{'){ s.pop();} else return false;
                break;
            case ']' : if(x=='['){ s.pop();} else return false;
                break;
            case ')' : if(x=='(') {s.pop();} else return false;
                break;
            }
        }
        i++;
    }
    return s.empty();
}

// Stock span
// find stocks span for each day
int *stockSpan(int *price,int size){
    int *output = new int[size];
    stack<int> s;
    output[0] = 1;
    s.push(0);
    for(int i = 1;i<size;i++){
        while(!s.empty() && price[s.top()] < price[i]){
            s.pop();
        }
        if(s.empty()){
            output[i]  = i+1;
        }
        else output[i] = i-s.top();
        s.push(i);
    }
    return output;
}

// minimum bracket reversal
int minBracketRev(string expr){
    stack<char> s;
    int l = expr.length();
    // odd number
    if(l%2!=0) return -1;

    // even number
    for(int i = 0;i<l;i++){
        if(expr[i] == '{')
            s.push(expr[i]);
        else if (expr[i] == '}' && !s.empty()){
            if(s.top()=='{') s.pop();
            else s.push(expr[i]);
        }
        else s.push(expr[i]);
    }

    int count = 0;
    while(!s.empty()){
        char c1 = s.top();s.pop();
        char c2 = s.top();s.pop();
        if(c1==c2) count++;
        else count+=2;
    }
    return count;
}

// check redundant brackets
bool checkRedundantBrackets(string expr){
    stack<char> s;
    for(int i = 0;i<expr.length();i++){
        if(expr[i] == '('){
            
            if(expr[i+2]==')') return true;

            // only for example like : (a)
            if(!s.empty() && (expr[i-1]=='+' || expr[i-1] == '(')){
                return true;
            }
            s.push('(');
        }
        if(expr[i]==')'){
            if(s.top()=='(')
            s.pop();
        }   
        else return false;
    }

    if(s.empty()) return false;
    else return true;
}