#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 37
#define PRIME     13

enum Marker {EMPTY,USED,DELETED};

typedef struct _slot{
    int key;
    enum Marker indicator;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashDelete(int key, HashSlot hashTable[]);


int hash1(int key);
int hash2(int key);

int main()
{
    int opt;
    int i;
    int key;
    int comparison;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].indicator = EMPTY;
        hashTable[i].key = 0;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Delete a key from the hash table|\n");
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
            comparison = HashInsert(key,hashTable);
            if(comparison <0)
                printf("Duplicate key\n");
            else if(comparison < TABLESIZE)
                printf("Insert: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Key Comparisons: %d. Table is full.\n",comparison);
            break;
        case 2:
            printf("Enter a key to be deleted:\n");
            scanf("%d",&key);
            comparison = HashDelete(key,hashTable);
            if(comparison <0)
                printf("%d does not exist.\n", key);
            else if(comparison <= TABLESIZE)
                printf("Delete: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Error\n");
            break;
        case 3:
            for(i=0;i<TABLESIZE;i++) printf("%d: %d %c\n",i, hashTable[i].key,hashTable[i].indicator==DELETED?'*':' ');
            break;
        }
        printf("Enter selection: ");
        scanf("%d",&opt);
    }
    return 0;
}

int hash1(int key)
{
    return (key % TABLESIZE); //given by prof
    //simply use the size of the hash table 
}

int hash2(int key)
{
    return (key % PRIME) + 1; //given by prof 

}

int HashInsert(int key, HashSlot hashTable[])
{
   //Write your code here
   //calculate the location of the key 
   int location=0, i=0;
   //location = hash1(key + i*hash2(key));
   i=0;
   //must check whether there is a used key in the first place
   i=0;
   while (i<=36){
       location = hash1(hash1(key) + i*hash2(key));
        if (hashTable[location].indicator == EMPTY || hashTable[location].indicator == DELETED){
            hashTable[location].key=key;
            hashTable[location].indicator = USED;
            return i;
        } else if (hashTable[i].indicator==USED  && hashTable[i].key== key){
            return -1;
        }
        else{
            i++;
        }
   }
   return i;

}

int HashDelete(int key, HashSlot hashTable[])
{
   //Write your code here
   //traverse the whole table until key found, mark as deleted and then return do not proceed further 
   int i=0, location =0, comparisons=0;
   while (i<37){
       location = hash1(hash1(key) + i*hash2(key));
       if (hashTable[location].key == key && hashTable[location].indicator == USED){
            hashTable[location].indicator = DELETED;
            comparisons++;
            return comparisons;
       }else if (hashTable[location].key != key && hashTable[location].indicator == USED) {
           comparisons++;
       }
        i++;
       
       
   }
   return -1;

}