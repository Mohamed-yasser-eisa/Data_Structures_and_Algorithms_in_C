
/**********************************************************************************
 * @file   : stack_using_array.c
 * @version: 1.0
 * @author : Mohamed Yasser
 * @brief  : Implementation of stack data structure using array
 **********************************************************************************/

/*----------------------------Includes Section Start----------------------------*/
#include "stack_using_linkedlist.h"
/*______________________________________________________________________________*/

/*----------------------------Main Program Start----------------------------*/
int main()
{

    // printf("",);
    return 0;
}
/*______________________________________________________________________________*/

/*----------------------------Sub-program Section Start----------------------------*/

uint8 stack_empty(void)
{
    uint8 flag = 0;
    if ('\0' == top)
    {
        flag = 1; // yes, stack is empty
    }
    else
    {
        flag = 0; // no, stack is not empty
    }
    return flag;
}

uint8 stack_push(uint8 data)
{
    node *temp_ptr = (node *)malloc(sizeof(node));
    temp_ptr->num = data;
    temp_ptr->next = top;
    top = temp_ptr;
    ++counter;
}

sint16 stack_pop(void)
{
    sint16 data = 0;
    if (1 == stack_empty())
    {
        data = -1; // stack is empty
    }
    else
    {
        data = top->num; // stack is not empty
        node *temp = top->next;
        free(top);
        top = temp;
    }
    --counter;
    return data;
}

void stack_print(void)
{
    uint8 i = 0;
    if (1 == stack_empty())
    {
        printf("\nStack is empty!!\n\n\a");
    }
    else
    {
        node *temp_ptr = top;
        uint16 i = 1;
        while ('\0' != temp_ptr)
        {
            printf("\nStack[%i] = %i\n", i, temp_ptr->num);
            ++i;
            temp_ptr = temp_ptr->next;
        }
    }
}

sint8 stack_top_val(void)
{
    sint8 data = 0;
    if (1 == stack_empty())
    {
        data = -1;
    }
    else
    {
        data = top->num;
    }
    return data;
}

sint16 stack_num_elements(void)
{
    return counter;
}
/*______________________________________________________________________________*/

/*******************************************************************
 * Revision Log
 * Date          By               Brief
 * -----------   --------------   ----------------------------------
 * 2,July,2022   Mohamed Yasser   created the function
 * -----------   --------------   ----------------------------------
 *******************************************************************/