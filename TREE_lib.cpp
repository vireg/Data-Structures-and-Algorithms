#include<stdio.h>
#include<stdlib.h>
#include"TREE_lib.h"

int total_nodes = 0;

void printinorder(thead treehead)
{
     if(treehead != NULL){
                       printinorder(treehead->left);
                       printf("%d ", treehead->data);
                       total_nodes++;
                       printinorder(treehead->right);
                       }
}

thead findnext(thead x)
{
      int x0 = x->data;
      if(x->right != NULL){
                  x = x->right;
                  while(x->left != NULL) x = x->left;
                  return x;
                  }
      else{
           while(x->parent != NULL){
                           x = x->parent;
                           if(x->data > x0) return x;
                           }
           }
}

thead findprev(thead x)
{
      int x0 = x->data;
      if(x->left != NULL){
                  x = x->left;
                  while(x->right != NULL) x = x->right;
                  return x;
                  }
      else{
           while(x->parent != NULL){
                           x = x->parent;
                           if(x->data < x0) return x;
                           }
           }
}

thead findmin(thead treehead)
{
      int n=0;
      thead treeptr = treehead;//temporary pointer
      if(treeptr == NULL) return NULL;
      while(treeptr->left != NULL){
                    treeptr = treeptr->left;
                    n++;
                    }
      printf("height from min = %d\n",n);
      return treeptr;
}

thead findmax(thead treehead)
{
      int n=0;
      thead treeptr = treehead;//temporary pointer
      if(treeptr == NULL) return NULL;
      while(treeptr->right != NULL){
                    treeptr = treeptr->right;
                    n++;
                    }
      printf("height from max = %d\n",n);
      return treeptr;
}
                    
thead searchtree(thead treehead, int searchdata)//iterative search
{
      thead treeptr = treehead;//temporary pointer
      while(treeptr != NULL)
      {
                    if(treeptr->data == searchdata){
                    printf("Found %d at memory location %u\n",treeptr->data,treeptr);
                    return treeptr;
                    }
                    else if(searchdata < treeptr->data)
                    treeptr = treeptr->left;
                    else treeptr = treeptr->right;
      }
      printf("%d not found in BST\n",searchdata);
      return NULL;
}

thead recsearchtree(thead treehead, int searchdata)//recursive search
{
      thead treeptr = treehead;//temporary pointer
      if(treeptr == NULL){
                 printf("%d not found in BST\n",searchdata);
                 return NULL;
                 }
      if(treeptr->data == searchdata){
                       printf("Found %d at memory location %u\n",treeptr->data,treeptr);
                       return treeptr;
                       }
      if(searchdata < treeptr->data) recsearchtree(treeptr->left, searchdata);          //recurse left
      else recsearchtree(treeptr->right, searchdata);                                   //recurse right
}

thead insertnode(thead treehead, int newdata)
{
     thead newtnode;
     thead newthead = treehead;//temporary pointer
     thead last = newthead;
     newtnode = (thead)malloc(sizeof(tnode));
     newtnode->data = newdata;               //assign passed data to the new node
     newtnode->left = newtnode->right = NULL;                  //init left and right children of new node to NULL
     while(newthead != NULL){                //starting from treehead, go left or right, keeping track of parent in last
                    if (newdata <= newthead->data){
                                       last = newthead;
                                       newthead = newthead->left;
                                       }
                    else if(newdata> newthead->data){
                                       last = newthead;
                                       newthead = newthead->right;
                                       }
                    }
     if(last != NULL){                 //last is equal to NULL iff NULL parameter is passed to function
     if (last->data >= newdata){
                    last->left = newtnode;
                    newtnode->parent = last;
                    }
     else if(last->data < newdata){
                    last->right = newtnode;
                    newtnode->parent = last;
                    }
     }
     else newtnode->parent = last;     //only executed if NULL parameter passed, which means this is the first(top) node
     return newtnode;
}

                                       
