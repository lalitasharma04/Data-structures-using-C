/*
 		Author:Lalita Sharma
 		Date:01/08/2019
 		Aim:To study various Comparative Sorting Techniques.
 */
 
//headers 
#include<stdio.h>
#include <time.h> 
#include<stdlib.h>

//pre-proc directives

int main(){
	clock_t t1,t2;
	double total;
	int*arr;
	int* arr3;
	int size,choice,choice1;
	int size2,choice2;
	printf("You will have to create an array \n");
	printf("Do you wish to create a random array??enter 1 for yes.....\n");
	scanf("%d",&choice1);
	if(choice1==1){
		printf("Enter the size of the array.......\n");
		scanf("%d",&size);
		arr=(int*)malloc( size * sizeof(int));
		if (arr== NULL) { 
        	printf("Memory not allocated.\n"); 
        	return 0;
    	}
     	CreateRandomArray(arr,size);
     	printf("Array Created successfully...........\n\n");
     	DisplayArray(arr,size);
	}
	else{
		printf("You chose to enter the array manually............\n ");
		printf("Enter the size of the array.......\n");
		scanf("%d",&size);
		arr=(int*)malloc( size * sizeof(int));
		if (arr== NULL) { 
        	printf("Memory not allocated.\n"); 
        	return 0;
    	}	 
    	CreateArray(arr,size);
    	printf("Array Created successfully...........\n\n");
    	DisplayArray(arr,size);

	}
	
	int arr2[size];
    
    	
    do{
    		
	    	
		printf("\n\nchoice???\n\n");
		printf("1.Selection Sort \t 2.Insertion Sort \t 3.Bubble Sort \t 4. Shell Sort \t 5.counting Sort\n");
		printf("6.Quick Sort \t 7.Merge Sort \t 8.Heap Sort \t 9.Display \t 0.EXIT \n");
		printf("-------------------------------------------------------------------------\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 0:
				printf("...................terminating.......................\n");
				break;
			case 1:
				CopyArray(arr,arr2,size);//coping arr into arr2	
	//	    			DisplayArray(arr2,size);
				t1=clock();
				SelectionSort(arr2,size);
				t2=clock();
				total=((double)(t2-t1))/ CLOCKS_PER_SEC;
				printf("Array is sorted successfully,time taken=%f seconds\n\n",total);
				printf("--------------------------------------------------------------\n");
				break;
			case 2:
				CopyArray(arr,arr2,size);//coping arr into arr2
				t1=clock();
				InsertionSort(arr2,size);
				t2=clock();
				total=((double)(t2-t1))/ CLOCKS_PER_SEC;
				printf("Array is sorted successfully,time taken=%f seconds\n\n",total);
				printf("--------------------------------------------------------------\n");
				break;
			case 3:
				CopyArray(arr,arr2,size);//coping arr into arr2
				t1=clock();
				BubbleSort(arr2,size);
				t2=clock();
				total=((double)(t2-t1))/ CLOCKS_PER_SEC;
				printf("Array is sorted successfully,time taken=%f seconds\n\n",total);
				printf("--------------------------------------------------------------\n");
				break;
			case 4:
				CopyArray(arr,arr2,size);//coping arr into arr2
				t1=clock();
				ShellSort(arr2,size);
				t2=clock();
				total=((double)(t2-t1))/ CLOCKS_PER_SEC;
				printf("Array is sorted successfully,time taken=%f seconds\n\n",total);
				printf("--------------------------------------------------------------\n");
				break;
			case 5:
				
				printf("I think you should make another array for counting sort...\n");
				printf("do u wish to make another array or continue in the same??enter 1 for yes\n");
				scanf("%d",&choice2);
				if(choice2==1){
					printf("Enter the size here.....\n");
					scanf("%d",&size2);
				
					arr3=(int *)malloc(size2 * sizeof(int));
					if(arr3==NULL){
						printf("No memory allocated\n");
						break;	
					}
					printf("Counting sort works better with a range (0-9)....\n");
					CreateArray(arr3,size2);
					printf("Array is created......\n");	
					CopyArray(arr3,arr2,size2);
					t1=clock();
					CountingSort(arr2,size2);
					t2=clock();
					total=((double)(t2-t1))/ CLOCKS_PER_SEC;
					printf("Array is sorted successfully,time taken=%f seconds\n",total);
					printf("displaying sorted array here....\n");
				    DisplayArray(arr2,size2);
				}
				else{
					CopyArray(arr,arr2,size);
					t1=clock();
					CountingSort(arr2,size);
					t2=clock();
					total=((double)(t2-t1))/ CLOCKS_PER_SEC;
					printf("Array is sorted successfully,time taken=%f seconds\n",total);
					printf("displaying sorted array here....\n");
					DisplayArray(arr2,size);
				}
				printf("--------------------------------------------------------------\n");
				break;
			case 6:
				CopyArray(arr,arr2,size);
				t1=clock();
				QuickSort(arr2,0,size-1);
				t2=clock();
				total=((double)(t2-t1))/ CLOCKS_PER_SEC;
				printf("Array is sorted successfully,time taken=%f seconds\n\n",total);
				printf("--------------------------------------------------------------\n");
				break;
			case 7:
				CopyArray(arr,arr2,size);
				t1=clock();
				MergeSort(arr2,0,size-1);
				t2=clock();
				total=((double)(t2-t1))/ CLOCKS_PER_SEC;
				printf("Array is sorted successfully,time taken=%f seconds\n\n",total);
				printf("--------------------------------------------------------------\n");
				break;
			case 8:
				CopyArray(arr,arr2,size);
				t1=clock();
				HeapSort(arr2,size);
				t2=clock();
				total=((double)(t2-t1))/ CLOCKS_PER_SEC;
				printf("Array is sorted successfully,time taken=%f seconds\n\n",total);
				printf("--------------------------------------------------------------\n");
				break;
			case 9:
				DisplayArray(arr2,size);
				break;
				
	    }
	}while(choice!=0);
	return 0;
	
}
 //create array
 void CreateArray(int  a[],int size){
 	int i;
 	printf("Enter the array here...........\n");
 	for(i=0;i<size;i++){
 		scanf("%d",&a[i]);
	 }
 }
 void CreateRandomArray(int a[],int size){
 	int i,ch,min,max;
// 	srand(time(0));
 	printf("Do you want any limit or upper range?(enter 1 for yes)\n");
 	scanf("%d",&ch);
 	if(ch==1){
 		printf("enter the range(min and max).....\n");
 		scanf("%d %d",&min,&max);
 		for(i=0;i<size;i++){
 			a[i]=rand()%(max+1-min)+min;
	 	}
 	}
 	else{
 		for(i=0;i<size;i++){
 			a[i]=rand()%(999999+1-0)+0;
	   }
	}
 	
 }
 //DisplayArray
 void DisplayArray(int a[],int size ){
 	printf("Array contents are.................\n");
 	int i;
 	for(i=0;i<size;i++){
 		printf("%d\t",a[i]);
	 }
 }
 //Copy
 void CopyArray(int arr[],int * arr2cpy,int size){
	int i;
	for(i=0;i<size;i++){
		arr2cpy[i]=arr[i];
	}
}
//Swap
void Swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
//Selection Sort
void SelectionSort(int arr2[],int size){
	int i,j;
	for(i=0;i<=size-2;i++){
		for(j=i+1;j<size;j++){
			if(arr2[i]>arr2[j]){
				Swap(&arr2[i],&arr2[j]);
			}
		}
	}
}
//InsertionSort
void InsertionSort(int arr2[],int size){
	int i,j;
	for(i=1;i<size;i++){
		j=i;
		while(j>0 && arr2[j]<arr2[j-1]){
			Swap(&arr2[j],&arr2[j-1]);
			j--;
		}
	}
}
//BubbleSort
void BubbleSort(int * arr2,int size){
	int i,j;
	for(i=0;i<=size-2;i++){
		for(j=0;j<=size-2-i;j++){
			Swap(&arr2[j],&arr2[j+1]);
		}
	}
}
//ShellSort
void ShellSort(int *arr2,int size){
	int gap,i,j,temp;
	for(gap=size/2;gap>=1;gap=gap/2){
		for(j=gap;j<size;j++){
			for(i=j-gap;i>=0;i=i-gap){
				if(arr2[gap+i]>arr2[i]){
					break;
				}
				else{
					temp=arr2[gap+i];
					arr2[gap+i]=arr2[i];
					arr2[i]=temp;
					
				}
			}
		}
	}
}
//CountingSort
void CountingSort(int *arr2,int size){
	int max,i,b[size];
	max=arr2[0];
	for(i=1;i<size;i++){
		if(arr2[i]>max){
			max=arr2[i];
		}
	}
	int count[max+1];
	for(i=0;i<max+1;i++){
		count[i]=0;
	}
	for(i=0;i<size;i++){
		++count[arr2[i]];
	}
	for(i=1;i<=max;i++){
		count[i]=count[i]+count[i-1];
	}
	for(i=size-1;i>=0;i--){
		b[--count[arr2[i]]]=arr2[i];
	}
	CopyArray(b,arr2,size);
}
//quickSort
void QuickSort(int  arr2[],int lb,int ub){
	int loc;
	if(lb<ub){
		loc=Partition(arr2,lb,ub);
		QuickSort(arr2,lb,loc-1);
		QuickSort(arr2,loc+1,ub);
	}
}



int Partition(int arr2[],int lb,int ub){
	int pivot=arr2[lb];
	int start=lb,end=ub;
	while(start<end){
		while(arr2[start]<=pivot){
			start++;
		}
		while(arr2[end]>pivot){
			end--;
		}
		if(start<end){
			Swap(&arr2[start],&arr2[end]);
		}
	}
	Swap(&arr2[lb],&arr2[end]);
	return end;
}

//MergeSort
void MergeSort(int * arr2,int lb,int ub){
	int mid;
	int size=ub+1;
	if(lb<ub){
		mid=(lb+ub)/2;
		MergeSort(arr2,lb,mid);
		MergeSort(arr2,mid+1,ub);
		Merge(arr2,lb,mid,ub,size);
	}
}
//Merge function
void Merge(int arr[], int lb, int mid, int ub) 
{ 
    int i, j, k; 
    int n1 = mid - lb + 1; 
    int n2 = ub - mid; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[lb + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = lb; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
//HeapSort
void HeapSort(int arr[],int leng){
	int i;
	BuildHeap(arr,leng-1);
	for(i=leng-1;i>0;i--){
		Swap(&arr[0],&arr[i]);
		leng--;
		Heapify(arr,0,leng-1);
	}
}
void BuildHeap(int arr[],int leng){
	int i;
	for(i=leng/2;i>=0;i--){
		Heapify(arr,i,leng);
	}
}
void Heapify(int arr[],int i,int leng){
	int l,r,largest;
	l=left(i);
	r=right(i);
	if(l<=leng && arr[l]>arr[i]){
		largest=l;
	}
	else{
		largest=i;
	}
	if(r<=leng && arr[r]>arr[largest]){
		largest=r;
	}
	if(largest!=i){
		Swap(&arr[i],&arr[largest]);
		Heapify(arr,largest,leng);
	}
}
int left(int i){
	return 2*i+1;
}
int right(int i){
	return 2*i+2;
}
