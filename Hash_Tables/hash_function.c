#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "interface.h"

int count;
int least_col=0;
int best_base;int best_tab;
int best_base_index;int best_tab_index;
int k=0; char** book;
int hashfunction(char *str, int base, int tablesize){
	int len = strlen(str);int sum =0;int mod=0;
	for (int i=0;i<len;i++){
		sum = sum + str[i];
		//sum = sum%base;//especially for large string values
	} 
	mod = sum%base;
	mod = mod%tablesize;
	return mod;
}
int collision(char** str1,int base, int table){//char [][]str1 shows error!!!

	int leng = k;
	int temp;
	//printf("%d\n", leng);
	int hash[table];
	for(int k=0;k<leng;k++){
		
		temp = hashfunction(str1[k],base,table);	
		hash[temp]++;
		if(hash[temp]>1){
			count++;		
		}
	}
	/*counts only where collision happens->for(int m=0;m<table;m++){
		if(hash[m]>1){
			count++;		
			}	
	}*/
	//printf("Number of collisions: %d\n", count);
	return count;
}
void updateBest(int col, int base, int tab){

	if(col<least_col){
		best_base_index = base;
		best_tab_index = tab;
		least_col = col;
		printf("least collision: %d\n",least_col);	
	}
}
char** inputParser(){ //char[][] gives error!maybe doesnt recgnize suh a return type
	FILE* fp = fopen("aliceinwonderland.txt","r");
	
	book = (char**)malloc(sizeof(char*)*30);
	int i;
	int count1=10;
	for(i=0;i<10;i++){
	book[i]=(char*)malloc(sizeof(char)*20);}	
	while(fscanf(fp,"%s",book[k++])!=-1)
	{
		if(count1==k+1)
		{
			count1+=10;
			book = (char**)realloc(book,sizeof(char*)*count1);
			for(i=count1-10;i<count1;i++){
			book[i]=(char*)malloc(sizeof(char)*20);}
		}
	}

//for(int m=0;m<k-1;m++){
	printf("AT index 161 - %s\n",book[161]);
//	}
printf("valid strings - %d\n",k-1);
return book;
}
void profiler(){
	int table[] = {500,50,100};
	int base[] = {97,89,93,1000001,1000003,1000007};
	//char** text = inputParser();
	//printf("%s\n",*text[0]);
	least_col = collision(book,base[0],table[0]);
	int no_col;
	int l=0;
	for(int k=0;k<3;k++){
		for(int i=0;i<6;i++){
			no_col = collision(book,base[i],table[k]);
			count = 0;
			printf("collisions in  %d is %d\n", l,no_col);
			updateBest(no_col,i,k);l++;
		}	
	}
best_base = base[best_base_index];
best_tab = table[best_tab_index];
printf("best_baseNum is %d, at index %d\n", base[best_base_index],best_base_index);
printf("best_tabSize is %d, at index %d\n", table[best_tab_index],best_tab_index);
}
//int main(){book = inputParser();profiler();return 0;}
/*char* token = strtok(str," ");
		printf("hello\n");
		while(token!=NULL){
			printf("%s, %d\n",token,i);
			strcpy(st1[i],token);i++;					
			//st1 = (char*)realloc(st1,(i+1)sizeof(char));
         		token = strtok(NULL," ");
			if(token==NULL){printf("%d,null\n",i);}
			
			
		}*/


















