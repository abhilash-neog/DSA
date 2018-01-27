#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include "cycle.h"

struct timeval t1,t2;
double elapsedtime;
int glb;
void* myalloc(int size,int count)
{
void* new = (void*)malloc(size*count);
glb = glb + size*count;
return new;
}
void myfree(void* ptr,int count,int size)
{
glb = glb - size*count;
printf("%1d\n",glb);
free(ptr);
}
Link createList(int N){
Link Ls = (Link)myalloc(sizeof(struct link),1);
int i=0;
for(i=0;i<N;i++)
{
	Element ei = (Element)myalloc(sizeof(struct element),1);
	int r = rand()%50;
	//printf("%d \n",r);
	ei->key = r;
	ei->next = NULL;
	if(Ls->head==NULL){
	Ls->head = ei;	
	}
	else{
	Element temp = Ls->head;	
	ei->next = temp;
	Ls->head = ei; 
	}
}
return Ls;	
}
Link createCycle(Link Ls){
	
	int toss = rand()%1;	
	printf(" toss-%d\n",toss);	
	if(toss==1){
	int r = rand()%50;
	printf("random number generated - %d\n",r);
	Element temp= Ls->head;
	Element point = NULL;
	while(temp->next!=NULL){
		if(temp->key == r)
		{
		point = temp;	
		}
	temp = temp->next;
	if(temp->next==NULL){if(point!=NULL){temp->next = point;break;}}
	}
	return Ls;	
	}
	else{return Ls;}
	
}
Link makeCircularList(Link Ls){
	int flag = 0;
	int test = testCyclic(Ls);
	if(test==1){
		Element X = Ls->head;
		Element Y = Ls->head;
		while(1){
		Y = Ls->head;
		while(Y!=X){
		if(X->next == Y)
		{
		Element tempo = Ls->head;
		while(tempo!=Y){
		Element z = tempo->next;
		myfree(tempo,1,sizeof(struct element));
		tempo = z;
		}
		Ls->head = Y;flag=1;break;}
		Y=Y->next;		
		}
		if(flag==1){break;}		
		else{X=X->next;}		
		}
		return Ls;
	}
	else{
		Element temp = Ls->head;
		while(temp!=NULL){
		if(temp->next==NULL){
				temp->next = Ls->head;
				break;
		}temp=temp->next;
		}
		return Ls;
	}
}
void main(){

	Link ls1 = createList(10);
	ls1 = createCycle(ls1);
	gettimeofday(&t1,NULL);
	int x = testCyclic(ls1);
	gettimeofday(&t2,NULL);
	printf("%d\n",x);	
	elapsedtime = (t2.tv_sec - t1.tv_sec)*1000;
	//printf("%d ms",elapsedtime);
	elapsedtime += (t2.tv_usec - t1.tv_usec)/1000;
	printf("%d ms\n",elapsedtime);
	Link s1 = makeCircularList(ls1);
	// a simple test:cycle1.c-65251376ms,cycle2.c-64907312ms(cyclic)
}
