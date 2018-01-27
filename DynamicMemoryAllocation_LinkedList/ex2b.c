#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int glb;

void* myalloc(int size,int count)
{
void* new = (void*)malloc(size*count);
glb = glb + size*count;
return new;
}

void myfree(void* ptr,int count,int size)

{
glb = glb - size*count;
free(ptr);
//printf("%d %d\n",*ptr,*(ptr+count));
}

void main(){
	int* ptri;int k=6;
	while(k>0){
	int m = 10000 + rand() % (15000);
	ptri = (int*)myalloc(sizeof(int),m);
	printf("%d %d %d\n",ptri,(ptri+m),m);//remember ptri+m means ptri+m*4  (size of int)
	myfree(ptri,m,sizeof(ptri));
	//printf("%1d %1d\n",ptri,ptri+m);
	k--;
	}
	/*printf("%2d\n",glb);
	myfree(ptr,20,sizeof(ptr));
	printf("%2d\n",glb);*/
	
}

