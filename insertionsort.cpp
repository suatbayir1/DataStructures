#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int dizi[],int boyut){
	int i,k,gecici;
	
	for(i=1;i<boyut;i++){
		gecici=dizi[i];
		for(k=i-1; k>=0 && gecici<=dizi[k];k--){
			dizi[k+1]=dizi[k];
			
		}
		dizi[k+1]=gecici;
	}
}

int main(){
	int i,dizi[5];
	srand(time(NULL));
	for(i=0;i<5;i++){
		dizi[i]=rand()%100+1;
	}
	
	for(i=0;i<5;i++){
		printf("%d\t",dizi[i]);
	}
	insertion(dizi,5);
	printf("\n\n");
	for(i=0;i<5;i++){
		printf("%d\t",dizi[i]);
	}
}
