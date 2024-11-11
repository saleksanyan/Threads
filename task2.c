#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 6

int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6};

void* sum_array_part(void* arg) {
    int start = ((int*)arg)[0];
    int end = ((int*)arg)[1];
    int sum = 0;

    for (int i = start; i < end; i++) {
        sum += arr[i];
    }
    printf("Partial sum from index %d to %d is %d\n", start, end-1, sum);
    return NULL;
}

int main() {
    pthread_t threads[2];
    int range1[2] = {0, ARRAY_SIZE / 2};
    int range2[2] = {ARRAY_SIZE / 2, ARRAY_SIZE};
    pthread_create(&threads[0], NULL, sum_array_part, range1);
    pthread_create(&threads[1], NULL, sum_array_part, range2);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;
}

