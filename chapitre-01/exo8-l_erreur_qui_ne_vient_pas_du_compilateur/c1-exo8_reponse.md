Avec -c, la compilation réussit : le compilateur ne fait que vérifier
la syntaxe et produire le fichier objet. Il ne cherche pas encore la
définition de la fonction calculer.
Sans -c, l'édition de liens échoue car le linker ne trouve pas le
corps de la fonction calculer. C'est donc l'éditeur de liens qui
signale l'erreur, pas le compilateur.