#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "float_lists_utils.h"
#include "lib_proj.h"

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
fclose(filename) ;
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



void read_and_agregate_data( char* filename )
{
char name[100] ;
int j ;
FILE* file = fopen(filename,"r") ;
colonne* res = (colonne*) malloc(NB_COLS_UTILES*sizeof(colonne)) ; 

FILE* destination = fopen("agregated_data.csv","a+") ; // on stocke le résultat dans ce fichier

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
char current_stage , new_stage ; // stage : col.4 
int current_id , new_id ; // id : col.5
int not_empty ; 
int first_change = 1 ; 
do
    {
    j = 0 ;
    for( int i = 1 ; i<=NB_COLS_TOTAL ; i++ ) // remplissage des listes
        {
        if ( i < 4 ) not_empty = fscanf(file,"%f ",&temp) ; //colonnes 1 à 3 inutiles
        if ( i = 4 ) not_empty = fscanf(file,"%c ",&new_stage) ; 
        if ( i = 5 ) not_empty = fscanf(file,"%f ",&new_id) ;
        if ( i > 6 && not_empty > 0 ) // condition qui donne les colonnes de données uniquement ( Cols 7 à 25 -> i>6 )
            {
            res[j].liste = add_noeud(res[j].liste,temp) ;
            j++ ;
            }
        if ( not_empty > 0 )
            {
            if ( new_id != current_id || new_stage != current_stage )
                {
                if ( first_change < 1 ) // 1er changement = initialisation, on ne le considère pas
                    {
                    fprintf(destination,"%d\t%c\t",current_id,current_stage) ; // changement de wafer
                    for ( int k = 0 ; k<NB_COLS_UTILES ; k++ )
                        {
                        fprintf(destination,"%f\t",moyenne_of_list(res[k].liste)) ;
                        res[k].liste = NULL ;
                        } 
                    fprintf(destination,"\n") ;
                    current_id = new_id ;
                    current_stage = new_stage ;
                    }
                else first_change = 0 ;
                }
            }
        }
    } 
while( not_empty > 0 ) ;

return res ;
}
