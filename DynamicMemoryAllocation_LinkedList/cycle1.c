#include<stdio.h>
#include "cycle.h"

Boolean testCyclic(Link Ls){
//Hare-tortoise-algo
Element hare = Ls->head->next;
Element tort = Ls->head;
while(hare!=NULL && tort!=NULL)
{
	if(hare == tort)
	{
		return True;
	}
	if(hare->next == tort)
	{
		return True;
	}
//if(hare->next != NULL){
Element temp=hare->next;
if(temp==NULL){return False;}
else{
hare = temp->next;}
tort=tort->next;
}
return False;
}

