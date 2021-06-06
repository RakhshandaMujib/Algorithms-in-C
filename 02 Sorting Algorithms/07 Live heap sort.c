#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void print_array(int *arr, int len);
void swap(int *left, int *right);
void heap_sort(int *arr, int len);
void min_heapify(int *arr, int node, int heap_size);

int main()
/**< Driver function: */
{
    int arr[MAX], i;

    printf("Enter %d elements:\n", MAX);
    heap_sort(arr, MAX);

    printf("\nThe array in sorted order:\n"); //Since the array gets 
                                              //sorted in descending order...
    for(i = MAX - 1; i >= 0; i--) //Print the array in reverse order.
        printf("\t%d", arr[i]);

    return 0;
}

void heap_sort(int *arr, int len)
/**\Brief: Heapifies the array as it reads its elements. Once the min heap is ready, 
 *         it pushes the root to the end after return the minimum element. The array 
 *         gets sorted in descending order.
 *
 * \Parameters:
 *     \arr: Pointer to the array interpreted as a heap to be sorted.
 *     \len: Int. Length of the array.
 *
 * \Returns: Void.
 */
{
    int i, j, last_element, current_length = 1; //Initialize the current length as 1.

    printf("\t\t\tBuilding min heap...\n\n");
    for(i = 0; i < len; i++, current_length++) //Iterate through the array. After
                                               //reading each element, increment the
                                               //current length of the array.
    {
        scanf("%d", &arr[i]); //Read the ith element.
        printf("\tMin heap after insertion of %d:\n", arr[i]);
        for(j = i/2; j >= 0; j--) //From the first non-leaf node to the root...
            min_heapify(arr, j, current_length); //heapify the node...
        print_array(arr, current_length); //and print the contents.
    }//Will return the min heap with all the elements.
     //Current length would be len + 1.

    printf("\n\n\t\t\tDeleting minimum elements...\n\n"); //Start deleting the root.
    --current_length; //Reset the current length to len.

    while(current_length) //Delete the root (minimum element) till the array has
                          //no element left.
    {
        last_element = current_length - 1; //Get the index of the last element.
          printf("\tMinimum: %d", arr[0]); //Root of the min heap before deletion.
        swap(&arr[0], &arr[last_element]); //Swap the root with the last leaf node.
        min_heapify(arr, 0, --current_length); //Again heapify the root.
          printf("\n\tNew min heap:");
          print_array(arr, current_length); //Contents of the latest min heap.
          printf("\n");
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

void print_array(int *arr, int len)
/** \Brief: Prints the array.
 *
 * \Parameter:
 *     \arr: Pointer to the declared array.
 *     \len: Integer. Length to print the contents till.
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
