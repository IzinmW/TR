#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// D�finition de la premi�re t�che ex�cut�e par le premier thread
void *tache1(void *arg) {
    int i = 0;
    // Boucle d'ex�cution de la t�che
    while (i < 5) {
        printf("Execution de Tache 1 \n");
        sleep(1); // Pause d'une seconde
        i++; // Incr�mentation du compteur
    }
    return NULL; // Fin de la fonction
}

// D�finition de la deuxi�me t�che ex�cut�e par le deuxi�me thread
void *tache2(void *arg) {
    int j = 0;
    // Boucle d'ex�cution de la t�che
    while (j < 3) {
        printf("Execution de Tache 2 \n");
        sleep(2); // Pause de deux secondes
        j++; // Incr�mentation du compteur
    }
    return NULL; // Fin de la fonction
}

int main() {
    pthread_t thread1, thread2; // D�claration des variables des threads

    // Cr�ation des thread 1 pour ex�cuter les t�ches
    pthread_create(&thread1, NULL, tache1, NULL);
    // Attente de la fin de l'ex�cution des thread 1
     pthread_join(thread1, NULL);
      // Cr�ation des thread 2 pour ex�cuter les t�ches
    pthread_create(&thread2, NULL, tache2, NULL);
    // Attente de la fin de l'ex�cution des thread 2
    pthread_join(thread2, NULL);

    return EXIT_SUCCESS; // Sortie du programme avec un code de succ�s
}

