/*
#Creamos el archivo .cpp
%%writefile HelloWorld.cpp
*/
#include <stdio.h>
#include <iostream>

//OpenMP
#include <omp.h>

int main(void) {
	//FILE* fp = fopen("output.txt", "w");
	int nthreads, tid;

	omp_set_num_threads(24);

	/*Se hace el Fork para generar los hilos y sus propias copias de variables*/
#pragma omp parallel private(tid)
	{
		/*Se obtiene y se imprime el id de los hilos generados*/
		tid = omp_get_thread_num();
		printf("Hola Mundo, soy el Hilo = %d\n", tid);
		//fprintf(fp,"Hola Mundo, soy el Hilo = %d\n", tid);

		/*Unicamente el hilo con id==0 hace esto*/
		if (tid == 0) {
			nthreads = omp_get_num_threads();
			printf("Numero de hilos = %d\n", nthreads);
			//fprintf(fp,"Numero de hilos = %d\n", nthreads);
		}
	}  /* Todos los hilos se sincronizan y terminan aqui con Join */
	//fclose(fp);
	return(0);
}

