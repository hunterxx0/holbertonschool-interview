#include "sort.h"

/**
* swap - swaps 2 elements of an array
* @a: pointer to the first element of the list
* @b: pointer to the second element of the list
* Return:
*/
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}
/**
* heapify - heap sort an array
* @arr: pointer to the  the list
* @n: the left element of the list
* @i: the right element of the list
* @size: size of the list
* Return:
*/
void heapify(int arr[], int n, int i, int size)
{
int max = i, lf = 2 * i + 1, rt = 2 * i + 2;

if (lf < n && arr[lf] > arr[max])
max = lf;

if (rt < n && arr[rt] > arr[max])
max = rt;

if (max != i)
{
swap(&arr[i], &arr[max]);
if (arr[i] != arr[max])
print_array(arr, size);
heapify(arr, n, max, size);
}
}
/**
* heapSort - heap sort an array
* @arr: pointer to the  the list
* @n: the left element of the list
* @size: size of the list
* Return:
*/
void heapSort(int arr[], int n, int size)
{
for (int i = n / 2 - 1; i >= 0; i--)
heapify(arr, n, i, size);

for (int i = n - 1; i >= 0; i--)
{
swap(&arr[0], &arr[i]);
if (arr[0] != arr[i])
print_array(arr, n);
heapify(arr, i, 0, size);
}
}
/**
* heap_sort - heap sort an array
* @array: pointer to the  the list
* @size: size of the list
* Return:
*/
void heap_sort(int *array, size_t size)
{
if (array && size > 2)
heapSort(array, (int)size, (int)size);
}
