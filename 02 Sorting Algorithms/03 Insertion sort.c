#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void read_array(int *arr);
void print_array(int *arr);
void insertion_sort(int *arr, int len);

int main()
/**< Driver function: */
{
    int arr[MAX];

    read_array(arr);

    printf("\nOriginal contents of the array:\n");
      print_array(arr);

    insertion_sort(arr, MAX);

    printf("\nThe array in sorted order:\n");
      print_array(arr);

    return 0;
}

void insertion_sort(int *arr, int len)
/**\Brief: Consider the array is sorted till the ith position. Run through the array.
 *         Find an element smaller than the element at the ith position and insert it
 *         at the correct position .
 *
 * \Parameters:
 *     \arr: Array to be sorted.
 *     \len: Length of the array.
 *
 * \Returns: Void.
 */
{
    int i, j, key;
/**< Initially, let the array be sorted till index 0 and unsorted from index 1 till index (len-1). */
    for(i = 1; i < len; i++) //Start from the first unsorted element and move till the end of the array.
    {
        key = arr[i]; //Pick up the key element. Let it be at index i.
        for(j = i-1; j >= 0 && key < arr[j]; j--)
        {/** Start from the last sorted element to the first sorted element (i.e. till index 0)
         * and check if the key is less than any element in the sorted part of the array...
         */
            arr[j+1] = arr[j]; //push the sorted element that is bigger than the key to the next index and...
            arr[j] = key; //insert the key in front of it.
        }
        printf("Array in pass %d:", i);
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
