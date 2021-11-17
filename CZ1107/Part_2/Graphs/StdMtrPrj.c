#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int vertex;
    struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _graph
{
    int V;
    int E;
    ListNode **list;
} Graph;

typedef ListNode QueueNode;

typedef struct _queue
{
    int size;
    QueueNode *head;
    QueueNode *tail;
} Queue;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void insertAdjVertex(ListNode **AdjList, int vertex);
void removeAdjVertex(ListNode **AdjList, int vertex);
int matching(Graph g);

void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
void printQ(QueueNode *cur);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
//////////////////////////////////
int BFS (Graph g, int v, int w, int pred[]);
int isMarked(int target, int list[], int size);
void printGraphList(Graph g);

int main()
{


    int Prj, Std, Mtr; //Project, Student and Mentor;
    int i=0, j=1, tempval;
    int maxMatch;
    ListNode *temp;
    int np, nm;
    int s=0, t=0;
    //source is 0 and sink is g.V-1
    Graph g;
    g.E = 0;
    scanf("%d %d %d \n", &Std, &Prj, &Mtr);
    //create empty graph first 
    g.V = Prj+Mtr+2*Std+2;//must add the source and sink 
    //then one layer of extra student 
    t=g.V;
    g.list = (ListNode **) malloc(g.V*sizeof(ListNode *));
    for(i=0;i<t;i++){
        g.list[i] = NULL;

    }

    for (i=1; i<= Prj; i++) {
        if(g.list[0]==NULL){
            g.list[0] = (ListNode *)malloc(sizeof(ListNode));
            g.list[0]->vertex = i;
            g.list[0]->next = NULL;
        }
        else{
            temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = g.list[0];
            temp->vertex = i;
            g.list[0] = temp;
        }
        g.E++;
    }

    for (i=Prj+2*Std+1; i<t; i++) {
        if(g.list[i]==NULL){
            g.list[i] = (ListNode *)malloc(sizeof(ListNode));
            g.list[i]->vertex = t-1;
            g.list[i]->next = NULL;
            }
        else{
            temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = g.list[i];
            temp->vertex = t-1;
            g.list[i] = temp;
        }
        g.E++;
    }

    //student to mentor, project to student 
    for (j=1; j<=Std; j++) {
        scanf("%d %d",&np,&nm);
        for (i=0; i<np; i++) {
            scanf("%d", &tempval);
            if(g.list[tempval]==NULL){
            g.list[tempval] = (ListNode *)malloc(sizeof(ListNode));
            g.list[tempval]->vertex = Prj+j;
            g.list[tempval]->next = NULL;
            }
            else{
                temp = (ListNode *)malloc(sizeof(ListNode));
                temp->next = g.list[tempval];
                temp->vertex = Prj+j;
                g.list[tempval] = temp;
            }
        g.E++;
           
        }
        //you connect the two parts of the graph 
        //this is to account for the extreme case if when all students want the same project and mentor, the maxmatch is 4?
        if(g.list[Prj+j]==NULL){
            g.list[Prj+j] = (ListNode *)malloc(sizeof(ListNode));
            g.list[Prj+j]->vertex = Prj+j+Std;
            g.list[Prj+j]->next = NULL;
            }
        /*
        else{
                temp = (ListNode *)malloc(sizeof(ListNode));
                temp->next = g.list[Prj+j];
                temp->vertex = Prj+Std+j;
                g.list[Prj+j] = temp;
            }
        this is not needed in the code because when you are making the graph there is no link between node 4 8, 5 9, 6 10, 7 11.
        */  
        g.E++;
        for (i=0; i<nm; i++) {
            scanf("%d", &tempval);
            if(g.list[Prj+Std+j]==NULL){
            g.list[Prj+Std+j] = (ListNode *)malloc(sizeof(ListNode));
            g.list[Prj+Std+j]->vertex = Prj+2*Std+tempval;
            g.list[Prj+Std+j]->next = NULL;
            }
            else{
                temp = (ListNode *)malloc(sizeof(ListNode));
                temp->next = g.list[Prj+Std+j];
                temp->vertex = Prj+2*Std+tempval;
                g.list[Prj+Std+j] = temp;
            }
        g.E++;
        }
        scanf("%*c");
    }
    

    
    

    maxMatch = matching(g);
    printf("%d\n", maxMatch);
    return 0;
}


void printGraphList(Graph g){
    int i;
    ListNode* temp;

    for(i=0;i<g.V;i++)
    {
        printf("%d:\t",i);
        temp = g.list[i];
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}


int matching(Graph g)
{ 
    //we need a residual graph too

   int x=0, y=0, numbermatches=0, pred[g.V];
   while(BFS(g, 0, g.V-1, pred)==1){
       for(y=g.V-1;y>0;y=pred[y]){
         x = pred[y];

        removeAdjVertex(&(g.list[x]), y);

        insertAdjVertex(&(g.list[y]), x);


       }
       numbermatches++;
   }
   return numbermatches;
}


int BFS(Graph g, int v, int w, int pred[]){
    if (w > g.V){
        return -1;
    }
   ListNode *tempnode;
    int marked[g.V];
    int j=0, i=0, count=0, mainvertex=0;
    Queue temp;
    temp.size = 0;
    temp.head = NULL;
    temp.tail = NULL;
    //tempnode = g.list[v-1];
    enqueue(&temp, v);
    marked[j++] = v;
    pred[0]=-1;
    while(!isEmptyQueue(temp)){
        mainvertex = getFront(temp);
        tempnode = g.list[mainvertex];
        dequeue(&temp);
        
        while(tempnode != NULL){
            if (!isMarked(tempnode->vertex, marked, j) && tempnode->vertex == w){
                pred[(tempnode->vertex)]=mainvertex;
                return 1;
            } else if(!isMarked(tempnode->vertex, marked, j)){
                enqueue(&temp, tempnode->vertex);
                marked[j++] = tempnode->vertex;
                pred[tempnode->vertex]=mainvertex;
            }
            tempnode = tempnode->next;
        }

    }

    return -1;
    
  
}


int isMarked(int target, int list[], int size){
    int i=0;
    //the issue is here 
    //i<=size causes runtime 
    for(i=0;i<size;i++){
        if (target == list[i]){
            return 1;
        }
    }
    return 0;

}



void removeAdjVertex(ListNode **AdjList, int vertex)
{
    ListNode *temp, *preTemp;
    if (*AdjList != NULL){
        if ((*AdjList)->vertex == vertex){ //first node
            temp = *AdjList;
            *AdjList = (*AdjList)->next;
            free(temp);
            return;}

        preTemp = *AdjList;
        temp = (*AdjList)->next;
        while (temp != NULL && temp->vertex != vertex){
            preTemp = temp;
            temp = temp->next;}
            preTemp->next = temp->next;
            free(temp);
    }
}

void insertAdjVertex(ListNode **AdjList, int vertex)
{
    ListNode *temp;
    if (*AdjList == NULL){
        *AdjList = (ListNode *)malloc(sizeof(ListNode));
        (*AdjList)->vertex = vertex;
        (*AdjList)->next = NULL;}
    else{
        temp = (ListNode *)malloc(sizeof(ListNode));
        temp->vertex = vertex;
        temp->next = *AdjList;
        *AdjList = temp;
    }
}


void enqueue(Queue *qPtr, int vertex)
{
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    if (newNode == NULL) exit(0);
    
    newNode->vertex = vertex;
    newNode->next = NULL;
    if (isEmptyQueue(*qPtr))
        qPtr->head = newNode;
    else
        qPtr->tail->next = newNode;
        qPtr->tail = newNode;
        qPtr->size++;
}

int dequeue(Queue *qPtr)
{
    if (qPtr == NULL || qPtr->head == NULL){ 
        //Queue is empty or NULL pointer
        return 0;
    }
    else{
        QueueNode *temp = qPtr->head;
        qPtr->head = qPtr->head->next;
        if (qPtr->head == NULL) 
            //Queue is emptied
            qPtr->tail = NULL;
            free(temp);
            qPtr->size--;
            return 1;
    }
}

int getFront(Queue q){
    return q.head->vertex;
}

int isEmptyQueue(Queue q)
{
    if (q.size == 0) return 1;
    else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
    while (dequeue(qPtr));
}

void printQ(QueueNode *cur)
{
    if (cur == NULL) printf("Empty");
    while (cur != NULL){
        printf("%d ", cur->vertex);
        cur = cur->next;
    }
    printf("\n");
}

void push(Stack *sPtr, int vertex)
{
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->vertex = vertex;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if (sPtr == NULL || sPtr->head == NULL){
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

int isEmptyStack(Stack s)
{
    if (s.size == 0) return 1;
    else return 0;
}

int peek(Stack s)
{
    return s.head->vertex;
}

void removeAllItemsFromStack(Stack *sPtr)
{
    while (pop(sPtr));
}





