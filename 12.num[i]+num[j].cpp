#include <stdio.h>

int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int maxSumWithSameDigitSum(int nums[], int size) {
    int maxSum[100]; 
    for (int i = 0; i < 100; i++) {
        maxSum[i] = -1;
    }

    int result = -1;

    for (int i = 0; i < size; i++) {
        int sum = digitSum(nums[i]);

       
        if (maxSum[sum] != -1) {
            result = (result > nums[i] + nums[maxSum[sum]]) ? result : nums[i] + nums[maxSum[sum]];
        }

        
        maxSum[sum] = (maxSum[sum] == -1 || nums[i] > nums[maxSum[sum]]) ? i : maxSum[sum];
    }

    return result;
}

int main() {
    int size;

    
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int nums[size];

    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    
    int result = maxSumWithSameDigitSum(nums, size);
    printf("Maximum value of nums[i] + nums[j] with the same digit sum: %d\n", result);

    return 0;
}
