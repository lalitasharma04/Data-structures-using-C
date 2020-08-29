
 /*
 		Author:Lalita Sharma
 		Date:20/07/2019
 		Aim:To study an array ADt and to implement various operations on an arrayADT
 */
 
 //headers
 #include<stdio.h>
 
 //pre-proc directives
 
 #define MX_SZ 5
 #define MN_VAL -99
 
 int main()
 {
 	int arr[MX_SZ],arr2[MX_SZ],arr3cpy[MX_SZ],choice1,choice2,value,index,element2,len2;
 	//arr2 is for merge purpose,arr3cpy is for copy operation......len2 is length of arr2
 	printf("An Array ADT\n");
 	printf("-------------------------\n\n");
 	int len=InitArray(arr);   //to initialize the length of the array to 0
 
 	printf("Create an array??? Enter 1 for yes and 0 for no\n");
 	scanf("%d",&choice1);
 	if(choice1==0){
 		return 0;
	 }
	 else{
	 	printf("yeah you are here!!!!!!\n");
	 	len=CreateArr(arr);//creating the array and return the length of the array
	 	printf("Successfully created the array!!!!!!\n\n");
	 	do{
	 		printf("The Array ADT operations here....\n");
	 		printf("\n1.Length \t 2.Display \t 3.Insert \t 4.Delete \t 5.Sort \t 6.Search\n");
	 		printf("7.Merge \t 8.Copy \t 9.IsFull \t 10.IsEmpty \t 11.Traverse \t 0.Exit\n");
	 		scanf("%d",&choice2);
	 		switch(choice2){
			 
	 			case 0:
	 				printf("Terminating the program--------------\n");
	 				break;
	 		    case 1:
	 		    	printf("The Length of array is %d\n",LengthArray(arr));
	 		    	printf("----------------------------------------\n\n");
	 		    	break;
	 		    case 2:
	 		    	len=LengthArray(arr);
	 		    	if(len==0){
	 		    		printf("oops your array is empty,nothing to be displayed...\n");
					 }
					 else{
					 	printf("\nyes sure your array is here\n");
					 	DisplayArray(arr,len);
					}
					printf("------------------------------------------------------\n\n");
					break;
				case 3:
					if(IsFull(arr)==1){
						printf("You will have to delete something to insert your element.....\n");
					}
					else{
						do{
							printf("Enter the value to be inserted ...and index starting from 0\n");
							scanf("%d %d",&value,&index);
						}while(index>LengthArray(arr) || value==-99 );
					    len=InsertArray(arr,index,value);
						printf("Element %d was successfull inserted at %d.....\n",value,index);
					}
					printf("-------------------------------------------------------------\n\n");
					break;
	 		    case 4:
	 		    	if(IsEmpty(arr)){
	 		    		printf("Array is already Empty,nothing to delete....\n");	
					}
					else{
						do{
							printf("Enter the index of the element to be deleted...\n");
					    	scanf("%d",&index);
						    
						}while(index>=MX_SZ || index<0 || index>LengthArray(arr)-1);
						int element=DeleteArray(arr,index);
						printf("element %d deleted.....\n",element);
					}
					printf("-----------------------------------------------------------------\n\n");
					break;
				case 5:
					printf("Array before sorting is...........  \n");
					printf("-----------------------------------------\n");
					DisplayArray(arr,LengthArray(arr));
					SortArray(arr);
					printf("Array after sorting is...........  \n");
					printf("-----------------------------------------\n");
					DisplayArray(arr,LengthArray(arr));
					printf("---------------------------------------------------------\n\n");
					break;
				case 6:
					printf("Enter the element to be searched....\n");
					scanf("%d",&element2);
					int pos=SearchArray(arr,element2);
					if(pos==-1){
						printf("Element %d is not found\n",element2);
					}
					else{
						printf("Element %d found at %d index\n",element2,pos);
					}
					printf("-------------------------------------------------\n\n");
					break;
				case 7:
					
					len2=InitArray(arr2);
					len2=CreateArr(arr2);
					printf("Array 1 is----\n");
					DisplayArray(arr,LengthArray(arr));
					printf("Array 2 is----\n");
					DisplayArray(arr2,len2);
					MergeArray(arr,arr2,len2);
					printf("---------------------------------------------------------\n\n");
					break;
				case 8:
					CopyArray(arr,arr3cpy);
					printf("copied array is.............\n");
					DisplayArray(arr3cpy,LengthArray(arr));
					printf("Array copied successfully...\n");
					printf("------------------------------------------------------------\n\n");
					break;
				case 9:
					if(IsFull(arr)){
						printf("Array is full...\n");
					}
					else{
						printf("Array is not full........\n");
					}
					printf("--------------------------------------------------------\n\n");
					break;
				case 10:
					if(IsEmpty(arr)){
						printf("Array is Empty...\n");
					}
					else{
						printf("Array is not Empty........\n");
					}
					printf("------------------------------------------------------\n\n");
					break;
				case 11:
					printf("Traversing the array..........\n");
					Traverse(arr);
					printf("-----------------------------------------------------\n\n");
					break;
	 		}	
		 }while(choice2!=0);
	 	
	 	
	 }
	 return 0;
 }

//initializing array here
int InitArray(int arr[]){
	arr[0]=MN_VAL;
	return 0;
}

//Creating array here
int CreateArr(int  arr[]){
	int index=0;
	printf("Enter the elements of the array.....and -99 to stop\n");
	do{
		
		scanf("%d",&arr[index]);
		if(arr[index]==MN_VAL){
			break;
		}
		index++;
	}while(index<MX_SZ && arr[index]!=MN_VAL);
	return (index);
}

//Length of the array
int LengthArray(int arr[]){
	int count=0;
	while(arr[count]!=MN_VAL && count<MX_SZ){
		count++;
	}
	return count;
}
//displaying the array
void DisplayArray(int arr[],int len){
	int index=0;
	while(index<len){
		printf("\n%d",arr[index]);
		index++;
	}
	printf("\n-------------------------------\n\n");
	
		
}
//IsFull
int IsFull(int arr[])
{
	if(LengthArray(arr)==MX_SZ){
		return 1;
	}
	return 0;
}
//Insert Element
int InsertArray(int arr[],int index,int value){
	int len=LengthArray(arr);
	int i;
	for(i=len;i>=index;i--){
		arr[i+1]=arr[i];
	}
	arr[index]=value;
	
	
	return len+1;
}
//IsEmpty
int IsEmpty(int arr[]){
	if(LengthArray(arr)==0){
		return 1;
	}
	return 0;
}
//deleteArray
int DeleteArray(int arr[],int index){
	int len=LengthArray(arr),i;
	int ele=arr[index];
	for(i=index;i<len;i++){
		arr[i]=arr[i+1];
	}
	if(len=MX_SZ){
		arr[len-1]=MN_VAL;
	}
	return ele;
}
//SortArray
void SortArray(int arr[]){
	int i,j;
	for(i=0;i<LengthArray(arr);i++){
		for(j=i+1;j<LengthArray(arr);j++){
			if(arr[i]>arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
//Search
int SearchArray(int arr[],int element){
	int i;
	for(i=0;i<LengthArray(arr);i++){
		if(arr[i]==element){
			return i;
		}
	}
	return -1;
}
//merge
void MergeArray(int arr1[],int arr2[],int len2){
	int total=LengthArray(arr1)+len2;
	int arr3[total];
	int i=0,j=0;
	for(i=0;i<LengthArray(arr1);i++){
		arr3[i]=arr1[i];
	}
	for(j=0;j<len2;j++,i++){
		arr3[i]=arr2[j];
	}
	printf("Merged array is-----\n");
	DisplayArray(arr3,total);
} 
//copy
void CopyArray(int arr[],int * arr3cpy){
	int i;
	for(i=0;i<LengthArray(arr);i++){
		arr3cpy[i]=arr[i];
	}
}
//traverse
void Traverse(int arr[]){
	int i=0;
	for(i=0;i<LengthArray(arr);i++){
		printf("\n%d \n",arr[i]*2);
	}
}
