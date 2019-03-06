#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void mergesort(int dizi[],int sol,int sag);
void merge(int dizi[],int p,int p1,int r,int r1);
 
 
void mergesort(int dizi[],int sol,int sag){	
	int q;
	if(sol<sag){
		
		q=(sol+sag)/2;
		mergesort(dizi,sol,q); 
		mergesort(dizi,q+1,sag);
		merge(dizi,sol,q+1,q,sag); 
	}
}

void merge(int dizi[],int p,int p1,int r,int r1){
	int i,j,k,gecicidizi[10000];
	j=p1; i=p; k=0;
	while(i<=r && j<=r1){
		if(dizi[i]<dizi[j]){ 
			gecicidizi[k]=dizi[i]; 
			i++; k++;
		}
		else{
			gecicidizi[k]=dizi[j];
			j++; k++;
		}
	}
	if(i<=r){
		while(i<=r){
			gecicidizi[k]=dizi[i];
			i++; k++;
		}
	}
	if(j<=r1){
		while(j<=r1){
			gecicidizi[k]=dizi[j];
			j++; k++;
		}
	}

	for(i=p,j=0;i<=r1;i++,j++){
		dizi[i]=gecicidizi[j];
	}
}


int main(){
	int dizi[10000],i;
	srand(time(NULL));

	for(i=0;i<10000;i++){ 
		dizi[i]=rand()%10000+1;
	}
	printf("      ********************************** SIRALAMADAN ONCE ********************************\n\n");
	for(i=0;i<10000;i++){ 
		printf("%d\t",dizi[i]);
	}
	mergesort(dizi,0,9999); 
	printf("\n\n     ******************************** SIRALAMADAN SONRA ********************************\n\n");
	for(i=0;i<10000;i++){ 
		printf("%d\t",dizi[i]);
	}
	
}
 
