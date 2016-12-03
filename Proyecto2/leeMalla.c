#include <stdlib.h>
#include <stdio.h>
#include "tipos.h"

void leeMalla(char *nomArchP, char *nomArchC, mallaCuadrilateros *malla) {
	FILE* ArchivoPuntos;
	FILE* ArchivoCuadrilateros;
	char linea[50];
	char temp[50];
	int points = 0, cuads = 0, i, j, k;

	//indices de Vertices en el archivo
	int A, B, C, D;
	int vertices[4];
	punto2D puntoTemp;


	//Primero contamos los puntos

	ArchivoPuntos = fopen(nomArchP, "r");

	if (ArchivoPuntos == NULL) {
		printf("Error al abrir el archivo\n");
		exit(1);
	}

	while (!feof(ArchivoPuntos)) {
		if (fgets(temp, 50, ArchivoPuntos))points++;
	}
	fclose(ArchivoPuntos);

	malla->numPuntos = points;
	printf("Numero de puntos: %d\n", points);

	//Ahora contamos los cuadrilateros

	ArchivoCuadrilateros = fopen(nomArchC, "r");
	if (ArchivoCuadrilateros == NULL) {
		printf("\nError al abirir el archivo\n");
		exit(1);
	}

	while (!feof(ArchivoCuadrilateros)) {
		if (fgets(temp, 50, ArchivoCuadrilateros))cuads++;
	}
	fclose(ArchivoCuadrilateros);

	malla->numCuadrados = cuads;
	printf("Numero de cuadrilateros: %d\n", cuads);

	malla->C = (cuadrilatero *)malloc(cuads*sizeof(cuadrilatero));

	ArchivoCuadrilateros = fopen(nomArchC, "r");
	if (ArchivoCuadrilateros == NULL) {
		printf("\nError al abirir el archivo\n");
		exit(1);
	}

	for (i = 0; i < cuads; i++) {
		fscanf(ArchivoCuadrilateros, "%d %d %d %d", &A, &B, &C, &D);
		vertices[0] = A; vertices[1] = B; vertices[2] = C; vertices[3] = D;

		for (j = 0; j < 3; j++) {
			ArchivoPuntos = fopen(nomArchP, "r");
			if (ArchivoPuntos == NULL) {
				printf("\nError al abrir el archivo");
				exit(1);
			}

			k = 0;
			while (k < vertices[j]) {
				fscanf(ArchivoPuntos, "%f %f", &puntoTemp.x, &puntoTemp.y);
				k++;
			}
			switch (j) {
			case 0:
				malla->C[i].v1 = puntoTemp;
				break;
			case 1:
				malla->C[i].v2 = puntoTemp;
				break;
			case 2:
				malla->C[i].v3 = puntoTemp;
				break;
			case 3:
				malla->C[i].v4 = puntoTemp;
				break;
			}
			fclose(ArchivoPuntos);
		}
	}
	fclose(ArchivoCuadrilateros);
}