
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
    ListNode *head=NULL; //creating a head node that points to nth
    //head = address of the new node 
    int size =0;
    int item;
    int index;

    printf("Enter a list of numbers, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        if(insertNode(&head,size, item)) size++; //passing pointer to the head pointer 
    scanf("%*s");

    printList(head);

    while(1){
        printf("Enter the index of the node to be removed: ");
        scanf("%d",&index);

        if(removeNode(&head,index))
            size--;
        else{
            printf("The node cannot be removed.\n");
            break;
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

ListNode *findNode(ListNode* cur, int index)
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

int insertNode(ListNode **ptrHead, int index, int item){ //when you put &head, it becomes *head. so it is address of the head 
    ListNode  *pre, *newNode;
    // If empty list or inserting first node, update head pointer
    if (index == 0){
        newNode = malloc(sizeof(ListNode)); //allocating memory for this newNode
        newNode->item = item; //storing the item value into the new node item 
        newNode->next = *ptrHead; // *ptrhead is pointing to NULL value, so next will point to NULL
        *ptrHead = newNode; //now the new head points to new node  so you are modifiying the value in the head address
        return 1;
    }

    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    else if ((pre = findNode(*ptrHead, index-1)) != NULL){ //through the findnode function you are finding the previous node, return the previous node to the prev var
    // then you check whether pre is null in the first place or not 
        newNode = malloc(sizeof(ListNode)); 
        newNode->item = item; //assign the item in the new node as the item given
        newNode->next = pre->next; //the new node now points to the previous one's next aka NULL
        pre->next = newNode; // previous now points to the newNode.
        return 1;
    }
    return 0;


}

int removeNode(ListNode **ptrHead,int index)
{
/* Write your program code here */

    //must find the prev node to the delete node 
    //the prev node point to next of next 
    //break linkage 
    ListNode *pre, *next, *cur;
    pre = findNode(*ptrHead, index-1);
    cur = findNode(*ptrHead, index);
    next = findNode(*ptrHead, index+1);
    if (cur == NULL){ //remember this condition!!
        return 0;
    }
    else if(cur == *ptrHead){
        *ptrHead = next;
        free (cur);
    }
    else {
        pre->next = next;
        cur->next = NULL; 
        free(cur); //must free the memory space 
        return 1; 
    }
    
    

}
