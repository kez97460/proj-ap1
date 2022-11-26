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
noeud* usage_of_backing_film ; // colonne 7
noeud* usage_of_dresser ;
noeud* usage_of_polishing_table ;
noeud* usage_of_dresser_table ;
noeud* pressurized_chamber_pressure ;	
noeud* main_outer_air_bag_pressure ;	
noeud* center_air_bag_pressure ; 
noeud* retainer_ring_pressure ;
noeud* ripple_air_bag_pressure ;
noeud* usage_of_membrane ;
noeud* usage_of_pressurized_sheet ;
noeud* slurry_flow_line_a ;	
noeud* slurry_flow_line_b ;	
noeud* slurry_flow_line_c ;	
noeud* wafer_rotation ;	
noeud* stage_rotation ;	
noeud* head_rotation ;	
noeud* dressing_water_status ;	// colonne 24 : 0 ou 1 
noeud* edge_air_bag_pressure ; 
}
full_data ;

#endif



