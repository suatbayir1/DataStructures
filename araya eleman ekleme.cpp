#include <stdio.h>
#include <stdlib.h>

typedef struct bagliliste{
	int veri;
	struct bagliliste * arka;
}blist;

void listele(blist *ilk){
	while(ilk!=NULL){
		printf("%d ",ilk->veri);
		ilk=ilk->arka;
	}
}

void ekle(blist *ilk,int veri){
	while(ilk->arka!=NULL){
		ilk=ilk->arka;
	}
	ilk->arka=(blist *)malloc(sizeof(blist));
	ilk->arka->veri=veri;
	ilk->arka->arka=NULL;
}

int main(){
	blist *ilk;
	ilk=(blist *)malloc(sizeof(blist));
	ilk->arka=NULL;
	ilk->veri=500;
	int i=0;
	for(i=0;i<5;i++){
		ekle(ilk,i*10);
	}
	listele(ilk);
	
// araya eleman ekleyen kod

	blist * gez=ilk;
	
	for(i=0;i<3;i++){	// döngünün 3 defa dönmesi araya ekleyeceðimiz elemanýn ilk elemandan 3 kutu uzakta olmasýndan dolayý baþka yere eklemek isteseydik döngüyü o kadar döndürmemiz gerekecekti
		gez=gez->arka;
	}
	blist * gecici=(blist *)malloc(sizeof(blist));
	gecici->arka=gez->arka;
	gez->arka=gecici;
	gecici->veri=100;
	printf("\n\n");
	listele(ilk);
	
}
