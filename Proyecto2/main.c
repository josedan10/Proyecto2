#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "tipos.h"

void leeMalla(char *, char *, mallaCuadrilateros *);

void calculoMalla(mallaCuadrilateros *, float*, float *);


int main() {

	char nomArchC[51], nomArchP[51];
	mallaCuadrilateros malla;
	float *perimetros, *areas;
	int i;
	FILE *salida;

	printf("Introduzca el nombre del archivo que contiene los puntos: ");
	scanf("%s%[^\n]", nomArchP);
	printf("\nIntroduzca el nombre del archivo que contiene los cuadrilatero: ");
	scanf("%s%[^\n]", nomArchC);
	//scanf("%50c%[^\n]", nomArchC);
	
	leeMalla(nomArchP, nomArchC, &malla);
	areas = (float *)malloc(malla.numCuadrados*sizeof(float));
	perimetros = (float *)malloc(malla.numCuadrados*sizeof(float));

	calculoMalla(&malla, areas, perimetros);

	salida = fopen("resultados.txt", "w");
	if (salida == NULL) {
		printf("\nError en el archivo de salida\n");
		return 0;
	}
	for (i = 0; i < malla.numCuadrados; i++) {
		fprintf("%d %f %f\n", i, areas[i], perimetros[i]);
	}
	fclose(salida);
	printf("\nSe ha generado el archivo 'resultados.txt'\n");

	system("PAUSE");
	return 0;
}