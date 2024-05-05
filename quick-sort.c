#include <stdio.h>

int A[100]; // Assuming a maximum array size of 100, you can adjust it as needed

void swap(int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(int left, int right) {
    int x = A[right];
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        if (A[j] <= x) {
            i++;
            swap(i, j);
        }
    }
    
    swap(i + 1, right);
    return i + 1;
}

void QuickSort(int left, int right) {
    if (left < right) {
        int q = Partition(left, right);
        QuickSort(left, q - 1);
        QuickSort(q + 1, right);
    }
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    QuickSort(0, n - 1);

    printf("\nOutput\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    // printf("\n");

    return 0;
}