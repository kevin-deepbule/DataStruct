#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#define DataType char
#define MAXNODE 100
typedef struct Node{
	DataType data;
	struct Node *lchild;
	struct Node *rchild; 
}*BiTree,BiTNode;

void creatBiTree(BiTree *T){
	char c;
	c = getchar();
	if(c=='#'){
		*T = NULL;
	}else{
		(*T) = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = c;
		creatBiTree(&((*T)->lchild));
		creatBiTree(&((*T)->rchild));
	}
}
void LevelOrder(BiTree T){
	BiTree queue[MAXNODE];
	int rear=0;
	int head=-1;
	queue[0] = T;
	while(rear!=head){
		head++;
		printf("%c",queue[head]->data);
		if(queue[head]->lchild){
			rear++;
			queue[rear]=queue[head]->lchild;
		}
		if(queue[head]->rchild){
			rear++;
			queue[rear]=queue[head]->rchild;
		}	
	} 
}
void preOrder(BiTree T){
	if(T){
		printf("%c",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
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
