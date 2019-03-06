#include <stdio.h>
#include <stdlib.h>

typedef struct bst{
	int data;
	struct bst *left;
	struct bst *right;
}node;

node *ekle(node *agac,int x){
	
	node *kok = (node *)malloc(sizeof(node));
	
	if(agac==NULL){
		kok->left =NULL;
		kok->right=NULL;
		kok->data = x;
		return kok;
	}
	
	if(agac->data < x){
		agac->right=ekle(agac->right,x);
		return agac;
	}
	agac->left=ekle(agac->left,x);	
	return agac;			
	}
	
void dolas(node *agac){
	if(agac!=NULL){	
		dolas(agac->right);
		printf("%d ",agac->data);
		dolas(agac->left);
	}
}

int max(node *agac){
	while(agac->right!=NULL)
		agac=agac->right;
	return agac->data;
}

int min(node *agac){
	while(agac->left!=NULL)
		agac=agac->left;
	return agac->data;
}

int ara(node *agac,int aranan){
	if(agac==NULL)
		return -1;
	if(agac->data==aranan)
		return 1;
	if(ara(agac->right,aranan)==1)
		return 1;
	if(ara(agac->left,aranan)==1)
		return 1;
	return -1;
}

node *sil(node *agac,int silinecek){
	
	if(agac==NULL)
		return NULL;
	if(agac->data==silinecek){
		if(agac->left==NULL && agac->right==NULL)
			return NULL;
		if(agac->right!=NULL){
			agac->data=min(agac->right);
			agac->right=sil(agac->right,min(agac->right));
			return agac;
		}
		agac->data=max(agac->left);
		agac->left=sil(agac->left,max(agac->left));
		return agac;
	}
	
	if(agac->data<silinecek){
		agac->right=sil(agac->right,silinecek);
		return agac;
	}
	agac->left=sil(agac->left,silinecek);
	return agac;
}

int main(){
	node *agac=NULL;
	agac=ekle(agac,12);
	agac=ekle(agac,200);
	agac=ekle(agac,190);
	agac=ekle(agac,213);
	agac=ekle(agac,56);
	agac=ekle(agac,24); 
	dolas(agac);
	printf("\n sonuc : %d",ara(agac,200));
	printf("\n max : %d",max(agac));
	printf("\n min : %d",min(agac));
	agac=sil(agac,56);
	agac=sil(agac,213);
	agac=sil(agac,500);
	printf("\n");
	dolas(agac);
}
