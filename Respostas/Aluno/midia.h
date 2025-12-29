#ifndef MIDIA_H 
#define MIDIA_H

/**
 * @brief Definição do tipo de funções de callback que irão imprimir determinada Mídia.
 * 
 * Essas funções já estão implementadas nos outros TADs, o typedef é apenas uma declaração do ponteiro para
 * a função de callback genérica, que pode assumir como valor as funções:
 * 
 * - livro_print
 * 
 * - musica_print
 * 
 * - pintura_print
 * 
 * @param data Mídia que será impressa, que pode ser Livro, Música ou Pintura.
 */
typedef void (*PrintFunction)(void* data);

/**
 * @brief Definição do tipo de funções de callback que irão liberar determinada Mídia da memória.
 * 
 * Essas funções já estão implementadas nos outros TADs, o typedef é apenas uma declaração do ponteiro para
 * a função de callback genérica, que pode assumir como valor as funções:
 * 
 * - livro_destroy
 * 
 * - musica_destroy
 * 
 * - pintura_destroy
 * 
 * @param data Mídia que será liberada, que pode ser Livro, Música ou Pintura.
 */
typedef void (*FreeFunction)(void* data);

/**
 * @brief Estrutura do tipo Mídia, contendo:
 * 
 * - Dado : a midia em si (ponteiro void que guarda um Livro, Música ou Pintura)
 * 
 * - Print_fn: objeto do tipo PrintFunction que guarda qual a função que imprime a Mídia
 * 
 * - Free_fn: objeto do tipo FreeFunction que guarda qual a função que libera a Mídia
 */
typedef struct Midia Midia;

/**
 * @brief Cria uma Mídia alocada dinamicamente, a partir dos parâmetros dados.
 * 
 * OBS: Ao usar/chamar a função, print_fn e free_fn devem ser funções já criadas nos outros TADs,
 * passadas diretamente como argumentos.
 * @param dado a midia em si (ponteiro void que guarda um Livro, Música ou Pintura).
 * @param print_fn objeto do tipo PrintFunction que guarda qual a função que imprime a Mídia.
 * @param free_fn objeto do tipo FreeFunction que guarda qual a função que libera a Mídia.
 * @return Um objeto do tipo música lido da entrada padrão e devidamente alocado.
 */
Midia *midia_construct(void *dado, PrintFunction print_fn, FreeFunction free_fn);

/**
 * @brief Imprime uma Mídia na tela, usando a função de impressão presente na própria Mídia.
 * @param m Mídia a ser impressa.
 */
void midia_print(Midia* m);

/**
 * @brief Libera uma Mídia da memória, usando a função de liberação presente na própria Mídia.
 * @param m Mídia a ser liberada.
 */
void midia_destroy(Midia* m);


#endif