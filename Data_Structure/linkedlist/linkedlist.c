#include "linkedlist.h"

/*
function takes address in head (address of first node element) and start printing list.
*/
uint8 linkedlist_print_list(node* head)
{
    uint8 flag = 1; //this flag returns '1' if list is empty, and returns '0' is list is printed.

    while ('\0' != head)//while head does not point to null, print node:
    {
        printf("Point is: (%i, %i)\n", head->x, head->y);
        head = head->next;
        flag = 0;
    }
    return flag;
}

/*
function insert a node at the beginning of linkedlist.
*/
void linkedlist_push_head(node** head, int x, int y)
{
    node* temp_ptr; //this temp_ptr will save address of new created node.
    temp_ptr = (node*) malloc(sizeof(node)); //create new node
    (temp_ptr->x) = x;
    (temp_ptr->y) = y;
    (temp_ptr->next) = *head;
    *head = temp_ptr;
}

/*
function insert a node at the end of linkedlist.
--> Is list empty? then (call the "push_head" function)
--> list not empty? then (loop on address to the end of the list, then insert node at the end).
*/
void linkedlist_push_end(node* head, node** head_ptr, int x, int y)
{
    if('\0' == head) //Is list empty?
    {
        linkedlist_push_head(head_ptr, x, y);
    }
    else
    {
        while ('\0' != (head->next)) //loop to the end of the list
        {
            head = (head->next);
        }
        node* temp_ptr = (node*) malloc(sizeof(node));
        (temp_ptr->x) = x;
        (temp_ptr->y) = y;
        (temp_ptr->next) = '\0';
        (head->next) = temp_ptr;
    }
}


/*
function pop first node of linkedlist, and returns its value to node of same struct.
it takes address of struct of node type to return data of deleted node in it.
*/
void linkedlist_pop_head(node** head, node* node_ptr)
{
    if('\0' != *head) //Is list not empty?
    {
        node* temp_ptr = *head; //save address of first node to return its data before deletion.
        *head = ((*head)->next); //make address of second node replace address of first node.
        (node_ptr->x) = (temp_ptr->x); //return data of poped node
        (node_ptr->y) = (temp_ptr->y); //return data of poped node
        free(*temp_ptr); //delete poped node.
    }
}

/*
function removes last node of linkedlist, and pass its value to node of same struct.
*/
void linkedlist_remove_last(node** head, node* node_ptr)
{
    if('\0' != *head)
    {
        node* temp_pte;
        while('\0' != (*head)->next)
        {
            
        }
    }
}







