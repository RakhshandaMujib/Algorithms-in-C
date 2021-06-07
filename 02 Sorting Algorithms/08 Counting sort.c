#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void read_array(int *arr);
void print_array(int *arr, int len);
void counting_sort(int *arr, int lower, int upper, int arr_len);

int main()
/**< Driver function: */
{
    int arr[MAX], lower_limit, upper_limit;

    //Get the upper and the lower limits:
    printf("Enter the lower limit:\t");
      scanf("%d", &lower_limit);
    printf("Enter the upper limit:\t");
      scanf("%d", &upper_limit);

    read_array(arr);

    printf("\nOriginal contents of the array:\n");
      print_array(arr, MAX);

    counting_sort(arr, lower_limit, upper_limit, MAX);

    return 0;
}

void counting_sort(int *arr, int lower, int upper, int arr_len)
/** \Brief: Creates an array from the lower to the upper limit and
 *          updates the frequency of each element within that range
 *          Prints the elements the number of time it occurs in
 *          ascending order.
 *
 * \Parameters:
 *      \arr: Pointer to the array to be sorted.
 *      \lower: Lower limit of the range (inclusive).
 *      \upper: Lower limit of the range (inclusive).
 *      \arr_len: Length of the array to be sorted.
 *
 * \Returns: Void
 *
 */

{
    int count[upper - lower + 1], count_len, i, j;
    count_len = upper - lower + 1;

    for(i = 0; i < count_len; i++) //Initialize the count array with 0s.
        count[i] = 0;

    for(i = 0; i < arr_len; i++)
    {
        if(arr[i] < lower || arr[i] > upper)
        {
            printf("%d does not belong to (%d, %d)", arr[i], lower, upper);
            return;
        }
        count[arr[i] - lower]++;
    }
    printf("\nThe array in sorted order is:\n");

    for(i = 0; i < count_len; i++)
        for(j = 0; j < count[i]; j++)
            printf("\t%d ", i + lower);
    printf("\n");
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
