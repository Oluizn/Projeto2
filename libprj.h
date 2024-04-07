#ifndef LISTACONTATO_LIBRARY_H
#define LISTACONTATO_LIBRARY_H
#define TAM 100

typedef struct contatos_t{
    int phone;
    char name[30];
    char email[30];
} contatos;

typedef struct lista_t lista;
lista *criar_lista();
int inserir_final(lista *li, contatos contatos);
void imprimir_lista(lista *li);
int lista_cheia(lista *li);
int remover_final_lista(lista *li);
int busca_sequencia(lista *li, char nome[30]);
int remover_da_lista(lista *li, char nome[30]);
void imprimir_contato(lista *li, char nome[30]);

#endif //LISTACONTATO_LIBRARY_H
