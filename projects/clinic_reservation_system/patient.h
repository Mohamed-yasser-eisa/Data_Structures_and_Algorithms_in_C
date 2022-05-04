#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stdTypedef.h"
#include "clinic.h"


typedef struct patient_node
{
    char name[22];
    uint8 index;
    uint32 age;
    uint64 phone;
    float32 paidFees;
    struct patient_node* next;
}pNode; //patient node


/*
function reserve a new patient.
*/
void patient_reserve(pNode** head_ptr);

/*
function view patient's details.
*/
void patient_view(pNode* head);

/*
function edit patient's details.
*/
void patient_edit(pNode* head);

/*
function delete patient's details.
*/
void patient_delete(pNode* head, pNode** head_ptr);


/*
function returns number of patients in the clinic:
*/
uint8 patient_get_number(void);
#endif // PATIENT_H_INCLUDED

