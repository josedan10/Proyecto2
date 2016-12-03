#include <stdlib.h>
#include <stdio.h>

typedef struct {
	float x;
	float y;
}punto2D;

typedef struct {
	punto2D v1, v2, v3, v4;
}cuadrilatero;

typedef struct {
	int numPuntos;
	int numCuadrados;
	cuadrilatero *C;
}mallaCuadrilateros;