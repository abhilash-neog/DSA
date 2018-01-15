#include "SeqList.h"

struct SeqList* newList()
{
	struct SeqList* newL = (struct SeqList*)malloc(sizeof(struct SeqList));
	newL->head = NULL;
	newL->tail = NULL;	
	return newL;
}

struct SeqList* insertInOrder(struct SeqList* sl,struct Element* e)
{
	int i = 0;
	if(sl->head==NULL)
	{
		sl->head = e;
	}
	else
	{
	struct Element* cur = sl->head;
	 while(cur->next!=NULL){
		struct Element* nex = cur->next;
		if(e->k > (cur->k) && e->k < (nex->k)  )
			{
				/*struct Element* temp = (struct Element* temp)malloc(sizeof(struct Element));
				temp->k = e->k;
				temp->next = cur->next;
				cur->next = temp;*/
				e->next = nex;
				cur->next = e;
				return sl;
			}
		cur = cur->next;		
	}
	cur->next = e;

}
	return sl;
}

struct SeqList* insertAtFront(struct SeqList* sl, struct Element* e)
{
	//struct Element* temp = (struct Element*)malloc(sizeof(struct Element));
	//temp->k = e->k;
	if(sl->head == NULL){sl->tail = e; sl->head = e; }
	else{
	e->next = sl->head;
	sl->head =  e;}
	return sl;
}
struct SeqList* insertAtEnd(struct SeqList* sl, struct Element* e)
{
	struct Element* temp = (struct Element*)malloc(sizeof(struct Element));
	if(sl->head == NULL){sl->head = e;sl->tail = e;}
	else{
	temp = sl->tail;
	temp->next = e;	
	sl->tail = e;}	
	return sl;
}
struct SeqList* delete(struct SeqList* sl, struct Element* e)
{
	struct Element* cur = sl->head;
	struct Element* prev = cur;
	 while(cur!=NULL){
		if(cur->k == e->k)
			{
			   prev->next = cur->next;
			   return sl;	
			}
		prev=cur;		
		cur = cur->next;
	}
return sl;
}
struct SeqList* deleteAtFront(struct SeqList* sl)
{
	sl->head = sl->head->next;
	return sl;
}
struct Element* find(struct SeqList* sl, int k)
{
	struct Element* cur = sl->head;
	 while(cur!=NULL){
		if(cur->k == k)
			{
			   return cur;	
			}		
		cur = cur->next;
	}
	printf("Not found!!");
	return NULL;
}
