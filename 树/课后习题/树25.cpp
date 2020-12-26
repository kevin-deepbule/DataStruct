//按照层次顺序遍历二叉树的算法 
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
void levelOrder(BiTree T){
	BiTree p=T,rear[30];
	int start=-1,tail=0;
	rear[0] = p;
	while(start!=tail){
		start++;
		 p = rear[start];
		printf("%c",rear[start]->data);
		if(rear[start]->lchild){
			tail++;
			rear[tail] = rear[start]->lchild;
		}
		if(rear[start]->rchild){
			tail++;
			rear[tail] = rear[start]->rchild;
		}
		
	}
}
//ABC###E#D##

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
	levelOrder(T);

	return 0;
	
}  
