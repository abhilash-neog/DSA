#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include "merge.h"
struct timeval t1,t2,t3,t4;
double elapsedtime1,elapsedtime2;

void print(Element lz,int length){
int i=0;
	for(i=0;i<length;i++)
	{
		printf("%lf,%s\n",lz[i].cgpa,lz[i].name);
	}
}
Element Reader(FILE* fp,int size){
	Element first = (Element)malloc(sizeof(struct element)*(size));
	int i=0;
	while(!feof(fp)){
		fscanf(fp,"%[^,], %lf\n",first[i].name,&first[i].cgpa);
		i++;
	}
return first;
}
int main(int argc, char **argv){
FILE* fp = fopen(argv[1],"r");//file in c can read the contents line by line
int size=atoi(argv[2]);
gettimeofday(&t3,NULL);
Element orig_list = Reader(fp,size);
gettimeofday(&t4,NULL);
print(orig_list,size);
elapsedtime2 = (t4.tv_sec - t3.tv_sec)*1000;
elapsedtime2 += (t4.tv_usec - t3.tv_usec)/1000;
printf("After sorting:\n");
gettimeofday(&t1,NULL);
mergeSort(orig_list,size);
gettimeofday(&t2,NULL);
elapsedtime1 = (t2.tv_sec - t1.tv_sec)*1000;
elapsedtime1 += (t2.tv_usec - t1.tv_usec)/1000;
print(orig_list,size);
printf("time required for sorting:%f ms\n", elapsedtime1);
printf("time required for loading:%f ms\n", elapsedtime2);
result(elapsedtime2,elapsedtime1);
}
