#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "float_lists_utils.h"
#include "lib_proj.h"

/////////////////////////////////// ( listes de wafers )

// renvoie la nouvelle liste après ajout d'un noeud en tête ( préciser le data du noeud a ajouter )
noeud_wafer* add_noeud_wafer( noeud_wafer* tete , wafer data ) 
{
noeud_wafer* nouveau = (noeud_wafer*) malloc(sizeof(noeud_wafer)) ;
nouveau->data = data ;
nouveau->suiv = tete ;
return nouveau ;
}

// affiche les premiers éléments d'une liste chainee ( affiche toute la liste si elle a moins de n_max elements )
void print_list_wafer( noeud_wafer* tete , int n_max )
{
printf("{") ;
while( tete != NULL && n_max > 0 )
	{
	printf("( %li %c ) ",tete->data.id,tete->data.stage) ;
	tete = tete->suiv ;
	n_max-- ;
	}
if( tete == NULL ) printf("}\n") ;
else printf("...\n") ;
}

/////////////////////////////////// ( others )

// lit un .csv et stocke les données . Les listes sont par ORDRE CHRONOLOGIQUE DECROISSANT
colonne* read_data( char* filename )
{
char name[100] ;
int j ;
FILE* file = fopen(filename,"r") ;
colonne* res = (colonne*) malloc(NB_COLS_UTILES*sizeof(colonne)) ; 
for( int i = 1 ; i<=NB_COLS_TOTAL ; i++ ) // on parcourt la 1ere ligne et initialise les listes
    {
    fscanf(file,"%s ",name) ; // les noms des colonnes sont au début du .csv
    if ( i > 6 ) // condition qui donne les colonnes utiles uniquement ( Cols 7 à 25 -> i>6 )
        {
        res[j].liste = NULL ;
        strcpy(res[j].nom,name) ;
        j++ ;
        }
    }
float temp ;
char bin ;
int not_empty ; 
do
    {
    j = 0 ;
    for( int i = 1 ; i<=NB_COLS_TOTAL ; i++ ) // remplissage des listes
        {
        if ( i != 5 ) not_empty = fscanf(file,"%f ",&temp) ; // STAGE ( col 5 ) fait buguer
        else not_empty = fscanf(file,"%c ",&bin) ;
        if ( i > 6 && not_empty > 0 ) // condition qui donne les colonnes utiles uniquement ( Cols 7 à 25 -> i>6 )
            {
            res[j].liste = add_noeud(res[j].liste,temp) ;
            j++ ;
            }
        }
    } 
while( not_empty > 0 ) ;
fclose(file) ;
return res ;
}

// affiche le nom des colonnes. testé , OK
void print_nom_colonnes( colonne* tableau )
{
for ( int i = 0 ; i<NB_COLS_UTILES ; i++ )
    {
    printf("Colonne %d : %s \n",i+1,tableau[i].nom) ;
    }
}

// affiche un apercu des données. testé , OK
void print_data_sample( colonne* tableau , int n_max )
{
for ( int i = 0 ; i<NB_COLS_UTILES ; i++ )
    {
    printf("Colonne %d ( %s ) : ",i+1,tableau[i].nom) ;
    print_list(tableau[i].liste,n_max) ;
    }
}

data_for_agregation read_data_for_agreg( char* filename )
{
char name[100] ;
int j ;
FILE* file = fopen(filename,"r") ;
colonne* data_cols_utiles = (colonne*) malloc(NB_COLS_UTILES*sizeof(colonne)) ; 
for( int i = 1 ; i<=NB_COLS_TOTAL ; i++ ) // on parcourt la 1ere ligne et initialise les listes
    {
    fscanf(file,"%s ",name) ; // les noms des colonnes sont au début du .csv
    if ( i > 6 ) // condition qui donne les colonnes utiles uniquement ( Cols 7 à 25 -> i>6 )
        {
        data_cols_utiles[j].liste = NULL ;
        strcpy(data_cols_utiles[j].nom,name) ;
        j++ ;
        }
    }
float temp ;
wafer current_wafer ;
noeud_wafer* liste_wafer = NULL ;
int not_empty ; 
do
    {
    j = 0 ;
    for( int i = 1 ; i<=NB_COLS_TOTAL ; i++ ) // remplissage des listes
        {
        printf("lol") ;
        switch(i) 
            {
            case 4 :
                printf("lol") ;
                not_empty = fscanf(file,"%li ",&current_wafer.id) ;
                break;
            case 5 :
                printf("lol") ;
                not_empty = fscanf(file,"%c ",&current_wafer.stage) ;
                break;
            default :
                 printf("lol") ;
                not_empty = fscanf(file,"%f ",&temp) ;
            }
        if ( i > 6 && not_empty > 0 ) // condition qui donne les colonnes utiles uniquement ( Cols 7 à 25 -> i>6 )
            {
            data_cols_utiles[j].liste = add_noeud(data_cols_utiles[j].liste,temp) ;
            j++ ;
            }
        }
    add_noeud_wafer(liste_wafer,current_wafer) ;
    } 
while( not_empty > 0 ) ;
fclose(file) ;
data_for_agregation full_data ;
full_data.data_cols_utiles = data_cols_utiles ;
full_data.wafers = liste_wafer ;
}

