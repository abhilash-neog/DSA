#include<stdio.h>
#include<stdlib.h>

struct Element{
int k;
struct Element* next;
};

struct SeqList{
struct Element* head;
struct Element* tail;
};

struct SeqList* newList();

struct SeqList* insertInOrder();

struct SeqList* insertAtFront(struct SeqList* sl, struct Element* e);

struct SeqList* insertAtEnd(struct SeqList* sl, struct Element* e);

struct SeqList* delete(struct SeqList* sl, struct Element* e);

struct SeqList* deleteAtFront(struct SeqList* sl);

struct Element* find(struct SeqList* sl, int k);
