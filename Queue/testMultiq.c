#include "multiq.h"
#include<stdlib.h>
#include<stdio.h>

typedef FILE* File;
void print(arr a1)
{
//print
	arr endPtr = a1 + sizeof(a1)/sizeof(a1[0]);
	while(a1 < endPtr)
	{
	Queue q = a1->que;
	Element temp = q->front;
		while(temp!=NULL)
		{
			printf("\n %2d \n",temp->k);
			temp = temp->next;
    	   	}
	}
}
MultiQ loadData(File f)
{
	MultiQ myQ = createMQ(10);
	int count=0;
	arr a24 = myQ->arrEle;
	int i=0;
	for(i=0;i<10;i++){
	a24->que = newQ();
	Task t1 = (Task)malloc(sizeof(struct task));	
	while(1)
	{
	char ch = fgetc(f);
	int x = ch - '0';
	if(count!=0){	
	t1->taskID = x;
	}
	if(count==1){
	a24->priority = x;  
	t1->priority = x;
	myQ = addMQ(myQ,t1);
	break;
	}
	if(ch==' '){
	count=1;	
	}
	}
	a24++;
	}
	return myQ;
}
int main()
{                                          
	FILE * fp; 
	fp = fopen("input10.txt", "r");	
	MultiQ retQ  = loadData(fp);	
	print(retQ->arrEle);
	/*int i,j=0;
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
	print(myQ);*/	
}
