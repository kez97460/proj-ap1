#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "float_lists_utils.h"
#include "lib_proj.h"

/////////////////////////////////// ( listes de wafers )

// renvoie la nouvelle liste de wafers après ajout d'un noeud en tête ( préciser le data du noeud a ajouter )
noeud_wafer* add_noeud_wafer( noeud_wafer* tete , wafer data ) 
{
noeud_wafer* nouveau = (noeud_wafer*) malloc(sizeof(noeud_wafer)) ;
nouveau->data = data ;
nouveau->suiv = tete ;
return nouveau ;
}

// affiche les premiers éléments d'une liste chainee de wafers ( affiche toute la liste si elle a moins de n_max elements )
void print_list_wafer( noeud_wafer* tete , int n_max )
{
printf("{") ;
while( tete != NULL && n_max > 0 )
	{
	printf("( %li %c ) ",tete->data.id,tete->data.stage) ;
	tete = tete->suiv ;
	n_max-- ;
	}
if( tete == NULL ) printf("}\n") ;
else printf("...\n") ;
}

noeud_wafer* miroir_of_list_wafer( noeud_wafer* tete )
{
noeud_wafer* res = NULL ;
while (tete != NULL)
	{
	res = add_noeud_wafer(res,tete->data) ;
	tete = tete->suiv ;
	}
return res ;
}

noeud_wafer* concat_list_wafer( noeud_wafer* tete_debut , noeud_wafer* tete_fin )
{
tete_debut = miroir_of_list_wafer(tete_debut) ;
while( tete_debut != NULL )
	{
	tete_fin = add_noeud_wafer(tete_fin,tete_debut->data) ;
	tete_debut = tete_debut->suiv ;
	}
return tete_fin ;
}

int is_in_list_wafer( wafer wa , noeud_wafer* liste )
{
while( liste != NULL)
	{
	if ( liste->data.id == wa.id & liste->data.stage == wa.stage ) return 1 ;
	liste = liste->suiv ;
	}
return 0 ;
}

/////////////////////////////////// ( others )

// lit un .csv et stocke les données .
/*colonne* read_data( char* filename )
{
char name[100] ;
int j ;
FILE* file = fopen(filename,"r") ;
colonne* res = (colonne*) malloc(NB_COLS_UTILES*sizeof(colonne)) ; 
if ( file != NULL )
	{
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
		else 
		    {
		    not_empty = fscanf(file,"%c ",&bin) ;
		    }
		if ( i > 6 && not_empty > 0 ) // condition qui donne les colonnes utiles uniquement ( Cols 7 à 25 -> i>6 )
		    {
		    res[j].liste = add_noeud(res[j].liste,temp) ;
		    j++ ;
		    }
		}
	    } 
	while( not_empty > 0 ) ;
	fclose(file) ;
	}
else printf("Error : couldn't open file\n") ;
return res ;
}*/

colonne* read_data2( char* filename )
{
char name_useless[100] ;
float temp ;
char bin ;
FILE* file = fopen(filename,"r") ;
colonne* res = (colonne*) malloc(NB_COLS_UTILES*sizeof(colonne)) ; 
for ( int i = 0 ; i<NB_COLS_UTILES ; i++ ) res[i].liste = NULL ;
float tab[NB_COLS_UTILES] ;
if ( file != NULL )
	{
	fscanf(file,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s ",
	name_useless,name_useless,name_useless,name_useless,name_useless,name_useless,
	&res[0].nom,&res[1].nom,&res[2].nom,&res[3].nom,&res[4].nom,&res[5].nom,&res[6].nom,&res[7].nom,&res[8].nom,&res[9].nom,
	&res[10].nom,&res[11].nom,&res[12].nom,&res[13].nom,&res[14].nom,&res[15].nom,&res[16].nom,&res[17].nom,&res[18].nom) ; // les noms des colonnes sont au début du .csv
	while( NB_COLS_TOTAL == fscanf(file,"%f %f %f %f %c %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ",
		&temp,&temp,&temp,&temp,&bin,&temp,
		&tab[0],&tab[1],&tab[2],&tab[3],&tab[4],&tab[5],&tab[6],&tab[7],&tab[8],&tab[9],
		&tab[10],&tab[11],&tab[12],&tab[13],&tab[14],&tab[15],&tab[16],&tab[17],&tab[18]) )
		{
		for( int j = 0 ; j<NB_COLS_UTILES ; j++ )
			{
			res[j].liste = add_noeud(res[j].liste,tab[j]) ;
			}
		}
	fclose(file) ;
	for( int i = 0 ; i<NB_COLS_UTILES ; i++ ) res[i].liste = miroir_of_list(res[i].liste) ;
	return res ;
	}
printf("Error : couldn't open file\n") ;
return NULL ;
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

int trouve_dizaine(int valeur_introduite) // trouve le chiffre des dizaines d'un nombre
{
    int reste = valeur_introduite%10;
    return((valeur_introduite-reste)/10); //JacqUES Ch1r4C
}

//génère le chemin vers le fichier csv n à partir du chemin vers un dossier où sont stockés tous les csv
void generate_path_to_file( int n , char* full_path )
{
char table_de_valeur[] = "0123456789";
char nom_fichier[100] = "CMP-training-000.csv";

int dizaine = trouve_dizaine(n);
int unite = n - dizaine*10;
nom_fichier[15] = table_de_valeur[unite];
nom_fichier[14] = table_de_valeur[dizaine];

strcpy(full_path,nom_fichier) ;
}

// lit tous les .csv ( ils doivent être dans le même fichier )
colonne* all_csv(int nb_csv_lus)
{
colonne* resultat;
char table_de_valeur[] = "0123456789";
char nom_fichier[100] = "CMP-training-000.csv";
colonne *temporaire;
resultat = read_data2(nom_fichier); printf("Successfuly read %s \n",nom_fichier) ;

for (int i = 1; i<nb_csv_lus ; i++)
    {
    int dizaine = trouve_dizaine(i);
    int unite = i - dizaine*10;
    nom_fichier[15] = table_de_valeur[unite];
    nom_fichier[14] = table_de_valeur[dizaine];
    temporaire = read_data2(nom_fichier); printf("Successfuly read %s \n",nom_fichier) ;
    for ( int j = 0 ; j<NB_COLS_UTILES ; j++ )
        {
        resultat[j].liste = concat_list(resultat[j].liste, temporaire[j].liste) ;
        }
    }
return resultat;
}

/////////////////////////////( l'enfer de la question 4 )

// lecture d'un csv et récupération des données des wafers
noeud_wafer* read_wafers( char* filename )
{
char name_useless[100] ;
float temp ;
char stage ;
long id ;
wafer current_wafer ;
FILE* file = fopen(filename,"r") ;
noeud_wafer* res = NULL ; 
if ( file != NULL )
	{
	fscanf(file,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s ",
	name_useless,name_useless,name_useless,name_useless,name_useless,name_useless,name_useless,name_useless,name_useless,name_useless,
	name_useless,name_useless,name_useless,name_useless,name_useless,name_useless,name_useless,name_useless,name_useless,name_useless,
	name_useless,name_useless,name_useless,name_useless,name_useless) ; // les noms des colonnes sont au début du .csv
	while( NB_COLS_TOTAL == fscanf(file,"%f %f %f %li %c %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ",
	&temp,&temp,&temp,&id,&stage,
	&temp,&temp,&temp,&temp,&temp,
	&temp,&temp,&temp,&temp,&temp,
	&temp,&temp,&temp,&temp,&temp,
	&temp,&temp,&temp,&temp,&temp) )
		{
		current_wafer.id = id ;
		current_wafer.stage = stage ;
		res = add_noeud_wafer(res,current_wafer) ;
		}
	fclose(file) ;
	return miroir_of_list_wafer(res) ;
	}
printf("Error : couldn't open file\n") ;
return NULL ;
}

// lit les wafers de tous les csv
noeud_wafer* all_wafers(int nb_csv_lus)
{
noeud_wafer* resultat;
char table_de_valeur[] = "0123456789";
char nom_fichier[100] = "CMP-training-000.csv";
resultat = read_wafers(nom_fichier); printf("Successfuly read wafers in %s \n",nom_fichier) ;

for (int i = 1; i<nb_csv_lus ; i++)
    {
    int dizaine = trouve_dizaine(i);
    int unite = i - dizaine*10;
    nom_fichier[15] = table_de_valeur[unite];
    nom_fichier[14] = table_de_valeur[dizaine];
    resultat = concat_list_wafer(resultat , read_wafers(nom_fichier) ) ; printf("Successfuly read wafers in %s \n",nom_fichier) ;
    }
return resultat;
}

void agregate_data( noeud_wafer* liste_wafer , noeud* liste_donnees , char* destination_name )
{
noeud_wafer* mem ;
float moyenne = 0 ;
int nb_vals = 0 ; // nombres de vals pour une wafer 
FILE* destination = fopen(destination_name,"w") ;
if ( destination != NULL )
    {
    while( liste_wafer != NULL && liste_donnees != NULL )
        {
        if ( is_in_list_wafer(liste_wafer->data , mem ) == 0 )
            {
            fprintf(destination,"%li\t",mem->data.id) ;
			fprintf(destination,"%c\t",mem->data.stage) ;
            moyenne /= nb_vals ;
            fprintf(destination,"%f\n",moyenne) ; printf("%f\n",moyenne) ;
            moyenne = 0 ;
            nb_vals = 0 ;
            add_noeud_wafer( mem , liste_wafer->data ) ;
            }
		moyenne += liste_donnees->data ;
		nb_vals++ ;
		liste_donnees = liste_donnees->suiv ; 
		liste_wafer = liste_wafer->suiv ;
        }
    fclose(destination) ;
    }
}

//////////////////////////////////////// ( q3 )

intervalle* get_histogramme( noeud* liste , int nb_bins )
{
intervalle* res = (intervalle*) malloc(nb_bins*sizeof(intervalle)) ;
float mini = min_of_list(liste) ;
float ecart = ( max_of_list(liste) - mini ) / nb_bins ;
int i ;
for( i = 0 ; i<nb_bins ; i++ ) 
    {
    res[i].debut = mini+i*ecart ;
    res[i].fin = mini+(i+1)*ecart ;
    res[i].nb_observations = 0 ;
    }
    
res[nb_bins-1].fin += ecart/100 ; // on s'assure d'insérer le max avec un léger surplus sur l'intervalle

while ( liste != NULL )
    {
    i = 0 ;
    for( i = 0 ; i<nb_bins ; i++ )
    	{
    	if( res[i].debut <= liste->data && res[i].fin > liste->data )
    		{
    		res[i].nb_observations++ ;
    		}
    	}
    liste = liste->suiv ;    
    }
return res ;
}

void print_histogramme( intervalle* histogramme , int nb_bins )
{
for( int i = 0 ; i<nb_bins ; i++ )
    {
    printf(" [ %f , %f ] : %d observations \n",histogramme[i].debut,histogramme[i].fin,histogramme[i].nb_observations) ;
    }
}
