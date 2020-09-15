/*
	Author:Lalita Sharma
	Aim:To implement Linked Lists,stack and queue using Linked lists.
*/
//headers
#include<stdio.h>
#include<stdlib.h>
#define MN_VAL -99

struct nodeList
{
 int data;
 struct nodeList* next;
};
typedef struct nodeList* node;
void LinkedList();
node CreateList(node first,int noE);
node CreateNode();
node InsertAtEnd(node first,int key);
void DisplayList(node first);
node InsertAtBeginning(node first,int key);
node InsertAtPos(node first,int key,int pos);
node DeleteAtBeg(node first,int *key);
node DeleteAtEnd(node first,int *key);
node Reverse(node first);
node Merge(node p,node q);
node Copy(node first);
int Length(node first);
int Sum(node p);
void Sort(node first);
node DeleteAtPos(node first,int*key,int pos);
node RemoveDuplicate(node p);
node InsertOrdered(node first,int ele);
node DeleteOrdered(node first,int ele,int *key);

void LinkedStack();
node CreateStackList(node top);
void DisplayStack(node top);
node Push(node top,int key);
node Pop(node top,int * key);
int TopValue(node top);
//
void LinkedQueue();
node CreateQueueList(node front,node rear,int noE);
void DisplayQueue(node front,node rear);
node InsertQueue(node front,node rear,int key);
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
//			case 1:
//				LinkedList();
//				printf("----------------------------------------------------------------\n\n");
//				break;
//			case 2:
//				LinkedStack();
//				printf("\n----------------------------------------------------------------\n\n");
//				break;
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
	int choice,noE,choice1,val,value,key;
	printf("you chose to work with the Stack.\n");
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
				printf("Enter the element here...\n");
				scanf("%d",&key);
				front=InsertQueue(front,rear,key);
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
	return front;
}
node InsertQueue(node front,node rear,int key){
	node neww;
	neww=CreateNode();
		if(neww==NULL){
			printf("No memory was allocated...\n");
			return front;
		}
//		printf("Enter the element here...\n");
//		scanf("%d",&key);
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
void LinkedStack(){
	int choice,key,x;
	node top=NULL;
	printf("Do you want a prefilled stack,enter 1 for yes\n");
	scanf("%d",&choice);
	if(choice==1){
		top=CreateStackList(top);
		printf("Stack is successfully created\n");
	}
	do{
		printf("\n----------------------------------------------------------------\n");
		printf("Enter choice\n");
		printf("1.Push \t2.Pop \t3.Top value \t 4.Display \t0.Exit\n");
		printf("----------------------------------------------------------------\n");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				printf("please wait...\n");
				break;
			case 1:
				printf("Enter element to push..\n");
				scanf("%d",&key);
				top=Push(top,key);
				printf("\n\n");
				break;
			case 2:
				top=Pop(top,&key);
				if(key==-1){
					printf("Stack is Empty\n");
				}
				else{
					printf("Deleted key is %d\n",key);
				}
				printf("\n\n");
				break;
			case 3:
				x=TopValue(top);
				if(x==-1){
					printf("Stack is empty\n");
				}
				else{
					printf("Top element is %d\n",x);
				}
				printf("\n\n");
				break;
			case 4:
				DisplayStack(top);
				printf("\n\n");
				break;
		}
	}while(choice!=0);

}
int TopValue(node top){
	if(top==NULL){
		return -1;
	}
	else{
		return top->data;
	}
}
node Pop(node top,int *key){
	if(top==NULL){
		*key=-1;
		return NULL;
	}
	node todelete;
	todelete=top;
	*key=top->data;
	top=top->next;
	free(todelete);
	return top;
}
node Push(node top,int key){
	node neww=CreateNode();
	if(neww==NULL){
		printf("no memory is allocated\n");
		return top;
	}
	neww->data=key;
	neww->next=NULL;
	if(top==NULL){
		return neww;
	}
	neww->next=top;
	top=neww;
	return top;
}
node CreateStackList(node top){
	int key;
	
	printf("Enter the key and -1 to stop\n");
	do{
		scanf("%d",&key);
		if(key==-1){
			break;
		}
		node neww=CreateNode();
		if(neww==NULL){
			printf("no memory is allocated\n");
			return top;
		}
		neww->data=key;
		neww->next=NULL;
		if(top==NULL){
			top=neww;
		}
		else{
			neww->next=top;
			top=neww;
		}
		
	}while(1);
	return top;
}
void DisplayStack(node top){
	node temp=top;
	if(top==NULL){
		printf("Stack is Empty...\n");
		return;
	}
	printf("Top:\t");
	while(temp){
		printf("[%d|%u]----->\n\t",temp->data,temp->next);
		temp=temp->next;
	}
	printf("\n");
}
void LinkedList(){
	node first=NULL,second=NULL,merge=NULL;
	int choice,noE,key,pos,x,ele;
	printf("Initially List is empty...enter 1 to create the List\n");
	scanf("%d",&choice);
	if(choice==1){
		printf("Enter the number of elements...\n");
		scanf("%d",&noE);
		first=CreateList(first,noE);
		printf("List is successfully created..\n");
	}
	do{
		printf("\n----------------------------------------------------------------\n\n");
		
		printf("Enter your choice..\n");
		printf("1.InsertAtEnd \t 2.InsertAtBeginning \t 3.InsertAtPos \t 4.DeleteAtBeginning\n");
		printf("5.DeleteAtEnd \t 6.DeletedAtPos \t7.Length \t 8.Sort \t 9.Merge \t 10.Reverse\n");
		printf("11.Search \t 12.Copy \t 13.Maximum \t 14.Remove Duplicate\t 15.Display\t 16.Sum\n");
		printf("---------------------------------------------------------------\n");
		
		
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter key to be inserted.\n");
				scanf("%d",&key);
				first=InsertAtEnd(first,key);
				printf("key Successfully inserted..\n");
				printf("\n\n");
				break;
			case 2:
				printf("Enter key to be inserted.\n");
				scanf("%d",&key);
				first=InsertAtBeginning(first,key);
				printf("key Successfully inserted..\n");
				printf("\n\n");
				break;
			case 3:
				printf("Enter key to be inserted and position\n");
				scanf("%d %d",&key,&pos);
				first=InsertAtPos(first,key,pos);
				printf("key Successfully inserted..\n");
				printf("\n\n");
				break;
			case 4:
				first=DeleteAtBeg(first,&key);
				if(key!=MN_VAL){
					printf("Key deleted is %d\n",key);
				}
				printf("\n\n");
				break;
			case 5:
				first=DeleteAtEnd(first,&key);
				if(key!=MN_VAL){
					printf("Key deleted is %d\n",key);
				}
				printf("\n\n");
				break;
			case 6:
				printf("Enter position");
 				scanf("%d",&pos);
 				if(pos<1||pos>Length(first))
 					printf("Invalid position\n");
				else
 				{
 					first=DeleteAtPos(first,&ele,pos);
 					if(ele==MN_VAL){
 						printf("List empty cannot delete\n");
					 }
 					else
 						printf("Element deleted is %d\n",ele);
 				}
 				printf("-\n\n");
 				break;
 			case 7:
 				printf("Length of the list is %d\n",Length(first));
 				printf("\n\n");
				break;
			case 8:
				printf("List before sorting\n");
				DisplayList(first);
 				Sort(first);
 				printf("List after sorting\n");
				DisplayList(first);
				printf("\n\n");
				break;
			case 9:
				printf("Enter the number of elements in second list...\n");
				scanf("%d",&noE);
				second=CreateList(second,noE);
				printf("List is successfully created..\n");
				Sort(first);Sort(second);
				printf("List 1:\n");
				DisplayList(first);
				printf("List 2:\n");
				DisplayList(second);				
				merge=Merge(first,second);
				printf("Merged list is \n");
				DisplayList(merge);
				printf("\n\n");
				break;
			case 10:
				printf("List is\n");
				DisplayList(first);
				first=Reverse(first);
				printf("List after reversing is\n");
				DisplayList(first);
				printf("\n\n");
				break;
			case 11:
				printf("Enter element to be searched..\n");
				scanf("%d",&key);
				x=Search(first,key);
				if(x==-1){
					printf("Element not found\n");
				}
				else{
					printf("Element %d is found ",x);
				}
				printf("\n\n");
				break;
			case 12:
				second=NULL;
				second=Copy(first);
				printf("Original list is:\n");
 				DisplayList(first);
 				printf("Copied list is:\n");
 				DisplayList(second);
 				printf("\n\n");
				break;
			case 13:
				printf("Maximum element in List is %d\n",Max(first));
				printf("\n\n");
				break;
				
			case 14:
				printf("List before:\n");
				DisplayList(first);
				first=RemoveDuplicate(first);
				printf("List after:\n");
				DisplayList(first);
 				printf("\n\n");
				break;
 			case 15:
 				DisplayList(first);
 				printf("\n\n");
				break;
			case 16:
				printf("Sum is %d\n",Sum(first));
		}
	}while(choice !=0);
	
}


void DisplayList(node first){
	node temp=first;
	if(temp==NULL){
		printf("List is empty..\n");
		return;
	}
	while(temp!=NULL){
		printf("[%d|%u]----->",temp->data,temp->next);
		temp=temp->next;
	}
	printf("\n");
}
node CreateList(node first,int noE){
	int key;
	printf("Enter data and -1 to stop..\n");
	while(noE){
		scanf("%d",&key);
		first=InsertAtEnd(first,key);
		noE--;
	}
	return first;
}

node InsertAtEnd(node first,int key){
	node temp,neww;
	temp=first;
	neww=CreateNode();
	if(neww==NULL){
		printf("no memory is allocated\n");
		return first;
	}
	neww->data=key;
	neww->next=NULL;
	if(first==NULL){
		
		first=neww;
		return first;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=neww;
	return first;
}

node InsertAtBeginning(node first,int ele)
{
  	node neww=CreateNode();
 	if(neww==NULL){
		printf("no memory is allocated\n");
		return first;
	}
	neww ->data=ele;
 	neww ->next=NULL;
 	if(first!=NULL){
 		neww ->next=first;
	}
	return neww;
}

node InsertAtPos(node first,int ele,int pos)
{
	int ndx=0;
	node neww,temp;
	neww=CreateNode();
	if(neww==NULL){
		printf("no memory is allocated\n");
		return first;
	}
	neww->data=ele;
	neww->next=NULL;
	if(pos==1)
	{
		neww->next=first;
		return neww;
	}
	temp=first;
	while(ndx<pos-2)
	{
		ndx++;
		temp=temp->next;
	}
	neww->next=temp->next;
	temp->next=neww;
	return first;
}

node DeleteAtBeg(node first,int * key)
{
	if(first==NULL){
		printf("No element found\n");
		*key=MN_VAL;
	}
	else
	{
		*key=first->data;
		first=first->next;
	}
	return first;
}

node DeleteAtEnd(node first,int*key)
{
	node temp;
	if(first==NULL){
		*key=MN_VAL;
	}
	else if(first->next==NULL){
		*key=first->data;
		return NULL;	
	}
	else
	{
		temp=first;
		while((temp->next)->next!=NULL)
			temp=temp->next;
		*key=(temp->next)->data;
		temp->next=NULL;
	}
	return first;
}
node DeleteAtPos(node first,int*key,int pos)
{
	node temp;
 	int ndx=0;
	if(first==NULL)
	{
		*key=MN_VAL;
		return first;
 	}
	if(pos==1)
 	{
 		*key=first->data;
 		first=first->next;
 		return first;
 	}
	temp=first;
	while(ndx<pos-2)
	{
		ndx++;
		temp=temp->next;
	}
	*key=(temp->next)->data;
	temp->next=(temp->next)->next;
	return first;
}
int Length(node first)
{
	int len=0;
	if(first==NULL){
		return len;
	}
	while(first!=NULL)
	{
		len=len+1;
		first=first->next;
	}
	return len;
}
void Sort(node first)
{
	node iptr,jptr;
	int key;
	if(first==NULL ||first->next==NULL){
		return;
	}
	for(iptr=first;iptr->next!=NULL;iptr=iptr->next)
	{
		for(jptr=iptr->next;jptr!=NULL;jptr=jptr->next)
		{
			if(iptr->data>jptr->data)
			{
				key=iptr->data;
				iptr->data=jptr->data;
				jptr->data=key;
			}
		}
	}
}
node Reverse(node first)
{
	node rev,ptr1,ptr2;
	if(first==NULL){
		return first;
	}
 	rev=first;
 	ptr1=first->next;
 	ptr2=(first->next)->next;
 	rev->next=NULL;
 	ptr1->next=rev;
 	while(ptr2!=NULL)
 	{
 		rev=ptr1;
		ptr1=ptr2;
 		ptr2=ptr2->next;
 		ptr1->next=rev;
 	}
 	return ptr1;
}

node Merge(node p,node q)
{
 	node last,third;
 	if(p->data < q->data)
 	{
 		third=last=p;
 		p=p->next;
 		third->next=NULL;
 	}
 	else
 	{
 		third=last=q;
 		q=q->next;
 		third->next=NULL;
 	}
 	while(p && q)
 	{
	 	if(p->data < q->data)
	 	{
	 		last->next=p;
			 last=p;
			 p=p->next;
			 last->next=NULL;
		}
	 	else
	 	{
			 last->next=q;
			 last=q;
			 q=q->next;
			 last->next=NULL;
		}
 	}
 	if(p){
 		last->next=p;
	}
 	if(q){
 		last->next=q;
	}
 	return third;
}
int Search(node first,int key)
{
 node temp,pos;
 temp=first;
 while(temp!=NULL)
 {
	if(key==temp->data){
 		pos=temp;
 		return pos->data;
 	}
 	else{
		temp=temp->next;
	}
 }
 return -1;
}

node Copy(node first)
{
	node dupl,temp,cpy,neww;
	if(first == NULL)
		return NULL;
	neww=CreateNode();
	if(neww==NULL)
		return neww;
	neww->data=first->data;
	neww->next=NULL;
	dupl=neww;
	temp=first;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		cpy=neww;
		neww=CreateNode();
		if(neww==NULL){
			return neww;
		}
		neww->data=temp->data;
 		neww->next=NULL;
 		cpy->next=neww;
 	}
 	neww->next=NULL;
 	return dupl;
}

int Sum(node p)
{
 	int s=0;
	while(p!=NULL)
 	{
 		s+=p->data;
 		p=p->next;
 	}
 	return s;
}
int Max(node p)
{
	 int max=-88888;
	
	 while(p)
	 {
	 	if(p->data>max)
	 		max=p->data;
	 	p=p->next;
	 }
	 return max;
}

node RemoveDuplicate(node first)
{
 	node q=first->next;
	node p=first; 
 	while(q!=NULL)
 	{
		if(p->data!=q->data)
		{
			p=q;
		 	q=q->next;
		}
		else
		{
		 	p->next=q->next;
		 	free(q);
		 	q=p->next;
		}
 	}
 	return first;

}
