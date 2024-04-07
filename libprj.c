#include "libprj.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

struct lista_t{
    int pos;
    contatos dados[TAM];
};

// Function to allocate the memory for the list
lista *criar_lista(){
    lista *li;
    li = (lista*) malloc(sizeof (lista));
    if (li!=NULL)
        li->pos = 0;    // If the memory allocation was successful, set the pointer to the position for the list to it's first place
    return li;
}

// Function to insert a person in the end of the list
int inserir_final(lista *li, contatos contatos){
    if (li == NULL || li->pos == TAM)    // Checking if the memory wasn't allocated or if the list is full
        return 0;
    li->dados[li->pos] = contatos;  // insert the data from the new person in the list
    li->pos++;      // increase the value of the pointer for the list position
    return 1;
}

// Function to print the whole list
void imprimir_lista(lista *li){
    for (int i = 0; i < li->pos; ++i) {     // print the whole list
        printf("Phone: %d\tName: %s\tEmail: %s\n", li->dados[i].phone, li->dados[i].name, li->dados[i].email);
    }
}

// Function to check if the list is ful
int lista_cheia(lista *li){
    if(li == NULL)
        return -1;
    return (li->pos == TAM);    // returns a boolean value
}

// Function to remove the last person from the list
int remover_final_lista(lista *li){
    if(li == NULL)
        return 0;
    if (li->pos == 0)   // checking if the list is empty
        return 0;
    li->pos--;  // decrease the pointer for the list position
    return 1;
}

// Function to sequencial search
int busca_sequencia(lista *li, char nome[30]){
    if(li == NULL)  // checking if the list is NULL
        return 0;
    int i = 0;
    while (strcmp(li->dados[i].name, nome) != 0){   // Iteration to sweep the list from it's begging till it's matching name
        i++;
        if(i > li->pos) // Stop the loop if the iteration surpass the position of the list
            return -1;
    }
    return i; // returns the position of the person in the list
}

// Function to remove a target from the list
int remover_da_lista(lista *li, char nome[30]){
    int x = busca_sequencia(li, nome);  // Finding which position of the list the target is
    if (x == -1)    // returns -1 if the target isn't in the list
        return -1;
    else {
        for (int i = x; i < li->pos; ++i) {
            li->dados[i] = li->dados[i+1];      // moving all elements one position backwards in the list until it reach the target position
        }
        li->pos--;  // decrease the pointer for the list position
    }
    return 1;
}

// Function to print a single target
void imprimir_contato(lista *li, char nome[30]){
    int x = busca_sequencia(li, nome);  // Set X to the list position value
    printf("Nome: %s\nTelefone: %d\nEmail: %s", li->dados[x].name, li->dados[x].phone, li->dados[x].email);     // print the specific target
}