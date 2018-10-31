#include "testing.h"
#include "heap.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int funcion_comparacion_enteros(const void *a, const void *b){
    if(*(int*)a > *(int*)b) return 1;
    if(*(int*)a < *(int*)b) return -1;
    return 0;
}

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
    int *valor = NULL;
    print_test("Se han incertado los elementos correctamente", ok);
    print_test("El heap no esta vacio", !heap_esta_vacio(heap));
    print_test("La cantida de elementos es correcta", heap_cantidad(heap) == tope);
    print_test("Veo el elemento mayor", heap_ver_max(heap) == vector[tope-1]);
    print_test("Desencolo el mayor", (valor = heap_desencolar(heap)) == vector[tope-1]);
    print_test("El heap no esta vacio", !heap_esta_vacio(heap));
    print_test("La cantida de elementos es correcta", heap_cantidad(heap) == tope-1);
    print_test("Veo el elemento mayor", heap_ver_max(heap) == vector[tope-2]);


    heap_destruir(heap, free);
    free(vector);
    free(valor);

}

void pruebas_volumen(){
    heap_t *heap = heap_crear(funcion_comparacion_enteros);
    if(!heap) return;
    int tope = 10000;
    int **vector = malloc(sizeof(int*)*tope);
    bool ok = true;
    for(int i=0; i<tope; i++){
        vector[i] = malloc(sizeof(int*));
        *vector[i] = i;
        ok &= heap_encolar(heap, vector[i]);
    }
    int *valor = NULL;
    print_test("Se han incertado los elementos correctamente", ok);
    print_test("El heap no esta vacio", !heap_esta_vacio(heap));
    print_test("La cantida de elementos es correcta", heap_cantidad(heap) == tope);
    print_test("Veo el elemento mayor", heap_ver_max(heap) == vector[tope-1]);
    for(int i=0; i<tope/2; i++){
        valor = heap_desencolar(heap);
        free(valor);
    }
    print_test("El heap no esta vacio", !heap_esta_vacio(heap));
    print_test("La cantida de elementos es correcta", heap_cantidad(heap) == tope/2);
    print_test("Veo el elemento mayor", heap_ver_max(heap) == vector[tope/2-1]);


    heap_destruir(heap, free);
    free(vector);

}

void pruebas_heapsort(){
    srand((unsigned int)time(NULL));
    int tope = 15;
    void **vector = malloc(sizeof(void*)*tope);
    for(int i=0; i<tope; i++){
        vector[i] = malloc(sizeof(void*));
        *(int*)vector[i] = rand() % 100;
    }
    heap_sort(vector, tope, funcion_comparacion_enteros);
    printf("\n{");
    for(int i=0; i<tope; i++){
        printf("%d, ", *(int*)vector[i]);
    }
    printf("}\n");
    for(int i=0; i<tope; i++){
        free(vector[i]);
    }
    free(vector);
}

void pruebas_heap_alumno(){
    printf("\n~~~~PRUEBAS SENCILLAS~~~~\n");
    pruebas_sencillas();
    printf("\n~~~~PRUEBAS DE VOLUMEN~~~~\n");
    pruebas_volumen();
//    pruebas_heapify();
printf("\n~~~~PRUEBAS HEAPSORT~~~~\n");
    pruebas_heapsort();
}
