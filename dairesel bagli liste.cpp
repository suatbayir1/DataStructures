#include <stdio.h>
#include <stdlib.h>

typedef struct bagliliste{
	int veri;
	struct bagliliste * arka;
}blist;

void listele(blist *r){
	blist *gez=r;
		printf("%d ",gez->veri);		// ilk eleman ve gezen pointer zaten ayn� yeri g�sterdiginden asag�daki d�ng� �al�sm�cak o y�zden ilk eleman� yazd�r�p bir sonraki kutuya ge�iyor
		gez=gez->arka;				
	while(gez!=r){		// gez ilk elemanda degilken
		printf("%d ",gez->veri);
		gez=gez->arka;		// yani gezici pointer ilk de�ere gelene kadar listeyi yazar
	}
	printf("\n");
}

void ekle(blist *r,int veri){
	blist *gez=r;
	while(gez->arka!=r){
		gez=gez->arka;
	}	
	gez->arka=(blist *)malloc(sizeof(blist));
	gez->arka->veri=veri;
	gez->arka->arka=r;	
}

blist * siraliekle(blist * r,int veri){
	 if(r==NULL){			
	 	r=(blist *)malloc(sizeof(blist));
	 	r->arka=r;						// ba�l� listenin bo� olma durumu
	 	r->veri=veri;
	 	return r;
	 }
	 
	   if(r->veri>veri){		
		blist * gecici=(blist *)malloc(sizeof(blist));
	 	gecici->veri=veri;					
	 	gecici->arka=r;						// yeni eleman�n ilk elemandan b�y�k olma durumu
	 	
	 	blist *gez=r;
	 	while(gez->arka!=r){
	 		gez=gez->arka;
		 }
		 gez->arka=gecici;
		return gecici;	
		 }
		 

	 	blist * gez = r;
	 	while(gez->arka!=r && gez->arka->veri < veri){  // listenin sonuna gelinmediyse ve listenin i�indeki eleman�n de�eri  yeni eklenecek kutunun de�erinden b�y�kse 
	 		gez=gez->arka;  
		 }

		 blist *gecici=(blist *)malloc(sizeof(blist));
		 gecici->arka=gez->arka;
		 gez->arka=gecici;
		 gecici->veri=veri;
		 return r;
		
	 }

blist *sil(blist *r,int veri){
	blist *silinecek;
	blist *gez=r;
	
	
	
	if(r->veri==veri){							// yani arad���m�z eleman listenin ba��ndaysa
		while(gez->arka!=r){
			gez=gez->arka;
		}
		gez->arka=r->arka;
		free(r);
		return gez->arka;			
	}
	
	while(gez->arka!=r && gez->arka->veri!=veri){
		gez=gez->arka;
	}
	
	if(gez->arka==r){			// gez pointer� son elaman� g�steriyorsa silinecek de�er listede yok demektir 
		printf("sayi bulunamadi\n\n");
		return r;
	}
	silinecek=gez->arka;
	gez->arka=gez->arka->arka;
	free(silinecek);
	return r;
}


int main(){
	
	blist * ilk;
	ilk=NULL;
	ilk=siraliekle(ilk,400);
	ilk=siraliekle(ilk,40);
	ilk=siraliekle(ilk,4);
	ilk=siraliekle(ilk,450);
	ilk=siraliekle(ilk,50);
	ilk=siraliekle(ilk,500);
	ilk=siraliekle(ilk,0);
	listele(ilk);
	printf("\n\n");
	ilk=sil(ilk,50);
	ilk=sil(ilk,4);
	ilk=sil(ilk,100);
	ilk=sil(ilk,450);
	listele(ilk);
}
