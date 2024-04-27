#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// D�claration de la fonction ex�cut�e par le thread
void *print_message(void *data) {
    // Cast du pointeur g�n�rique vers un pointeur de cha�ne de caract�res
    char *msg = (char *) data;
    // Affichage du message pass� en argument
    printf("Message : %s ", msg);
    // Renvoi de NULL, car la fonction ne renvoie rien
    return NULL;
}

int main() {
    pthread_t thread; // D�claration de la variable du thread
    char *msg = "Bonjour tout le monde "; // Message � afficher dans le thread

    // Cr�ation du thread, avec v�rification d'erreur
    if (pthread_create(&thread, NULL, print_message, msg) != 0) {
        perror("ERROR404"); // Affichage d'un message d'erreur en cas de probl�me lors de la cr�ation du thread
        return EXIT_FAILURE; // Sortie du programme avec un code d'erreur
    }

    // Attente de la fin du thread
    pthread_join(thread, NULL);

    return EXIT_SUCCESS; // Sortie du programme avec un code de succ�s
}


