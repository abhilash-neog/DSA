#include<stdlib.h>
#include<stdio.h>
typedef struct queue* Queue;
typedef struct element* Element;
typedef enum Boolean{False,True}Boolean;

struct element{
int k;
Element next;
};

struct queue{
int count;
Element front;
Element rear;
};

Queue newQ();
Boolean isEmpty(Queue q);
Element front(Queue q);
Queue delQ(Queue q);
Queue addQ(Queue q, Element e);
int length(Queue q);

