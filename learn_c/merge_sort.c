// Merge sort
#include <stdio.h>

void merge_sort(int arr[], int l, int r);
void merge(int arr[], int p, int q, int r);
void print_array(int arr[], int size);

// Main program
int main(void)
{
    int arr[] = {20, 6, 5, 12, 0, 10, 9, 1, 18, 4, 37, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, size - 1);

    printf("Sorted array: ");
    print_array(arr, size);
}

// Divide array into two subarrays, sort them and merge them
void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        // m is the middle point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        // Merge sorted subarrays
        merge(arr, l, m, r);
    }
}

// Merge subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{
    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Print array
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}