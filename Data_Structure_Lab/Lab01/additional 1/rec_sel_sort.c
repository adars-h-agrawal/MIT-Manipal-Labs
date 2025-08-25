#include <stdio.h>

void selectionSort(int arr[], int n, int index){
    if(index == n)
        return;

    // Find the minimum element in remaining unsorted array
    int min_index = index;
    for(int j = index + 1; j < n; j++){
        if(arr[j] < arr[min_index])
            min_index = j;
    }

    // Swap the found minimum element with the first element
    int temp = arr[min_index];
    arr[min_index] = arr[index];
    arr[index] = temp;

    // Move the boundary of unsorted subarray and sort the remaining array
    selectionSort(arr, n, index + 1);
}

int main(){
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements : ");
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    selectionSort(arr, n, 0);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}