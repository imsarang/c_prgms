#include<string.h>

void mySwap(char *x,char *y){
    char temp =*x;
    *x = *y;
    *y = temp;
}
// reverse word wise
// first reverse the entire input string and then reverse each word according to spaces in the input string
// take z = i-1 if input[i]!='\0'
// k = i+1 after reversing one word

void reverseWordWise(char input[],int n){
    int i,z,k=0,j=strlen(input)-1;
    for(int i = 0;i<j;i++){
        mySwap(&input[i],&input[j]);
        j--;
    }

    for(int i = 0;input[i]!='\0';i++){
        if(input[i+1] == '\0') z = i;
        else z = i-1;

        if(input[i] == ' ' || input[i+1]=='\0'){
            while(z>=k){
                mySwap(&input[z],&input[k]);
                z--;
                k++;
            }
            k = i+1;
        }
    }
}
