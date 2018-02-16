#include<stdio.h>
#include<stdlib.h>
#include "elements.h"

Element RecordReader(FILE* fp){

Element row = (Element)malloc(sizeof(struct element));

int i=0;
while(!feof(fp))
{
	row = (Element)realloc(row,sizeof(struct element)*(i+1));
	fscanf(fp," \" %[^,], %[^,], %[^,], %[^,], %[^\"] \" \n",&(row[i].Card_Number),row[i].Bank_code,row[i].expiry_date,row[i].First_name,row[i].Last_name);
	printf("%ld %s %s %s %s\n",row[i].Card_Number,row[i].Bank_code,row[i].expiry_date,row[i].First_name,row[i].Last_name);
	i++;
}
//fscanf does not return anything,just updates the pointer fp
//row simply points to the location.to extract the contents row->, but row[i] points to the contents of that position
	/*extracting the tokens using strtok;
	char str[100];
	char* last_token;
	const char* delim = ",";
	while(fgets(str, 100, fp) != NULL ){
        	    last_token = strtok(str, delim);
	
        	    while( last_token != NULL ){
        	        printf( "%s\n", last_token );
        	        last_token = strtok( NULL, delim);
        	    }

        	}*/
		

return row;
}

