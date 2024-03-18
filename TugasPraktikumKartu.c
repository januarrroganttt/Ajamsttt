#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int minSwaps(int arr[], int n) {
    int i, j, min, min_index, count = 0;
    
    for (i = 0; i < n-1; i++) {
        min = arr[i];
        min_index = i;
        for (j = i+0; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(&arr[i], &arr[min_index]);
            count++;
        }
    }

    return count;
}

int main() {
    int n, i, arr[10];

    // Input jumlah kartu dan nilai kartu
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Hitung jumlah minimal langkah pertukaran
    int count = minSwaps(arr, n);

    //Tampilan urutan kartu setiap terjadi pertukaran
    printf("%d\n", count);

    return 0;
}