#include "roteiro.h"
#include <stdlib.h>
#include <stdio.h>

struct Roteiro
{
    int num_midias;
    Midia **midias;
};

Roteiro *roteiro_construct(){
    Roteiro *r = (Roteiro*)calloc(1,sizeof(Roteiro));
    return r;
}

void roteiro_inserir_midia(Roteiro* r, void *dado,  PrintFunction print_fn, FreeFunction free_fn){
    r->num_midias++;
    r->midias = (Midia**)realloc(r->midias, r->num_midias * sizeof(Midia*));
    r->midias[r->num_midias - 1] = midia_construct(dado,print_fn,free_fn);
}

void roteiro_imprimir_midias(Roteiro *r){
    if(r->num_midias){
        printf("IMPRIMINDO MIDIAS\n");
        for(int i=0; i<r->num_midias; i++){
            printf("MIDIA %d: ",i+1);
            midia_print(r->midias[i]);
            printf("\n");
        }
    }
    else printf("SEM MIDIAS PARA IMPRIMIR\n");
}

void roteiro_destroy(Roteiro *r){
    if(r){
        for(int i=0; i<r->num_midias; i++){
            midia_destroy(r->midias[i]);
        }
        free(r->midias);
        free(r);
    }
}