#include<stdio.h>
#include<stdlib.h>
/*
void *myalloc(int size,int count)
{
void *temp=malloc((size*count)+4);
*(int*)temp=count*size;
globalcnt+=size*count+4(sizeof(int));
return temp+4(sizeof(int));
}
void myfree(void* temp)
{
void*temp3=temp2-4;
globalcnt-=(*(int*)temp3);
free(temp3);
}

makefile::
CompRecMS:merge.h mergerec.c
          gcc-c mergerec.c
          
RunRecMS:merge.h comprecms
        gcc -c driver.c 
        gcc driver.o mergerec.o
        
        
        in terminal call make runrecms
        then ./a.out

*/
struct element
{
char name[15];
float cgpa;
};
typedef struct element* Element;
void merge(Element ls1,int sz1,Element ls2,int sz2,Element ls)
{
int i=0,j=0,k=0;
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
void mergesort(Element arr,int size)
{
if(size>1)
{
	int mid=size/2;
	struct element ls1[mid];
	struct element ls2[size-mid];
	int i=0;
	int j=0;
	for(i=0;i<mid;i++)
	{
	ls1[i]=arr[j++];
	}
	for(i=mid;i<size;i++)
	{
	ls2[i-mid]=arr[j++];
	}
	mergesort(ls1,mid);
	mergesort(ls2,size-mid);
	merge(ls1,mid,ls2,size-mid,arr);
	}
}
int main()
{
	Element arr=(Element)malloc(10*sizeof(struct element));
	FILE *fp=fopen("1024.txt","r");
	int i=0;
	while(!feof(fp))
	{
	fscanf(fp,"%[^,],%f\n",arr[i].name,&(arr[i].cgpa));
	i++;
	if(i>10)
	{
	break;
	}
	}
	for(i=0;i<10;i++){
	printf("%s,%f\n",arr[i].name,arr[i].cgpa);
	}
	mergesort(arr,10);
	printf("After sorting:\n");
	for(i=0;i<10;i++){
	printf("%s,%f\n",arr[i].name,arr[i].cgpa);
}


return 0;
}




