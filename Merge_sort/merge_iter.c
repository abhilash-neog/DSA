#include<stdio.h>
#include<stdlib.h>
#include "merge.h"

int min(int x, int y) { 
	return (x<y)? x :y; 
}
void merge(Element ls1,int sz1,Element ls2,int sz2,Element ls){
int i=0;int j=0;int k=0;
	while(i<sz1 && j<sz2)
	{
	if(ls1[i].cgpa<ls2[j].cgpa)
	{
	ls[k]=ls1[i];
	i++;
	k++;
	}
	else
	{
	ls[k]=ls2[j];
	j++;
	k++;
	} 
	}
while(i<sz1)
	{
	ls[k]=ls1[i];
	k++;
	i++;
	}
while(j<sz2)
{
	ls[k]=ls2[j];
	k++;
	j++;
}

}
void mergeSort(Element ls, int n)
{
   int curr_size; // curr_size varies from 1 to n/2
   int left_start; // For picking starting index of left subarray to be merged
 
   // Merge subarrays in bottom up manner.  First merge subarrays of
   // size 1 to create sorted subarrays of size 2, then merge subarrays
   // of size 2 to create sorted subarrays of size 4, and so on.
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           // Find ending point of left subarray. mid+1 is starting 
           // point of right
           int mid = left_start + curr_size - 1;
           int right_end = min(left_start + 2*curr_size - 1, n-1);
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
	   struct element ls1[curr_size];
           struct element ls2[curr_size];
		int i=0;
		int j=0;
		int f=0;
		for(i=left_start;i<=mid;i++)
		{
		ls1[i]=ls[j];
		j++;
		}
		for(f=mid+1;f<=right_end;f++)
		{
		ls2[f-mid]=ls[j];
		j++;
		}
           merge(ls1, curr_size, ls2, curr_size,ls);
       }
   }
}
void result(double elapsedtime2,double elapsedtime1){
	
FILE* f = fopen("Result_iter.txt","w");
fprintf(f,"Time for loading data:%f\n Time for Sorting:%f",elapsedtime2,elapsedtime1);
}
/*void main(int argc, char **argv){
FILE* fp = fopen(argv[1],"r");//file in c can read the contents line by line
int size=atoi(argv[2]);
gettimeofday(&t3,NULL);
Element orig_list = Reader(fp,size);
gettimeofday(&t4,NULL);
print(orig_list,size);
elapsedtime2 = (t4.tv_sec - t3.tv_sec)*1000;
elapsedtime2 += (t4.tv_usec - t3.tv_usec)/1000;
printf("After sorting:\n");
gettimeofday(&t1,NULL);
mergeSort(orig_list,size);
gettimeofday(&t2,NULL);
elapsedtime1 = (t2.tv_sec - t1.tv_sec)*1000;
elapsedtime1 += (t2.tv_usec - t1.tv_usec)/1000;
print(orig_list,size);
printf("time required for sorting:%f ms\n", elapsedtime1);
printf("time required for loading:%f ms\n", elapsedtime2);
FILE* f = fopen("Result_iter.txt","w");
fprintf(f,"Time for loading data:%fms\n Time for Sorting:%f ms",elapsedtime2,elapsedtime1);
}
*/

