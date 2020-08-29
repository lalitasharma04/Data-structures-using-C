/*
	Author:Lalita Sharma
	Aim:To implement QueueADT and Circular Queue ADT using arrays...
*/

//headers
#include<stdio.h>

//pre-proc directives
#define MX_SZ 5

//Driver Function
int main(){
	int queue[MX_SZ],cqueue[MX_SZ],choice,choice1,choice2,ele,rear=-1,front=-1,val;
	do{
		printf("Enter your choice???\n");
		printf("1.Queue   \t   2.Circular Queue  \t  0.Exit\n");
		printf("***********************************************************************\n");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				printf("Terminating.....\n");
				break;
			case 1:
				printf("Do you want pre-filled queue?(enter 1 for yes)\n");
				scanf("%d",&choice1);
				if(choice1==1){
					CreateQueue(queue,&rear,&front);
					printf("Queue is created Successfully.....\n");
				
				}
				do{
					printf("Enter the operation ....\n");
					printf("1.Insert \t 2.Delete \t 3.Display \t 4.Front Value \n");
					printf("5.Rear value \t 6.IsEmpty \t 7.IsFull \t 0.Exit\n");
					printf("************************************************************************\n");
					scanf("%d",&choice2);
					switch(choice2){
						case 0:
							break;
						case 1:
							InsertQueue(queue,&rear,&front);
							printf("-----------------------------------------\n\n");
							break;
						case 2:
						    ele=DeleteQueue(queue,&rear,&front);
							if(ele!=-1){
								printf("%d was deleted successfully..\n",ele);
							}
							printf("-----------------------------------------\n\n");
							break;
						case 3:
							DisplayQueue(queue,&rear,&front);
							printf("\n-----------------------------------------\n\n");
							break;
						case 4:
							val=FrontValue(queue,&front);
							if(val){
								printf("value at front is %d..\n",val);
							}
							printf("-----------------------------------------\n\n");
							break;
						case 5:
							val=RearValue(queue,&rear);
							if(val){
								printf("value at rear is %d..\n",val);
							}
							printf("-----------------------------------------\n\n");
							break;
						case 6:
							val=IsEmpty(queue,&rear,&front);
							if(val){
								printf("Queue is empty\n");
							}
							else{
								printf("Queue is not Empty...\n");
							}
							printf("-----------------------------------------\n\n");
							break;
						case 7:
							val=IsFull(queue,&rear,&front);
							if(val){
								printf("Queue is Full..\n");
							}
							else{
								printf("Queue is not Full...\n");
							}
							printf("-----------------------------------------\n\n");
							break;
							
					}
				}while(choice2!=0);
				break;
				
			case 2:
				printf("Do you want pre-filled queue?(enter 1 for yes)\n");
				scanf("%d",&choice1);
				if(choice1==1){
					CreateQueue(cqueue,&rear,&front);
					printf("Queue is created Successfully.....\n");
				}	
				do{
					printf("Enter the operation ....\n");
					printf("1.Insert \t 2.Delete \t 3.Display \t 4.Front Value \n");
					printf("5.Rear value \t 6.IsEmpty \t 7.IsFull \t 0.Exit\n");
					printf("************************************************************************\n");
					scanf("%d",&choice2);
					switch(choice2){
						case 0:
							break;
						case 1:
							CQueueInsert(cqueue,&rear,&front);
							printf("front=%d   rear=%d\n",front,rear);
							printf("-----------------------------------------\n\n");
							break;
						case 2:
							val=CQueueDelete(cqueue,&rear,&front);
							printf("front=%d   rear=%d\n",front,rear);
							if(val){
								printf("%d element is no more\n...",val);
							}
							printf("-----------------------------------------\n\n");
							break;
						case 3:
							DisplayCQueue(cqueue,&rear,&front);
							printf("\n-----------------------------------------\n\n");
							break;
						case 4:
							val=CFrontValue(cqueue,&rear,&front);
							if(val){
								printf("value at front is %d..\n",val);
							}
							printf("-----------------------------------------\n\n");
							break;
						case 5:
							val=CRearValue(cqueue,&rear,&front);
							if(val){
								printf("value at rear is %d..\n",val);
							}
							printf("-----------------------------------------\n\n");
							break;
						case 6:
							val=CQueueEmpty(cqueue,&rear,&front);
							if(val){
								printf("Queue is Empty..\n");
							}
							else{
								printf("Queue is not Empty...\n");
							}
							printf("-----------------------------------------\n\n");
							break;
						case 7:
							val=CQueueFull(cqueue,&rear,&front);
							if(val){
								printf("Queue is Full..\n");
							}
							else{
								printf("Queue is not Full...\n");
							}
							printf("-----------------------------------------\n\n");
							break;
							
					}
				}while(choice2!=0);
		}
	}while(choice!=0);
	return 0;
}
//Functions used in driver function
//1.CreateQueue function
void CreateQueue(int * queue,int *rear,int *front){
	int ele;
	do{
		if(*rear==MX_SZ-1){
			printf("Queue is full...\n");
			break;
		}
		if (*rear==-1 && *front==-1){
			printf("Queue initially empty.\n");
			*front=0;
			*rear=0;
		}
		else{
			*rear+=1;
		}
		printf("Enter the element ...and (-1 to stop)\n");
		scanf("%d",&ele);
		if(ele==-1){
			*rear-=1;
			break;
		}
		queue[*rear]=ele;
	}while(*rear<MX_SZ);
}
//2.DisplayQueue function
void DisplayQueue(int * queue,int *rear,int *front){
	int i;
	if(*front!=-1 && *rear>=*front){
		printf("Queue Elements are....\n");
		for(i=0;i<=*rear;i++){
			if(i<*front){
				printf("-\t");
			}
			else{
				printf("%d\t",queue[i]);
			}
		}
	}
	else{
		printf("Queue is Empty..\n");
	}
}
//3.inserting into the queue
void InsertQueue(int *queue,int *rear,int *front){
	int ele;
	if(*rear==MX_SZ-1){
		printf("Queue is full...\n");
		return ;
	}
	if (*rear==-1 && *front==-1){
		printf("Queue initially empty.\n");
		*front=0;
		*rear=0;
	}
	else{
		*rear+=1;
	}
	printf("Enter the element ...\n");
	scanf("%d",&ele);
	if(ele==-1){
		printf("you entered MN_VAl,its discarded.\n");
		*rear-=1;
		return;
	}
	queue[*rear]=ele;
	printf("%d is inserted successfully...\n",ele);
}
//4.Deleting from the queue
int DeleteQueue(int *queue,int *rear,int *front){
	int ele;
	if((*rear==-1 && *front==-1)|| *front>*rear){
		printf("Queue is empty...\n");
		return -1;
	}
	ele=queue[*front];
	*front=*front+1;
	return ele;
}
//5.Front value
int FrontValue(int * queue,int *front){
	if(*front==-1){
		printf("Queue is Empty....\n");
		return 0;
	}
	return queue[*front];
}
//6.Rear value
int RearValue(int * queue,int *rear){
	if(*rear==-1){
		printf("Queue is Empty....\n");
		return 0;
	}
	return queue[*rear];
}
//7.Check if queue is empty
int IsEmpty(int *queue,int *rear,int *front){
	if((*rear==-1 && *front==-1)|| *front>*rear){
		return 1;
	}
	return 0;
}
//8.check if queue is full
int IsFull(int *queue,int *rear,int *front){
	if(*rear==MX_SZ-1){
		return 1;
	}
	return 0;
}



//circular queue functions
//9.inserting into circular queue
void CQueueInsert(int *cqueue,int *rear,int *front){
	int ele;
	if((*front==0 && *rear==MX_SZ-1)|| *rear==(*front-1)%(MX_SZ)){
		printf("Queue is full...\n");
		return;
	}
	if(*front==-1 && *rear==-1){
		*front=0;
		*rear=0;
	}
	else{
//		if(*rear==MX_SZ-1 && *front!=0){
//			*rear=0;
//		}
//		else{
//			*rear+=1;
//		}
		*rear=(*rear+1)%MX_SZ;//commented code in single line
	}
	printf("Enter the element ...\n");
	scanf("%d",&ele);
	if(ele==-1){
		printf("you entered MN_VAl,its discarded.\n");
		*rear-=1;
		return;
	}
	cqueue[*rear]=ele;
	printf("%d is inserted successfully...\n",ele);
}
//10.deleteing from circular queue
int CQueueDelete(int *cqueue,int * rear,int *front){
	int ele;
	if(*front==-1 && *rear==-1){
		printf("Queue is Empty,nothing to delete...\n");
		return 0;
	}
	//only one element in queue
	else if(*front==*rear){
		ele=cqueue[*front];
		*rear=*front=-1;
		return ele;
	}
	else{
		ele=cqueue[*front];
		*front=(*front+1)%MX_SZ;//the above commented code is equivalent to this 1 line.
	}
	return ele;
}
//11.displaying a circular queue
void DisplayCQueue(int *cqueue,int *rear,int *front){
	int i;
	if(*front==-1 && *rear==-1){
		printf("Queue is Empty..\n");
		return;
	}
	printf("Queue elements are..:\n");
	if (*rear >=* front) 
    { 
        for (i = 0; i <= *rear; i++) {
        	if(i<*front){
        		printf("-\t");
			}
			else{
				printf("%d\t",cqueue[i]);
			}
        	
		}
    } 
    else if(*front >*rear)
    { 
        for (i =0; i <=*rear; i++) {
        	
        	printf("%d \t", cqueue[i]); 
		}
		int diff=*front-*rear-1;
        for (i = *rear+1; i <*front; i++){
        	printf("- \t "); 
		}
		for(i=*front;i<MX_SZ;i++){
			printf("%d \t",cqueue[i]);
		} 
    } 
}
//12.checking if circular queue is full
int CQueueFull(int * cqueue,int *rear,int * front){
	if((*rear+1)%MX_SZ==*front){
		return 1;
	}
	return 0;
}
//13.checking if circular queue is empty
int CQueueEmpty(int *queue,int *rear,int *front){
	if((*front==-1 && *rear==-1)){
		return 1;
	}
	return 0;
}
//14.getting the front value in circular queue
int CFrontValue(int *cqueue,int *rear,int *front){
	if(*front==-1|| *front==(*rear+1)%MX_SZ){
		printf("Queue is Empty..\n");
		return 0;
	}
	return cqueue[*front];
}
//15.getting the rear value in circular queue
int CRearValue(int *cqueue,int *rear,int * front){
	if(*front==-1 && *rear==-1){
		printf("Queue is Empty..\n");
		return 0;
	}
	return cqueue[*rear];
}

/*  ***********************END*******************************/
