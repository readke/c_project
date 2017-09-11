/*
 * array_list.c
 *
 *  Created on: 2017年9月7日
 *      Author: readke
 */
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

/*
 *定义线性表类型
 */
struct List{
	ElemType *list;
	int size;
	int MaxSize;
};

//函数声明
void initList(struct List *L,int ms);
void clearList(struct List *L);

int size(struct List *L);
int isEmpty(struct List *L);
ElemType get(struct List *L, int index);
void printList(struct List *L);
int getIndex(struct List *L,ElemType elem);
int setValue(struct List *L,int index,ElemType e);
void judgeList(struct List *L);
void expansionSize(struct List *L,int x);
void addEleHead(struct List *L,ElemType e);
void addEleTail(struct List *L,ElemType e);
int insertEleAtIndex(struct List *L,ElemType e,int index);
void insertEleByASC(struct List *L, ElemType e);
void insertEleByDESC(struct List *L,ElemType e);
ElemType deleteHeader(struct List *L);
ElemType deleteTail(struct List *L);
ElemType deleteByIndex(struct List *L,int index);

int main(int argc, char **argv) {

	int a[10] = {0,2,4,6,8,10,12,14,16,18};
	int i ;
	struct List L;
	initList(&L,10);
	for(i=0; i<10; i++){
		addEleTail(&L,a[i]);
	}
	printList(&L);
	printf("从表头插入一个元素");
	addEleHead(&L,1);
	printList(&L);
	printf("size = %d\n",size(&L));
	insertEleAtIndex(&L,20,4);
	printList(&L);
	printf("size = %d\n",size(&L));
	deleteHeader(&L);
	printList(&L);
	printf("size = %d\n",size(&L));
	deleteTail(&L);
	printList(&L);
	printf("size = %d\n",size(&L));
	deleteByIndex(&L,3);
	printList(&L);
	printf("size = %d\n",size(&L));
	setValue(&L,0,1); 
	printList(&L);
	printf("size = %d\n",size(&L));
	printf("%d\n",get(&L,1));
	clearList(&L);
	printList(&L);
	printf("size = %d\n",size(&L));
	printf("flag = %d\n",isEmpty(&L));
}
/*
 * 初始化线性表
 */
void initList(struct List *L , int ms){
	if(ms < 0){
		printf("ms值非法!\n");
		exit(1);
	}

	L->MaxSize = ms; //设置线性表初始容量为ms
	L->list = (ElemType *) malloc(ms*sizeof(ElemType));
	if(!L->list){
		printf("动态分配内存空间失败。\n");
		exit(1);
	}
	L->size = 0;
}

/*
 * 清除线性表中的元素，释放动态存储空间
 */
void clearList(struct List *L){
	if(L->list != NULL){
		free(L->list);
		L->list = 0;
		L->size = L->MaxSize = 0;
	}
}

/*
 * 返回线性表的长度
 */
int size(struct List *L){
	return L->size;
}

/*
 * 判断线性表是否为空
 */
int isEmpty(struct List *L){
	if(L->list == 0){
		return 1;
	}else{
		return 0;
	}
}

/*
 * 返回指定索引处的元素，索引从0开始
 */
ElemType get(struct List *L, int index){
	if(index <0 || index > L->size-1){
		printf("数组下标越界\n");
		exit(1);
	}
	return L->list[index];
}

/*
 * 顺序输出每一个元素
 */
void printList(struct List *L){
	int i;
	for(i=0; i<L->size; i++){
		printf("%d,",L->list[i]);
	}
	printf("\n");
}

/*
 * 返回给定元素的索引
 */
int getIndex(struct List *L,ElemType elem){
	int i;
	for(i=0; i<L->size; i++){
		if(elem==L->list[i]){
			return i;
		}
	}
	return -1;
}

/*
 *将指定索引位置的元素修改为指定值
 */
int setValue(struct List *L,int index,ElemType e){
	if(index <0 || index > L->size-1){
		return 0;
	}
	L->list[index] = e;
	return 1;
}

/*
 *
 */
void judgeList(struct List *L){
	if(L->size == L->MaxSize){
		printf("表容量不足，扩充表容量");
		expansionSize(L,2);
	}
}
/*
 * 将表按指定倍数扩充容量
 */
void expansionSize(struct List *L,int x){
	ElemType * p = realloc(L->list,x*L->MaxSize*sizeof(ElemType));
	if(!p){
		printf("存储空间不足,无法分配新的空间\n");
		exit(1);
	}
	L->list = p;
	L->MaxSize = x * L->MaxSize;
	printf("存储空间已经扩充为当前的%d倍\n",x);
}

/*
 * 向线性表头插入元素e
 */
void addEleHead(struct List *L,ElemType e){
	int i;
	judgeList(L);

	for(i=L->size-1; i>=0; i--){
		L->list[i+1] = L->list[i];
	}
	L->list[0] = e;
	L->size ++;
}

/*
 * 向线性表尾部插入元素e
 */
void addEleTail(struct List *L,ElemType e){
	judgeList(L);
	L->list[L->size] = e;
	L->size++;
}

/*
 * 在指定索引位置插入元素e
 */
int insertEleAtIndex(struct List *L,ElemType e,int index){
	int i;
	if(index<0 || index>L->size){
		return 0;
	}
	judgeList(L);
	for(i=L->size-1; i>=index;i--){
		L->list[i+1] = L->list[i];
	}
	L->list[index] = e;
	L->size++;
	return 1;
}

/*
 * 在有序表(递增)中插入元素e，使得线性表依然有序
 */
void insertEleByASC(struct List *L, ElemType e){
	int i;
	judgeList(L);
	for(i = 0; i<L->size; i++){
		if(e <= L->list[i]){
			break;
		}
	}
	insertEleAtIndex(L,e,i);
}

/*
 * 在有序表(递减)中插入元素e,使得线性表依然有序
 */
void insertEleByDESC(struct List *L,ElemType e){
	int i;
	judgeList(L);
	for(i=0;i<L->size;i++){
		if(e>=L->list[i]){
			break;
		}
	}
	insertEleAtIndex(L,e,i);
}

/*
 * 从线性表L中删除表头元素并返回它，若删除失败则停止程序运行
 */
ElemType deleteHeader(struct List *L){
	return deleteByIndex(L,0);
}
/*
 * 从线性表L中删除表尾元素并返回它，若删除失败则停止程序运行
 */
ElemType deleteTail(struct List *L){
	return deleteByIndex(L,L->size-1);
}
/*
 * 从线性表L中删除指定索引元素并返回它，若删除失败则停止程序运行
 */
ElemType deleteByIndex(struct List *L,int index){
	int i;
	ElemType e ;
	if(index <0 || index >L->size){
		printf("指定索引位置不存在\n");
		exit(1);
	}
	e=L->list[index];
	for(i=index;i<L->size;i++){
		L->list[i] = L->list[i+1];
	}
	L->size--;
	return e;
}


