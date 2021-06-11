#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 6

void read_array(int *arr);
void print_array(int *arr, int len);
int* counting_sort(int *arr, int arr_len, int index);
int* radix_sort(int *arr, int arr_len);
int get_digits(int *arr, int arr_len);

int main()
/**< DRIVER FUNCTION: */
{
    int arr[MAX], *result; //Pointer that will hold the address of the
                           //resultant array.

    read_array(arr);

    printf("\nOriginal contents of the array:\n");
      print_array(arr, MAX);

    result = radix_sort(arr, MAX);

    printf("\nSorted array:\n");
      print_array(result, MAX);

    return 0;
}

int* radix_sort(int *arr, int arr_len)
/** \Brief: Employs a counting sort on each index of the number
 *          to sort the actual unsorted array.
 *
 * \Parameters:
 *      \arr: Pointer to the array to be sorted.
 *      \arr_len: Length of the array to be sorted.
 *
 * \Returns: Void
 */
{
    int i, msb_index;
    msb_index = get_digits(arr, arr_len);
    for(i = 0; i < msb_index; i++) //For each digit of the numbers in
                                   //the array...
    {
        printf("\n\tSorting index %d...\n", i);
        arr = counting_sort(arr, arr_len, i); //Apply counting sort.
        print_array(arr, arr_len);
    }
    return arr; //Return the final sorted array.
}

/**< UTILITY FUNCTIONS: */

int* counting_sort(int *arr, int arr_len, int index)
/** \Brief: Creates an array from the lower to the upper limit and
 *          updates the frequency of each element within that range
 *          Prints the elements the number of time it occurs in
 *          ascending order.
 *
 * \Parameters:
 *      \arr: Pointer to the array to be sorted.
 *      \arr_len: Length of the array to be sorted.
 *      \index: Index of the digit.
 *
 * \Returns: Void
 */
{
    int count[10], *result, digit, i, j, k;

    result = (int*)malloc(sizeof(int*)); //Allocate some space in the
                                         //heap for the resultant array
                                         //to return the pointer to it.

    for(i = 0; i < 10; i++) //Initialize the count array with 0s.
        count[i] = 0;

    for(i = 0; i < arr_len; i++) //For each number in the array...
    {
        digit = (arr[i] / (int)pow(10, index)) % 10; //Extract the digit
                                                     //corresponding to the
                                                     //given index position...
        count[digit]++; //& update the count of that digit in the count array.
    }

    for(k = 0, i = 0; i < 10; i++) //k keeps track of the index of the resultant
                                   //array. For each digit in (0,9)...
        for(j = 0; j < arr_len && count[i] > 0; j++) //If count of any digit is
                                                     //0 then we skip that digit.
                                                     //Check with each digit...

        {
            digit = (arr[j] / (int)pow(10, index)) % 10; //Extract the digit again.
            if(i == digit) //If the digit matches with the index of count...
            {
                count[i]--; //Decrement the count of that digit in the array count...
                result[k++] = arr[j]; //Append the number corresponding to that
                                      //digit in the resultant array and increment
                                      //k to the next index for the next element.
            }
        }
    //After each application of counting sort, the numbers will be sorted according to
    //their index values.
    return result;
}

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

int get_digits(int *arr, int arr_len)
/** \Brief: Gets the maximum number of digits required to represent
 *          the largest number in the array,.
 *
 * \Parameters:
 *      \arr: Pointer to the array to be sorted.
 *      \arr_len: Length of the array to be sorted.
 *
 * \Returns: Maximum digits.
 */
{
    int i, max = arr[0], max_digits = 0;

    for(i = 1; i < arr_len; i++) //Find the maximum.
        if(arr[i] > max)
            max = arr[i];

    while(max) //Count the digits needed to represent
    {
        max /= 10;
        max_digits++;
    }

    return max_digits;
}
