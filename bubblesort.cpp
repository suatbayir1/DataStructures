#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubblesort(int dizi[],int boyut){
int gecici,k,hareket;
	for(hareket=0;hareket<boyut-1;hareket++){
		for(k=0;k<boyut-1-hareket;k++){
			if(dizi[k]>dizi[k+1]){
				gecici=dizi[k];
				dizi[k]=dizi[k+1];
				dizi[k+1]=gecici;
			}
		}
	}
}

int main(){
	int i,dizi[10000];
	srand(time(NULL));
	for(i=0;i<10000;i++){
		dizi[i]=rand()%10000+1;
		printf("%d\t",dizi[i]);
	}
	printf("\n\n\n");
	bubblesort(dizi,10000);
	for(i=0;i<10000;i++){
		printf("%d\t",dizi[i]);
	}
}
