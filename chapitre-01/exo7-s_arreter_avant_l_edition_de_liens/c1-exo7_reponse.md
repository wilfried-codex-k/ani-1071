Commande utilisée :

clang++ -c bonjour.cpp

Cela produit un fichier bonjour.o.

Tentative de lancement :

./bonjour.o

Résultat :

Le système refuse de lancer le fichier : ce n'est pas un exécutable.
Message typique : bash: ./bonjour.o: cannot execute binary file

Explication :

L'option -c arrête la compilation après la production du fichier objet.
Le fichier .o contient du code machine, mais pas encore un programme
complet : il manque l'édition de liens, qui assemble le code objet avec
la bibliothèque C et le point d'entrée. Sans cette étape, le fichier
n'est pas exécutable.
