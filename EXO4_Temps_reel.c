#include <stdio.h>       // Inclut la bibliothèque standard d'entrée/sortie
#include <stdlib.h>      // Inclut la bibliothèque standard de fonctions utilitaires
#include <pthread.h>     // Inclut la bibliothèque de threads POSIX
#include <string.h>      // Inclut la bibliothèque de fonctions de manipulation de chaînes de caractères

// Fonction exécutée par le premier thread
void *thread_func1(void *arg) {
    printf("Thread 1: Bonjour Abdo !\n");    // Affiche "Bonjour Abdo !" sur la sortie standard
    return NULL;                              // Termine la fonction et retourne NULL
}

// Fonction exécutée par le deuxième thread
void *thread_func2(void *arg) {
    printf("Thread 2: Salut Abdo  !\n");      // Affiche "Salut Abdo !" sur la sortie standard
    return NULL;                              // Termine la fonction et retourne NULL
}

// Fonction principale du programme
int main(int arg, char *argv[]) {
    pthread_t t1, t2;                          // Déclare les identifiants des threads
    
    // Crée un nouveau thread qui exécutera thread_func1
    pthread_create(&t1, NULL, thread_func1, NULL);
    
    // Attend la fin d'exécution du thread t1
    pthread_join(t1, NULL);
    
    // Crée un nouveau thread qui exécutera thread_func2
    pthread_create(&t2, NULL, thread_func2, NULL);
    
    // Attend la fin d'exécution du thread t2
    pthread_join(t2, NULL);
    
    return EXIT_SUCCESS;                       // Termine le programme avec succès
}


