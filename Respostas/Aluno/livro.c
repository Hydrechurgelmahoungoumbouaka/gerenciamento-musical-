#include <stdio.h>
#include <stdlib.h>

#include "livro.h"

#define MAXTAM_STRINGS 100

/** @brief Estrutura do Livro, contendo:
 *
 * - Título
 *
 * - Autor
 *
 * - Gênero
 *
 * - Editora
 *
 * - Ano
 */
struct Livro
{
    char titulo[MAXTAM_STRINGS];
    char autor[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
    char editora[MAXTAM_STRINGS];
    int anoPublicacao;
};

/**
 * @brief Lê as informações de um livro, conforme as especificações, e o constrói.
 * Não é necessário alocar as strings dinamicamente, apenas o livro em si.
 * @return Um objeto do tipo livro lido da entrada padrão e devidamente alocado.
 */
Livro *livro_read_and_construct()
{
    Livro *l = (Livro *)calloc(1, sizeof(Livro));
    if (l == NULL)
    {
        printf("Erro ao alocar memoria para o livro.\n");
        exit(1);
    }
    if (l != NULL)
    {
        scanf("%s %s %s %s %d\n", l->titulo, l->autor, l->genero, l->editora, &l->anoPublicacao);
    }
    else
    {
        exit(1);
    }

    return l;
}

/**
 * @brief Imprime todas as informações de um livro na tela, conforme as especificações.
 * @param l Livro a ser impresso (passado como void*, é preciso fazer typecast dentro da função).
 */
void livro_print(void *l)
{
    Livro *livro = (Livro *)l;
    if (livro != NULL)
    {
        printf("LIVRO\n");
        printf("Titulo: %s\n", livro->titulo);
        printf("Autor: %s\n", livro->autor);
        printf("Genero: %s\n", livro->genero);
        printf("Editora: %s\n", livro->editora);
        printf("Ano: %d\n", livro->anoPublicacao);
    }
}

/**
 * @brief Destrói um livro, liberando toda a memória alocada para ele.
 * @param l Livro a ser liberado (passado como void*, é preciso fazer typecast dentro da função).
 */
void livro_destroy(void *l)
{
    Livro *livro = (Livro *)l;
    if (livro != NULL)
    {
        free(livro);
    }
}