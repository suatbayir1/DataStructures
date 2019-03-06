#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionsort(int dizi[],int boyut){
	
	int i,index,j,enkucuk;
	
	for(i=0;i<boyut-1;i++){
		enkucuk=dizi[boyut-1];
		index=boyut-1;
		for(j=i;j<boyut-1;j++){
			if(dizi[j]<enkucuk){
				enkucuk=dizi[j];
				index=j;
			}
		}
		
		dizi[index]=dizi[i];
		dizi[i]=enkucuk;
	}
}




int main(){
	
	int i,dizi[10000];
	srand(time(NULL));
	
	for(i=0;i<10000;i++){
		dizi[i]=rand()%10000+1;
	}
	
	for(i=0;i<10000;i++){
		printf("%d\t",dizi[i]);
	}
	selectionsort(dizi,10000);
	
	printf("\n\n\n");
	for(i=0;i<10000;i++){
		printf("%d\t",dizi[i]);
	}
	
}
