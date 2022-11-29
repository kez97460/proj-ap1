/* 
Auteur : Kezia Marcou 
Une description de chaque fonction est présente la ligne avant sa définition

>> Pour compiler un programme ( main.c ) qui utilise cette librairie :
1.  gcc -c lib_proj.c ( pour créer arrays_utils.o )
2.  gcc -c main.c ( pour créer main.o )
3.  gcc main.o lib_proj.o -o appli ( pour créer l'executable appli )

>> Lignes de code modifiables :
*/
#ifndef LIB_PROJ_H
#define LIB_PROJ_H

#include "float_lists_utils.h"


typedef struct 
{
char nom[100] ;
noeud* data ;
}
colonne ;

colonne* read_data( char* filename ) ;

#endif



