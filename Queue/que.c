#include "que.h"


Queue newQ(){

	Queue q = (struct queue*)malloc(sizeof(struct queue));
	q->count = 0;
	q->front = NULL;
	q->rear = NULL;
	return q;
}

Boolean isEmpty(Queue q){

	if(q->rear == NULL)
	{
		return True;
	}
	else
		return False;
}

Element front(Queue q){
	
	return q->front;
}

Queue delQ(Queue q){

	Element e1 = q->front;
	Element e2 = e1->next;
	q->front = e2;
	return q;
}
Queue addQ(Queue q, Element e){

	if(q->rear==NULL && q->front==NULL)
	{
		q->rear = e;
		q->front = e;
		q->count+=1;
		return q;
	}
	else
	{
		Element e1 = q->rear;
		e1->next = e;
		q->rear = e;
		q->count+=1;
		return q;
	}
}
int length(Queue q){

	return q->count;
}
