//利用栈的基本操作写出先序遍历的非递归形式的算法 
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
void No_diguiOrder(BiTree T){
	BiTree p = T;
	BiTree stack[30];int top=0;
	while(!(p==NULL&&top==0)){
		while(p){
			stack[top]=p;
			p = p->lchild;
			top++;
	}
		top--;
		p = stack[top];
		printf("%c",p->data);
		p = p->rchild;
	}
	return ;
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
	No_diguiOrder(T);
	return 0;
	
} 
