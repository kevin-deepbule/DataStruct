//���ö���������Ϊ�������Ĵ洢��ʾ������㷨��������ж�Ϊ1�Ľڵ���� 
#include<stdio.h>
#include<iostream>
#include<malloc.h>
typedef struct Node{
	char data;
	struct Node *lchild;
	struct Node *rchild;
}*BiTree,BiTNode; 
void CreatBiTree(BiTree *T){
	char c = getchar();
	if(c=='#'){
		*T =NULL;
	}else{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data =c;
		CreatBiTree(&((*T)->lchild));
		CreatBiTree(&((*T)->rchild));
	}
}
int count=0;
int finddegreeOne(BiTree T){
	if(T){
		if(T->lchild==NULL&&T->rchild!=NULL)
		count++;
	else if(T->lchild!=NULL&&T->rchild==NULL)
		count++;
	finddegreeOne(T->lchild);
	finddegreeOne(T->rchild);
	}
	
}
//AB##CE##D##
void preOrder(BiTree T){
	if(T){
		printf("%c",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild); 
	}
}
int main(){
	BiTree T;
	CreatBiTree(&T);
	preOrder(T);
	finddegreeOne(T);
	printf("%d",count);
	return 0;
	
} 
