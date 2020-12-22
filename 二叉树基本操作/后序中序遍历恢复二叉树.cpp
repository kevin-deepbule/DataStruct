#include<stdio.h>
#include<iostream>
#include<string.h>
#include<malloc.h>
#define DataType char
typedef struct Node{
	DataType data;
	struct Node *lchild;
	struct Node *rchild;
}*BiTree,BiTNode;
void Initital(char afterorder[],char midorder[]){
	scanf("%s",afterorder);
	scanf("%s",midorder);
}
void ReBiTree(BiTree *T,char afterorder[],char midorder[],int i,int j,int k,int h){
	(*T) = (BiTree)malloc(sizeof(BiTNode));
	(*T)->data = afterorder[j];
	int m = k;
	while(afterorder[j]!=midorder[m])
		m++;
	if(m==h)
		(*T)->rchild = NULL;
	else 
		ReBiTree(&((*T)->rchild),afterorder,midorder,i+m-k,j-1,m+1,h); 
	if(m==k)
		(*T)->lchild = NULL;
	else 
		ReBiTree(&((*T)->lchild),afterorder,midorder,i,i+m-k-1,k,m-1); 
}
void preOrder(BiTree T){
	if(T){
		printf("%c",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
} 
void midOrder(BiTree T){
	if(T){
		preOrder(T->lchild);
		printf("%d",T->data);
		preOrder(T->rchild);
	}
}
void afterOrder(BiTree T){
	if(T){
		preOrder(T->lchild);
		preOrder(T->rchild);
		printf("%d",T->data);
	}
}
int main(){
	BiTree T;
	char afterorder[9];
	char midorder[9];
	Initital(afterorder,midorder);
	ReBiTree(&T,afterorder,midorder,0,8,0,8);
	preOrder(T);
	return 0;
} 
