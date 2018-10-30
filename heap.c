#include "heap.h"
#include <stdbool.h>
#include <stddef.h>

#define TAM 30

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

struct heap{
	void** tabla;
	size_t cantidad;
	size_t capacidad;
	cmp_func_t cmp;
};

 /* ******************************************************************
  *                      PRIMITIVAS PRIVADAS
  * *****************************************************************/

void swap(void** elem_1, void** elem_2){
	void* aux = *elem_1;
	*elem_1 = *elem_2;
	*elem_2 = aux;
}

 /* ******************************************************************
 *                      PRIMITIVAS DEL HEAP
 * *****************************************************************/

heap_t *heap_crear(cmp_func_t cmp){
	if(!cmp) return NULL;

	heap_t * heap = malloc(sizeof(heap_t));
	if(!heap) return NULL;

	void** tabla = malloc(sizeof(void*)*TAM);
	if(!tabla){
		free(heap);
		return NULL;
	}

	heap->tabla = tabla;
	heap->cmp = cmp;
	
	return heap;
} 

// Heapify
heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp){
	if(!cmp) return NULL;

	heap_t * heap = malloc(sizeof(heap_t));
	if(!heap) return NULL;
	
	void** tabla = malloc(sizeof(void*)*n);
	if(!tabla){
		free(heap);
		return NULL;
	}	

	//Copiar arreglo y hacer heapify
	
	return heap;
}

size_t heap_cantidad(const heap_t *heap){
	return heap->cantidad;
}

bool heap_esta_vacio(const heap_t *heap){
	return !heap->cantidad;
}

void up_heap(heap_t *heap, int pos){
	int padre = (pos-1)/2;
	if ( (padre < 0) || (heap->cmp(heap[pos], heap[padre])<0) ) return;

	swap(&heap[pos], &heap[padre]);
	up_heap(heap, padre);
}

void down_heap(heap_t* heap, int pos){
	int hijo_izq = (2*pos) + 1;
	int hijo_der = (2*pos) + 2;

	if ( (hijo_der < heap->cantidad) && (heap->cmp(heap[pos], heap[hijo_der]) < 0) ){
		if( heap->cmp(heap[hijo_izq], heap[hijo_der]) > 0 ){
			swap(&heap[pos], &heap[hijo_izq]);
			down_heap(heap, hijo_izq);
		}
		else{
			swap(&heap[pos], &heap[hijo_der]);
			down_heap(heap, hijo_der);
		}
	}
	else if ( (hijo_izq < heap->cantidad) && (heap->cmp(heap[pos], heap[hijo_izq]) < 0) ){
		swap(&heap[pos], &heap[hijo_izq]);
		down_heap(heap, hijo_izq);
	}

	return;
}

bool heap_encolar(heap_t *heap, void *elem){
	heap->tabla[capacidad] = elem;
	
	up_heap(heap,capacidad);
	heap->capacidad++;
}

void *heap_ver_max(const heap_t *heap){
	if (heap_esta_vacio(heap)) return NULL;
	return heap->tabla[0];
}

void *heap_desencolar(heap_t *heap){

	void* dato = heap->tabla[0];
	swap(&heap[0], &heap[capacidad-1]);

	capacidad--;
	down_heap(heap, 0);
}

void heap_destruir(heap_t *heap, void destruir_elemento(void *e)){
	
	if(destruir_elemento){
		for(size_t i=0; i<cantidad; i++){
			destruir_elemento(heap->tabla[i]);
		}
	}

	free(heap->tabla);
	free(heap);
}

///
// Heap Sort
///
void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp);