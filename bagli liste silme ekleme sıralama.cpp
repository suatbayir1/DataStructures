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
	printf("\n");
}

blist * siraliekle(blist * ilk,int veri){
	 if(ilk==NULL){			
	 	ilk=(blist *)malloc(sizeof(blist));
	 	ilk->arka=NULL;						// bağlı listenin boş olma durumu
	 	ilk->veri=veri;
	 	return ilk;
	 }
	 
	   if(ilk->veri > veri){		
		blist * gecici=(blist *)malloc(sizeof(blist));
	 	gecici->veri=veri;					
	 	gecici->arka=ilk;						// yeni elemanın ilk elemandan büyük olma durumu
	 	return gecici;	
		 }
		 

	 	blist * gez = ilk;
	 	while(gez->arka!=NULL && gez->arka->veri < veri){  // listenin sonuna gelinmediyse ve listenin içindeki elemanın değeri  yeni eklenecek kutunun değerinden büyükse 
	 		gez=gez->arka;  
		 }

		 blist *gecici=(blist *)malloc(sizeof(blist));
		 gecici->arka=gez->arka;
		 gez->arka=gecici;
		 gecici->veri=veri;
		 return ilk;
		
	 }

blist *sil(blist *ilk,int veri){
	blist *silinecek;
	blist *gez=ilk;
	
	if(ilk->veri==veri){		// yani aradığımız eleman listenin başındaysa
		silinecek=ilk;
		ilk=ilk->arka;
		free(silinecek); // silinecek değeri ram den siler
		return ilk;			
	}
	
	while(gez->arka!=NULL && gez->arka->veri!=veri){
		gez=gez->arka;
	}
	
	if(gez->arka==NULL){			// gez son elamnı gösteriyorsa silinecek değer listede yok demektir 
		printf("sayi bulunamadi\n\n");
		return ilk;
	}
	
	silinecek=gez->arka;
	gez->arka=gez->arka->arka;
	free(silinecek);
	return ilk;
}


int main(){
	
	blist * ilk;
	ilk=NULL;
	ilk=siraliekle(ilk,400);
	ilk=siraliekle(ilk,40);
	ilk=siraliekle(ilk,4);
	ilk=siraliekle(ilk,450);
	ilk=siraliekle(ilk,50);
	listele(ilk);
	printf("\n\n");
	ilk=sil(ilk,50);
	ilk=sil(ilk,4);
	ilk=sil(ilk,100);
	listele(ilk);
}
