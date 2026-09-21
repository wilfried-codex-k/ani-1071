Mesures :

Programme simple                  : temps de compilation = ..., temps d'exécution = ...
Programme avec 5 en-têtes en plus : temps de compilation = ..., temps d'exécution = ...

Le temps de compilation dépasse largement le temps d'exécution, surtout avec des en-têtes supplémentaires : chaque #include fait lire et analyser un fichier entier par le préprocesseur, puis par le compilateur. À l'exécution, le programme fait très peu de choses, donc le temps d'exécution reste minuscule.

Sur un projet réel, on cherche surtout à réduire le temps de compilation (limiter les inclusions inutiles, utiliser des déclarations anticipées, découper les fichiers) car c'est là que se concentre l'essentiel de l'attente pour le développeur.
