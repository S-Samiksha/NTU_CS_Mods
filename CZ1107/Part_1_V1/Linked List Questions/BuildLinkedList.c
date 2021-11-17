////////////////////////////////////////////////////////////


//#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

void insertNode(ListNode **head, int n);

void main()
{
	ListNode *head, *p, *temp;
	int n;


	head=NULL;
	p=NULL;		// pointing to the last node in the list
	printf("Enter a list of numbers, terminated by the value -1:\n");
	while(n !=-1){
		scanf("%d", &n);
		if (n!=-1){
			insertNode(&head, n);
		}
		
	}
	/////////////////////////////////////////////////////////////////
	printf("Current List: ");
	temp = head;
	while(temp){
		printf("%d ", temp->item);
		temp = temp->next;
	}
	printf("\n");
	//Question 2
    //Write your program code here


   //////////////////////////////////////////////////////////////////
}

void insertNode(ListNode **head, int n){
	ListNode *new_node, *temp;
	if (!(*head)){
		new_node = (ListNode *)malloc(sizeof(ListNode));
		new_node->item = n;
		new_node->next = (*head);
		(*head) = new_node; //not (*head)->next = new_node
	} else if ((*head) && (*head)->next == NULL){  //if there is only the head node 
		new_node = (ListNode *)malloc(sizeof(ListNode));
		new_node->item = n;
		new_node->next = NULL;
		(*head)->next = new_node;
	} else{
		//now you have more than two nodes
		//must traverse to the end 
		temp = (*head);
		while(temp->next){
			temp = temp->next;
		}
		new_node = (ListNode *)malloc(sizeof(ListNode));
		new_node->item = n;
		new_node->next = temp->next;
		temp->next = new_node;

	}
}
