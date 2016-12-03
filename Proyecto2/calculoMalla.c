#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tipos.h"

void calculoMalla(mallaCuadrilateros *malla, float * areas, float *perimetros) {
	int i, j;
	float area, perimetro, area1, area2;
	//En vez de puntos serian vectores
	punto2D lado1, lado2, lado3, lado4;
	punto2D lados[4];
	cuadrilatero cuadTemp;

	lados[0] = lado1;
	lados[1] = lado2;
	lados[2] = lado3;
	lados[3] = lado4;

	for (i = 0; i < malla->numCuadrados; i++) {
		cuadTemp = malla->C[i];
		//Para calcular el perimetro, debemos sumar todos los lados
		//Primero calculamos cada lado
		j = 0;
		while (j < 3) {
			if (j == 0) {
				lado1.x = cuadTemp.v2.x - cuadTemp.v1.x;
				lado1.y = cuadTemp.v2.y - cuadTemp.v1.y;
			}
			else if (j == 1) {
				lado2.x = cuadTemp.v3.x - cuadTemp.v2.x;
				lado2.y = cuadTemp.v3.y - cuadTemp.v2.y;
			}
			else if (j == 2) {
				lado3.x = cuadTemp.v4.x - cuadTemp.v3.x;
				lado3.y = cuadTemp.v4.y - cuadTemp.v3.y;
			}
			else if (j == 3) {
				lado4.x = cuadTemp.v1.x - cuadTemp.v4.x;
				lado4.y = cuadTemp.v1.y - cuadTemp.v4.y;
			}
			j++;
		}
		perimetro = sqrt(pow(lado1.x, 2) + pow(lado1.y, 2)) + sqrt(pow(lado2.x, 2) + pow(lado2.y, 2)) + 
			sqrt(pow(lado3.x, 2) + pow(lado3.y, 2)) + sqrt(pow(lado4.x, 2) + pow(lado4.y, 2));

		perimetros[i] = perimetro;

		//Ahora calculamos el area
		area1 = fabs((lado1.x*lado2.y) - (lado1.y*lado2.x));
		area2 = fabs((lado3.x*lado4.y) - (lado3.y*lado4.x));
		area = area1/2 + area2/2;

		areas[i] = area;
	}


	
}