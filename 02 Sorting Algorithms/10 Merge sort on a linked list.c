#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 6

typedef struct Node
{
    int item;
    struct Node* next;

}node;

void merge_sort(node **head_is);
node* merge(node *left, node *right);
void partition(node *head, node **left, node **right);
void print_list(node *head);
node* create_list(); //Reads and creates a singly linked list of MAX elements.

int main()
/**< DRIVER FUNCTIONS: */
{

    node *myList;

    printf("Enter %d values:\n", MAX);
      myList = create_list(); //myList stores the pointer to the head of the linked list.
    printf("Content of the list is:\n");
      print_list(myList);
    printf("\n\nSorted array is:\n");
      merge_sort(&myList);
    print_list(myList);

    return 0;
}

void merge_sort(node **head_is)
/** \Brief: Sorts each list for each bucket.
 *
 * \Parameter:
 *     \head_is: Reference of the head to the list of a bucket, i.e.,
 *                  the content of the bucket value for that index.
 *
 * \Returns: Void.
 */
{
    node *head, *left, *right;
    head = *head_is; //Store the bucket value as the head of the list.

    if (!head || !head->next) //In case the length of the list is 0 or 1...
        return; //go back without making any change.

    partition(head, &left, &right); //Partition the array into left & right sub-arrays...
    merge_sort(&left); // and sort each of...
    merge_sort(&right); //the 2 sub-arrays.

    *head_is = merge(left, right); //Finally, merge the 2 sorted sub-arrays.
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

    if (left->item <= right->item) //If the left sub-array's first item is smaller
                                   //than the right sub-array's first item...
    {
        result = left; //Let the head be the left sub-array's first node.
        result->next = merge(left->next, right); //For the next sorted element, merge
                                                 //the left sub-array's remaining
                                                 //elementswith the right sub-array.
    }
    else //If the right sub-array's first item is smaller than the left
         //sub-array's first item...
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

/**< UTILITY FUNCTIONS: */

node* create_list()
/** \Brief: Creates a linked list of elements.
 *
 * \Parameter: None.
 *
 * \Returns: Pointer to the head of the linked list.
 */
{
    int i;
    node *head, *temp, *current;

    current = (node*)malloc(sizeof(node*)); //Create an empty space for the first node.
    head = current; //Let the head point to the first node.

    scanf("%d", &current->item);

    current->next = NULL;

    for(i = 1; i < MAX; i++)
    {
        temp = (node*)malloc(sizeof(node*)); //Create a temporary node.
          scanf("%d", &temp->item); //Store the item.
        current->next = temp; //Make the second last node created point to the newest created node.
        temp->next = NULL; //Let the newest created node point to NULL.
        current = temp; //Let the current node point to the newest node.
    }

    return head; //Return the head of the linked list.
}

void print_list(node *head)
/** \Brief: Prints the contents of the linked list.
 *
 * \Parameter:
 *     \head: Pointer to the original list.
 *
 * \Returns: Void.
 */
{
    node *temp = (node*)malloc(sizeof(node*));
    temp = head;
    while(temp)
    {
        printf("\t%d", temp->item);
        temp = temp->next;
    }
}
