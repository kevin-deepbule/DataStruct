#include<stdio.h>
#include<iostream>
#include<malloc.h>
#define DataType char
#define MAXNODE 100
typedef struct Node{
	DataType data;
	struct Node *lchild;
	struct Node *rchild;
}*BiTree,BTNode;
void creatBiTree(BiTree *T){
	char c;
	c = getchar() ;
	if(c=='#')
		*T = NULL;
	else{
	*T = (BiTree)malloc(sizeof(BTNode));
	(*T)->data = c;
	creatBiTree(&((*T)->lchild));
	creatBiTree(&((*T)->rchild));	
	}
	
}
void preOrder(BiTree T){
	if(T){
		printf("%c",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
void LevelOrder(BiTree T){
	BiTree queue[MAXNODE];
	int front=-1,rear=0;
	queue[rear] = T;
	while(front!=rear){
		front++;
		printf("%c",queue[front]->data);
		if(queue[front]->lchild){
			rear++;
			queue[rear]=queue[front]->lchild;
		}
		if(queue[front]->rchild){
			rear++;
			queue[rear]=queue[front]->rchild;
		}
	}
	
	
}
//AB#C##D#EF###
int main(){
	BiTree T;
	creatBiTree(&T);
	preOrder(T);
	LevelOrder(T);
	return 0;
}
