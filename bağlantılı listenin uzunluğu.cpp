#include<stdio.h>
#include<stdlib.h>

typedef struct blist{
    int veri;
    struct blist* arka;
};

void ekle(blist **r,int veri){
    blist* bliste=(blist*)malloc(sizeof(blist));
    bliste->veri=veri;
    bliste->arka=(*r);
    (*r)=bliste;
}
 
int say(blist* ilk){
    int say=0;  
    blist *gez=ilk;  
    while(gez!=NULL){
        say++;
        gez=gez->arka;
    }
    return say;
}
 
int main(){
    blist* ilk=NULL;
    ekle(&ilk,1);
    ekle(&ilk,3);
    ekle(&ilk,15);
    ekle(&ilk,10);
    ekle(&ilk,5); 
 	ekle(&ilk,5); 
    printf("Listenin Uzunlugu : %d",say(ilk));
}
