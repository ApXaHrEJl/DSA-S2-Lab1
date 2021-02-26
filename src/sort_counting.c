#include <inttypes.h>
#include <stdlib.h>

void sort(uint32_t* arr, int n)
{
    uint32_t* arr2 = (uint32_t*)calloc(100001, sizeof(uint32_t));
    for (int i = 0; i < n; i++) {
        arr2[arr[i]]++;
    }
    int k = 0;
    for (int i = 1; i < 100001; i++) {
        while (arr2[i] > 0) {
            arr[k] = i;
            k++;
            arr2[i] --;
        }
    }
    free(arr2);
}
