#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 37
#define PRIME     13

enum Marker {EMPTY,USED};

typedef struct _slot{
    int key;
    enum Marker indicator;
    int next;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashFind(int key, HashSlot hashTable[]);

int hash(int key)
{
    return (key % TABLESIZE);
}

int main()
{
    int opt;
    int i;
    int key;
    int index;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].next = -1;
        hashTable[i].key = 0;
        hashTable[i].indicator = EMPTY;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Search a key in the hash table  |\n");
    printf("|3. Print the hash table            |\n");
    printf("|4. Quit                            |\n");
    printf("=====================================\n");

    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=3){
        switch(opt){
        case 1:
            printf("Enter a key to be inserted:\n");
            scanf("%d",&key);
            index = HashInsert(key,hashTable);
            if(index <0)
                printf("Duplicate key\n");
            else if(index < TABLESIZE)
                printf("Insert %d at index %d\n",key, index);
            else
                printf("Table is full.\n");
            break;
        case 2:
            printf("Enter a key for searching in the HashTable:\n");
            scanf("%d",&key);
            index = HashFind(key, hashTable);

            if(index!=-1)
                printf("%d is found at index %d.\n",key,index);
            else
                printf("%d is not found.\n",key);
            break;

        case 3:
            printf("index:\t key \t next\n");
            for(i=0;i<TABLESIZE;i++) printf("%d\t%d\t%d\n",i, hashTable[i].key,hashTable[i].next);
            break;
        }
        printf("Enter selection: ");
        scanf("%d",&opt);
    }
    return 0;
}

int HashInsert(int key, HashSlot hashTable[])
{
 // Write your code here
    int index=0, i=0, count_used=0, location =0, prev_location=-1;

    //check if key exists
    while(i<=36){
        if (hashTable[i].indicator == USED){
            count_used ++;
        }
        i++;
    }
    if (count_used > 36){
        return 100;
    }
    i=0;
    if (HashFind(key, hashTable)!=-1){
        return -1;
    }
    i=0;
    location = hash(key+i);
    while(i<=36){
        if (hashTable[location].indicator==EMPTY){
            hashTable[location].key = key;
            hashTable[location].indicator = USED;
            if (prev_location !=-1 && hashTable[prev_location].next == -1){
                hashTable[prev_location].next = location;
            }
            return location;
        }else if (hashTable[location].indicator ==  USED && hashTable[location].next == -1){
            if (prev_location==-1){
                prev_location = location;
            }else if ( hash(key) == hash(hashTable[location].key)){
                prev_location = location;
            }
            i++;
            location = hash(key+i);
        }else if(hashTable[location].indicator == USED && hashTable[location].next !=-1){
            //prev_location = location; //this is wrong
            location = hashTable[location].next;
            /*if (prev_location==-1){
                prev_location = location; //you must not allocation prev_location at all 
            }else if (hash(key)==hash(hashTable[location].key)){
                prev_location = location;
                location = hashTable[location].next; //with this alone time limit will exceed 
            }else{
                i++;
                location = hash(key+i);
            }*/
        }
           
        
    }

    return location;

        
}


int HashFind(int key, HashSlot hashTable[])
{
 // Write your code here
    int location=0;
    location = hash(key);
    
    while(location<=36){
        if (hashTable[location].indicator == USED 
        &&hashTable[location].key == key){
            return location;
        }else if(hashTable[location].indicator == USED 
        &&hashTable[location].key != key 
        && hashTable[location].next !=-1){
            location = hashTable[location].next;
        }else if (hashTable[location].next ==-1){
            return -1;
            
        }else{
            location++;
        }
    }

    return -1;


}