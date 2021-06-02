#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void read_array(int *arr);
void print_array(int *arr, int len);
void merge_sort(int *arr, int start, int end);
void merge(int *arr, int start, int middle, int end);

int pass_no;

int main()
/**< Driver function: */
{
    int arr[MAX];

    read_array(arr);

    printf("\nOriginal contents of the array:\n");
      print_array(arr, MAX);
    printf("\n");

    merge_sort(arr, 0, MAX-1);

    printf("\nThe array in sorted order:\n");
      print_array(arr, MAX);

    return 0;
}

void merge_sort(int *arr, int start, int end)
/**\Brief: Sorts the first half and the second half separately then
 *         merges the two halves to form the completely sorted array.
 *
 * \Parameters:
 *     \arr: Pointer to the array to be sorted.
 *     \start: Index of the first element.
 *     \end: Index of the last element.
 *
 * \Returns: Void.
 */
{
    int middle = (start + end) / 2;
    pass_no++; //Counts the number of recursive calls made to quick_sort.

    if(start < end)
    {
          printf("\tSorting %d to %d...\n", start, middle);
        merge_sort(arr, start, middle); //Sort the first half.
          printf("\t  Sorted %d to %d!\n", start, middle);

          printf("\tSorting %d to %d...\n", middle+1, end);
        merge_sort(arr, middle+1, end); //Sort the second half.
          printf("\t  Sorted %d to %d!\n", middle+1, end);

          printf("\tMerging %d to %d...\n", start, end);
        merge(arr, start, middle, end); //Merge both the sorted halves.
    }
}

void merge(int *arr, int start, int middle, int end)
/** \Brief: The array passed is sorted from the start till the middle
 *          and from (middle + 1) to the end. This function merges the
 *          two sorted sub-arrays such that the resultant array is sorted.
 *
 * \Parameters:
 *     \arr: Pointer to the array.
 *     \start: Index of the first element.
 *     \middle: Index of the middle element.
 *     \end: Index of the last element.
 *
 * \Returns: Void.
 */
{
    int left_size = middle - start + 1; //Get the size of the left sub-array.
    int right_size = end - middle; //Get the size of the right sub-array.
    int left[left_size], right[right_size], i, j, k;

    /**< Partition the array into two halves (where each half is sorted):*/
    for(i = 0, k = start; i < left_size; i++, k++) //Copy the first half to left.
        left[i] = arr[k];
      printf("\t\tLeft array:");
      print_array(left, left_size);
    for(i = 0, k = middle+1; i < right_size; i++, k++) //Copy the second halt to right.
        right[i] = arr[k];
      printf("\t\tright array:");
      print_array(right, right_size);
    
    /**< Sorting begins... */
    for(i = 0, j = 0, k = start; k <= end; k++)
    {
        if(i == left_size) //If all the elements of left has been copied to arr...
        {
            for(; j < right_size; j++, k++) //copy the remaining elements... 
                arr[k] = right[j]; //of right to arr...
            break; // and return.
        }
        else if(j == right_size) //If all the elements of right has been copied to arr...
        {
            for(; i < left_size; i++, k++) //copy the remaining elements...
                arr[k] = left[i]; //of left to arr...
            break; // and return.
        }
        else
        {
            if(left[i] <= right[j]) //If the current element of left is smaller than right...
            {
                arr[k] = left[i]; //update the current position of arr with it.
                i++;
            }
            else //If the current element of right is smaller than right...
            {
                arr[k] = right[j]; //update the current position of arr with it.
                j++;
            }
        }
    }
    /**< Print the results... */
    printf("\t\tAfter merging:");
    print_array(arr, MAX);
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

void print_array(int *arr, int len)
/** \Brief: Prints the array.
 *
 * \Parameter:
 *     \arr: Pointer to the declared array.
 *
 * \Returns: Void.
 */
{
    int i;

    for(i = 0; i < len; i++)
        printf("\t%d ", arr[i]);
    printf("\n");
}
