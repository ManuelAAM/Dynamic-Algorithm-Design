#include "funciones.h"

int obtenerTamanioVarilla() {
    int tamanioVarilla;

    printf("Introduzca el tamanio de la varilla: ");
    scanf("%d", &tamanioVarilla);

    return tamanioVarilla;
}

void initArreglo(int **arreglo, int tamanio, int valor) {
    *arreglo = (int *)malloc(sizeof(int) * tamanio);

    if (*arreglo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < tamanio; i++) {
        (*arreglo)[i] = valor;
    }
}

int preguntarValoresPorUsuario() {
    char respuesta;

    printf("Desea introducir longitud y precio? (y/n): ");
    scanf(" %c", &respuesta);

    if (respuesta == 'y' || respuesta == 'Y') {
        return 1; 
    } else {
        return 0; 
    }
}

void ingresarPrecios(int *arreglo, int tam) {
    int tamVarilla;
    while (1) {
        printf("\nIngrese el tamanio del corte (-1 para salir): ");
        scanf("%d", &tamVarilla);

        if (tamVarilla == -1) {
            break; 
        }

        if (tamVarilla < 1 || tamVarilla > tam) {
            printf("Tamanio de corte no válido. Debe estar entre 1 y %d. Intente de nuevo.\n", tam);
            continue; 
        }

        printf("Inserte el precio para el tamanio %d: ", tamVarilla);
        scanf("%d", &arreglo[tamVarilla]);
    }
}

void imprimirSolucion(int* solucion, int tam){
	
	printf("\tLos tamanios  de corte son:");
	while(tam > 0){
		printf(" [%d]", solucion[tam]);
		tam = tam - solucion[tam];
	}
}

int cortarFuerzaBruta(int* precios, int tam, int nPrecios) {
    if (tam == 0) {
        return 0;
    }

    int maxGanancia = 0;

    for (int i = 1; i <= tam && i < nPrecios; i++) {
        int ganancia = precios[i] + cortarFuerzaBruta(precios, tam - i, nPrecios);
        if (ganancia > maxGanancia) {
            maxGanancia = ganancia;
        }
    }

    return maxGanancia;
}

int preguntarFuerzaBruta(){
	
	   char respuesta;

    printf("\nDesea mostrar la solucion por el metodo de fuerza bruta? (y/n): ");
    scanf(" %c", &respuesta);

    if (respuesta == 'y' || respuesta == 'Y') {
        return 1; 
    } else {
        return 0; 
    }
	
}