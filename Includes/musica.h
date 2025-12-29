#ifndef MUSICA_H
#define MUSICA_H

#define MAXTAM_STRINGS 100

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
typedef struct Musica Musica;

/**
 * @brief Lê as informações de uma música, conforme as especificações, e a constrói. 
 * Não é necessário alocar as strings dinamicamente, apenas a música em si.
 * @return Um objeto do tipo música lido da entrada padrão e devidamente alocado.
 */
Musica* musica_read_and_construct();

/**
 * @brief Imprime todas as informações de uma música na tela, conforme as especificações.
 * @param m música a ser impressa (passada como void*, é preciso fazer typecast dentro da função).
 */
void musica_print(void* m);

/**
 * @brief Destrói uma música, liberando toda a memória alocada para ela.
 * @param m música a ser liberada (passada como void*, é preciso fazer typecast dentro da função).
 */
void musica_destroy(void* m);


#endif