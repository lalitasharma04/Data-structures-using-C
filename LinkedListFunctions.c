typedef struct nodeList* node;
node CreateList(node first,int noE);
node CreateNode();
node InsertAtEnd(node first,node key);
void DisplayList(node first);

node CreateList(node first,int noE){
	int key;
	while(noE!=0){
		printf("enter the element..\n");
		scanf("%d",&key);
		first=InsertAtEnd(first,key);
		noE--;
	}
	return first;
}
node CreateNode(){
	node neww;
	neww=(node)malloc(sizeof(struct nodeList));
	return neww;
}
node InsertAtEnd(node first,node key){
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
