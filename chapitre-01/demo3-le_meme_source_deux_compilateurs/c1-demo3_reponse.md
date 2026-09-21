Programme utilisé :

#include <cstdio>

int main() {
    printf("Bonjour\n");
    return 0;
}

Compilation :

clang++ -std=c++17 -Wall c1-demo3_main.cpp -o prog_clang
g++     -std=c++17 -Wall c1-demo3_main.cpp -o prog_gcc

Tailles observées :
prog_clang : taille obtenue
prog_gcc   : taille obtenue

Les deux exécutables affichent exactement Bonjour.

Conclusion : le langage C++ garantit le comportement du programme (ce qu'il fait), mais ne garantit ni la taille exacte du binaire ni le code machine produit. Chaque compilateur est libre de générer le binaire à sa manière, tant que le résultat observable reste conforme au standard.
