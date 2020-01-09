#include "main.h"

using namespace std;

int main(int argc, char *argv[]) {
    SetConsoleOutputCP(65001);
    srand();

    //COMPLETE TAB MANUALLY
    //************************************************
    int tableau[9] = {7, 8, 7, 4, 3, 10, 4, 1, -2};
    afficherTableau(tableau, 9);
    //************************************************

    //COMPLETE TAB AUTO
    //************************************************
    //const int sizeTab = 20;
    //int tableau[sizeTab];
    //remplirTableau(tableau, 9, -99, sizeTab);
    //afficherTableau(tableau, sizeTab);
    //myTriRapide(tableau, 0, sizeTab);
    //cout << "Après le tri :" << endl;
    //afficherTableau(tableau, sizeTab);
    //cout << (estTrie(tableau, sizeTab) ? "Trié !" : "!!! ERREUR !!!") << endl << endl;
    //************************************************

    cout << "Tri rapide" << endl;
    //triRapideProf(tableau, 0, 9);
    myTriRapide(tableau, 0, 9);

    //cout << "Tri bulle" << endl;
    //triBulle(tableau, 0, 9);

    //cout << "Tri gnome" << endl;
    //triGnome(tableau, 0, 9);

    //cout << "Tri insertion" << endl;
    //triInsertionProf(tableau, 0, 9);
    //myTriInsertion(tableau, 0, 9);

    //cout << "Tri sélection" << endl;
    //triSelection(tableau, 0, 9);

    //cout << "Tri fusion" << endl;
    //triFusion(tableau, 0, 9);

    //cout << "Tri comptage" << endl;
    //triComptage(tableau, 0, 9);


    //cout << "Tri shaker" << endl;
    //triShaker(tableau, 0, 9);

    cout << "Après le tri :" << endl;
    afficherTableau(tableau, 9);
    cout << (estTrie(tableau, 9) ? "Trié !" : "!!! ERREUR !!!") << endl << endl;

    return 0;
}
