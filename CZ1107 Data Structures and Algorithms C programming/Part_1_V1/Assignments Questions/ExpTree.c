#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200 //The number digit limitation

typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

typedef struct _node{
     BTNode* item;
     struct _node *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode** root,char* prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);
BTNode* createNode(int item);
int precedence(char symbol);

void push(Stack *sPtr,  BTNode* item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

int main()
{
    char prefix[SIZE];
    BTNode* root=NULL;

    //printf("Enter an prefix expression:\n");
    scanf("%[^\n]s",prefix);

    createExpTree(&root, prefix);

    // printf("The Infix Expression:\n");
    printTree(root);
    printf("\n");
    //printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");
    //printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

void createExpTree(BTNode** root,char* prefix)
{
 //Write your code here
 //from preorder tree traversal to Binary tree
    Stack S, S1;
    int temp_value=0, count =1, i=0;
    char *temp;
    BTNode *center, *right, *left;
    temp = prefix;
    S.head = NULL;
    S.size = 0;
    S1.head = NULL;
    S1.size = 0;

    if (!prefix){
        return;
    }

    while (*temp != '\0'){
      temp++;
      temp_value++;
    }
  //from the above we got the size!
  //now we have to get the last index which is size - 1 for ease of use, keep the variable name
  temp_value--;
  //now to reverse the infix
  for(i=0;i<(temp_value+1)/2;i++){
        temp = prefix[i];
        prefix[i] = prefix[temp_value-i];
        prefix[temp_value-i] = temp;
    }
    prefix[temp_value+1] = '\0';
    temp_value = 0;
    temp = prefix;
    while(*temp != '\0'){
        switch(*temp){
            case '-':
            case '+':
            case '/':
            case '*':
                push(&S, createNode(*temp -'0'));
            case ' ':
                if (temp_value != 0){
                    push(&S, createNode(temp_value));

                }
                temp_value =0;
                count =1;
                break;
            default:
                temp_value += ((*temp)-'0')*count;
                count *=10;
                break;
        }
        temp++;
    }
    if (temp_value != 0){
        push(&S, createNode(temp_value));
    }

    temp_value =0;
    count =1;
    //printf("Pushed to stack\n");
    //reverse stack
    while(!isEmptyStack(S)){

        push(&S1, peek(S));
        pop(&S);
        printf("%d ", peek(S1)->item);

    }
    printf("reversed stack \n");

    while(!isEmptyStack(S1)){
        if (peek(S1)->item <0){
            center = peek(S1);
            pop(&S1);
            if (!isEmptyStack(S)){
                 left = peek(S);
                pop(&S);
                center->left = left;
            }else{
                left = peek(S1);
                pop(&S1);
                center->left = left;
            }
            if (!isEmptyStack(S)){
                right = peek(S);
                pop(&S);
                center->right = right;
            }else{
                right = peek(S1);
                pop(&S1);
                center->right = right;
            }
            if (precedence(right->item)==precedence(left->item)){
                center->left, center->right =
                center->right, center->left;
            }


            //printTree(center);
            push(&S, center);

        }else{
            push(&S, peek(S1));
            pop(&S1);
        }
    }


    center = peek(S);
    (*root) = center;




}

int precedence(char symbol)
{
    symbol += '\0';

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

BTNode* createNode(int item){
    BTNode *new_node;
    new_node = malloc(sizeof(BTNode));
    new_node->item = item;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

void printTree(BTNode *node){
    //Write your code here
    if (node == NULL){
        return;
    }

    printTree(node->left);
    if (node->item <= 0){
        printf("%c ", (node->item)+'0');
    }else{
        printf("%d ", node->item);
    }

    printTree(node->right);
}


void printTreePostfix(BTNode *node){
   //Write your code here
       if (node == NULL){
        return;
    }

    printTreePostfix(node->left);
    printTreePostfix(node->right);
    if (node->item <= 0){
        printf("%c ", (node->item)+'0');
    }else{
        printf("%d ", node->item);
    }

}

double computeTree(BTNode *node){
//Write your code here
    char temp_value;
    double temp;
    if (!node){
        return 0.00;
    } else if (node->left == NULL && node->right == NULL
            && node->item >0){
        return (double)node->item;
    }else{
        temp_value = (node->item + '0');
        switch(temp_value){
            case '+':
                temp = computeTree(node->left)
                + computeTree(node->right);
                return temp;
            case '/':
                temp = computeTree(node->left)
                / computeTree(node->right);
                //printf("%f ", temp);
                return temp;
            case '*':
                temp = computeTree(node->left)
                * computeTree(node->right);
                return temp;
            case '-':
                temp = computeTree(node->left)
                - computeTree(node->right);
                return temp;
            default:
                return 0.00;
        }

    }



}

void push(Stack *sPtr, BTNode *item){
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

BTNode *peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void deleteTree(BTNode **root){
    BTNode* temp;
    if(*root !=NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}

