#include<stdio.h>
#include<stdlib.h>

int bits;

void p(int n){
//if(n!=10000){
printf("%u\n",&n);
p(n++);//}
//printf("%u\n",&pilani);
}
void g(){
int goa;
printf("%u\n",&goa);
}
void h(){
int hyd;
printf("%u\n",&hyd);
}
void d(){
int dub;
printf("%u\n",&dub);
}
int main()
{
	//printf("%u\n",&bits);
	p(3);
	//g();
	//h();
	//d();	
}
