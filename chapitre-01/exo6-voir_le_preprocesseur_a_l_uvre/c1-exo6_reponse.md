Commande utilisée :

clang++ -E bonjour.cpp > sortie.txt

Puis comptage des lignes de sortie.txt :

wc -l sortie.txt

Écart observé :

Le fichier sortie.txt contient beaucoup plus de six lignes.
La commande -E exécute uniquement le préprocesseur : elle remplace
chaque #include par tout le contenu du fichier d'en-tête correspondant.
Le fichier <cstdio> contient à lui seul des centaines de lignes de
déclarations, de macros et de commentaires. Le fichier final est donc
très long, même si notre source ne faisait que six lignes.

Le préprocesseur ne compile pas : il ne fait que préparer le texte.
