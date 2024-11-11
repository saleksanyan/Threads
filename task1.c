#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
    printf("Thread %d is running\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
