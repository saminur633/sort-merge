#include <stdio.h>

void merge(int left, int mid, int right, int c[]) {
    int l = mid - left + 1;
    int r = right - mid;

    int L[10], R[10];

    for (int i = 0; i < l; i++) {
        L[i] = c[left + i];
    }

    for (int i = 0; i < r; i++) {
        R[i] = c[mid + 1 + i];
    }

    int k = left, i = 0, j = 0;

    while (i < l && j < r) {
        if (L[i] <= R[j]) {
            c[k++] = L[i++];
        } else {
            c[k++] = R[j++];
        }
    }
    while (i < l) {
        c[k++] = L[i++];
    }
    while (j < r) {
        c[k++] = R[j++];
    }
}

void mergesort(int left, int right, int c[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergesort(left, mid, c);
        mergesort(mid + 1, right, c);
        merge(left, mid, right, c);
    }
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int c[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    mergesort(0, n - 1, c);

    printf("Output: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}