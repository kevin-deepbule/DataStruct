#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define DataType char
#define MAXVALUE 1000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2-1 
typedef struct Node_W{
	DataType data;
	int weight;
	struct Node_W *lchild;
	struct Node_W *rchild;
};
meiyou 
