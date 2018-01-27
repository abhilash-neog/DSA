#include<stdio.h>
#include "cycle.h"

Boolean testCyclic(Link Ls){
//Link-Reversal
Element point = Ls->head->next;
Element e1 = Ls->head;
Element e2 = point;
while(point != NULL)
{
	if(point==Ls->head)
	{return True;}
	if(e1!=e2){
	point = point->next;
	e2->next = e1;
	e1 = e2;
	e2 = point;}
	else{
	point=point->next;
	e2 = point;}
			
}
return False;
}

