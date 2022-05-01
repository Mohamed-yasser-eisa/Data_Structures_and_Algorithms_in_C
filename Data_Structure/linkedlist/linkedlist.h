#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "stdTypedef.h"



typedef struct point
{
    int x;
    int y;
    struct point* next;
}node;

/*
function takes address in head (address of first node element) and start printing list.
it returns '1' if list is empty, and returns '0' is list is printed.
*/
uint8 linkedlist_print_list(node* head);
/*
function insert a node at the beginning of linkedlist.
*/
void linkedlist_push_head(node** head, int x, int y);
/*
function insert a node at the end of linkedlist.
*/
void linkedlist_push_end(node* head,node** head_ptr, int x, int y);
/*
function pop first node of linkedlist, and pass its value to node of same struct.
*/
void linkedlist_pop_head(node** head, node* node_ptr);
/*
function removes last node of linkedlist, and pass its value to node of same struct.
*/
void linkedlist_remove_last(node** head, node* node_ptr);

#endif //_LINKEDLIST_H_