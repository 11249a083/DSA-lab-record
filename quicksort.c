#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high, temp;

    while (1) {
        while (i <= high && arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < j) {
            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        } else break;
    }
    temp = arr[low]; arr[low] = arr[j]; arr[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int loc = partition(arr, low, high);
        quickSort(arr, low, loc - 1);
        quickSort(arr, loc + 1, high);
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
