#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Définition de la première tâche exécutée par le premier thread
void *tache1(void *arg) {
    int i = 0;
    // Boucle d'exécution de la tâche
    while (i < 5) {
        printf("Execution de Tache 1 \n");
        sleep(1); // Pause d'une seconde
        i++; // Incrémentation du compteur
    }
    return NULL; // Fin de la fonction
}

// Définition de la deuxième tâche exécutée par le deuxième thread
void *tache2(void *arg) {
    int j = 0;
    // Boucle d'exécution de la tâche
    while (j < 3) {
        printf("Execution de Tache 2 \n");
        sleep(2); // Pause de deux secondes
        j++; // Incrémentation du compteur
    }
    return NULL; // Fin de la fonction
}

int main() {
    pthread_t thread1, thread2; // Déclaration des variables des threads

    // Création des thread 1 pour exécuter les tâches
    pthread_create(&thread1, NULL, tache1, NULL);
    // Attente de la fin de l'exécution des thread 1
     pthread_join(thread1, NULL);
      // Création des thread 2 pour exécuter les tâches
    pthread_create(&thread2, NULL, tache2, NULL);
    // Attente de la fin de l'exécution des thread 2
    pthread_join(thread2, NULL);

    return EXIT_SUCCESS; // Sortie du programme avec un code de succès
}

