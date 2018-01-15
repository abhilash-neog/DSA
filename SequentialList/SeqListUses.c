#include "SeqListUses.h"

struct SeqList* merge(struct SeqList* sl1, struct SeqList* sl2)
{
	struct SeqList* bigList = newList();
	struct Element* e1 = sl1->head;
	struct Element* e2 = sl2->head;
	while(1)
	{
		if(e1==NULL)
		{
		bigList = insertAtEnd(bigList,e2);
		sl2 = deleteAtFront(sl2);
		e2 = sl2->head;
			if(e2 == NULL){
			break;}
		}
		else if(e2==NULL)
		{
		bigList = insertAtEnd(bigList,e1);
		sl1 = deleteAtFront(sl1);
		e1 = sl1->head;
			if(e1 == NULL){
			break;}
		}
		
		else if (e1->k <= e2->k)
		{
		bigList = insertAtEnd(bigList,e1);
		sl1 = deleteAtFront(sl1);
		e1 = sl1->head;
		}
		else
		{
		bigList = insertAtEnd(bigList,e2);
		sl2 = deleteAtFront(sl2);
		e2 = sl2->head;
		}
	}
	return bigList;
}
struct SeqList* insertionSort(struct SeqList* sl)
{
    int swapped, i;
    struct Element *ptr1;
    struct Element *lptr = NULL;
    ptr1 = sl->head;
    /* Checking for empty list */
    if (ptr1 == NULL)
        return NULL;
 
    do
    {
        swapped = 0;
        ptr1 = sl->head;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->k > ptr1->next->k)
            { 
		struct Element*b = ptr1->next;
	        int temp = ptr1->k;
    		ptr1->k = b->k;
    		b->k = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
	return sl;
}

/*void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}*/


