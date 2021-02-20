#include "pila.h"
#include <stdlib.h>
#define TAM_INI 10
 /******************************
 * Alumno: Francisco Gutierrez *
 * Padrón: 103543              *
 * Corrector: Rodrigo Souto    *
 ******************************/

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};


// Funciones auxiliares

bool redimensionar(pila_t* pila, size_t factor){
	void** datos_aux = realloc(pila->datos, factor);
	if(datos_aux == NULL){
		return false;
	}
	pila->datos = datos_aux;
	pila->capacidad = factor / sizeof(void*);
	return true;
}

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/
pila_t* pila_crear(void){
	pila_t* pila = malloc(sizeof(pila_t));
	if (pila == NULL){
		return NULL;
	}

	void** datos = malloc(sizeof(void*) * TAM_INI);
	if(datos == NULL){
		free(pila);
		return NULL;
	}

	pila->datos = datos;
	pila->cantidad = 0;
	pila-> capacidad = TAM_INI;
	return pila;
}

void pila_destruir(pila_t *pila){
	free(pila->datos);
	free(pila);
}

bool pila_esta_vacia(const pila_t *pila){
	return pila->cantidad == 0;
}

bool pila_apilar(pila_t *pila, void* valor){
	if(pila->cantidad == pila->capacidad){
		if(!redimensionar(pila, pila->capacidad*2 * sizeof(void*))){
			return false;
		}
	}

	pila->datos[pila->cantidad] = valor;
	pila->cantidad++;
	return true;
}

void* pila_ver_tope(const pila_t *pila){
	if(pila->cantidad == 0){
		return NULL;
	}
	return pila->datos[pila->cantidad-1];
}

void* pila_desapilar(pila_t *pila){
	if(pila->cantidad == 0){
		return NULL;
	}
	if((pila->cantidad > TAM_INI) && (pila->cantidad < pila->capacidad/4)){
		if(redimensionar(pila, (pila->capacidad/2) * sizeof(void*))){
		}
	}
	void* dato = pila->datos[pila->cantidad-1];
	pila->cantidad--;
	return dato;
}

