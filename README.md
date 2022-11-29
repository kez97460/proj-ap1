# projet Algo Prog 1

## Intro

Ce projet a pour objectif le traitement de données concernant le polissage chimico-mécanique de plaques semi-conductrices ( wafers ).

L'ensemble des données est réparti dans une cinquantaine de tableaux ( fichiers .csv ) qu'il faudra lire.

L'objectif final de ce projet est d'essayer de prédire le *taux moyen d'élimination des matériaux de surface* d'un wafer donné.

## Structures de données utilisées

Lors de la lecture des données dans les fichiers, on crée un tableau ( array ) contenant autant d'éléments qu'il y a de colonnes utiles dans les .csv lus. 

Nous avons ensuite stocké dans ce tableau des données du type colonne :
```c
/* lib_proj.h */
typedef  struct
{
char  nom[100] ; // nom de la colonne
noeud* data ; // liste des valeurs
}
colonne ;
```
L'utilisation d'une liste chaînée est avantageuse car elle permet de :
* facilement supprimer des valeurs 
* stocker un nombre arbitraire de valeurs

 La lecture du document se fait alors avec la fonction :
 ```c
 /* lib_proj.h */
 colonne* read_data( char* filename ) ;
 ```

## Etude statistique

On va dans un premier temps faire une étude statistique sur chaque liste avec les fonctions :
```c
/* float_lists_utils.c */
float min_of_list( noeud* tete ) ;
float max_of_list( noeud* tete ) ;
float mediane_of_list( noeud* tete ) ;
float moyenne_of_list( noeud* tete ) ;
float ecart_type_of_list( noeud* tete ) ;
```
