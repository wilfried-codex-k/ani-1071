Programme de référence :

#include <cstdio>

int main() {
    printf("Bonjour\n");
    return 0;
}

Programme avec dix en-têtes :

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cstdarg>
#include <cassert>

int main() {
    printf("Bonjour\n");
    return 0;
}

Tableau des six mesures :

Programme simple   | clang++ -E         | ...
Programme simple   | clang++ -c         | ...
Programme simple   | compilation totale | ...
Dix en-têtes       | clang++ -E         | ...
Dix en-têtes       | clang++ -c         | ...
Dix en-têtes       | compilation totale | ...

Étape dominante : le préprocessing (-E) domine largement lorsque le programme inclut beaucoup d'en-têtes, car chaque #include est remplacé par le contenu complet du fichier.
