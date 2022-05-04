#include "linkedlist.h"

/*
function takes address in head (address of first node element) and start printing list.
*/
uint8 linkedlist_print_list(node* head)
{
    uint8 flag = 1; //this flag returns '1' if list is empty, and returns '0' is list is printed.

    while ('\0' != head)//while head does not point to null, print node:
    {
        printf("Point is: (%i, %i)\n", head -> x, head -> y);
        head = head -> next;
        flag = 0;
    }
    return flag;
}

/*
function insert a node at the beginning of linkedlist.
*/
void linkedlist_push_head(node** head, node* dataNode)
{
    node* temp_ptr; //this temp_ptr will save address of new created node.
    temp_ptr = (node*) malloc(sizeof(node)); //create new node
    (temp_ptr -> x) = dataNode -> x;
    (temp_ptr -> y) = dataNode -> y;
    (temp_ptr -> next) = *head;
    *head = temp_ptr;
}

/*
function insert a node at the end of linkedlist.
--> Is list empty? then (call the "push_head" function)
--> list not empty? then (loop on address to the end of the list, then insert node at the end).
*/
void linkedlist_push_end(node* head,node** head_ptr, node* dataNode);
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
        head -> next = (node*) malloc(sizeof(node));
        head -> next -> x = dataNode -> x;
        head -> next -> y = dataNode -> y;
        head -> next -> next = '\0';
    }
}


/*
function pop first node of linkedlist, and returns its value to node of same struct.
it takes address of struct of node type to return data of deleted node in it.
*/
void linkedlist_pop_head(node** head, node* return_node)
{
    if('\0' != *head) //Is list not empty?
    {
        node* temp_ptr = *head; //save address of first node to return its data before deletion.
        *head = ((*head) -> next); //make address of second node replace address of first node.
        (return_node -> x) = (temp_ptr -> x); //return data of poped node
        (return_node -> y) = (temp_ptr -> y); //return data of poped node
        free(temp_ptr); //delete poped node.
    }
}


/*
function removes last node of linkedlist, and pass its value to node of same struct
function takes (node** head) as the linked list may contain one node, so we need to make head points to NULL.
function takes (node* head_ptr)(pointer to first node) as the linked list may has more than one node, so we need to loop on nodes tell node before last..
*/
void linkedlist_remove_last(node** head, node* head_ptr, node* return_node)
{
    if(head_ptr != '\0') // list not empty?
    {
        if('\0' == (head -> next)) //Is list contains one node?
        {
            linkedlist_pop_head(head, return_node);
        }
        else
        {
            while('\0' != (head -> next -> next) )
            {
                head = head -> next;
            }
            return_node -> x = head -> next -> x;
            return_node -> y = head -> next -> y;
            free( head -> next );
            head -> next = '\0';
        }
    }
}


void linkedlist_insert_index(node** head_ptr, node* head, node* dataNode, unsigned int index)
{
    if(index >= 0) //Did user enter a valid index?
    {
        if('\0' == head) //list is empty? create node and push data in it.
        {
            linkedlist_push_head(head_ptr, dataNode);
        }
        else //list on empty, then loop to the index and insert the node
        {
            unsigned int i;
            for(i=0; i<index-1; ++i)
            {
                head = head -> next;
            }
            node* temp_ptr = (node*) malloc(sizeof(node));
            temp_ptr -> next = head -> next;
            temp_ptr -> x = dataNode -> x;
            temp_ptr -> y = dataNode -> y;
            head -> next = temp_ptr;
        }
    }
}


void linkedlist_delete_index(node** head, node* dataNode, unsigned int index)
{
    if(index >= 0) //Did user enter a valid index?
    {
        if('\0' != *head) //list is not empty?
        {
            if(0 == index)
            {
                linkedlist_pop_head(head, dataNode);
            }
            else
            {
                unsigned int i;
                uint8 flag = 1;
                node* node_ptr = *head;
                for(i=0; i<index-1; ++i)
                {
                    if(node_ptr -> next == '\0')
                    {
                        linkedlist_remove_last(head, *head, dataNode);
                        flag = 0;
                        break;
                    }
                    node_ptr = node_ptr -> next;
                }
                if(flag)
                {
                    dataNode -> x = node_ptr -> x;
                    dataNode -> y = node_ptr -> y;
                    node* temp_ptr;
                    temp_ptr = node_ptr -> next;
                    node_ptr -> next = temp_ptr -> next;
                    free(temp_ptr);
                }
            }
        }
    }
}

