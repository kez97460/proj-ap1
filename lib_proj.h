/* 
Auteur : Kezia Marcou 
Une description de chaque fonction est présente la ligne avant sa définition

>> Pour compiler un programme ( main.c ) qui utilise cette librairie :
1.  gcc -c lib_proj.c ( pour créer arrays_utils.o )
2.  gcc -c main.c ( pour créer main.o )
3.  gcc main.o lib_proj.o -o appli ( pour créer l'executable appli )

>> Lignes de code modifiables :
*/

typedef struct 
{
float usage_of_backing_film ; // colonne 7
float usage_of_dresser ;
float usage_of_polishing_table ;
float usage_of_dresser_table ;
float pressurized_chamber_pressure ;	
float main_outer_air_bag_pressure ;	
float center_air_bag_pressure ; 
float retainer_ring_pressure ;
float ripple_air_bag_pressure ;
float usage_of_membrane ;
float usage_of_pressurized_sheet ;
float slurry_flow_line_a ;	
float slurry_flow_line_b ;	
float slurry_flow_line_c ;	
float wafer_rotation ;	
float stage_rotation ;	
float head_rotation ;	
int dressing_water_status ;	// colonne 24 : 0 ou 1 , pas utile pour des stats I guess
float edge_air_bag_pressure ; 
}
data_point ;

