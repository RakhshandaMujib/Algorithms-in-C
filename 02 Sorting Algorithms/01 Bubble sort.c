#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

void read_array(int *arr); //Reads an array of MAX elements.
void print_array(int *arr); //Prints the contents of the array.
void swap(int *left, int *right); //Swaps the values of left and right.
void bubble_sort(int *arr, int len); //Sorts the contents of array in ascending order.

int main()
/**< Driver function: */
{
    int arr[MAX];

    read_array(arr);

    printf("\nOriginal contents of the array:\n");
      print_array(arr);

    selection_sort(arr, MAX);

    printf("\nThe array in sorted order:\n");
      print_array(arr);

    return 0;
}

void bubble_sort(int *arr, int len)
/**\Brief: Compare every adjascent pair of element and place the smaller element before the larger. Repeat for one pass.
 *         Repeat for multiple passes. 
 *
 * \Parameters:
 *     \arr: Pointer to the array to be sorted.
 *     \len: Length of the array.
 *
 * \Returns: Void.
 */
{
    int i, j;
    bool swapped; //Boolean variable to check if swapping of contents of neighbouring indices took place.

    for(i = len-1; i > 0; i--) //With every iteration, the biggest element is pushed to the right most unsorted end. 
    {
        swapped = false; //Assuming no elements have been swapped.
        for(j = 0; j < i; j++) //For every jth and (j+1)th index...
        {
            if(arr[j] > arr[j+1]) //check if the smaller element is present at a higher index...
            {
                swap(&arr[j], &arr[j+1]); //If yes, then swap the contents...
                swapped = true; //and switch the boolean variable to true.
            }
        }
        if(swapped == false) //In case no swap operation took place in a pass, meaning the array is sorted...
            break; //stop further iterations.
        printf("\nArray in pass %d:", -(i-len)); //Print the contents of the array in every pass.
        print_array(arr); 
    }
}


/**< Utility functions: */

void read_array(int *arr)
/** \Brief: Read the array.
 *
 * \Parameter:
 *     \arr: Pointer to the declared array.
 *
 * \Returns: Void.
 */
{
    int i;

    printf("Enter %d elements:\n", MAX);

    for(i = 0; i < MAX; i++)
        scanf("%d", &arr[i]);
}

void print_array(int *arr)
/** \Brief: Prints the array.
 *
 * \Parameter:
 *     \arr: Pointer to the declared array.
 *
 * \Returns: Void.
 */
 {
    int i;

    for(i = 0; i < MAX; i++)
        printf("\t%d ", arr[i]);
    printf("\n");
}

void swap(int *left, int *right)
/** \Brief: Swap elements element at left and right.
 *
 * \Parameter:
 *     \left: Pointer to the the element at left.
 *     \left: Pointer to the the element at right.
 *
 * \Returns: Void.
 */
 {
    int temp = *left;
    *left = *right;
    *right = temp;
}
