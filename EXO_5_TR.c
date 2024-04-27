#include <stdio.h>       // Inclut la bibliothèque standard d'entrée/sortie
#include <stdlib.h>      // Inclut la bibliothèque standard de fonctions utilitaires
#include <pthread.h>     // Inclut la bibliothèque de threads POSIX
#include <unistd.h>      // Inclut la bibliothèque pour la fonction sleep()

// Structure représentant une tâche périodique
typedef struct {
    int id;          // Identifiant de la tâche
    int period;      // Période d'exécution de la tâche
} PeriodicTask;

// Fonction exécutée par chaque thread de tâche périodique
void *taskFunction(void *arg) {
    PeriodicTask *task = (PeriodicTask *)arg;  // Convertit l'argument en un pointeur vers PeriodicTask

    while (1) {                                // Boucle infinie
        sleep(task->period);                   // Attend la période spécifiée avant de continuer
        printf("la tache %d est executee\n", task->id); // Affiche le message de tâche exécutée
    }
    pthread_exit(NULL);  // Termine le thread
}

int main() {
    // Création des tâches périodiques
    PeriodicTask task1 = {1, 2};  // Tâche 1 avec période de 2 secondes
    PeriodicTask task2 = {2, 3};  // Tâche 2 avec période de 3 secondes

    // Création des threads pour exécuter les tâches
    pthread_t thread1, thread2;                      // Déclaration des identifiants de threads
    pthread_create(&thread1, NULL, taskFunction, (void *)&task1); // Création du premier thread avec task1
    pthread_create(&thread2, NULL, taskFunction, (void *)&task2); // Création du deuxième thread avec task2

    // Attente des threads (les tâches s'exécutent en arrière-plan)
    pthread_join(thread1, NULL);  // Attend la fin d'exécution du premier thread
    pthread_join(thread2, NULL);  // Attend la fin d'exécution du deuxième thread
    
    return 0;  // Fin du programme
}

