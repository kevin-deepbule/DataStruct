#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define DataType char
int leavecount = 0;
typedef struct Node{
	DataType data;
	struct Node *lchild;
	struct Node *rchild;
}BiTNode,*BiTree;

int Search(char a[],char b[]){
	int len = strlen(a);
	for(int i=0;i<len;i++){
		if(a[0]==b[i]){
			return i;
		}
	}
	return -1;
}
void headReduce(char data[],int s,int l,char result[]){
		
	if(l!=0){
		for(int i=0;i<l;i++){
			result[i] = data[i+s];
		} 	
	}
	
}
void ReBiTree(BiTree *T,char preorder[],char midorder[],int i,int j,int k,int h){
//		以先序序列[i,,,j] 中序序列[k...,h] 建立二叉树 
		(*T) = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = preorder[i];
		int	m = k;
		while(midorder[m]!=preorder[i])
			m++;
		if(m==k)
			(*T)->lchild = NULL;
		else
			ReBiTree(&((*T)->lchild),preorder,midorder,i+1,i+m-k,k,m-1); //秒。我好笨啊 
//			以先序序列[i+1,...i+m-k]中序序列[k,...m-1] 创建右子树 
		if(m==h)
			(*T)->rchild = NULL;
		else
			ReBiTree(&((*T)->rchild),preorder,midorder,i+m-k+1,j,m+1,h);
//			以 先序序列[i+m-k+1,...j] 中序序列[m+1,h] 创建左子树
 
	
}
void InitData(DataType preorder[],DataType midorder[]){ //,int a,int b,int c,int d
		printf("请输入先序和中序遍历的顺序\n"); 
		scanf("%s",preorder);
		scanf("%s",midorder);
}
void preOrder(BiTree T){
	if (T){
		printf("%c ",T->data);
		preOrder(T->lchild);
		
		preOrder(T->rchild);
	}
	return ;
}
//统计叶子节点的树数目
void leaveNode(BiTree T){
	if(T){
		leaveNode(T->lchild);
		leaveNode(T->rchild);
		if((T->lchild==NULL)&&(T->rchild==NULL)){
			leavecount++;
		}
	}
} 
BiTree findData(BiTree T,char a){
	if(T->data==a){
		return T;
	}
	if(T->lchild){
		BiTree t = findData(T->lchild,a); //对递归抛弃幻想，思考清楚 
		if(t) {
			return t;
		}	
	}
	if(T->rchild){
		BiTree t = findData(T->rchild,a);
		if(t) {
			return t;
		}	
	}
	return NULL;
	
}
int main(){
	BiTree T;
	char a[9];
	char b[9];
	InitData(a,b);
//	int i =Search(a,b);
//	printf("%d",i);
	ReBiTree(&T,a,b,0,9,0,9);
	preOrder(T);
	leaveNode(T);
	printf("%d ",leavecount);
	BiTree D = findData(T,'D');
	if(D->lchild){
		printf("%c ",D->lchild->data);
	}
	if(D->rchild)
		printf("%c ",D->rchild->data);
	return 0;
}
//收获：编程一定得每一步都得思路清晰，不能按照脑子里想的来 
//我没解出这题的原因是按照实际操作过程来的，没有按照程序化的思想，
//在以后编程的过程中要是脑子不清楚每一个步骤一定不能盲目开始浪费时间与精力，
//一定要想清楚，最好用文字写出过程在进行编程 。出现问题一定得停下来，思考是不是思路还是方法有问题 
//对于模糊的方法思路一定不能选择 。 
