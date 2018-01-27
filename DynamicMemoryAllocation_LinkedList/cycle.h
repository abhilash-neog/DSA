#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct element* Element;
typedef struct link* Link;
typedef enum Boolean{False,True}Boolean;

struct element{
int key;
Element next;
};
struct link{
Element head;
};

Boolean testCyclic(Link ls);
