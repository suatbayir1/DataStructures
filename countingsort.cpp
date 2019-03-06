#include <stdio.h>
#include <stdlib.h>



void countingsort(int A[],int B[],int k){
	int C[10],i,j;
	
	for(i=0;i<=k;i++){
		C[i]=0;
	}
	for(j=1;j<=10;j++){
		C[A[j]]=C[A[j]]+1;
	}
	for(i=1;i<=k;i++){
		C[i]=C[i]+C[i-1];
	}
	for(j=10;j<=1;j--){
		B[C[A[j]]]=A[j];
		C[A[j]]=C[A[j]]-1;
	}
}


int main(){
	int A[10]={9,4,5,6,7,3,2,1,10,5};
	int B[10],i;
	for(i=0;i<10;i++){
		printf("%d\t",A[i]);
	}
	printf("\n\n");
	countingsort(A,B,9);
	for(i=0;i<10;i++){
		printf("%d\t",A[i]);
	}
	
}
