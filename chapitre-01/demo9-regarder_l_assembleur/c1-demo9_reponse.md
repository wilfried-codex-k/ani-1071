Programme source :

#include <cstdio>

int main() {
    printf("Bonjour\n");
    return 0;
}

Génération :

clang++ -S c1-demo9_main.cpp

ou :

g++ -S c1-demo9_main.cpp

Cela produit un fichier .s contenant l'assembleur lisible.

Trois éléments identifiés :

1. L'étiquette main : elle marque le point d'entrée de la fonction. On la retrouve sous la forme main: ou _main: selon la plateforme.

2. L'appel à printf : il apparaît sous la forme call printf (ou call _printf). C'est la traduction de l'appel à la fonction de la bibliothèque C.

3. La valeur de retour : return 0; se traduit par le chargement de la valeur 0 dans le registre de retour, suivi d'une instruction ret ou d'un saut vers l'épilogue de la fonction.

Le texte C++ a été transformé en une suite d'instructions proches du processeur. La plupart des programmeurs n'ont jamais besoin de lire cet assembleur, mais une fois dans sa vie il est utile de constater que le code source est devenu des ordres exécutables.
