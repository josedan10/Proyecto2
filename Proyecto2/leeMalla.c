#include <stdlib.h>
#include <stdio.h>
#include "tipos.h"

void leeMalla(char *nomArchP, char *nomArchC, mallaCuadrilateros *malla) {
	FILE* ArchivoPuntos;
	FILE* ArchivoCuadrilateros;
	char linea[50];
	char temp[50];
	int points = 0, cuads = 0, i, j, k;
	//int prueba;
	//cuadrilatero *Cuadri;

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
	int* ptr, prueba[] = {13312,32,413,23 };
	ptr = (int*)malloc(4 * sizeof(int));
	if (ptr == NULL) {
		printf("\nError en la reserva de memoria de la prueba");
		exit(1);
	}
	//prueba


	//malla->C = (cuadrilatero *)calloc(400, sizeof(cuadrilatero));
	malla->C = (cuadrilatero *)calloc(cuads,sizeof(cuadrilatero));
	// = Cuadri;
	//ptr = cuads*sizeof(cuadrilatero);

	ArchivoCuadrilateros = fopen(nomArchC, "r");
	if (ArchivoCuadrilateros == NULL) {
		printf("\nError al abirir el archivo\n");
		exit(1);
	}
	ptr[0] = 5;
	ptr[1] = 43;

	for (i = 0; i < cuads; i++) {
		fscanf(ArchivoCuadrilateros, "%d %d %d %d", &A, &B, &C, &D);
		vertices[0] = A; vertices[1] = B; vertices[2] = C; vertices[3] = D;

		for (j = 0; j <=3; j++) {
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
	//printf("\nNumero de puntos: %d", malla->numPuntos);
	//printf("\nNumero de cuadrilateros: %d", malla->numCuadrados);
	//printf("\nPrimeros cuadrilateros: \n");
	//printf("\nEl primer cuadrilatero tiene:");
	//printf("\nv1 (%.5f,%.5f)", malla->C[0].v1.x, malla->C[0].v1.y);
	//printf("\nv2 (%.5f,%.5f)", malla->C[0].v2.x, malla->C[0].v2.y);
	//printf("\nv3 (%.5f,%.5f)", malla->C[0].v3.x, malla->C[0].v3.y);
	//printf("\nv4 (%.5f,%.5f)", malla->C[0].v4.x, malla->C[0].v4.y);
	//printf("\nPrimeros cuadrilateros: \n");
	//printf("\nEl segundo cuadrilatero tiene:");
	//printf("\nv1 (%.5f,%.5f)", malla->C[1].v1.x, malla->C[0].v1.y);
	//printf("\nv2 (%.5f,%.5f)", malla->C[1].v2.x, malla->C[0].v2.y);
	//printf("\nv3 (%.5f,%.5f)", malla->C[1].v3.x, malla->C[0].v3.y);
	//printf("\nv4 (%.5f,%.5f)", malla->C[1].v4.x, malla->C[0].v4.y);
	//system("pause");



	fclose(ArchivoCuadrilateros);
}