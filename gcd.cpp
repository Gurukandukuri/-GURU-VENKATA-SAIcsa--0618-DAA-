#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main() { 
    int num1, num2;
    printf("Enter two numbers for GCD calculation:\n");
    printf("Number 1: ");
    scanf("%d", &num1);
    printf("Number 2: ");
    scanf("%d", &num2);
    if (num1 < 0 || num2 < 0) {
        printf("Please enter non-negative integers.\n");
        return 1; 
    }
    int result = gcd(num1, num2);
    printf("GCD of %d and %d is: %d\n", num1, num2, result);
    return 0;
}