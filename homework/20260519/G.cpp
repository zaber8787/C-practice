#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Declaration of the merge function
void merge(int array[], size_t low, size_t middle1, size_t middle2, size_t high);

// ==========================================
// YOUR TASK: Complete this function
// ==========================================
void sortSubArray(int array[], size_t low, size_t high)
{
    if ((high - low) >= 1)
    {
        size_t middle1 = (low + high) / 2;
        size_t middle2 = middle1 + 1;
        if (high == low)
            return;
        sortSubArray(array, 0, middle1);
        sortSubArray(array, middle2, high);
        merge(array, low, middle1, middle2, high);
        // TODO: Fill in the missing core logic here
    }
}

// ==========================================
// System logic below. DO NOT MODIFY.
// ==========================================
void merge(int array[], size_t low, size_t middle1, size_t middle2, size_t high)
{
    size_t left_size = middle1 - low + 1;
    size_t right_size = high - middle2 + 1;

    int *left_arr = (int *)malloc(left_size * sizeof(int));
    int *right_arr = (int *)malloc(right_size * sizeof(int));

    for (size_t i = 0; i < left_size; i++)
        left_arr[i] = array[low + i];
    for (size_t i = 0; i < right_size; i++)
        right_arr[i] = array[middle2 + i];

    size_t i = 0, j = 0, k = low;
    while (i < left_size && j < right_size)
    {
        if (left_arr[i] <= right_arr[j])
        {
            array[k++] = left_arr[i++];
        }
        else
        {
            array[k++] = right_arr[j++];
        }
    }
    while (i < left_size)
        array[k++] = left_arr[i++];
    while (j < right_size)
        array[k++] = right_arr[j++];

    free(left_arr);
    free(right_arr);
}

int main()
{
    size_t length;
    if (scanf("%zu", &length) != 1)
        return 0;

    int *array = (int *)malloc(length * sizeof(int));
    for (size_t i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
    }

    if (length > 0)
    {
        sortSubArray(array, 0, length - 1);
    }

    for (size_t i = 0; i < length; i++)
    {
        printf("%d", array[i]);
        if (i < length - 1)
            printf(" ");
    }
    printf("\n");

    free(array);
    return 0;
}
