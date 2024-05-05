
#include <stdio.h>

void swap(int* a, int* b, int* swaps) {
    int temp = *a;
    *a = *b;
    *b = temp;
    (*swaps)++;
}

int partition(int arr[], int low, int high, int* swaps) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= j && arr[i] <= pivot)
            i++;

        while (arr[j] >= pivot && j >= i)
            j--;

        if (j < i)
            break;

        swap(&arr[i], &arr[j], swaps);
    }

    swap(&arr[low], &arr[j], swaps);
    return j;
}

void quicksort(int arr[], int low, int high, int* swaps) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, swaps);
        quicksort(arr, low, pivotIndex - 1, swaps);
        quicksort(arr, pivotIndex + 1, high, swaps);
    }
}

int main() {
    int arr[] = {12, 20, 5, 85, 22, 15, 25, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int swaps = 0;

    quicksort(arr, 0, n - 1, &swaps);

    // Printing the sorted array and number of swaps
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nNumber of swaps: %d\n", swaps);

    return 0;
}
