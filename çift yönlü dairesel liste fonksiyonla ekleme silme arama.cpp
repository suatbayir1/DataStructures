#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node{
        int data;
        node * next;
        node * prev;
};
node *  insert(node * root,int data){
     if(root==NULL){
                    root=(node*)malloc(sizeof(node));
                    root->data=data;
                    root->next = root;
                    root->prev = root;
                    return root;               
     }     
     node * iter=root;
     if(iter->data > data){
                   node * temp= (node*)malloc(sizeof(node));
                   temp->data = data;
                   temp->next=root;
                   temp->prev=root->prev;
                   root->prev=temp;
                   temp->prev->next = temp;
                   return temp;
     }
                   
     while(iter->next->data <data){
                      if(iter->next == root)
                      {
                            iter->next = (node*)malloc(sizeof(node));
                            iter->next->data = data;
                            iter->next->prev=iter;
                            iter->next->next = root;
                            root->prev = iter->next;
                            return root;             
                      }
                      iter=iter->next;                 
     }
     node * temp = (node*)malloc(sizeof(node));
     temp->data=data;
     temp->next = iter->next;
     temp->prev=iter;
     iter->next = temp;
     temp->next->prev = temp;
     return root;
}
node * del(node* root,int data){
       if(root==NULL)
                     return NULL;
       if(root->data ==data){
                     node *temp =root->next;
                     temp->prev = root->prev;
                     root->prev->next = temp;
                     free(root);
                     return temp;              
       } 
       node * iter = root;
       while(iter->data != data){
               if(iter->next==root)
                                   return root;
               iter=iter->next;
       }  
       iter->next->prev=iter->prev;
       iter->prev->next = iter->next;
       free(iter);
       return root;
}
int main(){
    node * root=NULL;  
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,25);
    root=insert(root,15);
    root=insert(root,5);
    root=insert(root,300);
    root=del(root,5);
    root=del(root,10);
    root=del(root,25);
    root=del(root,30);
    root=del(root,300);
    node *iter=root;
    while(iter->next!=root){
                    printf("\n%d",iter->data);  
                    iter=iter->next;
    }    
    printf("\n%d",iter->data);
    getch();
    return 0;
}
