/*without the size, just a simple linked list. 
 head --> node 1 --> node 2 --> NULL
you need the pointer of the head pointer 
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;


void printList(ListNode *cur);
ListNode * findNode(ListNode *cur, int index);
int insertNode(ListNode **ptrHead, int index, int item); //pointer of the head pointer 

int removeNode(ListNode **ptrHead,int index);

int main()
{
    ListNode *head=NULL;
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

}

ListNode *findNode(ListNode* cur, int index)
{

}

int insertNode(ListNode **ptrHead, int index, int item){

}

int removeNode(ListNode **ptrHead,int index)
{
/* Write your program code here */
}
