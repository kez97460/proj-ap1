# projet Algo Prog 1

# Intro

Ce projet a pour objectif le traitement de données concernant le polissage chimico-mécanique de plaques semi-conductrices ( wafers ).

L'ensemble des données est réparti dans une cinquantaine de tableaux ( fichiers .csv ) qu'il faudra lire.

L'objectif final de ce projet est d'essayer de prédire le *taux moyen d'élimination des matériaux de surface* d'un wafer donné.

# Compilation et execution du programme

Le makefile est normalement inclus dans le dossier envoyé

Le programme ouvre un menu (switch case) lorsqu'il est ouvert. Il suffit ensuite de le naviguer pour obtenir les résultats voulus.

Penser à toujours être sûr qu'un fichier a été lu ( commande 1 ) avant de faire de l'analyse de données.

Merci de placer tous les fichiers qui vont être lus dans le même dossier que les programmes.

# Structures de données utilisées

## Lectures des données des .csv

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

On va dans un premier temps faire une étude statistique classique sur chaque liste avec les fonctions :
```c
/* float_lists_utils.c */
float min_of_list( noeud* tete ) ;
float max_of_list( noeud* tete ) ;
float mediane_of_list( noeud* tete ) ;
float moyenne_of_list( noeud* tete ) ;
float ecart_type_of_list( noeud* tete ) ;
noeud* suppr_k_sigma( noeud* liste , int k ) ;
```

On peut aussi rassembler les valeurs dans un histogramme à l'aide de la structure
```c
/* lib_proj.h */
typedef struct inter
{
float debut ;
float fin ;
int nb_observations ;
}
intervalle ;

// fonctions associées 
intervalle* get_histogramme( noeud* liste , int nb_bins ) ;
void print_histogramme( intervalle* histogramme , int nb_bins ) ;
```

## Agrégation par wafer

Afin d'agréger les données par wafer, on va d'abord créer les structures de données
```c
typedef struct wa
{
long id ;
char stage ; // A ou B 
}
wafer ;

typedef struct no_w 
{
wafer data ;
struct no_w* suiv ;
} 
noeud_wafer ;
```

Ainsi on stocke les wafers dans des listes chaînées , qu'on analyse en parallèle avec les listes de données des séries temporelles.





