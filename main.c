#include "testing.h"
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

//void pruebas_heap_alumno(void);
//void pruebas_heap_catedra(void);
//void pruebas_heap_volumen_catedra(size_t, bool);

/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

int main(int argc, char *argv[])
<<<<<<< HEAD
{
    /*if (argc > 1) {
=======
{/*
    if (argc > 1) {
>>>>>>> 656a3f50e4cff57ea2ef50a50868f10c7000218f
        // Asumimos que nos están pidiendo pruebas de volumen.
        long largo = strtol(argv[1], NULL, 10);
        pruebas_heap_volumen_catedra((size_t) largo, false);
        return 0;
<<<<<<< HEAD
    }*/

=======
    }
*/
>>>>>>> 656a3f50e4cff57ea2ef50a50868f10c7000218f
    printf("~~~ PRUEBAS ALUMNO ~~~\n");
    pruebas_heap_alumno();
/*
    #ifdef CORRECTOR
        printf("\n~~~ PRUEBAS CÁTEDRA ~~~\n");
        pruebas_heap_catedra();
    #endif
*/
    return failure_count() > 0;
}
