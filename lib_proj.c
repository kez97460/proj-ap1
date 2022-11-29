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
int nb_colonnes_total = 25 ;
int nb_colonnes_utiles = 19 ; 
FILE* file = fopen(filename,"r") ;
colonne* res = (colonne*) malloc(nb_colonnes_utiles*sizeof(colonne)) ; 
for( int i = 1 ; i<=nb_colonnes_total ; i++ ) // on parcourt la 1ere ligne et initialise les listes
    {
    fscanf(file,"%s",name) ; // les noms des colonnes sont au début du .csv
    if ( i > 6 ) // condition qui donne les colonnes utiles uniquement ( Cols 7 à 25 -> i>6 )
        {
        res[j].data = NULL ;
        strcpy(res[j].nom,name) ;
        j++ ;
        }
    }
float temp ;
for( int i = 1 ; i<=nb_colonnes_total ; i++ ) // remplissage des listes
    {
    fscanf(file,"%f",&temp) ;
    if ( i > 6 ) // condition qui donne les colonnes utiles uniquement ( Cols 7 à 25 -> i>6 )
        {
        res[j].data = add_noeud(res[j].data,temp) ;
        j++ ;
        }
    }
return res ;
}

