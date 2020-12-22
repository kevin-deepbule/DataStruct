#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define DataType char
#define MAXNODE 100
typedef struct Node_W{
	DataType data;
	int weight;
	struct Node_W *lchild;
	struct Node_W *rchild;
}*HuffTree,HuffNode;
void initial(DataType a[]){
	scanf("%s",a);
}
int main(){
	DataType a[MAXNODE];
	initial(a);
	return 0;
}
