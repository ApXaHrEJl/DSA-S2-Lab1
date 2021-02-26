#include <inttypes.h>
#include <stdlib.h>

void merge(uint32_t* arr, uint32_t* arr2, int low, int mid, int high)
{
    for (int i = low; i < high; i++) {
        arr2[i] = arr[i];
    }
    int l = low;
    int r = mid + 1;
    int i = low;
    while ((l <= mid) && (r <= high)) {
        if (arr[l] <= arr[r]) {
            arr[i] = arr2[l];
            l++;
        } else {
            arr[i] = arr2[r];
            r++;
        }
        i++;
    }
    while (l <= mid) {
        arr[i] = arr2[l];
        l++;
        i++;
    }
    while (r <= high) {
        arr[i] = arr2[r];
        r++;
        i++;
    }
}

void merge_sort(uint32_t* arr, uint32_t* arr2, int low, int high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, arr2, low, mid);
        merge_sort(arr, arr2, mid + 1, high);
        merge(arr, arr2, low, mid, high);
    }
}

void sort(uint32_t* arr, int n)
{
    uint32_t* arr2 = (uint32_t*)calloc(n, sizeof(uint32_t));
    merge_sort(arr, arr2, 0, n);
    free(arr2);
}
