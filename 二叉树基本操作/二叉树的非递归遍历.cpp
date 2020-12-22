#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<string.h>
#define DataType char
#define MAXNODE 100
typedef struct Node{
	DataType data;
	struct Node *lchild;
	struct Node *rchild; 
}*BiTree,BiTNode; 
void Initial(char preorder[],char midorder[]){
	scanf("%s",preorder);
	scanf("%s",midorder);
}
//创建二叉树
//
//测试数据
//ABCDEFGHI
//BCAEDGHFI 
void ReBiTree(BiTree *T,char preorder[],char midorder[],int i,int j,int k,int h){
	(*T) = (BiTree)malloc(sizeof(BiTNode));
	(*T)->data = preorder[i];
	int m = k;
	while(preorder[i]!=midorder[m])
		m++;
	if(m==k)
		(*T)->lchild = NULL;
		
	else
		ReBiTree(&((*T)->lchild),preorder,midorder,i+1,i+m-k,k,m-1);
	if(m==h)
		(*T)->rchild = NULL;
	else
		ReBiTree(&((*T)->rchild),preorder,midorder,i+m-k+1,j,m+1,h);
} 

void No_digui_preOrder(BiTree T){
	BiTree stack[MAXNODE],p;
	if(!T)
		return ;
	p = T; 
	int top = 0;
	while(!(p==NULL&&top==0)){
		while(p){
			stack[top] = p;
			printf("%c",p->data); 
			top++;
			p = p->lchild;
		}
		top--;
		p = stack[top];
		p = p->rchild;
	}
}
void No_digui_midOrder(BiTree T){
	BiTree stack[MAXNODE],p;
	int top = 0;
	p = T; 
	while(!(p==NULL&&top==0)){
		while(p){
			stack[top] = p;
			top++;
			p = p->lchild;
		}
		top --;
		p = stack[top];
		printf("%c",p->data);
		p = p->rchild;
	}
	
}

typedef struct a{
	BiTree link;
	int flag;
}stacktype; 
void No_digui_afterOrder(BiTree T){
	stacktype stack[MAXNODE];
	BiTree p = T;
	int top = 0;
	int sign;
	while(!(p==NULL&&top == 0)){
		while(p){
			stack[top].link = p;
			stack[top].flag = 1;
			top++;
			p = p->lchild;
		}
		top--;
		p = stack[top].link;
		sign = stack[top].flag;
		if(sign==1){
			stack[top].link= p ;
			stack[top].flag = 2;
			top++;
			p = p->rchild;
		}else{
			printf("%c",p->data);
			p = NULL;
		}
		
		
	}
	
}
int main(){
	BiTree T; 
	char preorder[9],midorder[9];
	Initial(preorder,midorder);
	ReBiTree(&T,preorder,midorder,0,8,0,8);
//	preOrder(T);
	No_digui_preOrder(T);
	No_digui_midOrder(T);
	printf("\n");
	No_digui_afterOrder(T);
	return 0;
} 
