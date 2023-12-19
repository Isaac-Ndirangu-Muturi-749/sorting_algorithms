#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    /* Check if the array is not empty or contains only one element */
    if (array == NULL || size < 2)
        return;

    /* Call the recursive quick_sort function with the entire array */
    quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick sort
 * @array: The array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int pivot;

    /* Base case: partition size is 1 or 0 */
    if (low < high)
    {
        /* Partition the array and get the index of the pivot */
        pivot = lomuto_partition(array, low, high, size);

        /* Recursively sort the sub-arrays on both sides of the pivot */
        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: The size of the array
 * Return: The index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot, i, j, temp;

    /* Choose the pivot (in this case, the last element of the partition) */
    pivot = array[high];

    i = low - 1;

    /* Iterate through the partition to rearrange elements */
    for (j = low; j <= high - 1; j++)
    {
        /* If the current element is smaller than or equal to the pivot */
        if (array[j] <= pivot)
        {
            i++;

            /* Swap array[i] and array[j] */
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            /* Print the array after each swap */
            print_array(array, size);
        }
    }

    /* Swap array[i + 1] and array[high] (the pivot) */
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    /* Print the array after each swap */
    print_array(array, size);

    /* Return the index of the pivot after partitioning */
    return (i + 1);
}
