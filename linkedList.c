#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int member;
	struct node * next;
} Node;


void addLast(Node * pHead, int e);
Node* createList();
void printList(Node * pHead);
int main(){
	int i;
	Node * pHead = NULL;
	pHead = createList();
	for(i=0;i<10;i++){
		addLast(pHead,i);
	}
	
	printList(pHead);
}
Node* createList(){
	Node * pHead = (Node *)malloc(sizeof(Node));
	if(NULL == pHead){
		exit(1);
	} 
	pHead->next = NULL;
	return pHead;	
}
void addLast(Node * pHead,int e){
	Node * pNew = (Node*)malloc(sizeof(Node));
	Node * tail;
	if(pNew == NULL){
		exit(1);
	}
	pNew->member = e;
	pNew->next=NULL;
	/*tail=pHead->next;
	while(tail!=NULL){
		tail=tail->next;
	}
	tail=pNew;*/
 	tail=pHead;
 	while(tail->next!= NULL){
	 	tail=tail->next;
 	}
 	tail->next=pNew;
 		
} 
void printList(Node * pHead){
	Node * p = pHead->next;
	while(p!=NULL){
		printf("%d ",p->member);
		p=p->next;
	}
	printf("\n");
}
 