# FINSAS
Projet SAS

Election Présidentielle

Créer une application pour élire un président après un processus de vote et d'élection. Sachant que le processus passe par plusieurs tours d'élection présidentielle. 

L'application doit fournir les étapes suivantes : 

Obtention de la liste des présidents nominées aux élections présidentielles(liste dynamique - minimum 5) 
Obtention de la liste des électeurs par leurs identifiant CIN (liste dynamique - minimum 10)

Premier tour : Le premier tour des élections va consister d’un vote de chaque électeurs pour un président nominé de choix. Chaque électeur va pouvoir choisir un président nominé depuis la liste des présidents nominés déjà introduits. Après le processus de vote, le président ayant un pourcentage de votes moins de 15% sera exclu. N.B: si tous les présidents nominés ont un nombre de votes ex aequo, le tour doit être refait. 

Deuxième tour : Le deuxième tour des élections va consister d’un vote de chaque électeurs pour un président nominé de choix sauf les présidents nominés déjà exclus depuis le premier tour. Chaque électeur va pouvoir choisir un président nominé depuis la liste des présidents nominés qui restent. Après le processus de vote, le président ayant le moins de votes sera exclu. N.B: si tous les présidents nominés ont un nombre de votes ex aequo, le tour doit être refait. 

Troisième tour : Le troisième tour des élections va consister d’un vote de chaque électeurs pour un président nominé de choix sauf les présidents nominés déjà exclus depuis le deuxième tour. Chaque électeur va pouvoir choisir un président nominé depuis la liste des présidents nominés qui restent. Après le processus de vote, le président ayant le plus de votes sera élu comme président. N.B: si deux ou plusieurs présidents nominés ont un nombre de votes maximale et ex aequo, le tour doit être refait.
