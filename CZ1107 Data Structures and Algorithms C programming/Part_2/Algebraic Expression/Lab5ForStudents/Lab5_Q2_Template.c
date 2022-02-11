#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80 //The limit of expression length

typedef struct _stackNode{
    double item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, double item);
int pop(Stack *sPtr);
double peek(Stack s);
int isEmptyStack(Stack s);

double exePostfix(char*);

int main()
{
    char postfix[SIZE];

    printf("Enter a postfix expression:\n");
    gets(postfix);

    printf("The answer is %.2lf.\n",exePostfix(postfix));

    return 0;
}


double exePostfix(char* postfix)
{
	// Write your code here
    Stack S;
    int i=0;
    double x, y, temp=0;
    S.head = NULL;
    S.size=0;
    for (i=0; i<strlen(postfix); i++){
        if (isalnum(postfix[i])){
            temp = postfix[i]-'0';
            push(&S, temp);
        }else{
            y = peek(S);
            pop(&S);
            x = peek(S);
            pop(&S);
            switch (postfix[i]){
                case '+':
                    temp = x+y;
                    push(&S, temp);
                    break;
                case '-':
                    temp = x-y;
                    push(&S, temp);
                    break;
                case '/':
                    temp = x/y;
                    push(&S, temp);
                    break;
                case '*':
                    temp = x*y;
                    push(&S, temp);
                    break;
                default:
                    break;
            }
        }
    }
    temp = peek(S);
    pop(&S);
    return (double)temp;

}

void push(Stack *sPtr, double item){
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

double peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}
