#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void read_array(int *arr); //Reads an array of MAX elements.
int binary_search(int *arr, int left, int right, int key); //Takes in the array, the indices of left and right ends, and the key for searching. 

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

    while(right >= left) //Till the time the right end of the array is present at a higher end than the left...
    {
        middle = (left + right) / 2; //Find the middle index.
        if(arr[middle] == key) //If the middle element matches the key...
            return middle; //return the middle index.
        else if(arr[middle] > key) //In case the middle element is bigger than the key...
            left = middle; //ignore the left half of the current array and continue searching in the right half. 
        else //In case the middle element is smaller than the key...
            right = middle; //ignore the right half of the current array and continue searching in the left half. 
    }

    return -1; //In case no match is found return -1 as the index. 
}
