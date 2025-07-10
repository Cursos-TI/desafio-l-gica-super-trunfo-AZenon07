#include <stdio.h>
#include <string.h>

struct Cidade {
    char estado[3];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

void cadastrarCidade(struct Cidade *cidade) {
    printf("Digite o estado (sigla, ex: SP): ");
    scanf("%s", cidade->estado);
    printf("Digite o codigo da cidade: ");
    scanf("%s", cidade->codigo);
    printf("Digite o nome da cidade: ");
    scanf("%s", cidade->nome);
    printf("Digite a populacao: ");
    scanf("%d", &cidade->populacao);
    printf("Digite a area (km²): ");
    scanf("%f", &cidade->area);
    printf("Digite o PIB (em milhoes): ");
    scanf("%f", &cidade->pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &cidade->pontosTuristicos);
}

void exibirCidade(struct Cidade cidade) {
    printf("\nCidade: %s\n", cidade.nome);
    printf("Estado: %s\n", cidade.estado);
    printf("Codigo: %s\n", cidade.codigo);
    printf("Populacao: %d\n", cidade.populacao);
    printf("Area: %.2f km²\n", cidade.area);
    printf("PIB: %.2f milhoes\n", cidade.pib);
    printf("Pontos Turisticos: %d\n\n", cidade.pontosTuristicos);
}

void compararCartas(struct Cidade cidade1, struct Cidade cidade2, int atributo) {
    float densidade1 = cidade1.populacao / cidade1.area;
    float densidade2 = cidade2.populacao / cidade2.area;
    
    switch (atributo) {
        case 1:
            if (cidade1.populacao > cidade2.populacao) {
                printf("Cidade %s venceu por maior populacao!\n", cidade1.nome);
            } else if (cidade1.populacao < cidade2.populacao) {
                printf("Cidade %s venceu por maior populacao!\n", cidade2.nome);
            } else {
                printf("Empate em populacao!\n");
            }
            break;
        case 2:
            if (cidade1.area > cidade2.area) {
                printf("Cidade %s venceu por maior area!\n", cidade1.nome);
            } else if (cidade1.area < cidade2.area) {
                printf("Cidade %s venceu por maior area!\n", cidade2.nome);
            } else {
                printf("Empate em area!\n");
            }
            break;
        case 3:
            if (cidade1.pib > cidade2.pib) {
                printf("Cidade %s venceu por maior PIB!\n", cidade1.nome);
            } else if (cidade1.pib < cidade2.pib) {
                printf("Cidade %s venceu por maior PIB!\n", cidade2.nome);
            } else {
                printf("Empate em PIB!\n");
            }
            break;
        case 4:
            if (cidade1.pontosTuristicos > cidade2.pontosTuristicos) {
                printf("Cidade %s venceu por mais pontos turisticos!\n", cidade1.nome);
            } else if (cidade1.pontosTuristicos < cidade2.pontosTuristicos) {
                printf("Cidade %s venceu por mais pontos turisticos!\n", cidade2.nome);
            } else {
                printf("Empate em pontos turisticos!\n");
            }
            break;
        case 5:
            if (densidade1 < densidade2) {
                printf("Cidade %s venceu por menor densidade populacional!\n", cidade1.nome);
            } else if (densidade1 > densidade2) {
                printf("Cidade %s venceu por menor densidade populacional!\n", cidade2.nome);
            } else {
                printf("Empate em densidade populacional!\n");
            }
            break;
        default:
            printf("Atributo invalido!\n");
    }
}

int main() {
    struct Cidade cidade1, cidade2;
    int opcao;
    
    printf("Cadastro da Cidade 1:\n");
    cadastrarCidade(&cidade1);
    printf("Cadastro da Cidade 2:\n");
    cadastrarCidade(&cidade2);
    
    printf("Cidades cadastradas:\n");
    exibirCidade(cidade1);
    exibirCidade(cidade2);
    
    do {
        printf("Escolha o atributo para comparacao:\n");
        printf("1 - Populacao\n");
        printf("2 - Area\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turisticos\n");
        printf("5 - Densidade Populacional\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        if (opcao >= 1 && opcao <= 5) {
            compararCartas(cidade1, cidade2, opcao);
        } else if (opcao != 0) {
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
    
    return 0;
}
