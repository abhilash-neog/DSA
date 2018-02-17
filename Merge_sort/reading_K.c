#include<stdio.h>
#include<stdlib.h>
#include "merge.h"

void readFile(int K,FILE* f){

while(!(feof(f))){
	Element e1 = (Element)malloc(sizeof(struct element)*K);
	for(int i=0;i<K;i++){
			fscanf(f,"%[^,], %lf\n",e1[i].name,&e1[i].cgpa);
	}
	mergeSort(e1,K);
	static int fileindex = 0;
	char filename[1] = {(fileindex+48)};
	FILE* fw = fopen(filename,"w");
	for(int m=0;m<K;m++){
		fprintf(fw,"%s, %lf\n",e1[m].name,e1[m].cgpa);}
	
	fileindex++;
	fclose(fw);
}
}
int main(){
FILE* fp = fopen("10240.txt","r");
int K = 1024;
readFile(K,fp);
printf("Done reading the files!");
return 0;
}
