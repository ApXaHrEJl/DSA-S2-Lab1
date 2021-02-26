#include "sort.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{
    srand(wtime());
    int size = 0;
    uint32_t* arr = NULL;
    for (int i = 1; i <= 20; i++) {
        size += 50000;
        arr = (uint32_t*)calloc(size, sizeof(uint32_t));
        for (int k = 0; k < size; k++) {
            arr[k] = rand() % 100000;
        }
        double curr = wtime();
        sort(arr, size);
        curr = wtime() - curr;
        printf("%d\t%d\t\t%lf\n", i, size, curr);
        free(arr);
    }
    return 0;
}
