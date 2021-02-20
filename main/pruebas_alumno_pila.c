#include "pila.h"
#include "testing.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

bool pruebas_de_volumen(pila_t* pila, int volumen){
	int* vector = malloc(sizeof(int) * volumen);
	if(vector == NULL){
		return false;
	} 
    bool estado = true;
	for(int i = 0; i < volumen; i++){
		vector[i] = i+1;
		if(!pila_apilar(pila, &vector[i])){
            estado = false;
        }
	}
	for (int i = 0; i < volumen; i++){
        if((pila_ver_tope(pila) != &vector[volumen-i-1]) || (pila_desapilar(pila) != &vector[volumen-1-i])){
            estado = false;
        }
    }
    free(vector);
    return estado;

}

void pruebas_algunos_elementos(){
    /* Algunos elementos auxiliares*/
    int uno = 1;
    int dos = 2;
    int tres = 3;
    int cuatro = 4;

    pila_t* pila = pila_crear();

    print_test("La pila se creó correctamente", pila != NULL);
    print_test("La pila está vacía", pila_esta_vacia(pila));
    print_test("Desapilar una pila vacia es NULL", pila_desapilar(pila) == NULL);
    print_test("Ver tope es NULL", pila_ver_tope(pila) == NULL);
    print_test("Se apiló uno correctamente", pila_apilar(pila, &uno));
    print_test("La pila no está vacía", !pila_esta_vacia(pila));
    print_test("El tope es uno", pila_ver_tope(pila) == &uno);
    print_test("Se apiló dos correctamente", pila_apilar(pila, &dos));
    print_test("El tope es dos", pila_ver_tope(pila) == &dos);
    print_test("Se apiló tres correctamente", pila_apilar(pila, &tres));
    print_test("El tope es tres", pila_ver_tope(pila) == &tres);
    print_test("Se apiló cuatro correctamente", pila_apilar(pila, &cuatro));
    print_test("El tope es cuatro", pila_ver_tope(pila) == &cuatro);
    print_test("Desapilar es cuatro", pila_desapilar(pila) == &cuatro);
    print_test("Desapilar es tres", pila_desapilar(pila) == &tres);
    print_test("Desapilar es dos", pila_desapilar(pila) == &dos);
    print_test("Desapilar es uno", pila_desapilar(pila) == &uno);
    print_test("Desapilar es NULL", pila_desapilar(pila) == NULL);
    print_test("La pila está vacía", pila_esta_vacia(pila));
    print_test("Apilar NULL es válido", pila_apilar(pila, NULL));
    print_test("Ver tope es NULL", pila_ver_tope(pila) == NULL);
    print_test("Desapilar es NULL", pila_desapilar(pila) == NULL);
    pila_destruir(pila);
    print_test("La pila se destruyó correctamente", true);
}

void pruebas_pila_alumno(){
    printf("\n------------------ PRUEBAS ALGUNOS ELEMENTOS -----------\n");
    pruebas_algunos_elementos();

    pila_t* pila = pila_crear();

    printf("\n--------------------- PRUEBAS DE VOLUMEN ---------------\n");
    print_test("Prueba de volumen con 1000 elementos", pruebas_de_volumen(pila, 1000));
    print_test("Prueba de volumen con 10000 elementos", pruebas_de_volumen(pila, 10000));
    print_test("Prueba de volumen con 100000 elementos", pruebas_de_volumen(pila, 100000));
    pila_destruir(pila);
    print_test("La pila se destruyó correctamente", true);
}
