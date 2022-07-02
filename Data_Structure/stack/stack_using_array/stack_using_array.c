
/**********************************************************************************
 * @file   : stack_using_array.c
 * @version: 1.0
 * @author : Mohamed Yasser
 * @brief  : Implementation of stack data structure using array
 **********************************************************************************/

/*----------------------------Includes Section Start----------------------------*/
#include "stack_using_array.h"
/*______________________________________________________________________________*/

/*----------------------------Main Program Start----------------------------*/
int main()
{
    
    //printf("",);
    return 0;
}
/*______________________________________________________________________________*/

/*----------------------------Sub-program Section Start----------------------------*/
uint8 stack_full(void)
{
    uint8 flag = 0;
    if(top == (STACK_SIZE - 1) )
    {
        flag = 1; //yes, stack is full
    }
    else
    {
        flag = 0; //no, stack is not full
    }
    return flag;
}

uint8 stack_empty(void)
{
    uint8 flag = 0;
    if(-1 == top)
    {
        flag = 1; //yes, stack is empty
    }
    else
    {
        flag = 0; //no, stack is not empty
    }
    return flag;
}

uint8 stack_push(uint8 data)
{
    uint8 flag = 0;
    if(0 == stack_full() )
    {
        flag = 0; //no, stack is not full
        ++top;
        stack[top] = data;
    }
    else
    {
        flag = 1; //yes, stack is full
    }
    return flag;
}

sint16 stack_pop(void)
{
    sint16 data = 0;
    if(1 == stack_empty() )
    {
        data = -1; //stack is empty
    }
    else
    {
        data = stack[top]; //stack is not empty
        --top;
    }
    return data;
}

void stack_print(void)
{
    sint8 i = 0;
    if(1 == stack_empty() )
    {
        printf("\nStack is empty!!\n\n\a"); 
    }
    else
    {
        for(i=top; i>=0; --i)
        {
            printf("\nStack[%i] = %i\n", i, stack[i]);
        }
    }
}

sint8 stack_top_val(void)
{
    sint8 data = 0;
    if(1 == stack_empty())
    {
        data = -1;
    }
    else
    {
        data = stack[top];
    }
    return data;
}

sint16 stack_num_elements(void)
{
    return top+1;
}
/*______________________________________________________________________________*/

/*******************************************************************
 * Revision Log
 * Date          By               Brief
 * -----------   --------------   ----------------------------------
 * 2,July,2022   Mohamed Yasser   created the function
 * -----------   --------------   ----------------------------------
 *******************************************************************/