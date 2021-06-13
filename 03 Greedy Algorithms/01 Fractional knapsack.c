#include <stdio.h>
#include <stdlib.h>
#define MAX 7

void print_array(int *arr, int len);
void print_details(int item, int weight, float profit);
void greedy_knapsack(int input[3][MAX], int capacity, int len);
void swap_int(int *left, int *right);
void swap_float(float *left, float *right);

int main()
/**< DRIVER FUNCTION: */
{
    int input[3][MAX], capacity, i; //Input is a 3 x total_number_of_items matrix:
                                    //Row 1 => Index of the item.
                                    //Row 2 => Profit of the item.
                                    //Row 3 => Weight of the item.
    printf("Enter the knapsack capacity:\n");
      scanf("%d", &capacity); //Get the capacity of the knapsack.

    printf("%d items available. Enter the profit and weight for:\n", MAX); 
    for(i = 0; i < MAX; i++) //Get the weight and profit of each item.
    {
        input[0][i] = i + 1; //Initialize the first row with the index of item.
        printf("\tItem %d:\t", i+1); 
        scanf("%d %d", &input[1][i], &input[2][i]); 
    }

    printf("\nItem no.:");
      print_array(input[0], MAX);
    printf("\nProfit (P):");
      print_array(input[1], MAX);
    printf("\nWeight (W):");
      print_array(input[2], MAX);

    greedy_knapsack(input, capacity, MAX); 

    return 0;
}

void greedy_knapsack(int input[3][MAX], int capacity, int len)
/** \Brief: Sorts the input in descending order of profit/ weight ration. Prints 
 *          one of the possible collection of items needed to fill the knapsack
 *          such that maximum profit is earned.
 *
 * \Parameter:
 *     \input: 2D array including the input index, weight, and profit of items.
 *     \capacity: Capacity of the knapsack.
 *     \len: Total number of items available.
 *
 * \Returns: Void.
 */
{
    float p_by_w[len], max, total_profit = 0;
    int i, j, k;

    printf("\nRatio (P/W):");
    for(i = 0; i < len; i++) //Get the profit/ weight ratio for each item.
    {
        p_by_w[i] = (float) input[1][i] / input[2][i];
        printf("\t%.2f", p_by_w[i]);
    }

    printf("\n\n");

    for(j = 0; j < len; j++) //Sort the input in the descending order of the 
                             //profit/ weight ratio.
    {
        max = p_by_w[j]; //Say, the jth element has the max profit/ weight ratio.
        for(i = j+1; i < len; i++) //From j+1 till the end...
            if(max < p_by_w[i]) //if a bigger ratio is found...
            {
                max = p_by_w[i]; //update the max ratio,
                swap_float(&p_by_w[j], &p_by_w[i]); //push the min ratio behind,
                for (k = 0; k < 3; k++) //and sort the input accordingly.
                    swap_int(&input[k][j], &input[k][i]);
            }
    }

    i = 0; 
    //Fill the knapsack while the ith weight > = capacity > 0.
    while(capacity > 0 && input[2][i] <= capacity) 
    {
        capacity -= input[2][i]; //Subtract the ith weight from the capacity.
        total_profit += input[1][i]; //Add the ith profit.
        print_details(input[0][i], input[2][i], (float)input[1][i]);
        i++;
    }

    if(capacity > 0) //In case the knapsack is not full...
    {
        total_profit += (float)capacity * p_by_w[i]; //add the fractional profit
                                                     //of the last relevant item. 
        print_details(input[0][i], capacity, (float) capacity* p_by_w[i]);
    }
    printf("\n\nTotal profit:\t%.2f\n", total_profit);//Print the total profit.
}

/**< UTILITY FUNCTIONS: */

void print_array(int *arr, int len)
/** \Brief: Prints the array.
 *
 * \Parameter:
 *     \arr: Pointer to the array.
 *     \len: Length of the array.
 *
 * \Returns: Void.
 */
{
    int i;

    for(i = 0; i < len; i++)
        printf("\t%d", arr[i]);
}

void print_details(int item, int weight, float profit)
/** \Brief: Prints the details of each item.
 *
 * \Parameter:
 *     \item: Index of the item.
 *     \weight: Weight taken of the item.
 *     \profit: Profit earned from the weight of the corresponding item.
 *
 * \Returns: Void.
 */
{
    printf("\n\tItem %d:", item);
    printf("\n\t\tWeight taken: %d", weight);
    printf("\n\t\tProfit earned: %.2f", profit);
}

void swap_int(int *left, int *right)
/** \Brief: Swap the integer elements at left and right.
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

void swap_float(float *left, float *right)
/** \Brief: Swap the float elements at left and right.
 *
 * \Parameter:
 *     \left: Pointer to the the element at left.
 *     \left: Pointer to the the element at right.
 *
 * \Returns: Void.
 */
{
    float temp = *left;
    *left = *right;
    *right = temp;
}
