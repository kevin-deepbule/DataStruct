//按照层次顺序遍历二叉树的算法 
#include<stdio.h>
#include<iostream>
#include<malloc.h>
#define MAXSON 5
typedef struct Node{
	char data;
	struct Node *child[MAXSON];
}*NTree,NTNode; 
void CreatNTree(NTree *T){
	char c = getchar();
	if(c=='#'){
		*T =NULL;
	}else{
		*T = (NTree)malloc(sizeof(NTNode));
		(*T)->data =c;
		for(int i = 0;i<MAXSON;i++){
			CreatNTree(&((*T)->child[i]));
		}
	}
}
void levelOrder(NTree T){
	NTree p=T,rear[30];
	int start=-1,tail=0;
	rear[0] = p;
	while(start!=tail){
		start++;
		 p = rear[start];
		printf("%c",rear[start]->data);
//		if(rear[start]->lchild){
//			tail++;
//			rear[tail] = rear[start]->lchild;
//		}
//		if(rear[start]->rchild){
//			tail++;
//			rear[tail] = rear[start]->rchild;
//		}
		for(int i = 0;i<MAXSON;i++){
			if(rear[start]->child[i]){
			tail++;
			rear[tail] = rear[start]->child[i];
		}
	}
}
} 
//ABC###E#D##

void preOrder(NTree T){
	if(T){
		printf("%c",T->data);
		for(int i = 0;i<MAXSON;i++){
			preOrder(T->child[i]);
		}
	}
}
int main(){
	NTree T;
	CreatNTree(&T);
	preOrder(T);
	levelOrder(T);

	return 0;
	
}  
