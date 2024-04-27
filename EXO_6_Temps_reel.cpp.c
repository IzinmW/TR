#include <stdio.h>       // Inclut la bibliothèque standard d'entrée/sortie
#include <stdlib.h>      // Inclut la bibliothèque standard de fonctions utilitaires
#include <pthread.h>     // Inclut la bibliothèque de threads POSIX

#define ARRAY_SIZE 10          // Taille du tableau d'entiers
#define NUM_THREADS 4          // Nombre de threads à utiliser
#define PART_SIZE (ARRAY_SIZE / NUM_THREADS) // Taille des parties du tableau

int array[ARRAY_SIZE];         // Tableau d'entiers
int total_sum = 0;             // Somme totale des éléments du tableau
pthread_mutex_t mutex;         // Verrou pour synchroniser l'accès à total_sum

// Structure contenant les informations nécessaires pour effectuer le calcul partiel
typedef struct {
    int start_index;           // Indice de début du sous-tableau
    int end_index;             // Indice de fin du sous-tableau
} PartialSumInfo;

// Fonction pour calculer la somme des éléments d'un sous-tableau du tableau global
void *sum_partial(void *arg) {
    PartialSumInfo *info = (PartialSumInfo *)arg; // Conversion de l'argument en pointeur PartialSumInfo
    int partial_sum = 0;                           // Variable pour stocker la somme partielle

    // Parcours du sous-tableau et calcul de la somme partielle
    for (int i = info->start_index; i < info->end_index; i++) {
        partial_sum += array[i];
    }

    // Verrouillage pour éviter les accès concurrents à total_sum
    pthread_mutex_lock(&mutex);
    total_sum += partial_sum;         // Mise à jour de la somme totale
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);  // Terminaison du thread
}

int main() {
    pthread_t threads[NUM_THREADS];         // Tableau de threads
    PartialSumInfo infos[NUM_THREADS];      // Tableau de structures pour chaque thread

    // Initialisation du tableau d'entiers avec des valeurs de 1 à ARRAY_SIZE
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;
    }

    // Initialisation du verrou
    pthread_mutex_init(&mutex, NULL);

    // Création des threads et division du tableau en parties
    for (int i = 0; i < NUM_THREADS; i++) {
        infos[i].start_index = i * PART_SIZE;             // Calcul de l'indice de début
        infos[i].end_index = (i + 1) * PART_SIZE;         // Calcul de l'indice de fin
        pthread_create(&threads[i], NULL, sum_partial, (void *)&infos[i]); // Création du thread
    }

    // Attente de la fin de l'exécution de tous les threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Affichage de la somme totale
    printf("La somme totale des elements du tableau est : %d\n", total_sum);

    // Destruction du verrou
    pthread_mutex_destroy(&mutex);

    return 0;  // Fin du programme
}

