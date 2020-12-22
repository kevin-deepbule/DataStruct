#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#define DataType char 
typedef struct BinTree{
	DataType data;
	struct BinTree *lchild;
	struct BinTree *rchild;
}*BiTree,BiTNode;

void CreatBiTree(BiTree *T){    //扩充的先序序列构造二叉树 
	DataType data = getchar();
	if(data=='#'){
		*T = NULL;
	}else{
		(*T) = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = data;
		CreatBiTree(&((*T)->lchild));
		CreatBiTree(&((*T)->rchild)); 
	}
}
 
void PreOrder(BiTree T){
	if(T){
		printf("%c",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);	
	}	
}
int main(){
	BiTree a = NULL;
	CreatBiTree(&a);
	PreOrder(a);
	return 0;
}


