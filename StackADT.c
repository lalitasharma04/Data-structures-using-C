/*
	Author:Lalita Sharma
	Aim:To implement Stack ADT using arrays...

*/
//headers
#include<stdio.h>
//pre-proc directives
#define MX_SZ 5


//Driver function
int main(){
	int stack[MX_SZ],top=-1,choice,size,ele;
	printf("Do you want a pre-filled stack?(enter 1 for yes)\n");
	scanf("%d",&choice);
	if(choice==1){
		CreateStack(stack,&top);
		printf("Stack has been created successfully\n");
	}
	do{
		printf("\n\nEnter your choice of operations on the stack....\n");
		printf("1.Push \t  2.Pop  \t  3.Traverse \t 4.Top Value \t 5.Empty \t 6.Full \t 0.Exit\n");
		printf("*************************************************************************************************\n");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				printf("Terminating.........\n");
				printf("---------------------------------------------\n\n");
				break;
			case 1:
				ele=PushStack(stack,&top);
				if(ele==1){
					printf("Element was inserted successfully....\n");
				}
				printf("---------------------------------------------\n\n");
				break;
			case 2:
				ele=PopStack(stack,&top);
				if(ele!=0){
					printf("%d was deleted successfully\n",ele);
				}
				printf("---------------------------------------------\n\n");
				break;
			case 3:
				DisplayStack(stack,&top);
				printf("---------------------------------------------\n\n");
				break;
			case 4:
				ele=TopValue(stack,&top);
				if(ele!=-1){
					printf("Top value is %d\n",ele);
				}
				printf("---------------------------------------------\n\n");
				break;
			case 5:
				ele=IsEmpty(&top);
				if(ele==1){
					printf("Stack is empty\n");
				}
				else{
					printf("Stack is not empty\n");
				}
				printf("---------------------------------------------\n\n");
				break;
			case 6:
				ele=IsFull(&top);
				if(ele==1){
					printf("Stack is Full\n");
				}
				else{
					printf("Stack is not Full\n");
				}
				printf("---------------------------------------------\n\n");
				break;
		}
	}while(choice!=0);
	return 0;
}
//CreateStack
void CreateStack(int * stack,int *top){
	int ele;
	do{
		if(*top==MX_SZ-1){
			printf("\nStack overflow\n");
			break;
		}
		else{
			printf("Enter the element or -1 to stop\n");
			scanf("%d",&ele);
			if(ele!=-1){
				*top+=1;
				stack[*top]=ele;
			}
			else{
				break;
			}
			
		}
	
	}while(*top<MX_SZ );

}

void DisplayStack(int stack[],int *top){
	
	int i;
	if(*top!=-1){
		printf("stack elements are....\n");
		for(i=*top;i>=0;i--){
			printf("%d\n",stack[i]);
		}
	}
	

}
int PushStack(int * stack,int *top){
	int ele;
	if(*top==MX_SZ-1){
		printf("\nStack overflow\n");
		return -1;
	}
	else{
		printf("Enter the element\n");
		scanf("%d",&ele);
		*top+=1;
		stack[*top]=ele;
		return 1;
	}
}
int PopStack(int * stack,int *top){
	if(*top==-1){
		printf("Stack is empty,no element to delete\n");
		return 0;
	}
	else{
		int ele=stack[*top];
		*top=*top-1;
		return ele;
	}
}
int TopValue(int * stack,int *top){
	if(*top==-1){
		printf("Stack is empty ,so no top value\n");
		return -1;
	}
	return stack[*top];
}
int IsEmpty(int * top){
	if(*top==-1){
		return 1;
	}
	return 0;
}
int IsFull(int * top){
	if(*top==MX_SZ-1){
		return 1;
	}
	return 0;
}
