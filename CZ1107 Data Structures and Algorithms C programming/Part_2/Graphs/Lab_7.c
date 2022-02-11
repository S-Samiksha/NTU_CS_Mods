#include <stdio.h>
#include <stdlib.h>

enum GraphType {ADJ_MATRIX, ADJ_LIST}; // Types of Graph Representation

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;

union GraphForm{
    int **matrix;
    ListNode **list;
};

typedef struct _graph{
    int V;
    int E;
    enum GraphType type;
    union GraphForm adj;
}Graph;

void printGraphMatrix(Graph );
void adjM2adjL(Graph *);
void adjL2adjM(Graph *);
void printGraphList(Graph );
void calDegreeV(Graph,int *);
void printDegreeV(int *,int );

int main()
{
    Graph g;
    int i,j;

    int* degreeV;

    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

    g.E = 0;
    g.adj.matrix = (int **)malloc(g.V*sizeof(int *));
    for(i=0;i<g.V;i++)
        g.adj.matrix[i] = (int *)malloc(g.V*sizeof(int));

    for(i=0;i<g.V;i++)
        for(j=0;j<g.V;j++)
            g.adj.matrix[i][j] = 0;
    g.type = ADJ_MATRIX;

    degreeV = (int *) malloc(g.V*sizeof(int));
    for(i=0;i<g.V;i++)
        degreeV[i]=0;

    int V1, V2;
    printf("Enter two vertices which are adjacent to each other:\n");
    while(scanf("%d %d",&V1,&V2)==2)
    {
        if(V1>0 && V1<=g.V && V2>0 && V2<=g.V)
        {
            g.adj.matrix[V1-1][V2-1] = 1;
            g.adj.matrix[V2-1][V1-1] = 1;
            g.E++;
        }
        else
            break;
        printf("Enter two vertices which are adjacent to each other:\n");
    }

    calDegreeV(g,degreeV);

    printGraphMatrix(g);
    printDegreeV(degreeV,g.V);

    adjM2adjL(&g);

    calDegreeV(g,degreeV);

    printGraphList(g);
    printDegreeV(degreeV,g.V);

    adjL2adjM(&g);
    printGraphMatrix(g);

    return 0;
}

void printGraphMatrix(Graph g)
{
    int i,j;
    if(g.type == ADJ_LIST) {printf("Error"); return;}

    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            printf("%d\t",g.adj.matrix[i][j]);
        printf("\n");
    }

}

void printDegreeV(int *degreeV,int V)
{
    int i;
    for(i=0;i<V;i++)
        printf("%d: %d degree\n",i+1,degreeV[i]);
}

void printGraphList(Graph g){
    int i;
    ListNode* temp;

    if(g.type == ADJ_MATRIX) {printf("Error"); return;}

    for(i=0;i<g.V;i++)
    {
        printf("%d:\t",i+1);
        temp = g.adj.list[i];
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void adjM2adjL(Graph *g)
{
 // Question 1
 // Write your code here
 if (g->type == ADJ_LIST){
        return;
    }
    int i=0, j=0;
    ListNode *temp, **list;
    //must use a separate list 
    list = (ListNode **)malloc(g->V*sizeof(ListNode *));

    for(i=0;i<g->V;i++){
        list[i]= NULL;
    }

    for(i=0;i<g->V;i++){
        for(j=0;j<g->V;j++){
            if (g->adj.matrix[i][j] == 1){
                temp = (ListNode *)(malloc(sizeof(ListNode )));
                temp->next = NULL;
                temp->vertex = j+1;
                if (list[i] == NULL){
                    list[i] = temp;
                }else{
                    temp->next = list[i]->next;
                    list[i]->next = temp;
                    
                }


            }
        }
    }
   

    //free adjMatrix
    for(i=0;i<g->V;i++){
        free(g->adj.matrix[i]);

    }
    free(g->adj.matrix);

     g->adj.list = list;
    g->type = ADJ_LIST;

    

}

void adjL2adjM(Graph *g){
	// Question 2
    // Write your code here
    int **matrix, i=0, j=0;
    ListNode *temp, *temp2;
    if (g->type == ADJ_MATRIX){
     return;
    }
   

    matrix = (int **)malloc(g->V*sizeof(int *));
    for(i=0;i<g->V;i++)
        matrix[i] = (int *)malloc(g->V*sizeof(int));
    
     for(i=0;i<g->V;i++)
        for(j=0;j<g->V;j++)
            matrix[i][j] = 0;

    for(i=0;i<g->V;i++){
        temp = g->adj.list[i];
        while(temp!=NULL){
            matrix[i][temp->vertex -1] = 1;
            temp = temp->next;
        }
    }
    for(i=0;i<g->V;i++)
    {
        temp = g->adj.list[i];
        while(temp!=NULL){
            temp2= temp;
            temp = temp->next;
            free(temp2);
        }
    }
    g->adj.matrix = matrix;
    

    g->type = ADJ_MATRIX;

}

void calDegreeV(Graph g, int *degreeV)
{
	// Question 3
    // Write your code here
    int i=0, count=0, j=0;
    ListNode *temp;
    if(g.type == ADJ_LIST){
        for(i=0;i<g.V;i++)
        {
            temp = g.adj.list[i];
            while(temp !=NULL){
                count++;
                temp = temp->next;
            }
            degreeV[i]= count;
            count =0;
        }

    }
    if (g.type == ADJ_MATRIX){
        for(i=0;i<g.V;i++){
            for(j=0;j<g.V;j++)
                if (g.adj.matrix[i][j]==1){
                    count++;
                }
            degreeV[i] = count;
            count=0;
            
    }
    }

    
}
