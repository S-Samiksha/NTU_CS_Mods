////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////


typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;

} BTNode;

////////////////////////////////////////////////////////////////////


void mirrorTree(BTNode *node);

void printSmallerValues(BTNode *node, int m);
int smallestValue(BTNode *node);
int largestValue(BTNode *node);
int hasGreatGrandchild(BTNode *node);

void printTree_InOrder(BTNode *node);
////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]){

	int i;
	BTNode *root, *root2;
	BTNode btn[15];

	// Create the tree in Q1
	// Using manual dynamic allocation of memory for BTNodes

	root = malloc(sizeof(BTNode));
	root->item = 4;

	root->left = malloc(sizeof(BTNode));
	root->left->item = 5;

	root->right = malloc(sizeof(BTNode));
	root->right->item = 12;

	root->left->left = malloc(sizeof(BTNode));
	root->left->left->item = 10;

	root->left->left->right = NULL;
	root->left->left->left = malloc(sizeof(BTNode));
	root->left->left->left->item = 9;

	root->left->left->left->right = NULL;
	root->left->left->left->left = NULL;

	root->left->right = malloc(sizeof(BTNode));
	root->left->right->item = 6;

	root->left->right->left = NULL;
	root->left->right->right = NULL;

	root->right->left = malloc(sizeof(BTNode));
	root->right->left->item = 3;

	root->right->right = malloc(sizeof(BTNode));
	root->right->right->item = 2;

	root->right->left->left = NULL;

	root->right->left->right = NULL;

	root->right->right->left = NULL;

	root->right->right->right = NULL;

	printTree_InOrder(root);
	printf("\n");
	mirrorTree(root);
	printTree_InOrder(root);
	printf("\n\n");

	//question 2
	printf("\n input m for question 2:");
	scanf("%d", &i);
	printf("the values smaller than %d are:", i);
	printSmallerValues(root, i);
	printf("\n\n");

	//question 3
	printf("The smallest value in the tree is: %d\n", smallestValue(root));
	printf("The largest value in the tree is: %d\n", largestValue(root));

	//question 4
	// Create a tree for Q4: Tall enough so some nodes have great-grandchildren
	// Use array of BTNodes, create tree by linking nodes together
	for (i = 0; i <= 6; i++){
		btn[i].item = i;
		btn[i].left = &(btn[i * 2 + 1]);
		btn[i].right = &(btn[i * 2 + 2]);
	}

	for (i = 7; i <= 14; i++){
		btn[i].item = i;
		btn[i].left = NULL;
		btn[i].right = NULL;
	}
	root2 = &btn[0];

	printf("The tree for question 4 visited by in-order is \n");
	printTree_InOrder(root2);
	printf("\nthe values stored in all nodes of the tree that have at least one great-grandchild are: ");

	hasGreatGrandchild(root);

	return 0;
}

void mirrorTree(BTNode *node){

	// write your code here
	BTNode *temp;
	//temp->left = NULL;
	//temp->right = NULL;
	if (node == NULL){
		return;
	}else{
		temp = node->left;
		node->left = node->right;
		node->right = temp;
		mirrorTree(node->left);
		mirrorTree(node->right);
		

	}

}

int hasGreatGrandchild(BTNode *node){
	//calculate the maxdepth of each node, if it is more than 3 than you print the node
	// write your code here
	if (node == NULL){ //itself doesnt exist 
		return 0;
	} 
	if(node->left->right->left != NULL || node->left->right->right != NULL || 
	      node->left->left->left != NULL || node->left->left->right != NULL ||
          node->right->right->left != NULL ||node->right->right->right != NULL ||
		  node->right->left->left !=NULL || node->right->left->left !=NULL){
				printf("%d ", node->item);
				return 1;
	}
	else{
		return 0;
	}
	hasGreatGrandchild(node->left);
	hasGreatGrandchild(node->right);

}

void printSmallerValues(BTNode *node, int m){

	// write your code here
	if (node ==NULL){
		return;
	}
	else{
		printSmallerValues(node->left, m);
		if (node->item < m){
			printf("%d ", node->item);
		}
		printSmallerValues(node->right, m);
	}
}

int smallestValue(BTNode *node) {
	int l=0, r=0, min;

	// write your code here
	if (node == NULL){
		return 1000;
	}
	else{
		l = smallestValue(node->left);
		r = smallestValue(node->right);
		min = l<r ? l:r;
		min = min<(node->item) ? min:(node->item);
		return min;
	}

}
int largestValue(BTNode *node) {
	int l=0, r=0, max;

	// write your code here
	if (node == NULL){
		return -1;
	}
	else{
		l = largestValue(node->left);
		r = largestValue(node->right);
		max = l>r ? l:r;
		max = max>(node->item) ? max:(node->item);
		return max;
	}

}



//////////////////////////////////////////////////////////////////

void printTree_InOrder(BTNode *node){
//using iterative
if (!node){
		return;
	}
	else{
		printTree_InOrder(node->left);
		printf("%d ", node->item);
		printTree_InOrder(node->right);
	}

}
