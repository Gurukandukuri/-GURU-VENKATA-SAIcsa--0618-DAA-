#include <stdio.h>

void findMinMax(int arr[], int size, int m, int n, int *max, int *min) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    *max = arr[size - m];
    *min = arr[n - 1];
}
int main() {
    int size, m, n;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of m: ");
    scanf("%d", &m);
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int max, min;
    findMinMax(arr, size, m, n, &max, &min);
    int sum = max + min;
    int diff = max - min;
    printf("The m-th maximum number is: %d\n", max);
    printf("The n-th minimum number is: %d\n", min);
    printf("Sum of these numbers: %d\n", sum);
    printf("Difference of these numbers: %d\n", diff);
    return 0;
}
