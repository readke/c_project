#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int member;
	struct pNode * pNext; 
} Node;

void initLinkedList(Node * pHead);
void addLinkedList(Node * pHead,int m);
void foreachList(Node * pHead);

int main(){
	Node * pH;
	int i;
	initLinkedList(pH);
	for(i=0;i<10;i++){
		addLinkedList(pH,i);
	}
	foreachList(pH);
}

void initLinkedList(Node * pHead){
	pHead = NULL; 
}
void addLinkedList(Node *pHead,int m){
	Node * pNew,*pTemp;
	pNew = (Node *)malloc(sizeof(Node));
	 
	if(pNew == NULL){
		printf("存储空间不足");
		exit(1);
	}
	pNew->member = m;
	pNew->pNext = NULL;
	if(pHead == NULL){
		pHead->pNext = pNew;
	}
		/*else{
		pTemp = pHead;
		while(pTemp != NULL){
			pTemp = pTemp->pNext;
		}
		pTemp->pNext = pNew;
	}*/
}

void foreachList(Node * pHead){
	if(pHead == NULL){
		printf("链表为空");
		exit(1);
	}
	Node * pFirst = pHead->pNext;
	printf("%d",pFirst->member);
	/*Node * pFirst = pHead->pNext;
	while(pFirst != NULL){
		printf("%d ",pFirst->member);
	}*/
	printf("\n");
}