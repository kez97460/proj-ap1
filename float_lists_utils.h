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

typedef struct no 
{
float data ; // modifier si nécessaire
struct no* suiv ;
} 
noeud ;

noeud* add_noeud( noeud* tete , float data ) ;
noeud* miroir_of_list( noeud* tete ) ;
noeud* concat_list( noeud* tete_debut , noeud* tete_fin ) ;
noeud* sort_list( noeud* tete ) ; 
noeud* add_to_end_of_list( noeud* tete , float data ) ;
int length_of_list( noeud* tete ) ;
float* linked_list_to_array( noeud* tete ) ; // useless here ?

/////////////////////////////////// ( fonctions statistiques )
