/*
#Creamos el archivo .cpp
%%writefile SumaVectores.cpp
PROGRAMA:            SumaVectores_OpenMP.cpp
DESCRIPCIÓN:         Suma dos vectores con tipo de dato float y almacena el resultado
                     en un tercer vector del mismo tipo.
			               Paralelizamos la suma usando directivas de OpenMP.
AUTOR:               Francisco J. Hernández-López
Fecha Inicial:       16/Mar/2016
Fecha Actualización: 19/Oct/2023 Probándo el código en Google Colab
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <time.h>
//OpenMP
#include <omp.h>

void Suma_vectores(float *c, float *a, float *b, long int N)
{
	long int i;
#pragma omp parallel shared(a,b,c,N) private(i)
	{
#pragma omp for
		for (i = 0; i<N; i++){
			//c[i] = a[i] + b[i];
			c[i] = cos(a[i]) + (int)(b[i])%3;
		}
	}
}

// Código principal que se ejecuta en el Host
int main(void){
	float *a_h, *b_h, *c_h; //Punteros a arreglos en el Host
	long int N = 1000000000; //Número de elementos en los arreglos
	long int i;
	//struct timeb start, end;
	double t_ini, t_fin, time_cpu_seconds;

	int diff;
	size_t size_float = N * sizeof(float);
	a_h = (float *)malloc(size_float); // Pedimos memoria en el Host
	b_h = (float *)malloc(size_float);
	c_h = (float *)malloc(size_float); //También se puede con cudaMallocHost

	omp_set_num_threads(2); //Fijamos cuantos hilos vamos a lanzar

	//Inicializamos los arreglos a,b en el Host
/*#pragma omp parallel shared(a_h,b_h,N) private(i)
	{
#pragma omp for*/
		for (i = 0; i<N; i++){
			a_h[i] = (float)i;
			b_h[i] = (float)(i + 1);
		}
	//}

	printf("\nArreglo a:\n");
	for (i=0; i<20; i++) printf("%f ", a_h[i]);
	printf("\n\nArreglo b:\n");
	for (i=0; i<20; i++) printf("%f ", b_h[i]);

	printf("\n\nComenzando el procesamiento...");
	t_ini = clock();
	Suma_vectores(c_h, a_h, b_h, N);
	t_fin = clock();
	time_cpu_seconds = (t_fin - t_ini) / CLOCKS_PER_SEC;

	//Resultado
	printf("\n\nArreglo c:\n");
	for (i = 0; i<20; i++)
		printf("%f ", c_h[i]);

	printf("\nProcesamiento Finalizado...");
	printf("\nTiempo de procesamiento en CPU: %lf segundos.\n", time_cpu_seconds);

	// Liberamos la memoria del Host
	free(a_h);
	free(b_h);
	free(c_h);
	return(0);
}