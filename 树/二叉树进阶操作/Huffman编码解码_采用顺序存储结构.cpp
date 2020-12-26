//inquiry happiness 
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
	int parent;
	int lchild;
	int rchild;
}*HuffTree,HuffNode;
typedef struct {
	DataType data;
	int bit[MAXBIT];
	int start;
}HuffCode,*HuffCodeTree;
typedef struct {
	DataType data;
	int num;
}Message;
void select(int *x1,int *x2,int i,int count,HuffNode HuffNodes[]){
	int m1=MAXVALUE,m2=MAXVALUE;
	for(int j=0;j<count+i;j++){
		if(HuffNodes[j].parent==-1&&HuffNodes[j].weight<m1){ ///��δ��������� 
			m2 = m1;*x2 = *x1;m1 = HuffNodes[j].weight;*x1 = j;
		}else if(HuffNodes[j].parent==-1&&HuffNodes[j].weight<m2){
			m2 = HuffNodes[j].weight;
			(*x2) = j;
		}
	}
}
void HuffmanTree(HuffNode HuffNodes[],int count){
	int i,j,m1,m2,x1,x2,temp1;
	DataType temp2;
	//����Huffman��
	for(int i=0;i<count-1;i++){
		select(&x1,&x2,i,count,HuffNodes);
		HuffNodes[x1].parent=count+i;HuffNodes[x2].parent=count+i;
		HuffNodes[count+i].weight = HuffNodes[x1].weight+HuffNodes[x2].weight;
		HuffNodes[count+i].lchild=x1;HuffNodes[count+i].rchild=x2;
	}
}
void HuffmanCode(int count,HuffNode HuffNodes[],HuffCodeTree *HuffCodes){
	HuffCode cd;
	int c,p;
	*HuffCodes = (HuffCodeTree)malloc(sizeof(HuffCode)*count); //�������������һ��һ���� 
	for(int i=0;i<count;i++){
		c = i;cd.start = MAXBIT-1;
		p = HuffNodes[c].parent;
		while(p!=-1){
			if(HuffNodes[p].lchild==c){
				cd.bit[cd.start]=0;
			}else{
				cd.bit[cd.start]=1;
			}
			cd.start--;
			c=p;
			p=HuffNodes[c].parent;
		}
		for(int j = cd.start+1;j<MAXBIT;j++){
			(*HuffCodes)[i].bit[j] = cd.bit[j];
		}
		(*HuffCodes)[i].start = cd.start;
	}
		for(int i=0;i<count;i++){
			printf("  %c��Huffman���룺",HuffNodes[i].data); 
			for(int j=(*HuffCodes)[i].start+1;j<MAXBIT;j++){
				printf("%d",(*HuffCodes)[i].bit[j]);
			}
			printf("\n") ;
		}
} 
//��ʼ�������ã����ַ�����aת��ΪMessage�ṹ������õ�count,��ת��ΪHuffNode ���飬����������Ȩֵ�Ĵ�С�������� 
void Initial(DataType a[],HuffTree *HuffNodes,Message data[],int *count){
	scanf("%s",a);
	DataType *p = a;
	for(int i=0;i<30;i++){
		data[i].data = NULL;
		data[i].num = 0;
	}
	while(*p){ //���������ַ���Ȩ�� 
		for(int i=0;i<(*count)+1;i++){
			if(data[i].data==NULL){//??????soga 
				data[i].data=*p;data[i].num++;(*count)++;break;
			}
			else if(data[i].data==*p){
				data[i].num++;break;
			}
		}
		p++;
	}
	int temp1;
	DataType temp2;
	for(int i=0;i<*count;i++){
		for(int j=i+1;j<*count;j++){
			if(data[j].num>data[i].num){
				//�����ýṹ�帴ֵȻ��ֱ�ӽ����� 
				temp1=data[i].num;data[i].num=data[j].num;data[j].num=temp1;
				temp2=data[i].data;data[i].data=data[j].data;data[j].data=temp2;
			}
		}
	}
	//��̬����HuffNodes���� 
	*HuffNodes = (HuffTree)malloc(sizeof(HuffNode)*((*count)*2-1)); //�ٶ��ɹ� 
	for(int i=0;i<*count;i++){
		(*HuffNodes)[i].weight=data[i].num;
		(*HuffNodes)[i].data =data[i].data;
	}
	for(int i=0;i<2*(*count)-1;i++){ //huffman���Ľڵ�����ΪҶ�ӽڵ�*2 -1   �����ӵĽڵ��data���� 
		(*HuffNodes)[i].parent=-1;(*HuffNodes)[i].lchild=-1;(*HuffNodes)[i].rchild=-1;
	}
}
//ABCEEECCBBBBBBBBBBB
int main(){
	DataType *s;
	DataType a[MAXNODE];
	Message data[30];
	int count = 0;
	HuffNode *HuffNodes;  //���������𣿣����� ����
	HuffCode *HuffCodes; 
	printf("������һЩ�ַ���\n");
	Initial(a,&HuffNodes,data,&count);
	HuffmanTree(HuffNodes,count);
	printf(" \n��ͬ���ַ�����%d\n",count);
	for(int i=0;i<count;i++){
		printf("%c ",data[i].data);
		printf(" Ȩֵ��%d",data[i].num);
		printf("\n");
	}
	HuffmanCode(count,HuffNodes,&HuffCodes); 
//	HuffmanCode(count,data);
//	getch();
	return 0;
}
