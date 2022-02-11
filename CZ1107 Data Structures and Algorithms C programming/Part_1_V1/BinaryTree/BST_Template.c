//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
void printBSTPostOrder(BTNode *node);
void printBSTPreOrder(BTNode *node);
void printBSTLevelOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);
BTNode *findMax(BTNode *p);
BTNode *searchNode(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("Inorder: ");
	printBSTInOrder(root);
	printf("\n PostOrder: \n");
	printBSTPostOrder(root);
	printf("\n PreOrder: \n");
	printBSTPreOrder(root);
	printf("\n");

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");


	findMin(root);
	findMax(root);
	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);

	//question 5


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
	// write your code here
	//create a new node first
	//remember this!!!!!!! IMPORTANT 
	BTNode *new_Node;
	new_Node = (BTNode *)malloc(sizeof(BTNode));
	new_Node->item = value;
	new_Node->left = NULL;
	new_Node->right = NULL;

	if (*node == NULL){
		*node = new_Node;
	} else if (value < (*node)->item){
		insertBSTNode(&((*node)->left), value);
	}else if (value > (*node)->item) {
		insertBSTNode(&((*node)->right), value);
	} else{
		printf("Already Exists in the BST \n"); //you need to add this into the code 
		return;
	}
	return;
	
	
	
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
	// write your code here
	//using recursion
	if (!node){
		return;
	}
	else{
		printBSTInOrder(node->left);
		printf("%d ", node->item);
		printBSTInOrder(node->right);
	}
}
void printBSTPostOrder(BTNode *node)
{
	// write your code here
	//using recursion
	if (node == NULL){
		return;
	}
	else{
		if(node->left){ printBSTPostOrder(node->left);}
		if(node->right) {printBSTPostOrder(node->right);}
		printf("%d ", node->item);
	}

}
void printBSTPreOrder(BTNode *node)
{
	// write your code here
	//using recursion
	if (node ==NULL){
		return;
	}
	else{
		printf("%d ", node->item);
		printBSTPreOrder(node->left);
		printBSTPreOrder(node->right);
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
	// write your code here
	//traverse the bst 
	//using recursion 
	int l, r;
	if (node == NULL){
		return 1;

	}
	if (node->item >= max || node->item <=min){
		return 0;
	}

	l=isBST(node->left, min, node->item);
	r=isBST(node->right, node->item, max);
	if (l==1 && r==1){
		return 1;

	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
	// write your code here
	BTNode *p;

	if (node == NULL){
		printf("can't find the value!");
		return node;
	}else if (value > node->item){
		node->right = removeBSTNode(node->right, value);
	}else if (value < node->item){
		node->left = removeBSTNode(node->left, value);
	} else{
		if (node->right ==NULL && node->left == NULL){
			free(node);
			node = NULL;
			return node;
		}else if(node->left ==NULL){
			p = node;
			node = node->right;
			free(p);
			return node;
		}else if(node->right == NULL){
			p = node;
			node = node->left;
			free (p);
			return node;
		}else{
			p = findMin(node->right);
			node->item=p->item;
			node->right = removeBSTNode(node->right, p->item);
			

		}
	}
	return node;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p)
{
	// write your code here
	BTNode *temp;
	temp = p;
	while (temp->left !=NULL){ //note: the condition here
		temp = temp->left;
	}
	printf("Minimum value is %d \n", temp->item);
	return temp;
}

BTNode *findMax(BTNode *p)
{
	// write your code here
	BTNode *temp;
	temp = p;
	while (temp->right !=NULL){ //note: the condition here
		temp = temp->right;
	}
	printf("Maximum value is %d \n", temp->item);
	return temp;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *SearchNode(BTNode *p)
{
	// write your code here

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////