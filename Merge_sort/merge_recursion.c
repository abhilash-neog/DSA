#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "merge.h"

void merge(Element ls1,int sz1,Element ls2,int sz2,Element ls){
int i=0;int j=0;int k=0;
	while(i<sz1 && j<sz2)
	{
	if(ls1[i].cgpa<ls2[j].cgpa)
	{
	ls[k]=ls1[i];
	i++;
	k++;
	}
	else
	{
	ls[k]=ls2[j];
	j++;
	k++;
	} 
	}
while(i<sz1)
	{
	ls[k]=ls1[i];
	k++;
	i++;
	}
while(j<sz2)
{
	ls[k]=ls2[j];
	k++;
	j++;
}

}

void mergeSort(Element ls,int size){ 
	
	if(size>1){
		int mid = size/2;
		struct element ls1[mid];
		struct element ls2[size-mid];
		int i=0;
		int j=0;
		int f=0;
		for(i=0;i<mid;i++)
		{
		ls1[i]=ls[j];
		j++;
		}
		for(f=mid;f<size;f++)
		{
		ls2[f-mid]=ls[j];
		j++;
		}
		mergeSort(ls1,mid);
		mergeSort(ls2,size-mid);
		merge(ls1,mid,ls2,size-mid,ls);
	}
}
void result(double elapsedtime2,double elapsedtime1){
	
FILE* f = fopen("Result_recursion.txt","w");
fprintf(f,"Time for loading data:%f\n Time for Sorting:%f",elapsedtime2,elapsedtime1);
}

