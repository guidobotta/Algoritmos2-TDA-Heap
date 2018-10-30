#include <>

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

 void swap();

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

/*
 * Constructor alternativo del heap. Además de la función de comparación,
 * recibe un arreglo de valores con que inicializar el heap. Complejidad
 * O(n).
 *
 * Excepto por la complejidad, es equivalente a crear un heap vacío y encolar
 * los valores de uno en uno
*/
heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp){

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

size_t heap_cantidad(const heap_t *heap){
	return heap->cantidad;
}

bool heap_esta_vacio(const heap_t *heap){
	return !heap->cantidad;
}


void up_heap(heap_t *heap, size_t posicion){
	size_t padre = (posicion-1)/2;
	if(padre < 0) return;
	if(cmp(padre, posicion)<0) swap(heap, padre, hijo);
	up_heap(heap, padre);
}

void down_heap(heap_t* heap, size_t pos){
	size_t hijo_izq = 2i+1;
	size_t hijo_der = 2i+2;
	if(hijo_izq<capacidad && heap->cmp(heap->tabla[pos], heap->tabla[hijo_izq]) < 0){
		swap(heap, hijo);
	}
}

bool heap_encolar(heap_t *heap, void *elem){
	heap->tabla[capacidad] = elem;
	
	up_heap(heap,capacidad);
	heap->capacidad++;
}

void *heap_ver_max(const heap_t *heap){
	return heap->tabla[0];
}

void *heap_desencolar(heap_t *heap){
	void* dato = heap->tabla[0];
	swap(heap, 0, capacidad-1);
	capacidad--;
	down_heap(heap, 0);
}

///
// Heap Sort
///
void heap_sort(void *elementos[], size_t cant, cmp_func_t cmp);