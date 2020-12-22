#include<stdio.h>
#include<iostream>
#include<string.h>
#include<malloc.h>
#define DataType char
typedef struct Node{
	DataType data;
	struct Node *lchild;
	struct Node *rchild;
	int ltag ;
	int  rtag ;
}*BiTreeThr,BTNodeThr;
//采用递归的方法创建线索二叉树 
BiTreeThr pre; 
void InThreading(BiTreeThr p){
	if(p){
		InThreading(p->lchild);
		if(!p->lchild){
			p->ltag = 1;
			p->lchild = pre;
		}
		if(!pre->rchild){
			pre->rtag = 1;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild); 
	}
}
int InOrderThr(BiTreeThr *head,BiTreeThr T) { //子树线索化 
	(*head) = (BiTreeThr)malloc(sizeof(BTNodeThr));
	(*head)->ltag = 0;
	(*head)->rtag = 1;
	(*head)->lchild = T;pre = *head;
	InThreading(T); //中序遍历进行线索化 
	pre->rchild = *head;pre->rtag = 1;
	(*head)->rchild = pre;
	return 1;
}

void CreatBiTree(BiTreeThr *T){
	char c = getchar();
	if(c=='#')
		(*T) = NULL;
	else{
		(*T) = (BiTreeThr)malloc(sizeof(BTNodeThr));
		(*T)->data = c;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		CreatBiTree(&((*T)->lchild));
		CreatBiTree(&((*T)->rchild));
	}
	
} 
void midOrderThr(BiTreeThr head){
	BiTreeThr p;
	p = head->lchild;
	while(p!=head){
		while(p->ltag==0)
			p = p->lchild;
		printf("%c",p->data);
		while((p->rtag==1)&&(p->rchild!=head)){
			p = p->rchild;
			printf("%c",p->data);
		}
		p = p->rchild;
	}
}
void preOrder(BiTreeThr T){
	if(T){
		preOrder(T->lchild);
		printf("%c",T->data);
		preOrder(T->rchild);
	}
}
//D#EF### 
//AB#C##D#EF##h##
int main(){
	BiTreeThr T;
	BiTreeThr head;
	CreatBiTree(&T);
	InOrderThr(&head,T);
	midOrderThr(head);
//	preOrder(T);
	return 0;
}
