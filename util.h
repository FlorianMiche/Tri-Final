#ifndef _UTIL_H_
 #define _UTIL_H_

 #include <cstdlib>
 #include <iostream>
 #include <time.h>

 using namespace std;

 void remplirTableau(int tableau[], const int taille, const int min, const int max);

 void afficherTableau(const int tableau[], const int taille);

 bool estTrie(const int tableau[], const int taille);

 void srand();

 int rand(const int min, const int max);

 #endif
