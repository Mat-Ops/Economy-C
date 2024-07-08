#include <stdio.h>
#include <stdlib.h>
#include "economia.h"

void inicializaLista(Economia **lista){
    *lista = NULL;
}

int listaVazia(Economia *lista){

   return(lista == NULL);
}

void imprimeLista(Economia *lista) {
  system("cls");
  while (lista != NULL) {
    printf("%d: %f\n", lista->ano, lista->PIB);
    lista = lista->proximo;
  }
  system("PAUSE>a");
}

Economia *criaEconomia(int ano, float PIB) {
  Economia *novo = malloc(sizeof(Economia));
  if (novo == NULL) {
    printf("Erro ao alocar memoria\n");
    return NULL;
  }

  novo->ano = ano;
  novo->PIB = PIB;
  novo->proximo = NULL;

  return novo;
}

void insereNoInicio(Economia **lista, int ano, float PIB) {
  Economia *novo = criaEconomia(ano, PIB);

  novo->ano = ano;
  novo->PIB = PIB;

  if(listaVazia(*lista)){
    novo->proximo = NULL;
    novo->anterior = NULL;
  }

else{
    novo->proximo = *lista;
    novo->anterior = NULL;
}

*lista = novo;

}

void insereNoFim(Economia **lista, int ano, float PIB) {
  Economia *novo = criaEconomia(ano, PIB);
  if (novo == NULL) return;

  if ((listaVazia(*lista))) {
    *lista = novo;
    novo->anterior = NULL;
  } else {
    Economia *aux = *lista;
    while (aux->proximo != NULL) {
      aux = aux->proximo;
    }
    aux->proximo = novo;
    novo->anterior = aux;
  }
}

void insereOrdenada(Economia **lista, int ano, float PIB) {
    Economia *novo = criaEconomia(ano, PIB);

    Economia *atual = *lista;
    Economia *anterior = *lista;

    novo->ano = ano;
    novo->PIB = PIB;
    novo->proximo = NULL;

    if(listaVazia(*lista)){
        novo->proximo = NULL;
        novo->anterior = NULL;
        *lista = novo;
        return;
    }

    while ((atual != NULL) && (atual->PIB < PIB)){
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual == *lista){
        insereNoInicio(lista, ano, PIB);
        return;
    }

    if(atual == NULL){
        insereNoFim(lista, ano, PIB);
        return;
    }

    novo->proximo = atual;
    novo->anterior = anterior;
    anterior->proximo = novo;
    atual->anterior = novo;
}

void carregarDados(FILE *arquivo, Economia **lista, int *TAM){

  char linha[100];
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    int ano;
    float PIB;
    sscanf(linha, "%d,%f", &ano, &PIB);

    //insere os dados na lista
    insereOrdenada(lista, ano, PIB);
    *TAM++; // incrementa qtd de dados na lista
  }
}

void dezMenores(Economia *lista){
    system("cls");
    printf("TOP 10 MENORES\n\n");
    for(int i=0; i<=9; i++){
    printf("%d: %f\n", lista->ano, lista->PIB);
    lista = lista->proximo;
    }
    system("PAUSE>a");
}

void dezMaiores(Economia *lista){
    Economia *anterior;
    Economia *aux = lista;

    system("cls");
    printf("TOP 10 MAIORES\n\n");
    while(aux != NULL){
        anterior = aux;
        aux = aux->proximo;
    }
    for(int i=0; i<=9; i++){
    printf("%d: %f\n", anterior->ano, anterior->PIB);
    anterior = anterior->anterior;
    }
    system("PAUSE>a");
}


