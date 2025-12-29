#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "roteiro.h"
#include "pintura.h"
#include "musica.h"
#include "livro.h"
#include "midia.h"

int main(int argc, char const *argv[])
{
    int qtdN;
    char opcao;
    Roteiro *r = roteiro_construct();
    scanf("%d\n", &qtdN);

    for (int i = 0; i < qtdN; i++)
    {
        scanf("%c\n", &opcao);
        if (opcao == 'P')
        {
            Pintura *pin = pintura_read_and_construct();
            roteiro_inserir_midia(r, pin, pintura_print, pintura_destroy);
        }
        else if (opcao == 'M')
        {
            Musica *music = musica_read_and_construct();
            roteiro_inserir_midia(r, music, musica_print, musica_destroy);
        }
        else if (opcao == 'L')
        {
            Livro *livro = livro_read_and_construct();
            roteiro_inserir_midia(r, livro, livro_print, livro_destroy);
        }
        else
        {
            printf("Opcao invalida\n");
        }
    }
    roteiro_imprimir_midias(r);
    roteiro_destroy(r);

    return 0;
}
