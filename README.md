# projet Algo Prog 1
## Intro
Ce projet a pour objectif le traitement de données concernant le polissage chimico-mécanique de plaques semi-conductrices ( wafers ).
L'ensemble des données est réparti dans une cinquantaine de tableaux ( fichiers .csv ) qu'il faudra lire.
L'objectif final de ce projet est d'essayer de prédire le *taux moyen d'élimination des matériaux de surface* d'un wafer donné.

## Structures de données utilisées
Lors de la lecture des données dans les tableaux, créé un tableau ( array ) contenant autant d'élément qu'il y a de colonnes utiles dans les .csv lus.
Nous avons ensuite stocké dans ce tableau des données de type colonne contenant le nom de la colonne ainsi que les valeurs numériques stockées dans une liste chaînée ( type noeud* )
```c
typedef  struct
{
char  nom[100] ;
noeud* data ;
}
colonne ;
```
L'utilisation d'une liste chaînée est avantageuse car :
* Permet de facilement supprimer des valeurs 
* Permet de stocker un nombre arbitraire de valeurs

##
