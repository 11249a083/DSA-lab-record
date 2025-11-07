#include <stdio.h>

int main() {
    int arr[100], n, key, low, high, mid, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            printf("Element %d found at position %d\n", key, mid + 1);
            found = 1;
            break;
        }
        else if(arr[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if(found == 0) {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
