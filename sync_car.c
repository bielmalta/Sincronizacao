#include <pthread.h>

typedef struct station {
    pthread_mutex_t mutex;
    pthread_cond_t passageiros;
    pthread_cond_t vagao;

    int esperando;
    int assentos;
    int embarcando;
}station;

void station_init(struct station *station) {
    pthread_mutex_init(&station->mutex, NULL);
    pthread_cond_init(&station->passageiros, NULL);
    pthread_cond_init(&station->vagao, NULL);

    station->esperando = 0;
    station->assentos = 0;
    station->embarcando = 0;
}

void station_wait_for_car(station *station){
    pthread_mutex_lock(&station->mutex);

    while (station->assentos == 0) {
        pthread_cond_wait(&station->passageiros, &station->mutex);
    }

    station->esperando--;
    station->assentos--;
    station->embarcando++;

    pthread_mutex_unlock(&station->mutex);
}


void station_on_board(struct station *station) {
    pthread_mutex_lock(&station->mutex);

    station->embarcando--;

    if (station->embarcando == 0) {
        pthread_cond_signal(&station->vagao);
    }

    pthread_mutex_unlock(&station->mutex);
}
