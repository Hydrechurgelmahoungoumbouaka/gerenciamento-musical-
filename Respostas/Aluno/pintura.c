#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pintura.h"

#define MAXTAM_STRINGS 100

/**
 * @brief Estrutura de uma pintura, contendo:
 *
 * - Título
 *
 * - Artista
 *
 * - Movimento
 *
 * - Material
 *
 * - Ano
 */
struct Pintura
{
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    char movimento[MAXTAM_STRINGS];
    char material[MAXTAM_STRINGS];
    int anoPintura;
};

/**
 * @brief Lê as informações de uma pintura, conforme as especificações, e a constrói.
 * Não é necessário alocar as strings dinamicamente, apenas a pintura em si.
 * @return Um objeto do tipo pintura lido da entrada padrão e devidamente alocado.
 */
Pintura *pintura_read_and_construct()
{
    Pintura *pin = (Pintura *)malloc(sizeof(Pintura));
    if (pin == NULL)
    {
        printf("Erro ao alocar memoria para a pintura.\n");
        exit(1);
    }
    if (pin != NULL)
    {
        scanf("%s %s %s %s %d\n", pin->titulo, pin->artista, pin->movimento, pin->material, &pin->anoPintura);
    }
    else
    {
        exit(1);
    }

    return pin;
}

/**
 * @brief Imprime todas as informações de uma pintura na tela, conforme as especificações.
 * @param p pintura a ser impressa (passada como void*, é preciso fazer typecast dentro da função).
 */
void pintura_print(void *p)
{
    Pintura *pin = (Pintura *)p;

    if (pin != NULL)
    {
        printf("PINTURA\n");
        printf("Titulo: %s\n", pin->titulo);
        printf("Artista: %s\n", pin->artista);
        printf("Movimento: %s\n", pin->movimento);
        printf("Material: %s\n", pin->material);
        printf("Ano: %d\n", pin->anoPintura);
    }
}

/**
 * @brief Destrói uma pintura, liberando toda a memória alocada para ela.
 * @param p pintura a ser liberada (passada como void*, é preciso fazer typecast dentro da função).
 */
void pintura_destroy(void *p)
{
    Pintura *pin = (Pintura *)p;
    if (pin != NULL)
    {
        free(pin);
    }
}