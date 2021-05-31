#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void read_array(int *arr);
void print_array(int *arr);
void swap(int *left, int *right);
void quick_sort(int *arr, int start, int end);
int partition(int *arr, int start, int end);

int pass_no;

int main()
/**< Driver function: */
{
    int arr[MAX];

    read_array(arr);

    printf("\nOriginal contents of the array:\n");
      print_array(arr);

    quick_sort(arr, 0, MAX-1);

    printf("\nThe array in sorted order:\n");
      print_array(arr);

    return 0;
}

void quick_sort(int *arr, int start, int end)
/**\Brief: Partition the array such that the pivotal element is placed
 *         at its correct position. Recursively partition the array to
 *         the left and right of it to eventually sort the array.
 *
 * \Parameters:
 *     \arr: Pointer to the array to be sorted.
 *     \start: Index of the first element.
 *     \end: Index of the last element.
 *
 * \Returns: Void.
 */
{
    int partition_index;
    pass_no++; //Counts the number of recursive calls made to quick_sort.
    printf("\nArray in pass %d:", pass_no);
    print_array(arr);

    if(start < end)
    {
        partition_index = partition(arr, start, end); //Partition the array.
          quick_sort(arr, start, partition_index-1); //Partition to the left of partition_index.
          quick_sort(arr, partition_index+1, end); //Partition to the right of partition_index.
    }
}

int partition(int *arr, int start, int end)
/** \Brief: Partitions the array in such a way that the elements
 *          present at a lower/higher index than the partition_index
 *          are lesser/greater than the one present at it. After
 *          every partition one element will be placed at its correct
 *          position.
 *
 * \Parameters:
 *     \arr: Pointer to the array.
 *     \start: Index of the first element.
 *     \end: Index of the last element.
 *
 * \Returns:
 *     \partion_index: Index of the element placed correctly in the array.
 */
{
    int pivot, i, j;

    pivot = arr[end]; //Let the pivotal element be the last element of the array.
    i = start - 1; //i is going to point to the element preceding an element which is
                   //greater than the pivotal element. Initially we assume the first
                   //greater element is present at start index.

    for(j = start; j < end; j++) //From the first to the second last element...
    {
        if(arr[j] <= pivot) //If an element is found to be lesser than the pivotal element...
        {
            i++; //Make i point to element greater than the pivotal element.
            swap(&arr[i], &arr[j]); //Swap the positions of the smaller and lesser elements.
        }
    }
    swap(&arr[++i], &arr[end]); //Make i point to the last greater element and swap its position
                                //with the pivot.
    return i; //Return the index of the correct position of the pivotal element.
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
