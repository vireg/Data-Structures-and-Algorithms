#include<stdio.h>
#include<stdlib.h>
#include"listlib.h"

head queue(head listhead, int newitem)     //**l
{
     head newlisthead;
     newlisthead = (head)malloc(sizeof(node));     //Create new head pointer
     newlisthead->item = newitem;
     newlisthead->next = listhead;                 //Assign previous head as next node of new head
     putindex(newlisthead);                        //Re-calculate indices
     return newlisthead;                           //Return new head pointer
}

void dequeue(head listhead)
{
     head last;
     if(listhead == NULL) return;
     while(listhead->next!=NULL){
                                 last = listhead;
                                 listhead = listhead->next;
                                 }
     last->next = NULL;
     free(listhead);
}

void insertbeg(head listhead, int newitem)
{
     head p=listhead;
     head newlistail,last=NULL;
     while(p != NULL){
             last=p;
             p=p->next;
             }
     newlistail = (head)malloc(sizeof(node));
     newlistail->item = newitem;
     printf("%d\n", newlistail->item);
     if(last!=NULL) last->next = newlistail;
     newlistail->next = NULL;
     //p = newlistail;
     putindex(listhead);                        //Re-calculate indices
}

head popitem(head listhead)
{
     head oldlisthead = listhead;
     if(listhead!= NULL) {
                   listhead = listhead->next;
                   free(oldlisthead);
     }
     return listhead;
}

head delist(head listhead, int delitem)         //**l
{
     head p;
     head last;
     p = (head)malloc(sizeof(node));
     last = (head)malloc(sizeof(node));
     p = listhead;
     last = p;
     if(p->item == delitem)            //if item to be deleted is found in head
     {
                p = p->next;
                free(last);
                return p;              //return new head pointer
     }
     p = p->next;
     while(p != NULL)
     {
             if(p -> item == delitem)
             {
                  last->next = p->next;
                  free(p);
                  break;
              }
              last = p;
              p = p->next;
     }
     return listhead;                  //return original head pointer
                
 }

void printnode(head listhead)
{
     while(listhead != NULL){
     printf("%d ",listhead->item);
     listhead = listhead->next;
     }
}

void putindex(head listnum)
{
     int static i = 0;
     listnum->index = i;
     i++;
     if(listnum->next == NULL){
      i=0;
      return;
     }
     else
     putindex(listnum->next);

}

head searchlist(head listhead,int searchitem)
{
     if(listhead == NULL)                   //No further nodes exist
     {
                 printf("Item not found\n");
                 return 0;
     }
     else if(listhead->item == searchitem)  //Item found at current node
     {
     printf("Item found at index location %d\n", listhead->index);
     return listhead;
     }
     else                                   //Item not found in current node, recursively search next nodes
     searchlist(listhead->next, searchitem);   
}
