
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0, count = 0;

sem_t mutex, full, empty;

void wait(sem_t *s) { sem_wait(s); }
void signal_sem(sem_t *s) { sem_post(s); }

void *producer(void *arg) {
    if (count == BUFFER_SIZE) {
        printf("Buffer is full! Producer cannot produce.\n");
        return NULL;
    }

    wait(&empty);
    wait(&mutex);

    buffer[in] = in + 1;
    printf("Producer produced: Item %d at position %d\n", buffer[in], in);
    in = (in + 1) % BUFFER_SIZE;
    count++;

    signal_sem(&mutex);
    signal_sem(&full);
    return NULL;
}

void *consumer(void *arg) {
    if (count == 0) {
        printf("Buffer is empty! Consumer cannot consume.\n");
        return NULL;
    }

    wait(&full);
    wait(&mutex);

    int item = buffer[out];
    printf("Consumer consumed: Item %d from position %d\n", item, out);
    out = (out + 1) % BUFFER_SIZE;
    count--;

    signal_sem(&mutex);
    signal_sem(&empty);
    return NULL;
}

int main() {
    pthread_t thread;
    int choice;

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);

    while (1) {
        printf("Enter 1. Producer 2. Consumer 3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pthread_create(&thread, NULL, producer, NULL);
                pthread_join(thread, NULL);
                break;
            case 2:
                pthread_create(&thread, NULL, consumer, NULL);
                pthread_join(thread, NULL);
                break;
            case 3:
                sem_destroy(&mutex);
                sem_destroy(&full);
                sem_destroy(&empty);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

