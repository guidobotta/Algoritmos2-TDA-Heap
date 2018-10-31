#include "testing.h"
#include "heap.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int funcion_comparacion_enteros(const void *a, const void *b){
    if(*(int*)a > *(int*)b) return 1;
    if(*(int*)a < *(int*)b) return -1;
    return 0;
}
print_test("Veo el elemento mayor", heap_ver_max(heap) == NULL);
void pruebas_sencillas(){
    heap_t *heap = heap_crear(funcion_comparacion_enteros);
    if(!heap) return;
    int tope = 25;
    int **vector = malloc(sizeof(int*)*tope);
    print_test("El heap esta vacio", heap_esta_vacio(heap));
    print_test("La cantida de elementos es correcta", heap_cantidad(heap) == 0);
    print_test("Veo el elemento mayor", heap_ver_max(heap) == NULL);
    print_test("Desencolo el mayor", heap_desencolar(heap) == NULL);
    print_test("Veo el elemento mayor", heap_ver_max(heap) == NULL);

    bool ok = true;
    for(int i=0; i<tope; i++){
        vector[i] = malloc(sizeof(int*));
        *vector[i] = i;
        ok &= heap_encolar(heap, vector[i]);
    }
    print_test("Se han incertado los elementos correctamente", ok);
    print_test("El heap no esta vacio", !heap_esta_vacio(heap));
    print_test("La cantida de elementos es correcta", heap_cantidad(heap) == tope);
    print_test("Veo el elemento mayor", heap_ver_max(heap) == vector[tope-1]);
    print_test("Desencolo el mayor", heap_desencolar(heap) == vector[tope-1]);
    print_test("El heap no esta vacio", !heap_esta_vacio(heap));
    print_test("La cantida de elementos es correcta", heap_cantidad(heap) == tope);
    print_test("Veo el elemento mayor", heap_ver_max(heap) == vector[tope-2]);

    heap_destruir(heap, free);

}


void pruebas_heap_alumno(){
    pruebas_sencillas();
//    pruebas_volumen();
//    pruebas_heapify();
//    pruebas_heapsort();
}
