#include<stdio.h>
#include<stdlib.h>

typedef struct node* Node;

struct node{
	int value;
	Node left_st;
	Node rt_st;
	int ht;     // : 2;//limits/ bounds value to within a single digit.
};
int random_generate(){

	return 5 + rand()%10;
}

/*Node find_parent(Node bt, Node Z){
	//tree traversal from root to find parent of Z
	Node parent = (Node)malloc(sizeof(struct node));
	if(bt->left_st == Z || bt->rt_st==Z){	
		parent = bt;	
	}
	else{
		Node traverse = bt;
		while(traverse!=NULL){
			if(traverse->left_st == Z || traverse->rt_st==Z){	
				parent = bt; break;	
			}
			if(traverse->value < Z){
				traverse = traverse->rt_st;			
			}		
			else{
				traverse = traverse->left_st;			
			}
		}	
	}
	return parent;
}*/
int height(Node X)
{
    if (X == NULL)
        return 0;
    return X->ht;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
int getBalance(Node N)
{
    if (N == NULL)
        return 0;
    return height(N->rt_st) - height(N->left_st);
}
Node rightRotate(Node Z)
{
    Node Y = Z->left_st;
    Node T2 = Y->rt_st;
 
    // Perform rotation
    Y->rt_st = Z;
    Z->left_st = T2;
 
    // Update heights
    Z->ht = max(height(Z->left_st), height(Z->rt_st))+1;
    Y->ht = max(height(Y->left_st), height(Y->rt_st))+1;
 
    // Return new root
    return Y;
}
 
Node leftRotate(Node Z)
{
    Node Y = Z->rt_st;
    Node T2 = Y->left_st;
 
    // Perform rotation
    Y->left_st = Z;
    Z->rt_st = T2;
 
    //  Update heights
    Z->ht = max(height(Z->left_st), height(Z->rt_st))+1;
    Y->ht = max(height(Y->left_st), height(Y->rt_st))+1;
 
    // Return new root
    return Y;
}
/*
void rotate(Node X, Node Y, Node Z){
	//Node parent = find_parent(bt, Z);
	//cases 1,2,3,4
	if(Z->left_st == Y && Y->left_st==X){
		//rotate z right			
		Node temp = Y->rt_st;
		Y->rt_st	= Z;
		Z->left_st = temp;
		if(Z->value > parent->value){
			parent->rt_st = Y;	
		}
		else{
			parent->left_st = Y;	
		}
	}
	else if(Z->left_st == Y && Y->rt_st==X){
		//rotate Y left;		
		Node temp = Y->left_st; 
		X->left_st = Y;
		Y->rt_st = temp;
		Z->left_st = X;
		//rotate Z right
		Node alpha = X->rt_st;
		X->rt_st = Z;
		Z->left_st = alpha;
		if(Z->value > parent->value){
			parent->rt_st = X;	
		}
		else{
			parent->left_st = X;	
		}
	}
	else if(Z->rt_st == Y && Y->rt_st==X){
		//left rotate Z		
		Node temp = Y->left_st; 
		Y->left_st = Z;
		Z->rt_st = temp;
		if(Z->value > parent->value){
			parent->rt_st = Y;	
		}
		else{
			parent->left_st = Y;	
		}
	}
	else{
		if(Z->rt_st == Y && Y->left_st==X){
			//right rotate Y
			Node temp = X->rt_st;
			X->rt_st = Y;
			Y->left_st = temp;
			//left rotate Z
			Node beta = X->left_st;
			X->left_st = Z;
			Z->rt_st = beta;
			if(Z->value > parent->value){
				parent->rt_st = X;	
			}
			else{
				parent->left_st = X;	
			}
		}	
	}
	
}*/


Node newNode(int key)
{
    Node node = (Node)
                        malloc(sizeof(struct node));
    node->value   = key;
    node->left_st   = NULL;
    node->rt_st  = NULL;
    node->ht = 1;  // new node is initially added at leaf
    return node;
}
Node insert(Node bst,int val){
	
   	 if (bst == NULL){
        	return(newNode(val));}
   	 if (val < bst->value){
        	bst->left_st  = insert(bst->left_st, val);}
    	else if (val > bst->value){
    		bst->rt_st = insert(bst->rt_st, val);}
   	else {// Equal keys are not allowed in BST
		return bst;}
	
	bst->ht = 1 + max(height(bst->left_st),height(bst->rt_st));
	int balance = getBalance(bst);
	printf("Balance - %d\n", balance);
	//left left case
	if (balance < -1 && val < bst->left_st->value){
		return rightRotate(bst);
	}
	//right right case
	if (balance > 1 && val> bst->rt_st->value){
       		return leftRotate(bst);}
 
    	// Left Right Case
    	if (balance < -1 && val> bst->left_st->value)
    	{
		bst->left_st = leftRotate(bst->left_st);
		return rightRotate(bst); 	
    	}
 
    	// Right Left Case
    	if (balance >1 && val < bst->rt_st->value){
		bst->rt_st = rightRotate(bst->rt_st);
		return leftRotate(bst);	}
return bst;
}
Node createBST(){
	Node root_bst = NULL;
	for(int i=0;i<10;i++){
		int x = random_generate();
		printf("random value - %d\n", x);
	        root_bst = insert(root_bst,x);
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
int minValue(Node x){
	if(x->left_st==NULL){
	return x->value;}
	else{
	return minValue(x->left_st);
	}
}
Node deleteNode(Node bst, int val){

	if(bst->value==val){

		if(bst->left_st==NULL && bst->rt_st==NULL){
		
			free(bst);}
		
		else if(bst->left_st==NULL && bst->rt_st!=NULL){
			
			bst->value = bst->rt_st->value;
			deleteNode(bst->rt_st,val);
		}
		else if(bst->left_st!=NULL && bst->rt_st==NULL){
			bst->value = bst->left_st->value;
			deleteNode(bst->left_st,val);
		}
		else{
			bst->value = minValue(bst->rt_st);
			deleteNode(bst->rt_st,val);
		}
		
	}
	else if(bst->value > val){
	deleteNode(bst->left_st,val);}
	else{
	deleteNode(bst->rt_st,val);}
}
int arr[10];int h=0;
void visit(Node b){
	arr[h] = b->value;
	h++;
}
void Inorder(Node bst)
{
     if (bst == NULL)
          return;

     Inorder(bst->left_st);
     visit(bst); 
     Inorder(bst->rt_st);
}
int ksmallest(Node bst, int K){
	
	Inorder(bst);
	return arr[K-1];
}
void print(Node p){
	if(p!=NULL){
	print(p->rt_st);
	printf("%d\n",p->value);
	print(p->left_st);}
}
int main(){
	Node myBST = createBST();
	print(myBST);
	int v = ksmallest(myBST, 2);
	printf("2nd smallest is %d\n", v);
          return 0;		
}
