#include "tri.h"

void echange(int tableau[], const int a, const int b)
{
     int tmp = tableau[a];
     tableau[a] = tableau[b];
     tableau[b] = tmp;
}

//Try Tri Shaker
void triShaker(int tableau[], const int debut, const int fin)
{
  bool permutation;

  do
  {
    permutation = false;
    for (int i = debut; i < fin; i++)
    {
      if (tableau[i] > tableau[i+1])
      {
        echange(tableau, i, i+1);
        permutation = true;
      }
    }

    for (int i = fin; i > debut; i--)
    {
      if (tableau[i] < tableau[i-1])
      {
        echange(tableau, i, i-1);
        permutation = true;
      }
    }
  }
  while (permutation);
}


//TRI RAPIDE
//------------------------------------------------------------------------------

void triRapideProf(int tableau[], const int debut, const int fin)
{
   if(fin - debut > 1)
   {
     //Choisir le pivot pour notre trie
     int pivot = debut;
     int markerFin = fin;

     //Séparer les valeur par apport au pivot
     while (pivot+1 < markerFin)
     {
       if (tableau[pivot+1] < tableau[pivot])
       {
         echange(tableau, pivot, pivot+1);
         pivot++;
       }
       else
       {
         markerFin--;
         echange(tableau, pivot+1, markerFin);
       }
     }
     //On trie le tableau de gauche du pivot
     triRapideProf(tableau, debut, pivot);
     //On trie le tableau de droite du pivot
     triRapideProf(tableau, pivot+1, fin);
   }
}

void myTriRapide(int tableau[], const int debut, const int fin)
{
   if(fin - debut > 1)
   {
     //Choisir le pivot pour notre trie
     int pivot = debut;
     int markerFin = fin;

     //Séparer les valeur par apport au pivot
     while (pivot+1 < markerFin)
     {
       if (tableau[pivot+1] < tableau[pivot])
       {
         echange(tableau, pivot, pivot+1);
         pivot++;
       }
       else
       {
         markerFin--;
         echange(tableau, pivot+1, markerFin);
       }
     }
     //On trie le tableau de gauche du pivot
     myTriRapide(tableau, debut, pivot);
     //On trie le tableau de droite du pivot
     myTriRapide(tableau, pivot+1, fin);
   }
 }

//------------------------------------------------------------------------------

void triBulle(int tableau[], const int debut, const int fin)
{
      int passage = fin;
      bool echangeFait;
      do {
          echangeFait = false;
          for (int element = debut + 1; element < passage; element++) {
              if (tableau[element - 1] > tableau[element]) {
                  echange(tableau, element - 1, element);
                  echangeFait = true;
              }
          }
          passage--;
      } while (echangeFait && passage > debut);
  }

void triGnome(int tableau[], const int debut, const int fin)
{
      int element = debut;
      while (element < fin - 1) {
          if (element < debut || tableau[element] <= tableau[element + 1]) {
              element++;
          }
          else {
              echange(tableau, element, element + 1);
              element--;
          }
      }
  }

//TRI INSERTION
//------------------------------------------------------------------------------

void triInsertionProf(int tableau[], const int debut, const int fin)
{
      for (int passage = debut + 1; passage < fin; passage++) {
          int element = passage;
          while (element > debut && tableau[element] < tableau[element - 1]) {
              echange(tableau, element, element - 1);
              element--;
          }
      }
  }

  void myTriInsertion(int tableau[], const int debut, const int fin)
  {
    for (int element = debut + 1; element < fin; element++)
    {
      int checkPos = element;
      while (debut < checkPos && tableau[checkPos] < tableau[checkPos-1])
      {
        echange(tableau, checkPos, checkPos - 1);
        checkPos--;
      }
    }
  }
//------------------------------------------------------------------------------

void triSelection(int tableau[], const int debut, const int fin)
{
      for (int passage = debut; passage < fin; passage++) {
          int min = passage;
          for (int element = passage; element < fin; element++) {
              if (tableau[element] < tableau[min])
              {
                  min = element;
              }
          }
          echange(tableau, passage, min);
      }
  }

void triFusion(int tableau[], const int debut, const int fin)
{
      // Si le tableau contient au moins 1 valeur
      if (debut < fin - 1) {
          // On trouve le début
          int milieu = (debut + fin) / 2;
          // on trie séparément les deux côtés
          triFusion(tableau, debut, milieu);
          triFusion(tableau, milieu, fin);

          // On place deux marqueurs sur le début des deux moitiés
          int premier = debut;
          int deuxieme = milieu;

          // On crée un tableau temporaire
          int copie[fin - debut];
          int i = 0;

          while (i < fin - debut) {
              // Si la première partie a été entièrement consommée
              if (premier == milieu)
              {
                  // ... on place le premier élément de la seconde partie dans le tableau temporaire
                  copie[i] = tableau[deuxieme];
                  // ... et on le consomme
                  deuxieme++;
              }
              // Idem si la seconde partie a été entièrement consommée
              else if (deuxieme == fin)
              {
                  copie[i] = tableau[premier];
                  premier++;
              }
              // Si l'élément de tête de la première partie est le plus petit des deux
              else if (tableau[premier] <= tableau[deuxieme]) {
                  copie[i] = tableau[premier];
                  premier++;
              }
              // Si l'élément de tête de la seconde partie est le plus petit des deux
              else if (tableau[deuxieme] <= tableau[premier]) {
                  copie[i] = tableau[deuxieme];
                  deuxieme++;
              }

              i++;
          }

          // On vient remplacer la portion du tableau initial par le tableau temporaire
          for (i = 0; i < fin - debut; i++) {
              tableau[debut + i] = copie[i];
          }
      }
  }

void triComptage(int tableau[], int debut, int fin)
{
       int valeurMin = tableau[debut];
       int valeurMax = tableau[debut];
       for (int i = debut; i < fin; i++) {
           if (tableau[i] < valeurMin) {
               valeurMin = tableau[i];
           }
           else if (tableau[i] > valeurMax) {
               valeurMax = tableau[i];
           }
       }

       int comptage[valeurMax - valeurMin + 1];
       for (int i = 0; i < valeurMax - valeurMin + 1; i++) {
           comptage[i] = 0;
       }

       for (int i = debut; i < fin; i++) {
           comptage[tableau[i] - valeurMin]++;
       }

       for (int i = 1; i < valeurMax - valeurMin + 1; i++) {
           comptage[i] += comptage[i - 1];
       }

       int nouveauTableau[fin - debut];

       for (int i = debut; i < fin; i++) {
           int valeur = tableau[i];
           comptage[valeur - valeurMin]--;
           nouveauTableau[comptage[valeur - valeurMin]] = valeur;
       }

       for(int i = debut; i < fin; i++) {
           tableau[i] = nouveauTableau[i - debut];
       }
   }
