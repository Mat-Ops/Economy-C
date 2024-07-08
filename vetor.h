#ifndef VETOR_H
#define VETOR_H

typedef struct _vetor {
  int ano;
  float PIB;
  struct _vetor *proximo;
} Vetor;

void carregarVetor(Vetor *, int);
void imprimeVetor(Vetor *);
int pesquisaBinaria(Vetor *, int, int, int);
void imprimiResultado(Vetor *, int);
void exibirPesquisa(Vetor *);

#endif
