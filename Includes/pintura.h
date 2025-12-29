#ifndef PINTURA_H
#define PINTURA_H

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
typedef struct Pintura Pintura;

/**
 * @brief Lê as informações de uma pintura, conforme as especificações, e a constrói. 
 * Não é necessário alocar as strings dinamicamente, apenas a pintura em si.
 * @return Um objeto do tipo pintura lido da entrada padrão e devidamente alocado.
 */
Pintura* pintura_read_and_construct();

/**
 * @brief Imprime todas as informações de uma pintura na tela, conforme as especificações.
 * @param p pintura a ser impressa (passada como void*, é preciso fazer typecast dentro da função).
 */
void pintura_print(void* p);

/**
 * @brief Destrói uma pintura, liberando toda a memória alocada para ela.
 * @param p pintura a ser liberada (passada como void*, é preciso fazer typecast dentro da função).
 */
void pintura_destroy(void* p);


#endif