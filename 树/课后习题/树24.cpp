//编写递归算法，将二叉树中的所有左右子树相互交换
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
void exchangeRL(BiTree T){
	if(T){
		BiTree temp;
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
		exchangeRL(T->lchild);
		exchangeRL(T->rchild); 
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
	exchangeRL(T);
	preOrder(T);
	return 0;
	
}  
