#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

pthread_mutex_t lock1, lock2;
time_t startA, startB;

void *processA(void *arg) {
    startA = time(NULL);

    // Tenta adquirir lock1
    while (pthread_mutex_trylock(&lock1) != 0) {
        if (time(NULL) - startA > 3) { // Limite de 3 segundos
            printf("Deadlock detected in Process A, could not acquire lock 1\n");
            return NULL;
        }
        usleep(100000);  // Espera 100ms antes de tentar novamente
    }
    printf("Process A acquired lock 1\n");

    sleep(2);  // Simula algum processamento

    // Tenta adquirir lock2
    while (pthread_mutex_trylock(&lock2) != 0) {
        if (time(NULL) - startA > 3) {
            printf("Deadlock detected in Process A, releasing lock 1\n");
            pthread_mutex_unlock(&lock1);  // Libera lock1 para evitar deadlock
            return NULL;
        }
        usleep(100000);  // Espera 100ms antes de tentar novamente
    }
    printf("Process A acquired lock 2\n");

    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);

    return NULL;
}

void *processB(void *arg) {
    startB = time(NULL);

    // Tenta adquirir lock2
    while (pthread_mutex_trylock(&lock2) != 0) {
        if (time(NULL) - startB > 3) { // Limite de 3 segundos
            printf("Deadlock detected in Process B, could not acquire lock 2\n");
            return NULL;
        }
        usleep(100000);  // Espera 100ms antes de tentar novamente
    }
    printf("Process B acquired lock 2\n");

    sleep(2);  // Simula algum processamento

    // Tenta adquirir lock1
    while (pthread_mutex_trylock(&lock1) != 0) {
        if (time(NULL) - startB > 3) {
            printf("Deadlock detected in Process B, releasing lock 2\n");
            pthread_mutex_unlock(&lock2);  // Libera lock2 para evitar deadlock
            return NULL;
        }
        usleep(100000);  // Espera 100ms antes de tentar novamente
    }
    printf("Process B acquired lock 1\n");

    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);

    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);

    pthread_create(&t1, NULL, processA, NULL);
    pthread_create(&t2, NULL, processB, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);

    return 0;
}
