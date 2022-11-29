/* 
Auteur : Kezia Marcou 
Une description de chaque fonction est présente la ligne avant sa définition

>> Pour compiler un programme ( main.c ) qui utilise cette librairie :
1.  gcc -c linked_lists_utils.c ( pour créer linked_lists_utils.o )
2.  gcc -c main.c ( pour créer main.o )
3.  gcc main.o linked_lists_utils.o -o appli ( pour créer l'executable appli )

>> Lignes de code modifiables :
- type noeud -> le type de data peut être modifié 
- merge_list -> la fonction qui définit l'ordre peut être modifiée ( dans le .c , line 49 , chiant mais j'ai pas de meilleure idée , si quelqu'un en a une suis preneur )
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
noeud* concat_list( noeud* tete_debut , noeud* tete_fin ) ;
noeud* sort_list( noeud* tete ) ; 
int length_of_list( noeud* tete ) ;

/////////////////////////////////// ( fonctions statistiques )

float min_of_list( noeud* tete ) ;
float max_of_list( noeud* tete ) ;
float mediane_of_list( noeud* tete ) ;
float moyenne_of_list( noeud* tete ) ;
float ecart_type_of_list( noeud* tete ) ;

#endif