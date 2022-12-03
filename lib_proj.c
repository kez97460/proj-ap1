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
        else 
            {
            not_empty = fscanf(file,"%c ",&bin) ;
            printf("HI") ;
            }
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

noeud_wafer* read_wafers( char* filename )
{
char name[100] ;
int j ;
FILE* file = fopen(filename,"r") ;
for( int i = 1 ; i<=NB_COLS_TOTAL ; i++ ) // on parcourt la 1ere ligne et initialise les listes
    {
    fscanf(file,"%s ",name) ; // les noms des colonnes sont au début du .csv
    }
float temp ;
char stage ;
int id ;
wafer current_wafer ;
int not_empty ; 
noeud_wafer* liste_wafer = NULL ;
do
    {
    j = 0 ;
    for( int i = 1 ; i<=NB_COLS_TOTAL ; i++ ) // remplissage des listes
        {
        if ( i == 5 ) not_empty = fscanf(file,"%c ",&stage) ;
        else if ( i == 4 ) not_empty = fscanf(file,"%li ",&id) ;
        else not_empty = fscanf(file,"%f ",&temp) ; // STAGE ( col 5 ) fait buguer
        }
    current_wafer.id = id ;
    current_wafer.stage = stage ;
    liste_wafer = add_noeud_wafer(liste_wafer,current_wafer) ;
    } 
while( not_empty > 0 ) ;
fclose(file) ;
return liste_wafer ;
}

void agregate_data( noeud_wafer* liste_wafer , colonne* full_data , char* filename )
{
wafer current_wafer = liste_wafer->data ;
float tab_moyennes[NB_COLS_UTILES] ; // somme des valeurs pour une wafer
int nb_vals ; // nombres de vals pour une wafer 

FILE* destination = fopen(filename,"a+") ;

while( liste_wafer != NULL )
    {
    if ( liste_wafer->data.id != current_wafer.id )
        {
        for ( int i = 0 ; i<NB_COLS_UTILES ; i++ )
            {
            
            }
        }
    else
        {
        for ( int i = 0 ; i<NB_COLS_UTILES ; i++ )
            {
            tab_moyennes[i] += full_data[i].liste->data ;
            full_data[i].liste = full_data[i].liste->suiv ; 
            }
        liste_wafer = liste_wafer->suiv ;
        nb_vals += 1 ;
        }
    }
}

