#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct topluluk {
	int bilgi;
	char mesaj[100];			
	struct topluluk *arka;
}BLISTE;

int ekle(BLISTE *ki);
int listele();

BLISTE *ilk=NULL;		// listenin ilk ve son pointerý boþluðu gösteriyor..
BLISTE *son=NULL;		

BLISTE *ara(int);
BLISTE *sil(int);
BLISTE *okuKlavye();
void yazEkrana(BLISTE *);

int main(){
	
	setlocale(LC_ALL,"Turkish");
	
	BLISTE *eklenecek, *ki;
	int bilgi,sonuc;
	char secim;
	
	while(1){
		puts("Ekleme(E)\nListeleme(L)\nArama(A)\nSilme(S)\nÇýkýþ(C,Ç)\n\nSeçim yapýnýz");
		secim=getchar();
		
		switch(secim){
			
			case 'E' : eklenecek=okuKlavye();
						if(eklenecek!=NULL){
							ekle(eklenecek);
						}
						else{
							puts("Ekleme için Bellek Dolu\n");
						}
						break;
			
			case 'L' : sonuc=listele();
						if(sonuc==-1){
							puts("Boþ Liste\n");
						}
						break;
						
			case 'A' : puts("Aranan : ");
					   scanf("%d",&bilgi);
					   ki=ara(bilgi);
					   if(ki==NULL){
					   	puts("\nAranan Bulunamadý\n");
					   }
					   else{
					   	yazEkrana(ki);
					   }
					   break;
			
			case 'S' : puts("\nSilinecek : ");
						scanf("%d",&bilgi);
						ki=sil(bilgi);
						if(ki!=NULL){
							puts("\nSilindi..\n");
						}
						else{
							puts("\nSilinmek istenen Listede yok");
						}
						break;
		
			case 'Ç' :
						puts("\nProgram Kapandý\n");
						exit(0);
						break;
					default: puts("Yanlýþ Seçim yaptýn \n");
 					break;
		}
	}
}

	int ekle(BLISTE *ki){
		if(ilk!=NULL){
			son->arka=ki;
			son=ki;
			son->arka=NULL;
		}
		else{
			ilk=ki;
			son=ilk;
			ilk->arka=NULL;
		}
		return 0;
	}
	
	int listele(){
		BLISTE *p;
		p=ilk;
		if(p==NULL){
			return -1;
		}
		while(p){
			yazEkrana(p);
			p=p->arka;
		}
		return 0;
	}
	
	BLISTE *ara(int aranan){
		BLISTE *p;
		p=ilk;
		while(p){
			if(p->bilgi==aranan){
				return p;
			}
			p=p->arka;
		}
		return NULL;
	}
	
	BLISTE *sil(int silinecek){
		BLISTE *p, *bironceki;
		p=ilk;
		bironceki=NULL;
		while(p){
			if(silinecek==p->bilgi){
				break;
			}
			bironceki=p;
			p=p->arka;
		}
		
		if(p!=NULL){
			if(bironceki==NULL){
				if(ilk==son){
					ilk=NULL;
					son=NULL;
				}
				else{
					ilk=ilk->arka;
				}
			}
			else{
				bironceki->arka=p->arka;
				if(bironceki->arka==NULL){
					son=bironceki;
				}
			}
			free(p);
			return p;
		}
		else 
		return NULL;
	}
	
	void yazEkrana(BLISTE *yazilacak){
		printf("\nbilgi : %d mesaj : %s\n",yazilacak->bilgi,yazilacak->mesaj);
	}
	
	BLISTE *okuKlavye(){
		BLISTE *okunan;
		
		okunan= (BLISTE *)malloc(sizeof(BLISTE));
		if(okunan==NULL){
			return NULL;
		}
		puts("\nBilgi Giriniz : ");
		scanf("%d",&(okunan->bilgi));
		puts("\nMesaj Giriniz : ");
		scanf("%s",okunan->mesaj);
		return okunan;
}
