#include<stdio.h>
#include<sys/time.h>
#include<string.h>
#include<stdlib.h>
#include "elements.h"

struct timeval t1,t2;
struct timeval t3,t4;
double elapsedtime;
double elapsedtime2;
int ptr1;
void print(Element row,int leng){
	int len = sizeof(row)/sizeof(row[0]);
	int i;
	for(i=0;i<leng;i++)
	{
		printf("%ld %s %s %s %s\n",row[i].Card_Number,row[i].Bank_code,row[i].expiry_date,row[i].First_name,row[i].Last_name);
	}
}

void main(){
	FILE* fp= fopen("/home/Abhilash/Desktop/DSA/Lab4/1000","r");
	if(fp==NULL){printf("not working");}
	printf("Loaded array:\n");
	gettimeofday(&t1,NULL);
	Element test = RecordReader(fp);
	gettimeofday(&t2,NULL);
	elapsedtime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedtime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	gettimeofday(&t3,NULL);
	int a =0;	
	ptr1 = &a;
	Element sorted_test = insertionSort(test,1000);
	
	gettimeofday(&t4,NULL);
	elapsedtime2 = (t4.tv_sec - t3.tv_sec) * 1000.0;
	elapsedtime2 += (t4.tv_usec - t3.tv_usec) / 1000.0;
	
	printf("After sorting:\n");
	print(sorted_test,1000);
	printf("Total time for loading data:%f ms\n",elapsedtime);
	printf("Total time by insertionSort:%f ms\n",elapsedtime2);
	printf("Stack size:%d",ptr2-ptr1);
	FILE* f = fopen("Result.txt","w");
	fprintf(f,"Time for loading data:%f\n Time for Sorting:%f\n Stack size:%d",elapsedtime,elapsedtime2,ptr2-ptr1);
	fclose(f);
}
