#include<stdio.h>
#include<stdlib.h>

typedef struct edge* Edge;
typedef struct adjList* AdjList;
typedef struct graph* Graph;
typedef struct node* Node;
struct edge{

    int v1;
    int v2;
};
struct node{

	int value;
	Node next;
};
struct adjList{

	Node head;
	int vertex;
};
struct graph{

    AdjList adl;
};
int k=0;
void printList(Node n, int val){

    Node temp = n;
    printf("%d",val);
    while(temp!=NULL){
        printf("->%d",temp->value);
        temp = temp->next;
    }
    printf("\n");
}
Edge readGraph(){
    FILE *fp = fopen("citation1.txt","r");
    Edge e1 = (Edge)malloc(sizeof(struct edge));
    int i=1;
    while(!feof(fp)){
        fscanf(fp,"%d %d",&e1[k].v1,&e1[k].v2);
        i+=1;k++;
        e1 = (Edge)realloc(e1,sizeof(struct edge)*i);
    }
    return e1;
}
int isPresent(int* arr, int g, int val){
    int flag;
    for(int h=0;h<g;h++){
        if(val==arr[h]){
            return 1;}
    }
    return 0;

}
int q=0;int* count;
int* noOfVertices(Edge e){

     count = (int*)malloc(sizeof(int));

     for(int j=0;j<k;j++){
        if(isPresent(count,q,e[j].v1)==0){
        count[q] = e[j].v1;

        q++;
        count = (int*)realloc(count, sizeof(int)*(q+1));}
        if(isPresent(count,q,e[j].v2)==0){
        count[q] = e[j].v2;

        q++;
        count = (int*)realloc(count, sizeof(int)*(q+1));}
     }
     printf("Value of q is %d\n", q);
     return count;
}
Node addNode(int vertex, Edge e){

    Node alpha = (Node)malloc(sizeof(struct node));
    Node temp = alpha;
    int hasEdge=0;
    for(int f= 0; f<k;f++){

        if(e[f].v1==vertex){
            Node new = (Node)malloc(sizeof(struct node));
            new->value = e[f].v2;
            temp->next = new;
            temp = new;
            hasEdge++;
        }
    }
    if(hasEdge>0){
    return alpha;}
    else{
    return NULL;}
}
Graph list(Edge e){
    int* n = noOfVertices(e);
    Graph g1 = (Graph)malloc(sizeof(struct graph));
    g1->adl = (AdjList)malloc(sizeof(struct adjList)*q);

    for(int d=0;d<q;d++){

        g1->adl[d].vertex = n[d];
        g1->adl[d].head = addNode(n[d],e);
        //printList(g1->adl[d].head,n[d]);
    }
    return g1;
}
void printEdge(Edge e){

    Edge temp = e;

    for(int m=0;m<k;m++){

        printf("%d %d\n",e[m].v1,e[m].v2);
    }
}
int updateIndegree(int v,Edge e){
    int cx=0;
     for(int l=0;l<k;l++){
        if(e[l].v2==v){
            cx++;
        }
     }
     return cx;
}
int findIndex(int valu, int* vert){
  for(int y=0;y<q;y++){
    if(vert[y]==valu){
      return y;
    }
  }
  return -1;
}
int findMin(int* arr,int qq,int deg){

  int least_degree_index=deg;
  for(int v=0;v<qq;v++){
    printf("indgrees:%d\n",arr[v]);
    if(arr[v]<=arr[least_degree_index]){least_degree_index=v;}
  }
  return least_degree_index;
}
int* find_update_adjacents(int ind, int* d,Edge e,int* vert){
  for(int f=0;f<k;f++){
    if(e[f].v1==vert[ind]){
      int in = findIndex(e[f].v2,vert);
      d[in]--;
    }
  }
  return d;
}
int findMax(int* a1,int size){
  int great = a1[0];
  for(int e=0;e<size;e++){
    if(a1[e]>=great){great = a1[e];}
  }
  return great;
}
int* topoSort(Edge e){//topological sorting using edge list implementation
     int* vertices = count;
     int* indegree = (int*)malloc(sizeof(int)*q);
     for(int m=0;m<q;m++){
        indegree[m] = updateIndegree(vertices[m],e);
        printf("indegree of index %d - %d\n",m,indegree[m]);
     }//got the indegree stored
     int* sorted = (int*)malloc(sizeof(int)*q);//use dynamic allocation to avoid errors
     int index=0;
     int max = findMax(indegree,q);
     for(int h=0;h<q;h++){
       index = findMin(indegree,q,index);//returns the index of the min value
       printf("index - %d\n",index);
       sorted[h] = vertices[index];
       indegree[index] = max;
       //the index of the element added
       //update indegree of adjacent vertices
       indegree = find_update_adjacents(index,indegree,e, vertices);
   }
   return sorted;
}
int main(){
    Edge e = readGraph();
    printEdge(e);
    printf("Adjacenecy list: \n");
    Graph g = list(e);
    printf("Done with adjacency list\n");
    int* ax = topoSort(e);
    FILE* f = fopen("sorted_vert","w");
    for(int c=0;c<q;c++){
      fprintf(f,"Sorted vertices: %d\n",ax[c]);
    }
    return 0;
}
