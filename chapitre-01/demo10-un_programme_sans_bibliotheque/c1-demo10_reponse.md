Compilation et exécution :

clang++ -std=c++17 -Wall c1-demo10_main.cpp -o prog
./prog
echo $?

Le code de sortie affiché est 7.

Comparaison de tailles :

Programme int main() { return 7; } : taille = ...
Programme qui affiche Bonjour    : taille = ...

Les deux exécutables sont très proches en taille : quelques centaines d'octets pour le programme minimal, un peu plus pour celui qui affiche « Bonjour » car il faut inclure le code de printf et lier la bibliothèque C standard.

Ce qui a été ajouté : le programme minimal est enrichi automatiquement par l'éditeur de liens. Il ajoute le point d'entrée de la bibliothèque C, la fonction _start, et parfois des informations de démarrage et d'arrêt. Tout cela est ajouté par le linker, pas par le programmeur.
