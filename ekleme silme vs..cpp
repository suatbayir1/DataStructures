#include <stdio.h>
#include <stdlib.h>

typedef struct bagliste{
	int veri;
	struct bagliste *arka;
}blist;

blist *ilk=NULL,*son=NULL,*gez=NULL,*eleman=NULL;

void ekle(blist *eleman,int veri){
eleman=(blist *)malloc(sizeof(blist));
	if(ilk==NULL){
		ilk=eleman;
		son=eleman;
		eleman->veri=veri;
		eleman->arka=NULL;
	}
	else{
		son->arka=eleman;
		son=eleman;
		eleman->veri=veri;
		eleman->arka=NULL;
	}
}

blist *ara(int aranan){
	int say=1;
	gez=ilk;
	while(ilk!=NULL){
		if(gez->veri==aranan){
			printf("%d. kutuda ",say);
			return gez;
		}
			gez=gez->arka;
			say++;
	
	}
	return NULL;
}

int listele(){
	gez=ilk;
	while(gez!=NULL){
		printf("%d\t",gez->veri);
		gez=gez->arka;
	}
}

int main(){
	ekle(eleman,10);
	ekle(eleman,20);
	ekle(eleman,30);
	ara(20);
	listele();
}
