#include <pthread.h>

struct station {
    pthread_mutex_t mutex;
    pthread_cond_t passageiros;
    pthread_cond_t vagao;

    int esperando;
    int assentos;
    int embarcando;
};

void station_init(struct station *station) {
    pthread_mutex_init(&station->mutex, NULL);
    pthread_cond_init(&station->passageiros, NULL);
    pthread_cond_init(&station->vagao, NULL);

    station->esperando = 0;
    station->assentos = 0;
    station->embarcando = 0;
}