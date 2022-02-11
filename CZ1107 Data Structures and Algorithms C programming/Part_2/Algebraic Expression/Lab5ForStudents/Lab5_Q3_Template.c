#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 80 //The limit of expression length

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);
int precedence(char symbol);

void in2Pre(char*, char*);

int main()
{
    char infix[SIZE];
    char prefix[SIZE];

    printf("Enter an infix expression:\n");
    gets(infix);

    in2Pre(infix,prefix);
    printf("The prefix expression is \n");
    printf("%s\n",prefix);

    return 0;
}

void in2Pre(char* infix, char* prefix)
{
 // Write your code here
    int i=0, j=0, size;
    char temp;
    Stack S;
    S.head = NULL;
    S.size = 0;
    size = strlen(infix)-1;
    //postfix = malloc((strlen(infix) + 1 ) * sizeof(char));
    for(i=0;i<(size+1)/2;i++){
        temp = infix[i];
        infix[i] = infix[size-i];
        infix[size-i] = temp;
    }
    i=0;
    //printf("%s ", infix);
    for(i=0;i<strlen(infix);i++){
        if (infix[i]=='+' || infix[i]== '-' || infix[i] == '/' || infix[i] == '*'){
            //DO NOT FORGET TO WRITE DOWN PRECEDENCE
            while (!isEmptyStack(S) && peek(S) != ')' && precedence(peek(S))> precedence(infix[i])){
                prefix[j++]=peek(S);
                pop(&S);
            }
            push(&S, infix[i]);
            
        }else if (infix[i] == ')'){
            push(&S, infix[i]);
        }else if (infix[i] == '(' ){
            while (peek(S) != ')' && !isEmptyStack(S)){
                prefix[j]=peek(S);
                pop(&S);
                j++;
            }
            pop(&S);
        }else {
            prefix[j]=infix[i];
            j++;
        }
    }
    while(!isEmptyStack(S)){
        prefix[j]=peek(S);
        pop(&S);
        j++;
    }
    prefix[j]='\0';
    size = strlen(prefix)-1;
    j=0;
    temp = '\0';
    for(j=0;j<(size+1)/2;j++){
        temp = prefix[j];
        prefix[j] = prefix[size-j];
        prefix[size-j] = temp;
    }
    prefix[size+1] = '\0';

}
int precedence(char symbol)
{
	if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void push(Stack *sPtr, char item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}
