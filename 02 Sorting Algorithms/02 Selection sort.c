#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void read_array(int *arr);
void print_array(int *arr);
void swap(int *left, int *right);
void selection_sort(int *arr, int len);

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

void selection_sort(int *arr, int len)
/**\Brief: Pick the smallest element and place it at the beginning. Repeat.
 *
 * \Parameters:
 *     \arr: Array to be sorted.
 *     \len: Length of the array.
 *
 * \Returns: Void.
 */
{
    int i, j, at_min;
    for(i = 0; i < len-1; i++) //Start through the first index and iterate till the second last index.
    {
        at_min = i; //Suppose, the smallest element is present at the ith index.
        for(j = i+1; j < len; j++) //Start from the (i+1)th index and iterate till the last index.
            if(arr[j] < arr[at_min]) //If the element at the the jth index is smaller than the element at at_min index...
                at_min = j; //update the at_min index.
        swap(&arr[at_min], &arr[i]); //Swap the elements.
        printf("\nArray in pass %d:", i+1);
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
