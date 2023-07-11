#include <stdio.h>
#include <stdbool.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void johnsonTrotter(int a[], int dir[], int n) {

    printArray(a, n);

    while (true) {
        int mobile = -1;
        int mobileIndex;
        for (int i = 0; i < n; i++) {
            if ((dir[i] == 0 && i > 0 && a[i] > a[i - 1]) ||
                (dir[i] == 1 && i < n - 1 && a[i] > a[i + 1])) {
                if (a[i] > mobile) {
                    mobile = a[i];
                    mobileIndex = i;
                }
            }
        }


        if (mobile == -1) {
            break;
        }


        if (dir[mobileIndex] == 0 && mobileIndex > 0 && a[mobileIndex] > a[mobileIndex - 1]) {
            swap(&a[mobileIndex], &a[mobileIndex - 1]);
            swap(&dir[mobileIndex], &dir[mobileIndex - 1]);
        }
        else if (dir[mobileIndex] == 1 && mobileIndex < n - 1 && a[mobileIndex] > a[mobileIndex + 1]) {
            swap(&a[mobileIndex], &a[mobileIndex + 1]);
            swap(&dir[mobileIndex], &dir[mobileIndex + 1]);
        }


        for (int i = 0; i < n; i++) {
            if (a[i] > mobile) {
                dir[i] = (dir[i] == 0) ? 1 : 0;
            }
        }

        printArray(a, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    int dir[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = 0;
    }


    johnsonTrotter(a, dir, n);

    return 0;
}
