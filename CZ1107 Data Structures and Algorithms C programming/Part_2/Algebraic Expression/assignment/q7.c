#include <stdio.h>
#include <stdlib.h>


#define SIZE 80 //The size of the array

enum ExpType {OPT,OPERAND};

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

typedef struct _listnode
{
    int  item;
    enum ExpType type;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item,enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);


void in2PreLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExp);

int main()
{
    char infix[SIZE];

    //printf("Enter an infix expression:\n");
    scanf("%s",infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    in2PreLL(infix, &inExpLL);

    printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}

void in2PreLL(char* infix, LinkedList *inExpLL)
{
  //Write your code here
  char *end;
  char temp;
  int number=0, i=0;
  Stack S;
  S.head = NULL;
  S.size = 0;
  end = infix;
  while (*end != '\0'){
      end++;
      number++;
  }
  //from the above we got the size!
  //now we have to get the last index which is size - 1 for ease of use, keep the variable name
  number--;
  //now to reverse the infix 
  for(i=0;i<(number+1)/2;i++){
        temp = infix[i];
        infix[i] = infix[number-i];
        infix[number-i] = temp;
    }
    i=1;
    end = infix;
    number = 0;
    // to check print infix
    //printf("%s ", infix);
    //once we know it works, time to implement infix to prefix algorithm
    while(*end != '\0'){
        if (*end=='+' || *end== '-' || *end== '/' || *end== '*'){
            //DO NOT FORGET TO WRITE DOWN PRECEDENCE
            if (number != 0){
                insertNode(inExpLL, number, OPERAND);
                number =0;
                i =1;
            }
            while (!isEmptyStack(S) && peek(S) != ')' 
            && precedence(peek(S))> precedence(*end)){
                insertNode(inExpLL, peek(S), OPT);
                pop(&S);
            }
            push(&S, *end);
            
        }else if (*end== ')'){
            if (number != 0){
                insertNode(inExpLL, number, OPERAND);
                number =0;
                i =1;
            }
            push(&S, (*end));
        }else if ((*end) == '(' ){
            if (number != 0){
                insertNode(inExpLL, number, OPERAND);
                number =0;
                i =1;
            }
            while (peek(S) != ')' && !isEmptyStack(S)){
                insertNode(inExpLL, peek(S), OPT);
                pop(&S);
            }
            pop(&S);
        }else{
            number += ((*end) - '0')*i;
            i *=10;
        }
        end++;

    }

    if (number != 0){
                insertNode(inExpLL, number, OPERAND);
                number =0;
                i =1;
    }
    
    while(!isEmptyStack(S)){
        insertNode(inExpLL, peek(S), OPT);
        pop(&S);
    }
    
    

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

void printExpLL(LinkedList inExpLL)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item);
        else
            printf(" %c ",(char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if(newNode==NULL) exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head=newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
    if(LLPtr==NULL || LLPtr->size==0){
        return 0;
    }
    else{
       ListNode *temp = LLPtr->head;
       LLPtr->head = LLPtr->head->next;

       free(temp);
       LLPtr->size--;
       return 1;
    }
}

int isEmptyLinkedList (LinkedList ll) {
    if(ll.size==0) return 1;
    else return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
	while(deleteNode(LLPtr));
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