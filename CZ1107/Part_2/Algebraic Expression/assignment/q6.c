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
    int temp_value=0, count =1;
    char *temp;
    BTNode *center, *right, *left;
    temp = prefix;
    S.head = NULL;
    S.size = 0;
    S1.head = NULL;
    S1.size = 0;
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
    while(!isEmptyStack(S)){
        if (peek(S)->item <0){
            center = peek(S);
            pop(&S);
            left = peek(S1);
            pop(&S1);
            right = peek(S1);
            pop(&S1);
            center->left = left;
            center->right = right;
            //printTree(center);
            push(&S1, center);
            
        }else{
            push(&S1, peek(S));
            pop(&S);
        }
    }


    center = peek(S1);
    (*root) = center;

 


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
        printf("%c", (node->item)+'0');
    }else{
        printf("%d", node->item);
    }
    printf(" ");
    
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
        printf("%c", (node->item)+'0');
    }else{
        printf("%d", node->item);
    }
    printf(" ");

}

double computeTree(BTNode *node){
//Write your code here
    char temp_value;
    if (!node){
        return 0;
    } else if (node->left == NULL && node->right == NULL){
        return node->item;
    }else{
        temp_value = (node->item + '0');
        switch(temp_value){
            case '+':
                return computeTree(node->left) 
                + computeTree(node->right);
                break;
            case '/':
                return computeTree(node->left) 
                / computeTree(node->right);
                break;
            case '*':
                return computeTree(node->left) 
                * computeTree(node->right);
                break;
            case '-':
                return computeTree(node->left) 
                - computeTree(node->right);
                break;
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