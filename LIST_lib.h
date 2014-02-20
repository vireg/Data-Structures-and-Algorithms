#ifndef LIST_lib_H
#define LIST_lib_H

typedef struct node_type{
        int item,index;
        node_type* next;
        } node;
typedef node* head;        

head queue(head, int); //insert item at the end of the list, return new head pointer
void dequeue(head);       //remove first item from the list
void insertbeg(head, int);//insert new item at the beginning of the list
head popitem(head listhead);//remove last item from the list, return new head pointer
head delist(head, int);   //delete the given item from the list (if present), return head pointer (new if last item deleted)
void printnode(head);     //print all the items in the list
void putindex(head);
head searchlist(head,int);

#endif
