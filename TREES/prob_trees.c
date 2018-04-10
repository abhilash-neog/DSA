#include<stdio.h>
#include<stdlib.h>

typedef struct node* Node;
typedef struct bst* BST;
struct node{
	int value;
	Node left_st;
	Node rt_st;
	int ht_bal : 2;//limits/ bounds value to within a single digit.
};
int random_generate(){

	return 150 + rand()%20;
}
void add(Node bst,Node new){
	
	if(new->value <= bst->value){
		if(bst->left_st!=NULL){
			add(bst->left_st,new);}// with no return the stack space increases
		else{
			bst->left_st = new;
			printf("Added %d to left of %d\n", new->value,bst->value);
			return;
		}
	}
	if(new->value > bst->value){
		if(bst->rt_st!=NULL){
			add(bst->rt_st,new);}
		else{
			bst->rt_st = new;
			printf("Added %d to right of %d\n", new->value,bst->value);
			return;
		}
	}
	
}

Node createBST(){
	int val;
	Node root_bst = (Node)malloc(sizeof(struct node));
	root_bst->value = random_generate();
	printf("root's value: %d\n", root_bst->value);
	for(int i=0;i<10;i++){
		val = random_generate();
		//printf("value %d is: %d\n", i, val);
		Node x = (Node)malloc(sizeof(struct node));
		x->value = val;
	        add(root_bst,x);
	}
	return root_bst;
}
Node find(Node bst, int num){

	if(num == bst->value){
		return bst;
	}
	else if(num < bst->value){
		return find(bst->left_st,num);
	}
	else{
		return find(bst->rt_st,num);
	}
}
int add_flag;
int minValue(Node x){
	if(x->left_st==NULL){
	return x->value;}
	else{
	return minValue(x->left_st);
	}
}
void deleteNode(Node bst, int val){

	if(bst->value==val){

		if(bst->left_st==NULL && bst->rt_st==NULL){
			printf("finally deleted!\n");
			free(bst);
			bst = NULL;}
		
		else if(bst->left_st==NULL && bst->rt_st!=NULL){
			printf("reached part1\n");
			int temp = bst->value;
			bst->value = bst->rt_st->value;
			bst->rt_st->value = temp;
			deleteNode(bst->rt_st,val);
		}
		else if(bst->left_st!=NULL && bst->rt_st==NULL){
			printf("reached part2\n");			
			int temp = bst->value;
			bst->value = bst->left_st->value;
			bst->left_st->value = temp;
			deleteNode(bst->left_st,val);
		}
		else{
			printf("reached part3\n");
			bst->value = minValue(bst->rt_st);
			deleteNode(bst->rt_st,val);
		}
		
	}
	else if(bst->value > val){
	if(bst->left_st!=NULL){
	deleteNode(bst->left_st,val);}}
	else{
	if(bst->rt_st!=NULL){
	deleteNode(bst->rt_st,val);}}
}
void print(Node p){
	if(p!=NULL){
	print(p->rt_st);
	printf("%d\n",p->value);
	print(p->left_st);}
}
int main(){
	Node myBST = createBST();
	printf("Before deletion!\n");	
	print(myBST);
	deleteNode(myBST, 159);
	//Node x = find(myBST, 162);
	printf("After deletion!\n");
	print(myBST);
return 0;		
}
