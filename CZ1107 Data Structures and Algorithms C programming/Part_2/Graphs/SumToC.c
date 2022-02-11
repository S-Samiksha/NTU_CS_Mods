#include <stdio.h>
#include <stdlib.h>

typedef struct _arraynode
{
    int *itemArray;
    int sizeArray;
    struct _arraynode *next;
}ArrayNode;

typedef struct _arraylist{
   int size; //the size of a possible sequence
   ArrayNode *head;
} ArrayList;

typedef struct _listnode
{
    int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int sum; //the number of possible sequences
   int size;
   ListNode *head;
} LinkedList;

// You should not change the prototypes of these functions
//////LinkedList///////////////////////////////////////////
int insertNode(LinkedList *ll, int index, int coin);
int removeNode(LinkedList *ll, int index);
ListNode *findNode(LinkedList ll, int index);
void removeAllItems(LinkedList *ll);
///////////////////////////////////////////////////

void sumToC(LinkedList* ll, int C, ArrayList* al);
int main()
{
    int C;
    printf("Enter a number:\n");
    scanf("%d",&C);

    LinkedList ll;
    ll.head = NULL;
    ll.sum = 0;
    ll.size = 0;
    ArrayList al;
    al.head = NULL;
    al.size = 0;

    sumToC(&ll,C,&al);
    ArrayNode* temp;
    int i,j;
    temp = al.head;
    for(i=0;i<al.size;i++){
        for(j=0;j<temp->sizeArray;j++)
            printf(" %d ",temp->itemArray[j]);
        printf("\n");
        temp = temp->next;
    }

    return 0;
}

void sumToC(LinkedList* ll, int C, ArrayList* al)
{
   // Write your code here
	int i=0, exists=1, val;
	int *num, *temparr;
	ArrayNode *temp, *temp2;
	ListNode *tempNode;
	tempNode = ll->head;
	if (ll->sum == C){
		num = (int *) malloc((ll->size) * sizeof(int)); 
		temparr = num;
		tempNode = ll->head;
		while(tempNode !=NULL){
			*temparr = tempNode->item;
			tempNode = tempNode->next;
			temparr++;
		}
		temp = (ArrayNode*) malloc(sizeof(ArrayNode)); 
		temp->itemArray = num;
		temp->sizeArray = ll->size;
		temp->next = NULL;
		if (al->size == 0){
			al->head = temp;

		}else{
			temp2 = al->head;
			while(temp2->next !=NULL){
				temp2 = temp2->next;
			}
			temp2->next = temp;

		}
		(al->size) += 1;
		return;
	}else if (ll->sum>C){ 
		return;
	}
	if (ll->size >0){
		tempNode = ll->head;
		while(tempNode->next !=NULL){
			tempNode= tempNode->next;
		}
		val= tempNode->item;
		

	}else{
		val =1;
	}
	
	for(i=val;i<=C;i++){
		tempNode = ll->head;
		exists=0;
		while(tempNode!=NULL){
			if (tempNode->item == i){
				exists = 1;
				break;
			}
			tempNode= tempNode->next;
		}
		if (exists == 0){
			insertNode(ll, ll->size, i);//add the new index 
			sumToC(ll, C, al); //find the next round 
			removeNode(ll, (ll->size-1));
			
		}
		
		
	}


	
	




	
	
	

	


}
///////////////////////////////////////////////////////
int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size)
		return 0;

        if (index == 0){
		cur = ll->head;
		ll->head = (ListNode*) malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->sum += value;
		ll->size++;
		return 1;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->sum += value;
		ll->size++;
		return 1;
	}

	return 0;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index > ll->size)
		return 0;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		ll->sum -= ll->head->item;
		free(ll->head);
		ll->head = cur;
		ll->size--;
		return 1;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(*ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return 0;

		cur = pre->next;
		ll->sum -= cur->item;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 1;
	}

	return 0;
}

ListNode *findNode(LinkedList ll, int index){

	ListNode *temp;

	if (index < 0 || index >= ll.size)
		return NULL;

	temp = ll.head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
	ll->sum =0;
}