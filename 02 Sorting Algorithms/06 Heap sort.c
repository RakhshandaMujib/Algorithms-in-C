#include <stdio.h>
#include <stdlib.h>
#define MAX 6

void read_array(int *arr);
void print_array(int *arr, int len);
void swap(int *left, int *right);
void heap_sort(int *arr, int len);
void min_heapify(int *arr, int node, int heap_size);

int main()
/**< Driver function: */
{
    int arr[MAX], i;

    read_array(arr);

    printf("\nOriginal contents of the array:\n");
      print_array(arr, MAX);

    heap_sort(arr, MAX);

    printf("\nThe array in sorted order:\n");
    for(i = MAX - 1; i >= 0; i--)
        printf("\t%d", arr[i]);

    return 0;
}

void heap_sort(int *arr, int len)
/**\Brief: Heapifies the array till the contents are sorted in
 *         descending order.
 *
 * \Parameters:
 *     \arr: Pointer to the array interpreted as a heap to be sorted.
 *     \len: Int. Length of the array.
 *
 * \Returns: Void.
 */
{
    int i, last_element;
    
    printf("\n\n\t\t\tHeapifying the array...\n\n"); //Start deleting the root.
     
    for(i = len / 2 - 1; i >= 0; i--) //From the first non-leaf to the root.
    {
        min_heapify(arr, i, len); //Heapify the node.
        printf("\n\tHeapifying node [%d]...\n", i);
        printf("\tNew min heap:");
        print_array(arr, len);
    }//Will return the min heap.
    
    printf("\n\n\t\t\tDeleting minimum elements...\n\n"); //Start deleting the root.

    while(len) //Delete the root (minimum element).
    {
        last_element = len - 1; //Get the index of the last element.
        printf("\n\tMinimum element: %d", arr[0]);
        swap(&arr[0], &arr[last_element]); //Swap the root with the last leaf node.
        min_heapify(arr, 0, --len); //Again heapify the root.
        printf("\n\tNew min heap:");
        print_array(arr, len);
    }
}

void min_heapify(int *arr, int node, int heap_size)
/** \Brief: Compares the node with its left & right children
 *          and brings the smallest among the three to the node.
 *
 * \Parameters:
 *     \arr: Pointer to the array.
 *     \start: Integer. Index of the current element.
 *     \end: Integer. Size of the heap.
 *
 * \Returns: Void.
 */
{
    int left, right, min;
    left = 2 * node + 1; //Initialize the index of the left child.
    right = left + 1; //Initialize the index of the right child.

    //If the left child exists and it is smaller than the parent node...
    if(left < heap_size && arr[left] < arr[node])
        min = left; //The index of the min element is the index of the left child.
    else
        min = node; //Else the index of the min element remains that of the node.
    //If the right child exists and it is smaller than the min element...
    if(right < heap_size && arr[right] < arr[min])
        min = right; //Update the index of the min element with that of the right child.
    if(min != node) //If the node is not the node with the minimum element...
    {
        swap(&arr[node], &arr[min]); //Swap the elements...
        min_heapify(arr, min, heap_size); //Heapify again in case the adjustment doesn't
                                          //result in a min heap.
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

void print_array(int *arr, int len)
/** \Brief: Prints the array.
 *
 * \Parameter:
 *     \arr: Pointer to the declared array.
 *     \len: Integer. Length to be printed till.
 *
 * \Returns: Void.
 */
 {
    int i;

    for(i = 0; i < len; i++)
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
