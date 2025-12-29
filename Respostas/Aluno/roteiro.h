#ifndef ROTEIRO_H
#define ROTEIRO_H

#include "midia.h"

/**
 * @brief Estrutura do tipo Roteiro, contendo:
 * 
 * - Mídias: todas as mídias gerenciadas pelo sistema, assim como
 * as demais informações necessárias para a manipulação desse vetor dinâmico.
 */
typedef struct Roteiro Roteiro;

/**
 * @brief Cria um Roteiro, alocando dinamicamente seu vetor de mídias e a si mesmo.
 * @return Um Roteiro criado e devidamente alocado.
 */
Roteiro *roteiro_construct();

/**
 * @brief Insere uma nova mídia ao vetor guardado no roteiro, fazendo as manipulações de memória necessárias.
 * Essa função deve criar uma nova mídia internamente.
 * @param r Roteiro ao qual a mídia será adicionada.
 * @param dado A mídia em si (Livro, Música ou Pintura).
 * @param print_fn função de impressão da mídia (consulte "midia.h" para mais info).
 * @param free_fn função de liberação da mídia (consulte "midia.h" para mais info).
 */
void roteiro_inserir_midia(Roteiro* r, void *dado,  PrintFunction print_fn, FreeFunction free_fn);

/**
 * @brief Imprime todas as midias presentes em determinado roteiro na tela, usando midia_print.
 * 
 * Se houverem mídias no roteiro, inicia imprimindo "IMPRIMINDO MIDIAS\n".
 * 
 * Caso contrário, apenas imprime "SEM MIDIAS PARA IMPRIMIR\n".
 * @param r Roteiro do qual as mídias serão impressas.
 */
void roteiro_imprimir_midias(Roteiro *r);

/**
 * @brief Destrói um Roteiro, liberando todas as mídias, o vetor de mídias e o objeto do tipo Roteiro em si.
 * @param r Roteiro que será liberado.
 */
void roteiro_destroy(Roteiro *r);

#endif