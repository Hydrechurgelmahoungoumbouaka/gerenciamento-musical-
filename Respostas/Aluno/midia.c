#include "midia.h"
#include <stdlib.h>

struct Midia
{
    void* dado;
    PrintFunction print_fn;
    FreeFunction free_fn;
};

Midia *midia_construct(void *dado, PrintFunction print_fn, FreeFunction free_fn){
    Midia *m = (Midia*)malloc(sizeof(Midia));
    
    m->dado = dado;
    m->print_fn = print_fn;
    m->free_fn = free_fn;

    return m;
}

void midia_print(Midia* m){
    m->print_fn(m->dado);
}

void midia_destroy(Midia* m){
    if(m){
        m->free_fn(m->dado);
        free(m);
    }
}