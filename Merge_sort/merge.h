#include<stdio.h>
#include<stdlib.h>

typedef struct element* Element;
struct element{
char name[10];
double cgpa;
};
void mergeSort(Element ls,int size);
void merge(Element ls1,int sz1,Element ls2,int sz2,Element ls);
void result(double x1, double x2);
