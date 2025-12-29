#ifndef LIVRO_H
#define LIVRO_H

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
typedef struct Livro Livro;

/**
 * @brief Lê as informações de um livro, conforme as especificações, e o constrói. 
 * Não é necessário alocar as strings dinamicamente, apenas o livro em si.
 * @return Um objeto do tipo livro lido da entrada padrão e devidamente alocado.
 */
Livro* livro_read_and_construct();

/**
 * @brief Imprime todas as informações de um livro na tela, conforme as especificações.
 * @param l Livro a ser impresso (passado como void*, é preciso fazer typecast dentro da função).
 */
void livro_print(void* l);

/**
 * @brief Destrói um livro, liberando toda a memória alocada para ele.
 * @param l Livro a ser liberado (passado como void*, é preciso fazer typecast dentro da função).
 */
void livro_destroy(void* l);


#endif