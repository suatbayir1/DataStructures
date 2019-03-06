#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node *next;
}n;

node *ilk=NULL,*son=NULL,*gez=NULL;

void ekle(int veri){
	node *eleman=(n *)malloc(sizeof(n));
	if(ilk==NULL){
		ilk=eleman;
		son=eleman;
		eleman->next=NULL;
		eleman->data=veri;
	}
	else{
		son->next=eleman;
		son=eleman;
		eleman->data=veri;
		eleman->next=NULL;	
	}
}

int listele(){
	gez=ilk;
	while(gez!=NULL){
		printf("%d ",gez->data);
		gez=gez->next;
	}
}

int ara(int aranan){
	gez=ilk;
	while(gez!=NULL){
		if(gez->data==aranan){
			return gez->data;
		}
		else{
			gez=gez->next;
		}
		printf("%d dizide yok",aranan);
	}
}

int main(){
	
	ekle(5);
	ekle(10);
	ara(140);
	listele();
}
