#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int size, target;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter sorted array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &target);
    clock_t start_time = clock();
    int result = binarySearch(arr, 0, size - 1, target);

    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Number found at index: %d\n", result);
    else
        printf("Number not found in the array.\n");

    printf("Time taken for binary search: %f seconds\n", time_taken);
    free(arr);

    return 0;
}
