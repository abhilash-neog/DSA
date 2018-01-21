#include "que.h"
#include<stdlib.h>
#include<stdio.h>

void print(Queue myQ)
{
//print
	Element temp = myQ->front;
	while(temp!=NULL){
		printf("\n %2d \n",temp->k);
		temp = temp->next;
	}
}
int main()
{
	Element myEle[5] ;
	Queue myQ = newQ();
	int i,j=0;
	for(i=0;i<5;i++)
	{
		myEle[i] = (struct element*)malloc(sizeof(struct element));
		myEle[i]->k = i+2;
		myQ = addQ(myQ,myEle[i]);
	}
	Element e1 = (struct element*)malloc(sizeof(struct element));
	Element e2 = (struct element*)malloc(sizeof(struct element));
	Element e3 = (struct element*)malloc(sizeof(struct element));
	print(myQ);
	e1->k = 8;
	e1->next = NULL;
	e2->k = 9;
	e2->next = NULL;
	e3->k = 7;
	e3->next = NULL;
	myQ = delQ(myQ);
	Element ef = front(myQ);
	printf("%d",ef->k);
	//print(myQ);
	//printf("%d",length(myQ));
	myQ = addQ(myQ,e2);
	print(myQ);
}
