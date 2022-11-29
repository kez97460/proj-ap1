#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "float_lists_utils.h"
#include "lib_proj.h"

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
int not_empty = 1; 
while( not_empty > 0 )
    {
    j = 0 ;
    for( int i = 1 ; i<=NB_COLS_TOTAL ; i++ ) // remplissage des listes
        {
        if ( i != 5 ) not_empty = fscanf(file,"%f ",&temp) ; // STAGE ( col 5 ) fait buguer
        else not_empty = fscanf(file,"%c ",&bin) ;
        if ( i > 6 ) // condition qui donne les colonnes utiles uniquement ( Cols 7 à 25 -> i>6 )
            {
            res[j].liste = add_noeud(res[j].liste,temp) ;
            j++ ;
            }
        }
    }
for( j = 0 ; j<NB_COLS_UTILES ; j++ )
    {
        res[j].liste = res[j].liste->suiv ; // on retire un 0 parasite . 
    }
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