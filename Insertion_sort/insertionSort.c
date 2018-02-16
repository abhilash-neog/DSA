#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "elements.h"
int ptr2;
Element swap(Element e1,Element e2,int j){	
		Element temp = (Element)malloc(sizeof(struct element));
		temp[0].Card_Number = e2[j].Card_Number;
		strcpy(temp[0].Bank_code,e2[j].Bank_code);
		strcpy(temp[0].expiry_date,e2[j].expiry_date);
		strcpy(temp[0].First_name,e2[j].First_name);
		strcpy(temp[0].Last_name,e2[j].Last_name);
		e2[j].Card_Number = e1->Card_Number;
		strcpy(e2[j].Bank_code,e1->Bank_code);
		strcpy(e2[j].expiry_date,e1->expiry_date);
		strcpy(e2[j].First_name,e1->First_name);
		strcpy(e2[j].Last_name,e1->Last_name);
		e1->Card_Number = temp[0].Card_Number;	
		strcpy(e1->Bank_code,temp[0].Bank_code);
		strcpy(e1->expiry_date,temp[0].expiry_date);
		strcpy(e1->First_name ,temp[0].First_name);
		strcpy(e1->Last_name,temp[0].Last_name);	
		int b=0;
		ptr2 = &b;
	return e1;
}
Element InsertInOrder(Element orig_arr,Element newR,int len){
	int j=0;
	for(j=0;j<len;j++)
	{
		if(newR->Card_Number < orig_arr[j].Card_Number ){
		newR = swap(newR,orig_arr,j);
		}
	}	
return orig_arr;
}

Element insertionSort(Element arr,int size){
	int i=0;
	for(i=0;i<size;i++){
		Element e1;
		e1 = &arr[i];
		arr = InsertInOrder(arr,e1,i);
	}
	return arr;
}

