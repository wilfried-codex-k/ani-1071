Copie du programme, puis suppression de tous les points-virgules :

#include <cstdio>

int main() {
    printf("Bonjour\n")
    return 0
}

Compilation :

clang++ -std=c++17 -Wall c1-exo9_main.cpp -o programme

Messages observés : plusieurs erreurs sont signalées en cascade,
souvent trois ou quatre, pointant vers des lignes différentes.

Ensuite, on remet un seul point-virgule, celui de la première erreur
signalée, c'est-à-dire après printf("Bonjour\n") :

#include <cstdio>

int main() {
    printf("Bonjour\n");
    return 0
}

Recompilation : le nombre de messages diminue nettement. Il ne reste
plus qu'une seule erreur, celle qui concerne la ligne return 0.

Observation :

Une seule faute peut provoquer plusieurs messages d'erreur. Le
compilateur signale souvent une erreur sur la ligne suivante, car
il attend la fin de l'instruction précédente. Quand on corrige la
première erreur signalée, beaucoup d'autres disparaissent d'elles-mêmes.
C'est une leçon importante : toujours corriger la première erreur en
premier, puis recompiler.
