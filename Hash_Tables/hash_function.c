#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//char book[20][20];
int best_base=0;int best_tab=0; int least_col=0;
int i=0;
int hashfunction(char *str, int base, int tablesize){
	int len = strlen(str);int sum;int mod;
	for (int i=0;i<len;i++){
		sum = sum + str[i];
		sum = sum%base;//especially for large string values
	} 
	mod = sum%base;
	mod = mod%tablesize;
	return mod;
}
int collision(char** str1,int base, int table){//char [][]str1 shows error!!!

	int leng = i;
	int count;int temp;
	//printf("%d\n", leng);
	int hash[table];
	for(int k=0;k<leng;k++){
		
		temp = hashfunction(str1[k],base,table);	
		printf("%d\n",54);
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
	printf("Number of collisions: %d", count);
	return count;
}
void updateBest(int col, int base, int tab){
	if(col<least_col){
		best_base = base;
		best_tab = tab;
		least_col = col;	
	}
}
char** inputParser(){ //char[][] gives error!maybe doesnt recgnize suh a return type
	FILE* fp = fopen("test_file","r");
	
	char** book = (char**)malloc(sizeof(char*));
	while(!feof(fp)){	
		fscanf(fp,"%s",book[i]);
		i++;
		book = (char**)realloc(book,sizeof(char*)*i);
			
	}
i = i-1; //since i gets incremented an extra time
for(int m=0;m<i;m++){
	printf("%s\n",book[m]);
	}
printf("valid strings - %d\n",i);
return book;
}
void profiler(){
	int table[] = {50,100,500};
	int base[] = {89,93,97,1000001,1000003,1000007};
	char** text = inputParser();
	printf("%s\n",*text[0]);
	least_col = collision(text,base[0],table[0]);
	int no_col;
	int l=0;
	for(int k=0;k<3;k++){
		for(int i=0;i<6;i++){
			no_col = collision(text,base[i],table[k]);
			printf("collisions in  %d is %d", l,no_col);
			updateBest(no_col,base[i],table[k]);l++;
		}	
	}
printf("best_baseNum is %d, at index %d\n", base[best_base],best_base);
printf("best_tabSize is %d, at index %d\n", table[best_tab],best_tab);
}
int main(){profiler();return 0;}
/*char* token = strtok(str," ");
		printf("hello\n");
		while(token!=NULL){
			printf("%s, %d\n",token,i);
			strcpy(st1[i],token);i++;					
			//st1 = (char*)realloc(st1,(i+1)sizeof(char));
         		token = strtok(NULL," ");
			if(token==NULL){printf("%d,null\n",i);}
			
			
		}*/


















