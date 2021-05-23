#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void read_array(int *arr); //Reads an array of MAX input.
int binary_search(int *arr, int left, int right, int key); //Takes the arrar, the indices of left and right ends, and the key for searching.

int main()
{
    int arr[MAX], key, result;

    read_array(arr);

    printf("\nEnter key:\n");
      scanf("%d", &key);

    result = binary_search(arr, 0, MAX - 1, key);
    result == -1
    ? printf("\nKey (%d) not found.", key)
    : printf("Key (%d) found at index %d.", key, result);

    return 0;
}

void read_array(int *arr)
{
    int i;

    printf("Enter %d elements:\n", MAX);

    for(i = 0; i < MAX; i++)
        scanf("%d", &arr[i]);
}

int binary_search(int *arr, int left, int right, int key)
{
    int middle;
    middle = (left + right) / 2; //Get the middle index of the array. 

    if(left <= right) //If the right end is at a higher end than the left end...
    {
        if(arr[middle] == key) //check if the middle element matches the key.
            return middle; //If yes, return the middle index.
        if(arr[middle] > key) //If the middle element is bigger than the key...
            return binary_search(arr, left, middle, key); //return the left half of the array for search.
        if(arr[middle] < key) //If the middle element is bigger than the key...
            return binary_search(arr, middle + 1, right, key); //return the right half of the array for search.
    }
  
    return -1; //If no match is found, return -1 as the index. 
}
