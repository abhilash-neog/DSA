#include<stdio.h>

extern int best_base_index;extern int best_tab_index;
extern int best_base;extern int best_tab;

extern int k; extern char** book;
typedef struct node* Node;
typedef struct hashtable* Hashtable;
typedef enum Boolean{True,False}Boolean;

struct node{
Node next;
Node head;
int index;
char* str;
};
struct hashtable{
Node link;
int elementCount;//total number of elements(strings) in table
int loadFactor;
int insertionCost; //total number of elements summed over all lists with len(list)>1
int queryingCost; //updated during lookup;
};

int hashfunction(char *str, int base, int tablesize);
int collision(char** str1,int base, int table);
void updateBest(int col, int base, int tab);
char** inputParser();
void profiler();
int InsertAll(Hashtable h, char** str);
void Insert(Hashtable h, char** str, int index);
Hashtable create();
