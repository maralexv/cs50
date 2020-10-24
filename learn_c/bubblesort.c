// Bubble sort in C

#include <stdio.h>

void bubble_sort(int array[], int size)
{
    // run loops two times: one for walking throught the array
    // and the other for comparison
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            // To sort in descending order, change">" to "<".
            if (array[j] > array[j + 1])
            {
                // swap if greater is at the rear position
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// function to print the array
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("size: %d\n", size);
}

// main code
int main()
{
    int data[] = {-2, 45, 0, 11, -9, 23, 31, -28, 105, 2, 67};
    int size = sizeof(data) / sizeof(data[0]);
    bubble_sort(data, size);
    printf("Sorted array in ascending order:\n");
    print_array(data, size);
}