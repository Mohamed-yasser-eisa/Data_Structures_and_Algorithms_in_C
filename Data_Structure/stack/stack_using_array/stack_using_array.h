
/**********************************************************************************
 * @file   : stack_using_array.c
 * @version: 1.0
 * @author : Mohamed Yasser
 * @brief  : Implementation of stack data structure using array
 **********************************************************************************/

/*----------------------------Includes Section Start----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "stdTypedef.h"
/*______________________________________________________________________________*/

/*----------------------------Macro Section Start----------------------------*/
#define STACK_SIZE 5
/*______________________________________________________________________________*/


/*----------------------------Global variables Section Start----------------------------*/
static sint16 top = -1; // Variable to store the index of stack pointer of the array, (-1) means no elements yet.
static uint8 stack[STACK_SIZE] = {0}; //the stack array data structure
/*______________________________________________________________________________*/

/*----------------------------Definitions Section Start----------------------------*/

/*
* function name: stack_full
* arguments: (void)
* return type: (0 (not full) or 1 (is full))
* brief: it returns the status of stack is full or not.
*/
uint8 stack_full(void);

/*
* function name: stack_empty
* arguments: (void)
* return type: (0 (not empty) or 1 (is empty))
* brief: it returns the status of stack is empty or not.
*/
uint8 stack_empty(void);

/*
* function name: stack_push
* arguments: (uint8 data)
* return type: (0 (data pushed) or 1 (data not pushed))
* brief: it pushes data in stack if it is not full and returns 0.
*/
uint8 stack_push(uint8 data);

/*
* function name: stack_pop
* arguments: (void)
* return type: (data popped or -1 (no data) )
* brief: it pops data from stack, but if stack is empty, it returns -1.
*/
sint16 stack_pop(void);

/*
* function name: stack_print
* arguments: (void)
* return type: (void)
* brief: it prints data from stack.
*/
void stack_print(void);

/*
* function name: stack_top_val
* arguments: (void)
* return type: (sint8)
* brief: it returns data from top of the stack, or -1 if stack is empty.
*/
sint8 stack_top_val(void);

/*
* function name: stack_num_elements
* arguments: (void)
* return type: (sint8)
* brief: it returns number of elements in the stack, or -1 if stack is empty.
*/
sint16 stack_num_elements(void);

/*______________________________________________________________________________*/

/*******************************************************************
 * Revision Log
 * Date          By               Brief
 * -----------   --------------   ----------------------------------
 * 2,July,2022   Mohamed Yasser   created the function
 * -----------   --------------   ----------------------------------
 *******************************************************************/