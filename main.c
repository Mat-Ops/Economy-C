#include <stdio.h>
#include <stdlib.h>
#include "economia.h"
#include "vetor.h"

int main()
{
    //abrir arquivo
    FILE *arquivo = fopen("economia.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    Vetor *vetor;
    vetor = (Vetor*)malloc(62 *sizeof(Vetor));

    Economia *lista;
    inicializaLista(&lista);
    int TAM = 0; //tamanho inicial da lista

    carregarDados(arquivo, &lista, &TAM);
    carregarVetor(vetor, 62);

    int opcao = 0;

    do{
        system("cls");
        printf("1 - Imprimir Dados\n");
        printf("2 - Imprimir Dados Ordenados\n");
        printf("3 - 10 anos de Maior Crescimento\n");
        printf("4 - 10 anos de Menor Crescimento\n");
        printf("5 - Pesquisar PIB por ano\n");
        printf("0 - Sair\n");
        printf("-->");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: imprimeLista(lista); break;
            case 2: imprimeLista(lista); break;
            case 3: dezMaiores(lista); break;
            case 4: dezMenores(lista); break;
            case 5: exibirPesquisa(vetor); break;
        }

    }while (opcao != 0);


    fclose(arquivo);

    return 0;
}
