appli: lib_proj.o float_lists_utils.o main.o
	gcc float_lists_utils.o lib_proj.o main.o -o app2 -lm
	
main.o: main.c
	gcc -c main.c

float_lists_utils.o: float_lists_utils.c
	gcc -c float_lists_utils.c
	
lib_proj.o: lib_proj.c
	gcc -c lib_proj.c
