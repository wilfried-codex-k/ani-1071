Compilation avec -c :

clang++ -std=c++17 -Wall -c c1-exo8_main.cpp -o c1-exo8_main.o

Résultat : succès, aucun message.

Compilation sans -c :

clang++ -std=c++17 -Wall c1-exo8_main.cpp -o programme

Résultat : échec.
Message typique :

Undefined symbols for architecture x86_64:
  "calculer()", referenced from:
      _main in c1-exo8_main.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1

Explication :

Avec -c, le compilateur s'arrête après avoir produit le fichier objet.
Il ne cherche pas encore le corps de la fonction calculer : il se
contente de vérifier que la déclaration existe.

Sans -c, l'éditeur de liens (ld) entre en jeu. Il doit assembler tous
les symboles utilisés. Comme la fonction calculer n'est déclarée mais
jamais définie, le linker ne trouve pas son code et signale l'erreur.

C'est donc l'éditeur de liens qui parle ici, pas le compilateur.
