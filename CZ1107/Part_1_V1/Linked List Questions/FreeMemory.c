////////////////////////////////////////////////////////////

//#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

//////////////////////////////////////////////////////

int searchList(ListNode *head, int value);
void insertNode(ListNode **head, int n);

//////////////////////////////////////////////////////

void main()
{
	ListNode *head, *p, *temp;
	int n;


	head=NULL;
	p=NULL;		// pointing to the last node in the list
	printf("Enter a list of numbers, terminated by the value -1:\n");

 ////////////////////////////////////////////////////////////////////

 // Question 2
 //Write your program code here
	while(n !=-1){
			scanf("%d", &n);
			if (n!=-1){
				insertNode(&head, n);
			}
			
		}
	printf("Current List: ");
	temp = head;
	if (head == NULL){ 
		printf("Empty");
	}else{
		while(temp){
			printf("%d ", temp->item);
			temp = temp->next;
		}
		printf("\n");
	}

//////////////////////////////////////////////////////////////////////

//search for a value in the list. Q3

	printf("Enter value to search for:");
	scanf("%d", &n);
	searchList(head,n);

/////////////////////////////////////////////////////////

    //free up memory for question 4
	//this part is wrong. It will cause problems.
/*	p = head;
	while (p!= NULL) {
		free(p);
		p=p->next;
	}
*/


    // Question 4
	//rewrite the free up using temporary pointer temp.
	p = head;
	while (p) {
		temp = p;
		p=p->next;
		free(temp);
	}
	head = NULL; //must do this!
	
	printf("Current List: ");
	if (!head){ 
		printf("Empty \n");
	}

/////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////



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

int searchList(ListNode *head, int value)
{

////////////////////////////////////////////////////////////////////

 // Question 3
 //Write your program code here
	ListNode *temp;
	int index =0;
	temp = head;
	while(temp){
		if (temp->item == value){
			printf("Value %d found at index %d \n", value, index);
			return 1;
		}
		index++;
		temp = temp->next;
	}
	printf("Value %d not found! \n", value);


//////////////////////////////////////////////////////////////////////
}
