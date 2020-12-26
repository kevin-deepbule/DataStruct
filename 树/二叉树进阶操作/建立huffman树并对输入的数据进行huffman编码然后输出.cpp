#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define DataType char
#define MAXNODE 100
#define MAXVALUE 10000 
#define MAXBIT 50
typedef struct Node_H{
	DataType data;
	int weight;
	struct Node_H parent;
	struct Node_H *lchild;
	struct Node_H *rchild;
}*HuffTree,HuffNode;
typedef struct {
	DataType data;
	int bit[MAXBIT];
	int start;
}HuffCode,*HuffCodeP;
typedef struct {
	DataType data;
	int num;
}Message;


int main(){
	DataType *s;
	DataType a[MAXNODE];
	Message data[30];
	int count = 0;
	HuffNode *HuffNodes;  //这样可以吗？！！！ 可以
	HuffCode *HuffCodes; 
	printf("请输入一些字符：\n");
	Initial(a,&HuffNodes,data,&count);
	HuffmanTree(HuffNodes,count);
	printf(" \n不同的字符数：%d\n",count);
	for(int i=0;i<count;i++){
		printf("%c ",data[i].data);
		printf(" 权值：%d",data[i].num);
		printf("\n");
	}
	HuffmanCode(count,HuffNodes,&HuffCodes); 
//	HuffmanCode(count,data);
//	getch();
	return 0;
}
