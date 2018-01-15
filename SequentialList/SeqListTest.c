#include<stdio.h>
#include "SeqListUses.h"

void print(struct SeqList* myList)
{
//print
	struct Element* temp = myList->head;
	while(temp!=NULL){
		printf("\n %2d \n",temp->k);
		temp = temp->next;
	}
}
int main()
{
	struct Element* myEle[5] ;
	struct Element* myEle2[5] ;
	struct SeqList* myList= newList();
	struct SeqList* myList2 = newList();
	int i,j=0;
	for(i=0;i<5;i++)
	{
		myEle[i] = (struct Element*)malloc(sizeof(struct Element));
		myEle[i]->k = i*3-1;
		myList = insertAtEnd(myList,myEle[i]);
		myEle2[i] = (struct Element*)malloc(sizeof(struct Element));
		myEle2[i]->k = i+2;
		myList2 = insertAtEnd(myList2,myEle2[i]);
	}
	struct Element* e1 = (struct Element*)malloc(sizeof(struct Element));
	struct Element* e2 = (struct Element*)malloc(sizeof(struct Element));
	struct Element* e3 = (struct Element*)malloc(sizeof(struct Element));
	//print(myList);
	//print(myList2);
	e1->k = 8;
	e1->next = NULL;
	e2->k = 9;
	e2->next = NULL;
	e3->k = 7;
	e3->next = NULL;
	struct SeqList* merged = merge(myList,myList2);
	//print(merged);
	struct SeqList* toSort = newList();
	toSort = insertAtEnd(toSort,e1);
	toSort = insertAtEnd(toSort,e3);
	toSort = insertAtEnd(toSort,e2);
	print(toSort);
	toSort = insertionSort(toSort);
	printf("After sorting");
	print(toSort);
	/*uncomment the following if this driver needs to implement fn of odr modules 		as well
        myList = insertAtEnd(myList, e2);
	myList = insertAtFront(myList,e2);
	myList = insertInOrder(myList,e3);
	printf("After inserting 43 as an element");
	print(myList);
	myList = deleteAtFront(myList);
	printf("After deleting first element");
	print(myList);
	myList = delete(myList, e2);
	printf("After deleting e1 element");
	print(myList);
	printf("Finding e3");
	struct Element* x = find(myList,7);
	printf("%d",x->k);
	*/
	
	return 0;	
}
