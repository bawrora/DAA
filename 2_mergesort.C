#include <stdio.h>
#include <conio.h>
#define MAX 100
#define INF 32767
void merge(int arr[], int start, int mid, int end) {
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[51], right[51]; 
    for (i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];
    left[n1] = INF;
    right[n2] = INF;
    i = 0; j = 0;
    for (k = start; k <= end; k++) {
        if (left[i] <= right[j])
            arr[k] = left[i++];
        else
            arr[k] = right[j++];
    }
}
void mergesort(int arr[], int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
void main(void) {
    int arr[MAX], len, i;
    clrscr(); 
    printf("Enter the number of elements (max 100): ");
    scanf("%d", &len);
    if (len > MAX || len > 100) {
        printf("Array size exceeds maximum limit.");
        getch();
        return;
    }
    printf("Enter the elements:\n");
    for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, len - 1);
    printf("Sorted array:\n");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    getch(); 
}
