#include<stdio.h>
#include<stdlib.h>

typedef struct element* Element;
struct element{
double cgpa;
char name[10];
};
void mergeFiles(FILE* f1,FILE* f2, int s1,int s2){
FILE* fo = fopen("output.txt","w");
Element e1 = (Element)malloc(sizeof(struct element)*s1);
Element e2 = (Element)malloc(sizeof(struct element)*s2);
int i=0;
int j=0;
printf("%lf,%lf\n",e1[i].cgpa,e2[j].cgpa);
while(!(feof(f1)) && !(feof(f2))){
	//printf("%lf,%lf\n",e1[i].cgpa,e2[j].cgpa);
	if(i==0 && j==0){	
	fscanf(f1,"%[^,], %lf\n",e1[i].name,&e1[i].cgpa);
	fscanf(f2,"%[^,], %lf\n",e2[j].name,&e2[j].cgpa);}
	if(e1[i].cgpa <= e2[j].cgpa && !(feof(f1))){
	fprintf(fo,"%s, %lf\n",e1[i].name,e1[i].cgpa);i++;
		fscanf(f1,"%[^,], %lf\n",e1[i].name,&e1[i].cgpa);
		printf("i - %d\n",i);
	}
	else{	
	fprintf(fo,"%s, %lf\n",e2[j].name,e2[j].cgpa);j++;
		fscanf(f2,"%[^,], %lf\n",e2[j].name,&e2[j].cgpa);
		printf("j - %d\n",j);
	}
}
while(!(feof(f1))){
	if(j!=0){
	fprintf(fo,"%s, %lf\n",e2[j].name,e2[j].cgpa);j=0;fprintf(fo,"%s, %lf\n",e1[i].name,e1[i].cgpa);i++;}
	fscanf(f1,"%[^,], %lf\n",e1[i].name,&e1[i].cgpa);
	fprintf(fo,"%s, %lf\n",e1[i].name,e1[i].cgpa);
	i++;
}
while(!(feof(f2))){
	if(i!=0){
	fprintf(fo,"%s, %lf\n",e1[i].name,e1[i].cgpa);i=0;fprintf(fo,"%s, %lf\n",e2[j].name,e2[j].cgpa);j++;}
	fscanf(f2,"%[^,], %lf\n",e2[j].name,&e2[j].cgpa);
	fprintf(fo,"%s, %lf\n",e2[j].name,e2[j].cgpa);
	j++;
}
}
int main(){
FILE* fp1 = fopen("first.txt","r");
FILE* fp2 = fopen("second.txt","r");
int size1 = 10;
int size2 = 12;
mergeFiles(fp1,fp2,size1,size2);	
return 0;
}
