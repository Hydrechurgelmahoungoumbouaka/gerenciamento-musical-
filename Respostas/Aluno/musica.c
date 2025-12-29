#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "musica.h"

#define MAXTAM_STRINGS 100
#define MAXTAM_PARTICIPANTES 5
/**
 * @brief Estrutura da Música, contendo:
 *
 * - Título
 *
 * - Artista
 *
 * - Número de participantes
 *
 * - Participantes (vetor)
 *
 * - Álbum
 *
 * - Gênero
 */
struct Musica
{
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    int numParticipante;
    char participantes[MAXTAM_PARTICIPANTES][MAXTAM_STRINGS];
    char album[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
};

/**
 * @brief Lê as informações de uma música, conforme as especificações, e a constrói.
 * Não é necessário alocar as strings dinamicamente, apenas a música em si.
 * @return Um objeto do tipo música lido da entrada padrão e devidamente alocado.
 */
Musica *musica_read_and_construct()
{
    Musica *musica = (Musica *)calloc(1, sizeof(Musica));
    if (musica == NULL)
    {
        printf("Erro ao alocar memoria para musica.\n");
        exit(1);
    }

    if (musica != NULL)
    {
        scanf("%s %s %d\n", musica->titulo, musica->artista, &musica->numParticipante);
        for (int i = 0; i < musica->numParticipante; i++)
        {
            scanf("%s\n", musica->participantes[i]);
        }
        scanf("%s %s\n", musica->album, musica->genero);
    }
    else
    {
        exit(1);
    }

    return musica;
}

/**
 * @brief Imprime todas as informações de uma música na tela, conforme as especificações.
 * @param m música a ser impressa (passada como void*, é preciso fazer typecast dentro da função).
 */
void musica_print(void *m)
{
    Musica *music = (Musica *)m;

    printf("MUSICA\n");
    printf("%s - %s", music->artista, music->titulo);

    if (music->numParticipante)
    {
        printf(" (feat.");
        for (int i = 0; i < music->numParticipante; i++)
        {
            printf(" %s", music->participantes[i]);
            if (i + 1 < music->numParticipante)
                printf(",");
        }
        printf(")");
    }
    printf("\n");
    printf("Album: %s\n", music->album);
    printf("Genero: %s\n", music->genero);
}

/**
 * @brief Destrói uma música, liberando toda a memória alocada para ela.
 * @param m música a ser liberada (passada como void*, é preciso fazer typecast dentro da função).
 */
void musica_destroy(void *m)
{
    Musica *music = (Musica *)m;
    if (music != NULL)
    {
        free(music);
    }
}