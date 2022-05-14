#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stdTypedef.h"
#include "patient.h"
#include "clinic.h"

int main()
{
    static uint8 first_open = 1;
    uint8 option = 0;
    uint8 stop = 1;
    get_clinic_name();
    //linked list:
    pNode* head = '\0'; //create head of linked list:

    while (stop)
    {
        system("cls");
        printf("\n*-*-*-*-* Welcome to %s clinic *-*-*-*-*\n", clinic_Name);
        puts("__________________________________________\n");
        puts("How can I serve you?");
        puts("------------------------------------------\n");
        puts("(1) Reserve an appointment.\n");
        puts("(2) View patient's information.\n");
        puts("(3) Edit patient's information.\n");
        puts("(4) View clinic's informations.\n");
        puts("(5) Delete a patient.\n");
        puts("(6) Setup clinic's informations.\n");
        puts("(7) Exit.\n");
        puts("------------------------------------------\n");
        if(1 == first_open) //if it is the first open then setup clinic's information:
        {
            option = 6;//setup clinic's information
            ++first_open; //change "first" variable.
        }
        else //not the first time to open:
        {
            printf("option: ");
            fflush(stdin);
            scanf("%i", &option);
        }
        switch(option)
        {
        case 1://Reserve an appointment
            patient_reserve(&head);
            printf("press any key to return main menu...");
            fflush(stdin);
            getchar();
            stop = 1;
            break;
        case 2://view patient
            patient_view(head);
            stop = 1;
            break;
        case 3://Edit patient's information
            patient_edit(head);
            stop = 1;
            break;
        case 4://view clinic informations
            clinic_view_info();
            stop = 1;
            break;
        case 5://Delete patient:
            patient_delete(head, &head);
            stop = 1;
            break;
        case 6://setup clinic informations
            clinic_setup();
            stop = 1;
            break;
        default:
            stop = 0;
            break;

        }//end of switch case.
    }//end of while(1);


    return 0;
}
