#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#define DataType char
#define MAXNODE 100
typedef struct Node{
	DataType data;
	struct Node *lchild;
	struct Node *rchild;
}*BiTree,BiTNode;
void ReBiTree(BiTree *T,char preOrder[],char midOrder[],int i,int j,int k,int h){
	(*T) = (BiTree)malloc(sizeof(BiTNode));
	(*T)->data = preOrder[i];
	int m = k;
	while(preOrder[i]!=midOrder[m])
		m++;
	if(m==k)
		(*T)->lchild = NULL;
	else 
		ReBiTree(&((*T)->lchild),preOrder,midOrder,i+1,i+m-k,k,m-1);
	if(m==h)
		(*T)->rchild = NULL;
	else
		ReBiTree(&((*T)->rchild),preOrder,midOrder,i+m-k+1,j,m+1,h);	
}
void Initial(char preOrder[],char midOrder[]){
	scanf("%s",preOrder);
	scanf("%s",midOrder);

}
void PreOrder(BiTree T){
	if(T){
		printf("%c",T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	} 
} 
void No_Digui_midOrder(BiTree T){
	BiTree stack[MAXNODE],p;
	int top = 0;
	p  = T;
	while(!(p==NULL&&top == 0)){
		while(p){
			stack[top] = p;
			top++;
			p= p->lchild;
		}
		top--;
		p = stack[top];
		printf("%c",p->data);
		p = p->rchild;
	}
}
typedef struct a{
	int sign;
	BiTree link;
}sign_Tree; 
void No_Digui_afterOrder(BiTree T){
	BiTree p = T;
	sign_Tree stack[MAXNODE];
	int top = 0;
	int sign;
	while(!(p==NULL&&top == 0)){
		while(p){
			 stack[top].link = p;
			 stack[top].sign = 1;
			 p = p->lchild;
			 top++;		
		}
		top--;
		sign = stack[top].sign;
		 p  = stack[top].link;
		if(sign==1){
			
			stack[top].link = p;
			stack[top].sign = 2;
			top++;
			p = p->rchild;
		}else{
			printf("%c",p->data);
			p = NULL;
		}	
	}
}
//ABCDEFGHI
//BCAEDHGIF
int main(){
	BiTree T;
	char preOrder[9];
	char midOrder[9];
	Initial(preOrder,midOrder);
	ReBiTree(&T,preOrder,midOrder,0,8,0,8);
	PreOrder(T);
	printf("\n");
	No_Digui_midOrder(T);
	printf("\n");
	No_Digui_afterOrder(T);
	return 0;
	
} 
