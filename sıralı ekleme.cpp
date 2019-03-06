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
	 	ilk->arka=NULL;						// bağlı listenin boş olma durumu
	 	ilk->veri=veri;
	 	return ilk;
	 }
	 
	   if(ilk->veri<veri){		
		blist * gecici=(blist *)malloc(sizeof(blist));
	 	gecici->veri=veri;					
	 	gecici->arka=ilk;						// yeni elemanın ilk elemandan büyük olma durumu
	 	return gecici;	
		 }
		 
	 	blist * gez = ilk;
	 	while(gez->arka!=NULL && gez->arka->veri > veri){  // listenin sonuna gelinmediyse ve listenin içindeki elemanın değeri  yeni eklenecek kutunun değerinden büyükse 
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
