#include "util.h"

void remplirTableau(int tableau[], const int taille, const int min, const int max) {
    for (int i = 0; i < taille; i++) {
        tableau[i] = rand(min, max);
    }
}

void afficherTableau(const int tableau[], const int taille) {
    for (int i = 0; i < taille; i++) {
        cout << tableau[i] << " ";
    }
    cout << endl << endl;
}

bool estTrie(const int tableau[], const int taille) {
    for (int i = 1; i < taille; i++) {
        if (tableau[i] < tableau[i - 1]) {
            return false;
        }
    }
    return true;
}

void srand() {
    srand(time(NULL));
}

int rand(const int min, const int max) {
    int difference = max - min;
    int maxAcceptedValue = RAND_MAX - RAND_MAX % difference;
    int randomNumber;
    do {
        randomNumber = rand();
    } while (randomNumber > maxAcceptedValue);

    return randomNumber % difference + min;
}
