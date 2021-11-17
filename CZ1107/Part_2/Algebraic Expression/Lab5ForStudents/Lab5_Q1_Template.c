#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void in2Post(char*, char*);

int main()
{
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter an infix expression:\n");
    gets(infix);

    in2Post(infix,postfix);
    printf("The postfix expression is \n");
    printf("%s\n",postfix);
    return 0;
}

void in2Post(char* infix, char* postfix)
{
// Write your code here
    int i=0, j=0;
    Stack S;
    S.head = NULL;
    S.size = 0;
    //postfix = malloc((strlen(infix) + 1 ) * sizeof(char));
    for(i=0;i<strlen(infix);i++){
        if (isalpha(infix[i])||isalnum(infix[i])){
            postfix[j]=infix[i];
            j++;
        }else if (infix[i] == '('){
            push(&S, infix[i]);
        }else if (infix[i] == ')' ){
            while (peek(S) != '('){
                postfix[j]=peek(S);
                pop(&S);
                j++;
            }
            pop(&S);
        }else{

            while (!isEmptyStack(S) && peek(S) != '(' && precedence(peek(S))>=precedence(infix[i])){
                postfix[j]=peek(S);
                pop(&S);
                j++;
            }
            push(&S, infix[i]);
            
        }
    }
    while(!isEmptyStack(S)){
        postfix[j]=peek(S);
        pop(&S);
        j++;
    }
    postfix[j] = '\0';

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
