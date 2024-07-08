#ifndef ECONOMIA_H
#define ECONOMIA_H

typedef struct Economia {
  int ano;
  float PIB;
  struct Economia *proximo, *anterior;
} Economia;

void inicializaLista(Economia **);
int listaVazia(Economia *);
void imprimeLista(Economia *);
Economia *criarEconomia(int, float);
void insereNoInicio(Economia **, int, float);
void insereNoFim(Economia **, int, float);
void insereOrdenada(Economia **, int, float);
void carregarDados(FILE *, Economia **, int *);
void dezMenores(Economia *);
void dezMaiores(Economia *);

/*

Fonte de Dados:
https://data.worldbank.org/indicator/NY.GDP.PCAP.KD.ZG?end=2022&start=1960&view=chart

*/


#endif // ECONOMIA_H
