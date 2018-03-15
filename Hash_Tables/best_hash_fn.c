#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char book[20][20];
int best_base=0;int best_tab=0; int least_col=0;
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


void updateBest(int col, int base, int tab){
	if(col<least_col){
		best_base = base;
		best_tab = tab;
		least_col = col;	
	}
}
void inputParser(){ //char[][] gives error!maybe doesnt recgnize suh a return type
	FILE* fp = fopen("test_file","r");
	int i=0;
	while(!feof(fp)){	
		fscanf(fp,"%s",book[i]);//fscanf ignores the whitespace character
		i++;
		/*char* token = strtok(str," ");
		printf("hello\n");
		while(token!=NULL){
			printf("%s, %d\n",token,i);
			strcpy(st1[i],token);i++;					
			//st1 = (char*)realloc(st1,(i+1)sizeof(char));
         		token = strtok(NULL," ");
			if(token==NULL){printf("%d,null\n",i);}
			
			
		}*/	
	}
i = i-1; //since i gets incremented an extra time
for(int m=0;m<i;m++){
	printf("%s\n",book[m]);
	}
printf("valid strings - %d\n",i);
	int table[] = {50,100,500};
	int base[] = {89,93,97,1000001,1000003,1000007};
	int temp1;int count1;
	for(int k=0;k<10;k++){
			int hash[table[0]];
			temp1 = hashfunction(book[k],base[0],table[0]);	
			hash[temp1]++;
			if(hash[temp1]>1){
			count1++;		
			}
		}
	least_col = count1;
	int no_col;
	int l=0;
	for(int k=0;k<3;k++){
		for(int i=0;i<6;i++){
			int count=0;int temp;
		//printf("%d\n", leng);
		
		for(int j=0;j<10;j++){
			int hash[table[k]];
			temp = hashfunction(book[j],base[i],table[k]);	
			hash[temp]++;
			if(hash[temp]>1){
			count++;		
			}}
			printf("collisions at combination no %d is %d\n", l,count);
			updateBest(count,i,k);l++;
			
		}	
}
printf("best_baseNum is %d, at index %d\n", base[best_base],best_base);
printf("best_tabSize is %d, at index %d\n", table[best_tab],best_tab);
}

int main(){inputParser();return 0;}
