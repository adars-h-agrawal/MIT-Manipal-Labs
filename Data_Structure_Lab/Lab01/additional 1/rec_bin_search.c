#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key){
    if(high < low)
        return -1; // Element is not present in the array

    int mid = (high + low) / 2;

    // If the element is present at the middle itself
    if (arr[mid] == key)
        return mid;

    // If the element is smaller than mid, then it can only be in the left subarray
    if (arr[mid] > key)
        return binarySearch(arr, low, mid - 1, key);

    // Else the element can only be in the right subarray
    return binarySearch(arr, mid + 1, high, key);
}

int main() {
    int n, key;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements : ");
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("Enter element to find : ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);
    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in array\n");
    return 0;
}