/* 
Auteurs : Kezia Marcou , Liam Lotte
Une description de chaque fonction est présente la ligne avant sa définition
*/
#ifndef FLOAT_LISTS_UTILS_H
#define FLOAT_LISTS_UTILS_H




typedef struct no 
{
float data ; // modifier si nécessaire
struct no* suiv ;
} 
noeud ;

void print_list( noeud* tete , int n_max ) ;
noeud* add_noeud( noeud* tete , float data ) ;
noeud* suppr_noeud( noeud* tete) ;
noeud* miroir_of_list( noeud* tete ) ;
noeud* concat_list( noeud* tete_debut , noeud* tete_fin ) ;
noeud* sort_list( noeud* tete ) ; 
int length_of_list( noeud* tete ) ;

/////////////////////////////////// ( fonctions statistiques )

float min_of_list( noeud* tete ) ;
float max_of_list( noeud* tete ) ;
float mediane_of_list( noeud* tete ) ;
float moyenne_of_list( noeud* tete ) ;
float ecart_type_of_list( noeud* tete ) ;

noeud* suppr_k_sigma( noeud* liste , int k ) ;
void print_stats_liste(noeud* liste) ;

#endif
