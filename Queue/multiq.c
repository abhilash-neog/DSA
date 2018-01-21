#include "multiq.h"
#include<stdio.h>
#include<stdlib.h>

MultiQ createMQ(int num){

	MultiQ m1 = (MultiQ)malloc(sizeof(struct MQ));
	 arr a1= (struct ArrElement*)malloc(sizeof(struct ArrElement)*num);
	m1->arrEle = a1;
	m1->count=num;
	return m1;
}
MultiQ addMQ(MultiQ mq, Task t){

	arr a1 = mq->arrEle;
	arr endPtr = a1 + sizeof(a1)/sizeof(a1[0]);
	while(a1 < endPtr)
	{
	if(a1->priority == t->priority)
	{
	Queue q = a1->que;
	Element e2 = (Element)malloc(sizeof(struct element));
	e2->k = t->taskID;
	q = addQ(q,e2);
	return mq;
	}
	a1++;
	}
	return mq;
}
Task nextMQ(MultiQ mq){

	arr a1 = mq->arrEle;
	arr endPtr = a1 + sizeof(a1)/sizeof(a1[0]);
	arr ax = mq->arrEle;
	while(a1 < endPtr-1)
	{
	arr a2 = a1++;
	if(ax->priority < a2->priority)
	{
		continue;
	}
	else{
		ax  = a2;
		}
	a1++;
	}
	Queue q = ax->que;
	Element ex = front(q);
	Task t = (Task)malloc(sizeof(struct task));
	t->taskID  = ex->k;
	t->priority = ax->priority;
	return t;
} 
MultiQ delNextMQ(MultiQ mq){
	
	arr a1 = mq->arrEle;
	arr endPtr = a1 + sizeof(a1)/sizeof(a1[0]);
	arr ax = mq->arrEle;
	while(a1 < endPtr)
	{
	arr a2 = a1++;
	if(ax->priority < a2->priority)
	{
		continue;
	}
	else{
		ax  = a2;
		}
	a1++;
	}
	Queue q = ax->que;
	q = delQ(q);
	return mq;
}
Boolean isEmptyMQ(MultiQ mq){
	
	arr a1 = mq->arrEle;
	arr endPtr = a1 + sizeof(a1)/sizeof(a1[0]);
	while(a1 < endPtr)
	{
	if(a1->que->front != NULL)
	{
		return False;
	}
	a1++;
	}
	return True;
}
int sizeMQ(MultiQ mq){
	
	return mq->count;
}
int sizeMQbyPriority(MultiQ mq, int p){
	
	int pcount;
	arr a1 = mq->arrEle;
	arr endPtr = a1 + sizeof(a1)/sizeof(a1[0]);
	while(a1 < endPtr)
	{
	if(p == a1->priority)
	{
	pcount++;}a1++;
	}
	return pcount;
}
Queue getQueueFromMQ(MultiQ mq, int p){

	arr a1 = mq->arrEle;
	arr endPtr = a1 + sizeof(a1)/sizeof(a1[0]);
	while(a1 < endPtr)
	{
	if(p == a1->priority)
	{
	return a1->que;}a1++;
	}
return NULL;
}
