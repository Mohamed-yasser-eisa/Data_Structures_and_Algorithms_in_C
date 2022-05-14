#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

/************************************************
* The best case is when the array is already sorted, the outer loop will be run one time, inner loop run (n-1)
* So time complexity in best case scenario is: O( (1)*(n-1) ) = O(n)
* and time complexity in the worst case (array not sorted) is: O( (n-1)*(n-1) ) = O(n^2)
*************************************************/



void bubble_sort_array_ascending(int arr[], int size) //(int *arr, int size)
{
    int i=0,j=0,temp=0,flag=0;

    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            flag = 0;
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1; // put '1' in flag if any swap is done.
            }
        }
        if(0 == flag)
        {
            break; //if no swap is done, then break
        }
    }
}

void print_array(int *arr, int size)
{
    int i=0;
    printf("\n*********************************************\n");
    for(i=0; i<size; ++i)
    {
        printf("%i ", arr[i]);
    }
    printf("\n*********************************************\n");
}

int main()
{
    int array[SIZE] = {20,5,10,18,17,7,2,1,19,13,4,3,8,6,11,9,12,16,15,14};

    bubble_sort_array_ascending(array, (sizeof(array)/sizeof(int)) );

    print_array(array, (sizeof(array)/sizeof(int)) );
    
    return 0;
}


