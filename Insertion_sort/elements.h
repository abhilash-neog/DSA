#include<stdio.h>
#include<stdlib.h>

extern int ptr1;
extern int ptr2;
typedef struct element* Element; 
struct element{
long long Card_Number;
char* Bank_code[5];
char* expiry_date[10];
char* First_name[20];
char* Last_name[20];
};
Element RecordReader(FILE* fp);
Element insertionSort(Element arr,int size);
Element InsertInOrder(Element orig_arr,Element newR,int len);
Element swap(Element e1,Element e2,int j);
