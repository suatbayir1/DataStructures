#include <stdio.h>
#include <stdlib.h>

typedef struct yapi{
	int veri;
	struct yapi * arka;
}liste;


void listele(liste * ilk){
	while(ilk!=NULL){
		printf("%d ",ilk->veri);
		ilk=ilk->arka;
	}
}


int main(){
	
	int i;
	
	liste * arka=NULL;	
	liste *ilk=NULL;
	liste *son=NULL;
	liste *eleman;
	liste *gez;
	
	//1. eleman ekleniyor
	
	eleman=(liste *)malloc(sizeof(liste));
	eleman->veri=5;
	eleman->arka=NULL;
	ilk=eleman;
	printf("%d\n",eleman->veri);
	
	//2.eleman ekleniyor 
	
	eleman=(liste *)malloc(sizeof(liste));
	eleman->veri=8;
	eleman->arka=NULL;
	printf("%d\n",eleman->veri);

	gez=ilk;
	

	while(gez->arka!=NULL){
		i++;
		printf("%d",gez->arka);
		gez=gez->arka;
	}
	listele(ilk);
	 
	
	for(i=0;i<10;i++){
		gez->arka=(liste *)malloc(sizeof(liste));
		gez=gez->arka;
		gez->veri=i*10;
		printf("%d\n",gez->veri);
		gez->arka=NULL;
	}
	
	

}
