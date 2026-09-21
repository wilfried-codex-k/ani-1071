Ligne de commande sous Unix :

./programme && echo "pair"

Ligne de commande sous Windows :

programme.exe && echo pair

ou avec la variable d'environnement :

if %ERRORLEVEL%==0 echo pair

L'opérateur && n'exécute la commande suivante que si la précédente a rendu un code de sortie nul (succès). On n'affiche donc « pair » que lorsque le programme a rendu 0. Cela reproduit en une ligne ce que fait un système de construction : enchaîner des étapes conditionnellement selon le succès ou l'échec de la précédente.
