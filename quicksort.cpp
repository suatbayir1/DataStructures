#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Quicksort(int A[],int p,int r);
int partition(int A[],int p,int r);

void Quicksort(int A[],int p,int r){
	int q;
	if(p<r){
		q=partition(A,p,r);					//parametrelerde bir eksiklik gösteriyor.
		Quicksort(A,p,q-1);
		Quicksort(A,q+1,r);
	}
}

int partition(int A[],int p,int r){
	int x,j,i,gecici;
	x=A[r];
	i=p-1;
	for(j=p;j<=r-1;j++){
		if(A[j]<=x){
			i=i+1;
			gecici=A[i];
			A[i]=A[j];
			A[j]=gecici;
		}
	}
	gecici=A[i+1];
	A[i+1]=A[r];
	A[r]=gecici;
	return i+1;
}

int main(){
	
	int A[100],i;
	srand(time(NULL));
	printf("SIRALAMADAN ONCE\n");
	for(i=0;i<100;i++){
		A[i]=rand()%100+1;
		printf("%d\t",A[i]);
	}
	printf("\n\n");
	Quicksort(A,0,99);
	printf("SIRALAMADAN SONRA\n");
		for(i=0;i<100;i++){
		printf("%d\t",A[i]);
	}
	
}
