Erreur 1 : point-virgule retiré
Message : error: expected ';' after return statement
Ligne signalée : return 0
Ligne réellement fautive : return 0
Étape : compilation (analyse syntaxique)

Erreur 2 : Printf au lieu de printf
Message : error: use of undeclared identifier 'Printf'
Ligne signalée : Printf("Bonjour\n");
Ligne réellement fautive : Printf("Bonjour\n");
Étape : compilation (analyse sémantique)

Erreur 3 : #include <cstdio> retiré
Message : error: use of undeclared identifier 'printf'
Ligne signalée : printf("Bonjour\n");
Ligne réellement fautive : printf("Bonjour\n");
Étape : compilation (analyse sémantique)