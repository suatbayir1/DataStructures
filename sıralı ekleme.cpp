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

blist * siraliekle(blist * ilk,int veri){
	 if(ilk==NULL){			
	 	ilk=(blist *)malloc(sizeof(blist));
	 	ilk->arka=NULL;						// ba�l� listenin bo� olma durumu
	 	ilk->veri=veri;
	 	return ilk;
	 }
	 
	   if(ilk->veri<veri){		
		blist * gecici=(blist *)malloc(sizeof(blist));
	 	gecici->veri=veri;					
	 	gecici->arka=ilk;						// yeni eleman�n ilk elemandan b�y�k olma durumu
	 	return gecici;	
		 }
		 
	 	blist * gez = ilk;
	 	while(gez->arka!=NULL && gez->arka->veri > veri){  // listenin sonuna gelinmediyse ve listenin i�indeki eleman�n de�eri  yeni eklenecek kutunun de�erinden b�y�kse 
	 		gez=gez->arka;  
		 }

		 blist *gecici=(blist *)malloc(sizeof(blist));
		 gecici->arka=gez->arka;
		 gez->arka=gecici;
		 gecici->veri=veri;
		 return ilk;
	 }

int main(){
	
	blist * ilk;
	ilk=NULL;
	ilk=siraliekle(ilk,275);
	ilk=siraliekle(ilk,313);
	ilk=siraliekle(ilk,79);
	ilk=siraliekle(ilk,-1);
	ilk=siraliekle(ilk,2);
	ilk=siraliekle(ilk,7);
	ilk=siraliekle(ilk,7);
	ilk=siraliekle(ilk,2);
	ilk=siraliekle(ilk,3);
	listele(ilk);
	 
}
