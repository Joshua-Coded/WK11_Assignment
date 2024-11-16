#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10

typedef struct {
    long start;
    long end;
    int thread_id;
} ThreadData;

void* list_numbers(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    long start = data->start;
    long end = data->end;
    int thread_id = data->thread_id;

    for (long i = start; i < end; i++) {
        // Uncomment the line below to see the numbers being processed
        // printf("Thread %d: %ld\n", thread_id, i);
    }

    printf("Thread %d finished processing from %ld to %ld\n", thread_id, start, end - 1);
    return NULL;
}

int main() {
    long n;
    printf("Enter the value of n (minimum 1,000,000): ");
    scanf("%ld", &n);

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    long range_size = n / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].start = i * range_size;
        thread_data[i].end = (i == NUM_THREADS - 1) ? n + 1 : (i + 1) * range_size;
        thread_data[i].thread_id = i;

        pthread_create(&threads[i], NULL, list_numbers, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have completed their tasks.\n");
    return 0;
}

