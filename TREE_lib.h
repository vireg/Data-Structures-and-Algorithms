#ifndef TREE_lib_H
#define TREE_lib_H

//typedef item_type int;
typedef struct tnode_type{
        int data;
        tnode_type* left;
        tnode_type* right;
        tnode_type* parent;
        } tnode;
typedef tnode* thead;

thead insertnode(thead, int);      //inserts node at appropriate postion in the BST and returns the pointer to the node
thead searchtree(thead, int);      //if data found returns pointer to the node, else returns NULL
thead recsearchtree(thead, int);   //recursive search
thead findmin(thead treehead);
thead findmax(thead treehead);
void printinorder(thead);
thead findnext(thead);
thead findprev(thead);

#endif
