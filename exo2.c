#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Déclaration de la fonction exécutée par le thread
void *print_message(void *data) {
    // Cast du pointeur générique vers un pointeur de chaîne de caractères
    char *msg = (char *) data;
    // Affichage du message passé en argument
    printf("Message : %s ", msg);
    // Renvoi de NULL, car la fonction ne renvoie rien
    return NULL;
}

int main() {
    pthread_t thread; // Déclaration de la variable du thread
    char *msg = "Bonjour tout le monde "; // Message à afficher dans le thread

    // Création du thread, avec vérification d'erreur
    if (pthread_create(&thread, NULL, print_message, msg) != 0) {
        perror("ERROR404"); // Affichage d'un message d'erreur en cas de problème lors de la création du thread
        return EXIT_FAILURE; // Sortie du programme avec un code d'erreur
    }

    // Attente de la fin du thread
    pthread_join(thread, NULL);

    return EXIT_SUCCESS; // Sortie du programme avec un code de succès
}


