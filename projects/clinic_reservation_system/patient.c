#include "patient.h"

static uint8 element; //this variables contains number of elements in linked list.
//static uint8 onePatient;


static void linkedlist_read_node(pNode* node_ptr)
{
    printf("Name.....: ");
    fflush(stdin);
    fgets(node_ptr->name, sizeof(node_ptr->name), stdin);
    (node_ptr->name)[strlen(&(node_ptr->name))-1] = '\0';//remove last read '\n'

    printf("Age......: ");
    fflush(stdin);
    scanf("%u", &(node_ptr->age) );

    printf("Phone....: ");
    fflush(stdin);
    scanf("%llu", &(node_ptr->phone) );

    printf("Paid fees: ");
    fflush(stdin);
    scanf("%f", &(node_ptr->paidFees) );
}//end of linkedlist_read_node();

static void linkedlist_print_node(pNode* node_ptr)
{
    puts("------------------------------------------\n");
    printf("Patient number is: %i\n", (node_ptr->index)+1);
    printf("Name.............: %s\n", node_ptr->name);
    printf("Age..............: %i\n", node_ptr->age);
    printf("Phone............: 0%llu\n", node_ptr->phone);
    printf("PaidFees.........: %0.3f\n", node_ptr->paidFees);
    puts("-------------------------------------------");
}//end of linkedlist_print_node();


static void pop_head(pNode** node_ptr)
{
    pNode* temp = (*node_ptr)->next;
    free(*node_ptr);
    *node_ptr = temp;
    element--;
}


static void delete_node(pNode* node_ptr)
{
    pNode* temp;
    temp = node_ptr->next->next; //store address that in next of delete node.
    element--;
    if('\0' != temp)
    {
        //temp->index = node_ptr->next->index;
        temp->index = element-1;
    }
    free(node_ptr->next);//delete the selected node
    node_ptr->next = temp;
}

void patient_reserve(pNode** head_ptr)
{
    pNode* temp_node;

    system("cls");
    puts("\nPatient reserve screen:");
    puts("_________________________\n");
    puts("Enter patient's details: (Name - Age - Phone - Paid fees)");
    puts("----------------------------------------------------------\n");

    if(*head_ptr == '\0')//Is this the first node?
    {
        temp_node = (pNode*) malloc(sizeof(pNode));
        temp_node -> index = 0;
        linkedlist_read_node(temp_node);
        temp_node->next='\0';
        *head_ptr = temp_node;
        puts("------------------------------------------\n");
        puts("\nPatient's details are:");
        linkedlist_print_node(temp_node);
        element++;//add new element.
    } //end of if;
    else//add node at the end of the linked list:
    {
        element++;//add new element.
        temp_node = *head_ptr;
        while('\0' != temp_node->next)
        {
            temp_node = temp_node->next;
        }
        pNode* new_node = (pNode*) malloc(sizeof(pNode));
        linkedlist_read_node(new_node);
        new_node->index = element-1;//index of this node = number of this element in the list.
        new_node->next = '\0';
        temp_node->next = new_node;
        puts("------------------------------------------\n");
        puts("\nPatient's details are:");
        linkedlist_print_node(new_node);
    }//end of else;
}//end of patient_reserve(pNode** head_ptr);

void patient_view(pNode* head)
{
    uint64 pho_num = 0;
    uint8 flag = 1;

    system("cls");
    puts("\nPatient view details screen:");
    puts("______________________________\n");
    printf("Enter patient's phone number: ");
    fflush(stdin);
    scanf("%llu", &pho_num);
    puts("------------------------------------------------------\n");
    while('\0' != head) //Is head not points to NULL?
    {
        if(pho_num == head->phone)
        {
            puts("\nPatient's details are:");
            linkedlist_print_node(head);
            flag = 0;
            break;
        }//end of if();
        else
        {
            flag = 1;
        }//end of else
        head = head->next;
    }//end of while loop;
    if(flag)
    {
        puts("Patient is not found.\n");
        puts("Make sure you enter phone number correctly.\n");
    }
    printf("press any key to return main menu...");
    fflush(stdin);
    getchar();
}//end of patient_view();

void patient_edit(pNode* head)
{
    uint8 flag = 1;
    uint64 pho_num = 0;

    system("cls");
    puts("\nPatient edit details screen:");
    puts("______________________________\n");
    printf("Enter patient's phone number: ");
    fflush(stdin);
    scanf("%llu", &pho_num);
    puts("------------------------------------------------------\n");

    while('\0' != head) //Is head not points to NULL?
    {
        if(pho_num == head->phone)
        {
            puts("\nPatient's details are:");
            linkedlist_print_node(head);
            puts("Enter edited details: ");
            linkedlist_read_node(head);
            puts("------------------------------------------\n");
            puts("\nPatient's new data are:");
            linkedlist_print_node(head);
            flag = 0;
            break;
        }//end of if();
        else
        {
            flag = 1;
            break;
        }//end of else
        head = head->next;
    }//end of while loop;
    if(flag)
    {
        puts("Patient is not found.\n");
        puts("Make sure you enter phone number correctly.\n");
    }
    printf("press any key to return main menu...");
    fflush(stdin);
    getchar();
}


void patient_delete(pNode* head, pNode**head_ptr)
{
    uint8 pat_num = 0;//patient number: (0,1,2,3,4,...);
    uint16 pass = 0;
    uint8 i = 0;
    char decision = '\0';
    pNode* temp_ptr;

    system("cls");
    puts("\nPatient delete details screen:");
    puts("________________________________\n");
    printf("Enter patient's row number \"NOT phone number\": ");//enter number of patient in the queue
    fflush(stdin);
    scanf("%u", &pat_num);
    if(pat_num > 0)
    {
        printf("Enter password: ");
        fflush(stdin);
        scanf("%hu", &pass);
        puts("------------------------------------------------------\n");
        if(pass == pass_word)
        {
            if(1 == pat_num)//delete first element
            {
                puts("\nPatient's details are:");
                linkedlist_print_node(head); //print details of node before deletion
                puts("Are you sure you want to delete? (Y/N)\a");
                fflush(stdin);
                scanf("%c", &decision);
                if( ((char)decision == (char)'Y') || ((char)decision == (char)'y') )
                {
                    pop_head(head_ptr); //delete node that at the temp_ptr->next;
                    printf("Patient number %u is removed successfully\n", pat_num);
                }
                //temp_ptr = head; //store address of node before the selected one in temp_ptr;
            }
            else
            {
                for(i=0; i<pat_num-1; ++i) //stop at the index - 1;
                {
                    temp_ptr = head; //store address of node before the selected one in temp_ptr;
                    head = temp_ptr -> next; //get address of selected node and put it in head;
                }
                puts("\nPatient's details are:");
                linkedlist_print_node(head); //print details of node before deletion
                puts("Are you sure you want to delete? (Y/N)\a");
                fflush(stdin);
                scanf("%c", &decision);
                if( ((char)decision == (char)'Y') || ((char)decision == (char)'y') )
                {
                    delete_node(temp_ptr); //delete node that at the temp_ptr->next;
                    printf("Patient number %u is removed successfully\n", pat_num);
                }
            }
        }//end of if();
        else
        {
            puts("Wrong password!.\n");
            puts("Make sure you are an admin.\n");
        }//end of else
    }
    printf("press any key to return main menu...");
    fflush(stdin);
    getchar();

}

uint8 patient_get_number(void)
{
    return element;
}
