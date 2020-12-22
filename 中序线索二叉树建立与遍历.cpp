#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<string.h>
#define DataType char
typedef struct NodeThr{
	DataType  data;
	struct NodeThr *lchild;
	struct NodeThr *rchild;
	unsigned ltag;
	unsigned rtag;
}*BiTreeThr,BTNodeThr;
BiTreeThr pre;
void creatBiTree(BiTreeThr *T){
	char c = getchar();
	if(c=='#')
		(*T) = NULL;
	else{
		(*T) = (BiTreeThr)malloc(sizeof(BTNodeThr));
		(*T)->data = c;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		creatBiTree(&((*T)->lchild));
		creatBiTree(&((*T)->rchild));
	}
}
void InTreading(BiTreeThr p){
	if(p){
		InTreading(p->lchild);
		if(!p->lchild){
			p->lchild = pre;
			p->ltag = 1;
		}
		if(!pre->rchild){
			pre->rchild = p;
			pre->rtag = 1; 
		}
		pre = p;
		InTreading(p->rchild);		
	}
} 
void InOrderThr(BiTreeThr *head,BiTreeThr T){
	(*head) = (BiTreeThr)malloc(sizeof(BTNodeThr));
	(*head)->lchild = T;
	(*head)->ltag = 0;
	pre = *head;
	InTreading(T);
	pre->rchild = *head;pre->rtag = 1; 
	(*head)->rchild = pre; (*head)->rtag = 1;
}

void midOrderThr(BiTreeThr head){
	BiTreeThr p = head->lchild;
	while(p!=head){
		while(p->ltag==0)
			p = p->lchild;
		printf("%c",p->data);
		while(p->rtag==1&&p->rchild!=head){
			p = p->rchild;
			printf("%c",p->data);
		}
		pre = p;
		p = p->rchild;
	}
}
void preOrder(BiTreeThr T){
	if(T){
		printf("%c",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
//AB#C##D#EF###
int main(){
	BiTreeThr T;
	BiTreeThr head;
	creatBiTree(&T);
//	preOrder(T);
	InOrderThr(&head,T);
	midOrderThr(head);
	return 0;
} 
