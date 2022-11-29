#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "float_lists_utils.h"

/////////////////////////////////////////////// ( Fonctions )

// affiche les premiers éléments d'une liste chainee
void print_list( noeud* tete , int n_max )
{
printf("{") ;
while( tete != NULL && n_max > 0 )
	{
	printf(" %f ",tete->data) ;
	tete = tete->suiv ;
	n_max-- ;
	}
if( tete == NULL ) printf("}\n") ;
else printf("...\n") ;
}

// renvoie la nouvelle liste après ajout d'un noeud en tête ( préciser le data du noeud a ajouter )
noeud* add_noeud( noeud* tete , float data ) 
{
noeud* nouveau = (noeud*) malloc(sizeof(noeud)) ;
nouveau->data = data ;
nouveau->suiv = tete ;
return nouveau ;
}

// renvoie le miroir d'une liste chainee. En O(n)
noeud* miroir_of_list( noeud* tete )
{
noeud* res = NULL ;
while (tete != NULL)
	{
	res = add_noeud(res,tete->data) ;
	tete = tete->suiv ;
	}
return res ;
}

// renvoie la concatenation de deux listes chainees. En O(n+m)
noeud* concat_list( noeud* tete_debut , noeud* tete_fin )
{
tete_debut = miroir_of_list(tete_debut) ;
while( tete_debut != NULL )
	{
	tete_fin = add_noeud(tete_fin,tete_debut->data) ;
	tete_debut = tete_debut->suiv ;
	}
return tete_fin ;
}

// fusionne 2 listes triées en maintenant l'ordre ( pour le tri fusion )
noeud* merge_list( noeud* tete1 , noeud* tete2 )
{
noeud* res = NULL ;
while ( tete1 != NULL && tete2 != NULL )
	{
	if ( tete1->data < tete2->data ) // test de l'inégalité , modifier si nécessaire
		{
		res = add_noeud(res,tete1->data) ;
		tete1 = tete1->suiv ;
		}
	else
		{
		res = add_noeud(res,tete2->data) ;
		tete2 = tete2->suiv ;
		}
	}
while ( tete1 != NULL || tete2 != NULL )
	{
	if ( tete1 != NULL )
		{
		res = add_noeud(res,tete1->data) ;
		tete1 = tete1->suiv ;
		}
	else
		{
		res = add_noeud(res,tete2->data) ;
		tete2 = tete2->suiv ;
		}
	}
return miroir_of_list(res) ;
}

//renvoie le tri fusion d'une liste chainee ( pour définir l'ordre voir merge_list ). En O( n.log n )
noeud* sort_list( noeud* tete )
{
noeud* list1 = NULL ;
noeud* list2 = NULL ;
int i = 0 ;
if ( tete == NULL ) return NULL ;
else if ( tete->suiv == NULL ) return tete ;
else
	{
	while ( tete != NULL )
		{
		if ( i == 0 )
			{
			list1 = add_noeud(list1,tete->data) ;
			tete = tete->suiv ;
			i++ ;
			}
		else
			{
			list2 = add_noeud(list2,tete->data) ;
			tete = tete->suiv ;
			i = 0 ;
			}
		}
	return merge_list( sort_list(list1) , sort_list(list2) ) ;
	}
printf("Error : what did you do ? Something wrong. ") ;
}

// Ajout d'un noeud en FIN de liste. En O(n). Why does this even exist ?
noeud* add_to_end_of_list( noeud* tete , float data ) 
{
noeud* res = NULL ;
res = add_noeud(res,data) ;
res = concat_list(tete,res) ;
return res ;
}

// renvoie la longueur de la liste. En O(n).
int length_of_list( noeud* tete )
{
int res = 0 ;
while ( tete != NULL )
	{
	res++ ;
	tete = tete->suiv ;
	}
return res ;
}

// renvoie un tableau contenant les éléments de la liste. En O(n). Isn't it beautiful ? Kinda useless tho
float* linked_list_to_array( noeud* tete )
{
int len = length_of_list(tete) ;
float* res = (float*) malloc( len * sizeof(float) ) ;
for ( int i = 0 ; i<len ; i++ )
	{
	res[len-1-i] = tete->data ;
	tete = tete->suiv ;
	}
return res ;
}

//////////////////////////////////// ( fonctions statistiques )

//renvoie le minimum d'une liste
float min_of_list( noeud* tete )
{
if ( tete != NULL) 
	{	
	float res = tete->data ;
	while ( tete!= NULL )
		{
		if (tete->data < res) res = tete->data ;
		tete = tete->suiv ;
		}
	return res ;
	}
printf("Error : min of empty list\n") ;
}

//renvoie le maximum d'une liste
float max_of_list( noeud* tete )
{
if ( tete != NULL) 
	{	
	float res = tete->data ;
	while ( tete!= NULL )
		{
		if (tete->data > res) res = tete->data ;
		tete = tete->suiv ;
		}
	return res ;
	}
printf("Error : max of empty list\n") ;
}

//renvoie la médiane d'une liste en la triant et récupérant l'élément du milieu. En O(n.log n)
float mediane_of_list( noeud* tete )
{
int len = length_of_list(tete) ;
tete = sort_list(tete) ;
if (len>0)
	{
	int mid = len/2 ;
	for ( int i = 0 ; i<mid ; i++ )
		{
		tete = tete->suiv;
		}
	return tete->data ;
	}
printf("Error : median of empty list\n") ;
}

//renvoie la moyenne d'une liste
float moyenne_of_list( noeud* tete )
{
int res = 0 ;
int len = length_of_list(tete) ;
if (len>0)
	{
	while ( tete != NULL )
		{
		res += tete->data ;
		tete = tete->suiv ;
		}
	return res/len ;
	}
printf("Error : average of empty list\n") ;
}

float variance_of_list( noeud* tete )
{
int len = length_of_list(tete) ;
if (len>0)
	{
	float moy_carres = 0 ;
	float moy = moyenne_of_list(tete) ;
	while ( tete != NULL )
		{
		moy_carres += tete->data * tete->data ;
		tete = tete->suiv ;
		}
	return ( moy_carres - moy*moy ) ;
	}
printf("Error : variance of empty list \n") ;
}

float ecart_type_of_list( noeud* tete )
{
return sqrt(variance_of_list(tete)) ;
}

