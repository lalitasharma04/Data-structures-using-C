/*
	Author:Lalita Sharma
	Aim:To implement Linked Lists and stack and queue using Linked lists.
*/
//headers
#include<stdio.h>
#include<stdlib.h>
//#include"try.c"

struct nodeList
{
 int data;
 struct nodeList* next;
};
typedef struct nodeList* node;
//node CreateList(node first,int noE);
node CreateNode();
//node InsertAtEnd(node first,node key);
//void DisplayList(node first);
//node InsertAtBeginning(node first,int key);
//node InsertAtPos(node first,int key,int pos);
//node DeleteAtBeginning(node first,int *key);
//node DeleteAtEnd(node first,int *key);
//int LengthList(node first);
//node CopyList(node first);
//node DeleteAtPos(node first,int pos,int *key);
//node ReverseList(node first);
//node MergeList(node first,node second);
//node InsertOrdered(node first,int ele);
//node DeleteOrdered(node first,int ele,int *key);
//
//
//node CreateStackList(node top,int noE);
//node Push(node top);
//node Pop(node top,int * key);
//int TopValue(node top);
//
void LinkedQueue();
node CreateQueueList(node front,node rear,int noE);
void DisplayQueue(node front,node rear);
node InsertQueue(node front,node rear);
node DeleteQueue(node front,node rear,int *val);
int FrontValue(node front);
int RearValue(node rear);
int main(){
	int choice;
	do{
		printf("Enter your choice...?\n");
		printf("1.Linked List \t 2.Linked Stack \t 3.Linked Queue \t 0.Exit\n");
		printf("**************************************************************************\n");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				printf("Terminating......\n");
				break;
			case 1:
//				LinkedList();
				printf("----------------------------------------------------------------\n\n");
				break;
			case 2:
//				LinkedStack();
				printf("\n----------------------------------------------------------------\n\n");
				break;
			case 3:
				LinkedQueue();
				printf("----------------------------------------------------------------\n\n");
				break;
		}
	}while(choice!=0);
	return 0;
}
void LinkedQueue(){
	node rear=NULL,front=NULL;
	int choice,noE,choice1,val,value;
	printf("you chose to work with a Stack.\n");
	printf("Initially Queue is empty...enter 1 to create the Queue\n");
	scanf("%d",&choice);
	if(choice==1){
		printf("Enter the number of elements...\n");
		scanf("%d",&noE);
		front=CreateQueueList(front,rear,noE);
		printf("Queue is successfully created..\n");
	}
	do{
		printf("Enter the operation...\n");
		printf("1.Insert \t 2.Delete \t 3.Display \t 4.FrontValue \t 5.RearValue 0.Exit\n");
		printf("***********************************************************************\n");
		scanf("%d",&choice1);
		switch(choice1){
			case 0:
				break;
			case 1:
				printf("Value of front=%d \t rear=%d\n",front->data,rear->data);
				front=InsertQueue(front,rear);
				printf("Element was inserted successfully\n");
				printf("--------------------------------------------\n");
				break;
			case 2:
				front=DeleteQueue(front,rear,&val);
				if(val!=-1){
					printf("%d was deleted..\n",val);
				}
				printf("--------------------------------------------\n");
				break;
				
			case 3:
				DisplayQueue(front,rear);
				printf("\n--------------------------------------------\n");
				break;
			case 4:
				value=FrontValue(front);
				if(value!=-1){
					printf("Value at front is %d\n",value);
				}
				printf("--------------------------------------------\n");
				break;
			case 5:
				value=RearValue(rear);
				if(value!=-1){
					printf("Value at Rear is %d\n",value);
				}
				printf("--------------------------------------------\n");
				break;
		}
	}while(choice1!=0);
}
node CreateNode(){
	node neww;
	neww=(node)malloc(sizeof(struct nodeList));
	return neww;
}
node CreateQueueList(node front,node rear,int noE){
	int key;
	node neww;
	while(noE){
		neww=CreateNode();
		if(neww==NULL){
			printf("No memory was allocated...\n");
			return front;
		}
		printf("Enter the element here...\n");
		scanf("%d",&key);
		neww->data=key;
		neww->next=NULL;
		if(front==NULL && rear==NULL){
			front=rear=neww;
		}else{
			rear->next=neww;
			rear=neww;
		}
		noE--;
	}
	printf("Value of front=%d   rear=%d\n",front->data,rear->data);
	return front;
}
node InsertQueue(node front,node rear){
	int key;
	node neww=CreateNode();
	if(neww==NULL){
		printf("No memory was allocated...\n");
		return front;
	}
	printf("Enter the element here...\n");
	scanf("%d",&key);
	neww->data=key;
	neww->next=NULL;
	if(front==NULL && rear==NULL){
		front=rear=neww;
		
	}else{
		rear->next=neww;
		rear=neww;
	}
	
	return front;
}
node DeleteQueue(node front,node rear,int *val){
	if(front==NULL && rear==NULL){
		*val=-1;
		printf("Queue is Empty...\n");
		return front;
	}
	else{
		*val=front->data;
		front=front->next;
		return front;
	}
}
int FrontValue(node front){
	if(front==NULL){
		printf("Queue is Empty..\n");
		return -1;
	}
	return front->data;
}
int RearValue(node rear){
	if(rear==NULL){
		printf("Queue is empty..\n");
		return -1;
	}
	return rear->data;
}
void DisplayQueue(node front,node rear){
	if(front==NULL && rear==NULL){
		printf("Queue is empty...\n");
		return;
	}
	printf("Queue contents are:::\n");
	node temp=front;
	while(temp!=NULL){
		printf("[%d|%u]---->",temp->data,temp->next);
		temp=temp->next;
	}
//	printf("%d[%u]----->\n",temp->data,temp->next);
}
