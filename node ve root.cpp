#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int x;
	struct n * next;
};

typedef struct n node;

int main(){
	node * root;
	root= (node *)malloc(sizeof(node));
	root->x=10;
	root->next= (node *) malloc(sizeof(node));
	root->next->x=20;
	root->next->next=(node *)malloc(sizeof(node));
	root->next->next->x=30;
	root->next->next->next=(node *)malloc(sizeof(node));
	root->next->next->next->x=40;

	root->next->next->next->next=NULL;  // iþlemler bittikten sonra son pointer boþluðu göstermelidir.
	
	node * iter;
	iter = root;
	printf("%d",iter->x);
	iter=iter->next;
	printf("\n%d",iter->x);
	iter=iter->next;
	printf("\n%d",iter->x);
	iter=iter->next;
	printf("\n%d",iter->x);
	
	iter=root;
	int i=0;
	
	while(iter->next!=NULL){
		i++;
		printf("\n%d. eleman : %d",i,iter->x);
		iter=iter->next;
	}
	
	for(i=4;i<10;i++){
		iter->next=(node *)malloc(sizeof(node));
		iter=iter->next;
		iter->x=i*10;
		printf("\n%d. eleman : %d",i,iter->x);
		iter->next=NULL;
	}
	
}
