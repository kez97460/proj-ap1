/* 
Auteurs : Kezia Marcou , Liam Lotte
Une description de chaque fonction est présente la ligne avant sa définition

>> Pour compiler un programme ( main.c ) qui utilise cette librairie :
1.  gcc -c lib_proj.c ( pour créer arrays_utils.o )
2.  gcc -c main.c ( pour créer main.o )
3.  gcc main.o lib_proj.o -o appli ( pour créer l'executable appli )

>> Lignes de code modifiables :
*/
#ifndef LIB_PROJ_H

#define LIB_PROJ_H
#define NB_COLS_UTILES 19
#define NB_COLS_TOTAL 25
#define NB_CSV 40

#include "float_lists_utils.h"


typedef struct col
{
char nom[100] ;
noeud* liste ;
}
colonne ;

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

typedef struct inter
{
float debut ;
float fin ;
int nb_observations ;
}
intervalle ;


/////////////////////////////////// ( question 4 -> listes de wafers )
noeud_wafer* add_noeud_wafer( noeud_wafer* tete , wafer data ) ;
void print_list_wafer( noeud_wafer* tete , int n_max ) ;


noeud_wafer* read_wafers( char* filename ) ;
noeud_wafer* all_wafers(int nb_csv_lus) ;
void agregate_data( noeud_wafer* liste_wafer , noeud* liste_donnees , char* destination_name ) ;

/////////////////////////////////// ( autres )
colonne* read_data( char* filename ) ;
colonne* read_data2( char* filename ) ; // because segfault sur read_data
colonne* all_csv(int nb_csv_lus ) ;

void print_nom_colonnes( colonne* tableau ) ;
void print_data_sample( colonne* tableau , int n_max ) ;
void generate_path_to_file( int n , char* full_path) ;


intervalle* get_histogramme( noeud* liste , int nb_bins ) ;
void print_histogramme( intervalle* histogramme , int nb_bins ) ;





#endif



