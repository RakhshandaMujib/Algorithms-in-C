#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct Node
{
    int item;
    struct Node* next;

}node;

node* create_list(); //Reads and creates a singly linked list of MAX elements.
int search(node* ptr, int key); //Searches for the key in the linked list.

int main()
{

    int key, result;
    node *myList; 

    myList = create_list(); //myList stores the pointer to the head of the linked list.
    printf("Enter key:\n");
      scanf("%d", &key);

    result = search(myList, key);
    result
    ? printf("\nKey (%d) found at node %d.", key, result)
    : printf("\nKey (%d) not found.", key);

    return 0;
}

node* create_list()
{
    int i;
    node *head, *temp, *current;

    current = (node*)malloc(sizeof(node*)); //Create an empty space for the first node.
    head = current; //Let the head point to the first node.
  
    printf("Enter %d values:\n", MAX);
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

int search(node* ptr, int key)
{
    int node_counter = 1; //Indexing of the nodes starts from 1 (and not 0).
    bool keyFound = false; //Assuming the key is not found initially.
  
    while(ptr) //As long as the node doesn't point to NULL, run the loop.
    {
        if(ptr->item == key) //If the current node's item matches the key...
        {
            keyFound = true; //change the state of the boolean variable...
            break; //and break the loop.
        }
      //If the current node's item doesn't match the key...
        ptr = ptr->next; //point to the next node in the linked list
        node_counter += 1; //and increment the index.
    }

    if (!keyFound) //If the state of the boolean variable DOESN'T switch to true...
        node_counter = 0; //return 0 as the index.

    return node_counter; //If the state of the boolean variable switches to true, return the index.
}
