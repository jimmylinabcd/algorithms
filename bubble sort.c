#include <stdio.h>
#include <time.h>

int main(){
    int unsorted[] = {6,5,12,789,3,123,7832,245,782,882,98453,67,7878,35654,345,2345,6537,3457,345,643,56,2,2345,23,7,658,3,567};

    int length = sizeof(unsorted) / sizeof(unsorted[0]);
    
    clock_t begin = clock();

    int *p1, *p2;
    for (int i = 0; i < length; i++){
        for (int x = 0; x < (length - 1); x++){
            if (unsorted[x] > unsorted[x + 1]){
                p1 = &unsorted[x];
                p2 = &unsorted[x + 1];

                *p1 = *p1 + *p2;
                *p2 = *p1 - *p2;
                *p1 = *p1 - *p2;
            }
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    for (int i = 0; i < length; i++){
        printf("%d,", unsorted[i]);
    }
    printf("\nTook %f seconds", time_spent);
    return 0;
}