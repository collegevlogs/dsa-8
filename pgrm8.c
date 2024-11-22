#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node{
    int info;
    struct node *left;
    struct node *right;
};typedef struct node * NODE;
NODE create(NODE root){
    NODE pres,prev;
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    printf("\n Enter the element to insert\n");
    scanf("%d",&newnode->info);
    newnode->left=newnode->right=NULL;
    if(root==NULL){
    root=newnode;
        return root;
    }
    pres=root,prev;
    while(pres!=NULL){
        if(newnode->info>pres->info){
            prev=pres;
            pres=pres->right;
        }else if(newnode->info<pres->info){
            prev=pres;
            pres=pres->left;
        }else{
        printf("\n Duplicate identifiers are not allowed");
        return root;
        }
    }
    if(newnode->info>prev->info)
    prev->right=newnode;
    else
    prev->left=newnode;
    return root;
}
void preorder(NODE root){
    if(root!=NULL){
        printf("%d\t",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(NODE root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}
void postorder(NODE root){
    if(root!=NULL){
        
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->info);
    }
}
void search(NODE root,int key){
    NODE pres;int flag=0;
    if(root==NULL){
        printf("The tree is Empty ,search cannot be done\n");
    }else{
        pres=root;
        while(pres!=NULL){
            if(key==pres->info){
                flag=1;
                printf("\nkey found");
                return;
            }
            if(key>pres->info)
                pres=pres->right;
            else
            pres=pres->left;
        }
    }
    if(flag==0)
    printf("\nkey not found");
}

void main(){
    int ch,key;
    NODE root = NULL;
    while(1){
        printf("\n1:create 2:preoder  3:inorder  4:postorder 5:search 0:Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:root=create(root);
                   break;
            case 2:if(root==NULL)
                   printf("\n The tree is Empty\n");
                   else{
                       printf("\n The preorder Tranversal is \n");
                       preorder(root);
                   }
                   break;
            case 3:if(root==NULL)
                   printf("\n The tree is Empty\n");
                   else{
                       printf("\n The Inorder Tranversal is \n");
                       inorder(root);
                   }
                   break;
            case 4:if(root==NULL)
                   printf("\n The tree is Empty\n");
                   else{
                       printf("\n The Post order Tranversal is \n");
                       postorder(root);
                   }
                   break;
            case 5:printf("\n Enter the element to search");
                   scanf("%d",&key);
                   search(root,key);
                   break;
            default:exit(0);
        }
    }
}