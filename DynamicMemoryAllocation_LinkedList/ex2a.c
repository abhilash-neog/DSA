#include<stdio.h>
#include<stdlib.h>

int glb;

void* myalloc(int size,int count)
{
void* new = (void*)malloc(size*count);
glb = glb + size*count;
return new;
}

void myfree(void** ptr,int count,int size)

{
glb = glb - size*count;//here sizeof(ptr) returns 1 since here ptr is void* and not int*(although am passing int* pointer), therefore needs to pass the size
printf("%1d\n",size);
free(*ptr);
}

void main(){

	int* ptr = myalloc(sizeof(int),100);
	printf("%2d\n",glb);
	//printf("%1d\n",sizeof(*ptr));
	myfree(&ptr,50,sizeof(*ptr));
	printf("%2d\n",glb);
}

//void* is used since we aren't aware of the type of pointers being used/passed. can be a double/float/int pointer. so void* is sort of a general pointer-generic pointer
/*freeing the pointer only dereferences it, does not delete the data from the address.it is still accessible*/
