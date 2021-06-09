#include <stdio.h>
#include <stdlib.h>
#define MAX 6

typedef struct Node
{
    float data;
    struct Node *next;
}node;

void read_array(float *arr, int len);
void bucket_sort(float *arr, int len);
void merge_sort(node **bucket_val);
node* merge(node *left, node *right);
void partition(node *head, node **left, node **right);

int main()
/**< DRIVER FUNCTION: */
{
    float arr[MAX];

    printf("Enter %d elements:\n", MAX);
      read_array(arr, MAX);

    printf("\nThe array in sorted order:\n");
        bucket_sort(arr, MAX);
    return 0;
}

void bucket_sort(float *arr, int len)
/** \Brief: Creates buckets from 0-10 and appends a list of elements to each bucket.
 *          The lists are then sorted using the utility function of merge_sort and
 *          finally the elements are printed in a sorted order. Bucket sort is used
 *          in case we have a uniformly distributed unordered array of floating point
 *          numbers in the range of 0.0-1.0.
 *
 * \Parameter:
 *     \arr: Pointer to the declared array.
 *     \len: Length to print the contents till.
 *
 * \Returns: Void.
 */
 {
    int i, after_radix;
    node *element, *bucket[10], *temp; //bucket is an array of pointers
                                       //to 10 node type structures.

    for(i = 0; i < 10; i++) //Initialize the buckets:
        {
            bucket[i] = malloc(sizeof(node*)); //Allocate space occupied by a
                                               //single node to each index.
            bucket[i] = NULL; //Initialize them with NULL values.
        }

    //Create the lists for each bucket:
    for(i = 0; i < len; i++) //For each element in the unordered array...
    {
        element = (node*)malloc(sizeof(node*)); //Create an empty node.
        after_radix = (int)(arr[i] * 10); //Say, the ith element is 0.57. So,
                                          //after_radix will store the first integer
                                          //value after the radix point, i.e., 5.
        element->data = arr[i]; //The node's data will be 0.57.
        element->next = NULL; //And, the next pointer will store NULL.
        if(!bucket[after_radix]) //If the bucket has not been initialized...
            bucket[after_radix] = element; //initialize it with the pointer
                                           //to the element.
        else //If the current bucket is already pointing to some element...
        {
            temp = (node*)malloc(sizeof(node*)); //Create a temporary node.
            temp = bucket[after_radix]; //Let it point to the node pointed by
                                        //the first bucket entry after_radix index.
            while(temp->next) //Till we do not find a node's next pointer as NULL, i.e.,
                              //till we do not reach the end of a chain for a
                              //particular bucket...
                temp = temp->next; //let the temp node point to its next node.
            temp->next = element; //Finally, append the element at the end of the chain.
        }
    }

    //For each bucket, sort the list of elements pointed by it.:
    for(i = 0; i < 10; i++)
        merge_sort(&bucket[i]);

    //Finally, print the sorted lists appended to the buckets:
    for(i = 0; i < 10; i++) //For each bucket...
    {
        temp = bucket[i]; //Let a temporary node point to the head of the bucket's list.
        while(temp) //Till temp doesn't reach the end of the list...
        {
            printf("\t%f", temp->data); //Print the data...
            temp = temp->next; //Make temp point to its next node.
        }
    }
}

/**< UTILITY FUNCTIONS: */

void read_array(float *arr, int len)
/** \Brief: Reads the array.
 *
 * \Parameter:
 *     \arr: Pointer to the declared array.
 *     \len: Length to print the contents till.
 *
 * \Returns: Void.
 */
 {
    int i;

    for(i = 0; i < len; i++)
        scanf("%f", &arr[i]);
}

void merge_sort(node **bucket_val)
/** \Brief: Sorts each list for each bucket.
 *
 * \Parameter:
 *     \bucket_val: Reference of the head to the list of a bucket, i.e.,
 *                  the content of the bucket value for that index.
 *
 * \Returns: Void.
 */
{
    node *head, *left, *right;
    head = *bucket_val; //Store the bucket value as the head of the list.

    if (!head || !head->next) //In case the length of the list is 0 or 1...
        return; //go back without making any change.

    partition(head, &left, &right); //Partition the array into left & right sub-arrays...
    merge_sort(&left); // and sort each of...
    merge_sort(&right); //the 2 sub-arrays.

    *bucket_val = merge(left, right); //Finally, merge the 2 sorted sub-arrays.
}

node* merge(node *left, node *right)
/** \Brief: Merges the two lists such that the resultant list is in sorted order.
 *
 * \Parameter:
 *     \left: Pointer to the head of the (already sorted) left list.
 *     \right: Pointer to the head of the (already sorted) right list.
 *
 * \Returns: Pointer to the head of the merged and sorted resultant list.
 */
{
    node *result = NULL; //Initialize the resultant head pointer.

    if (left == NULL) //If the left node is empty...
        return(right); //return the right node as the updated head.
    else if (right == NULL) //If the right node is empty...
        return(left); //return the left node as the updated head.

    if (left->data <= right->data) //If the left sub-array's first data is smaller
                                   //than the right sub-array's first data...
    {
        result = left; //Let the head be the left sub-array's first node.
        result->next = merge(left->next, right); //For the next sorted element, merge
                                                 //the left sub-array's remaining
                                                 //elementswith the right sub-array.
    }
    else //If the right sub-array's first data is smaller than the left
         //sub-array's first data...
    {
        result = right; //Let the head be the right sub-array's first node.
        result->next = merge(left, right->next); //For the next sorted element, merge
                                                 //the right sub-array's remaining
                                                 //elements with the left sub-array.
    }
    return(result); //Finally, return the head to the merged lists.
}

void partition(node *head, node **left, node **right)
/** \Brief: Partitions the original list into 2 sub-arrays such that
 *          ultimately both the sub-arrays are sorted.
 *
 * \Parameter:
 *     \head: Pointer to the original list to be sorted.
 *     \left: Reference to the left list.
 *     \right: Reference to the right list.
 *
 * \Returns: Void.
 */
{
    node *last, *middle;
    middle = head; //Let middle point to the 1st element of the list.
    last = head->next; //Let last point to the 2nd element of the list.

    while (last) //As long as last does not go out of the list, i.e.,
                 //as long as it is not pointing to NULL...
    {
        last = last->next; //make last point to its next node.
        if (last) //If it is still not NULL...
        {
            middle = middle->next; //make middle point to its next node &
            last = last->next; //...again make last point to its next node.
        }
    }//For every iteration, last will jump 2 nodes and middle will
     //jump 1 node. Thus, finally middle will point to the element right
     //before the middle element and last will point to the last node's next
     //value, that is, NULL.

    *left = head; //Let left point to the first node or the head and...
    *right = middle->next; //right point to the center node of the list.
    middle->next = NULL; //Partition the list by breaking the link between
                         //middle and (middle + 1)th node.
}
