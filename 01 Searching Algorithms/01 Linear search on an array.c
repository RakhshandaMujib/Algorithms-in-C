#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void read_array(int *arr); //Reads an array of MAX elements.
int linear_search(int *ptr, int len, int key); //Finds if the key is present in the array.

int main()
{
    int arr[MAX], key, result;

    read_array(arr);

    printf("\nEnter key:\n");
      scanf("%d", &key);

    result = linear_search(arr, MAX, key);
    result == -1 
    ? printf("\nKey (%d) not found.", key)
    : printf("Key (%d) found at index %d.", key, result);

    return 0;
}

int linear_search(int *ptr, int len, int key)
{
    int i;

    for(i = 0; i < len; i++) //Iterate through the entire array once.
        if(ptr[i] == key) //If any element matches the key...
            return i; //Return the index of that element.

    return -1; //If no match found, return -1 as the index.
}

void read_array(int *arr)
{
    int i;

    printf("Enter %d elements:\n", MAX);

    for(i = 0; i < MAX; i++)
        scanf("%d", &arr[i]);
}
