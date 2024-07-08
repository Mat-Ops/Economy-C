#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

void carregarVetor(Vetor *vetor, int n){
    FILE *arquivo = fopen("economia.txt", "r");
    int i = 0;

    if (arquivo == NULL){
        perror("Não foi possivel ler");
        exit(0);
    }
    while (!feof(arquivo)){
        fscanf(arquivo, "%d,%f\n", &vetor[i].ano,&vetor[i].PIB);
        i++;
    }
    fclose(arquivo);
}

void imprimeVetor (Vetor *vetor){
    system("cls");
    for(int i = 0; i<62; i++){
        printf("%d %.2f\n", vetor[i].ano, vetor[i].PIB);
    }
    system("PAUSE>a");
}

int pesquisaBinaria (Vetor *v, int inicio, int fim, int ano) {

    int meio = (inicio + fim) / 2;

    if (v[meio].ano == ano)
        return meio;

    if (inicio >= fim)
        return -1;

    if (ano < v[meio].ano)
        pesquisaBinaria(v, inicio, meio-1, ano);
    else
        pesquisaBinaria(v, meio+1, fim, ano);

}

void imprimeDados (Vetor *v, int ano) {
    if (ano == -1) {
        printf("\nAno nao encontrado!\n");
        return;
    }
    printf("\nANO PESQUISADO\n");
    printf("Ano: %d PIB: %.2f", v[ano].ano, v[ano].PIB);
}

void exibirPesquisa (Vetor *vetor){
    system("cls");
    int ano, pesquisa;
    printf("DIGITE O ANO->");
    scanf("%d", &ano);
    pesquisa = pesquisaBinaria(vetor, 0, 62, ano);
    imprimeDados (vetor, pesquisa);
    system("PAUSE>a");
}
