#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "float_lists_utils.h"
#include "lib_proj.h"

colonne* read_data( char* filename )
{
char name[100] ;
int len_colonnes = 19 ;
FILE* file = fopen(filename,"r") ;
colonne* res = (colonne*) malloc(len_colonnes*sizeof(colonne)) ; 
for( int i = 0 ; i<len_colonnes ; i++ )
    {
    fscanf(file,"%s",name) ; // les noms des colonnes sont au début du .csv
    res[i].data = NULL ;
    strcpy(res[i].nom,name) ;
    }

}

