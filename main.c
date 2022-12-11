#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "float_lists_utils.h"
#include "lib_proj.h"

int main()
{
char filename[100] ;
colonne* file_data ;
noeud_wafer* wafer_data ;
int nb_elem ;
int num_col ;
int k ;
int selection ;
char destination[100] ;
char all_str[] = "all" ;
int nb_bins ;

while (1)
	{
		
	printf("\nPress 0 for a list of commands. To choose a file to scan press 1. \n") ;
	scanf("%d", &selection);
	switch (selection)
		{
			
		case 0:
		    printf("0 - Afficher les commandes disponibles \n");
		    printf("1 - Stocker les données d'un fichier CSV \n");
		    printf("2 - Afficher la liste des colonnes ( séries temporelles ) , et un extrait des valeurs\n");
		    printf("3 - Afficher les statistiques d'une des séries temporelles \n");
		    printf("4 - Détecter et supprimer, dans une série temporelle, les obervations trop éloignées de la moyenne \n");
			printf("5 - Séparer les données en n intervalles et afficher un histogramme \n");
		    printf("6 - Agréger une série temporelle par wafer, agréger par moyenne, et stocker l'agrégation dans un fichier \n");
		    printf("9 - Exit app \n") ;
		    break;

		case 1: //ok mais pas sur les 59 csv, 40 ca passe tranquille
			printf("Entrez le nom du fichier à lire ( \"all\" scanne tous les csv si non renommés ) : ");
			scanf("%s",&filename);
			if ( strcmp(filename,all_str) == 0 ) file_data = all_csv(NB_CSV) ;
			else file_data = read_data2(filename) ;
			printf("\n--Data succesfully scanned--  \n");
			printf("Length of data : %d rows \n",length_of_list(file_data[0].liste)) ;
			break ;
		
		case 2: //ok
			printf("Entrez le nombre d'éléments de chaque colonne à lire : ");
			scanf("%d",&nb_elem) ;
			print_data_sample(file_data,nb_elem) ;
			break;
			
		case 3: //ok
			printf("Choisir un numéro de colonne : ");
			scanf("%d",&num_col) ;
			if( num_col > 0 ) print_stats_liste(file_data[num_col-1].liste) ;
			break;
			
		case 4:
			printf("Choisir un numéro de colonne ( \"0\" -> toutes les colonnes ) : ");
			scanf("%d",&num_col) ;
			printf("Entrez k : ");
			scanf("%d",&k) ;
			if ( num_col == 0 )
				{
				for( num_col = 1 ; num_col<=NB_COLS_UTILES ; num_col++ )
					{
					int len = length_of_list(file_data[num_col-1].liste) ;
					file_data[num_col-1].liste = suppr_k_sigma(file_data[num_col-1].liste,k) ;
					int nb_suppr = len - length_of_list(file_data[num_col-1].liste) ;
					printf("Colonne %d -> Supprimés : %d éléments \n",num_col,nb_suppr) ;
					}
				}
			else
				{
				int len = length_of_list(file_data[num_col-1].liste) ;
				file_data[num_col-1].liste = suppr_k_sigma(file_data[num_col-1].liste,k) ;
				int nb_suppr = len - length_of_list(file_data[num_col-1].liste) ;
				printf("\nSupprimés : %d éléments \n",nb_suppr) ;
				}
			break;
		
		case 5: //ok
			printf("Choisir un numéro de colonne : ");
			scanf("%d",&num_col) ;
			printf("Choisir le nombre de bins : ");
			scanf("%d",&nb_bins) ;
			intervalle* histogramme = get_histogramme(file_data[num_col-1].liste,nb_bins) ;
			printf("\n--Histogramme sauvegardé--  \n");
			print_histogramme(histogramme,nb_bins) ;
			break;
		
		case 6: //AAAAAAAAAAAAAAAAAAA
			printf("Choisir un numéro de colonne : ");
			scanf("%d",&num_col) ;
			printf("Choisir le nom du fichier destination : ") ;
			scanf("%s",destination) ;
			if ( strcmp(filename,all_str) == 0 ) wafer_data = all_wafers(NB_CSV) ;
			else wafer_data = read_wafers(filename) ;
			printf("\n--Wafers succesfully scanned--  \n");
			agregate_data( wafer_data , file_data[num_col-1].liste , destination ) ;
			printf("\n--File created--  \n");
			break ;
		
		case 9:
			//printf(" Plus jamais je code en C sous windows, c'était une mauvaise idée. \n -kez ") ; 
			//for( int i = 0 ; i<9 ; i++ ) printf("\n") ;
			return 0;
			break ;
		}

	}
}
