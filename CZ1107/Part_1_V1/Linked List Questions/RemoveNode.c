
#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;


void printList(ListNode *cur);
ListNode * findNode(ListNode *cur, int index);
int insertNode(ListNode **ptrHead, int index, int item);

int removeNode(ListNode **ptrHead,int index);

int main()
{
    ListNode *head=NULL; //must remember to initialize the head pointer to null
    int size =0;
    int item;
    int index;

    printf("Enter a list of numbers, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        if(insertNode(&head,size, item)) size++;
    scanf("%*s");

    printList(head);

    while(1){
        printf("Enter the index of the node to be removed: ");
        scanf("%d",&index);

        if(removeNode(&head,index)) //if it is successful, return 1. 
            size--;
        else{
            printf("The node cannot be removed.\n");
            //break;
        }

        printf("After the removal operation,\n");
        printList(head);
    }

    printList(head);
    return 0;
}

void printList(ListNode *cur){
    printf("Current List: ");
    while (cur != NULL){
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}

ListNode *findNode(ListNode* cur, int index) //you are passing in the index here 
{
   if (cur==NULL || index<0)
      return NULL;
   while(index>0){
      cur=cur->next;
      if (cur==NULL)
         return NULL;
      index--;
   }
   return cur;
}

int insertNode(ListNode **ptrHead, int index, int item){
    ListNode  *pre, *newNode;
    // If empty list or inserting first node, update head pointer
    if (index == 0){
        newNode = malloc(sizeof(ListNode)); //you must malloc if you are creating a list and free if you are removing 
        newNode->item = item;
        newNode->next = *ptrHead;
        *ptrHead = newNode;
        return 1;
    }
    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    else if ((pre = findNode(*ptrHead, index-1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = pre->next;
        pre->next = newNode;
        return 1;
    }
    return 0;
}

int removeNode(ListNode **ptrHead,int index)
{
/* Write your program code here */
    //given the find node function, find the previous node and the current node
    ListNode *previous, *current;   
    current = findNode(*ptrHead, index); 
    if (index > 0 && current !=NULL){
        previous = findNode(*ptrHead, index-1);
        previous->next = current->next;
        current->next = NULL;
        free(current);
        return 1;
    }else if (index ==0 && current !=NULL) {
        current = *ptrHead;
        *ptrHead = (*ptrHead)->next;
        free(current);
        return 1;
    } else if (current == NULL) {
        return 0;
    }
    
}
