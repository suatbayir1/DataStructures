#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node {
        int data;
        node *next;
        };
int main(){
 node * root= (node *) malloc(sizeof(node));
 node * temp = root;
 for(int i=0;i<10;i++){
         temp->data=i*10;
         temp->next=(node *) malloc(sizeof(node));
         temp=temp->next;
         } 
 temp->next=NULL;    
 printf("inserted");
 temp =root;
 while(temp->next!=(node*)0){
         printf("\n%d",temp->data);
         temp=temp->next;
         
         }
         getch();
    return 0;
}        
