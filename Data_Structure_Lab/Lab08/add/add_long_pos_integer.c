#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
char* addLongNumbers(const char *num1, const char *num2);

// Main function
int main() {
    char num1[1000], num2[1000], *result;

    printf("Enter first long positive integer: ");
    scanf("%s", num1);

    printf("Enter second long positive integer: ");
    scanf("%s", num2);

    result = addLongNumbers(num1, num2);
    printf("Sum: %s\n", result);

    free(result);
    return 0;
}

// Add two long positive integers represented as strings
char* addLongNumbers(const char *num1, const char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;
    char *result = (char *)malloc((maxLen + 2) * sizeof(char)); // +1 for carry, +1 for null terminator
    int carry = 0, sum, i, j, k;

    if (!result) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    result[maxLen + 1] = '\0'; // Null-terminate the result string

    i = len1 - 1;
    j = len2 - 1;
    k = maxLen;

    while (i >= 0 || j >= 0 || carry) {
        sum = carry;

        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }

        if (j >= 0) {
            sum += num2[j] - '0';
            j--;
        }

        carry = sum / 10;
        result[k] = (sum % 10) + '0';
        k--;
    }

    // Shift result to the start of the string
    return &result[k + 1];
}
