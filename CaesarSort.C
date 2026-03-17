#include <stdio.h>
#include <stdlib.h>

// Sort small arrays (<=5 items) quickly
void CaesarSort_Sorting(int arr[], int n) {
    if (n <= 1) return;

    // Simple insertion, dual-ended handling could be added later
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Find pivot = element closest to average
int findPivotClosestToAverage(int arr[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    int avg = sum / n;

    int closest = arr[0];
    int minDiff = abs(arr[0] - avg);

    for (int i = 1; i < n; i++) {
        int diff = abs(arr[i] - avg);
        if (diff < minDiff) {
            minDiff = diff;
            closest = arr[i];
        }
    }
    return closest;
}

// Caesar-style divide-and-conquer sorting
void CaesarSort_Dividing(int arr[], int n) {
    if (n <= 5) {
        CaesarSort_Sorting(arr, n); // micro-battle: sort tiny blocks
        return;
    }

    int pivot = findPivotClosestToAverage(arr, n);

    // Allocate arrays for < pivot and > pivot
    int *left = malloc(n * sizeof(int));
    int *right = malloc(n * sizeof(int));
    int l = 0, r = 0;
    int pivotPlaced = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < pivot) left[l++] = arr[i];
        else if (arr[i] > pivot) right[r++] = arr[i];
        else {
            if (!pivotPlaced) pivotPlaced = 1; // one pivot in middle
            else left[l++] = arr[i]; // duplicates go left
        }
    }

    // Recursively sort left and right
    CaesarSort_Dividing(left, l);
    CaesarSort_Dividing(right, r);

    // Merge back
    int index = 0;
    for (int i = 0; i < l; i++) arr[index++] = left[i];
    arr[index++] = pivot; // only one pivot
    for (int i = 0; i < r; i++) arr[index++] = right[i];

    free(left);
    free(right);
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Test program
int main() {
    int arr[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original: ");
    printArray(arr, n);

    CaesarSort_Dividing(arr, n);

    printf("Sorted:   ");
    printArray(arr, n);

    return 0;
}
