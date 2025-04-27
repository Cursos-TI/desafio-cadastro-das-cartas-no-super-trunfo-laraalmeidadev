#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para a função exit()

// Estrutura para representar uma carta
typedef struct {
    char estado[3];
    char codigo[4];
    char nome_cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular a densidade populacional e o PIB per capita
void calcular_atributos(Carta *carta) {
    carta->densidade_populacional = (float)carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib * 1000000000.0 / carta->populacao;
    carta->super_poder = (float)carta->populacao + carta->area + carta->pib +
                         carta->num_pontos_turisticos + carta->pib_per_capita +
                         (1.0 / carta->densidade_populacional);
}

// Função para ler os dados de uma carta
void ler_carta(Carta *carta, int numero_carta) {
    printf("Digite os dados da Carta %d:\n", numero_carta);
    printf("Estado (ex: MG): ");
    scanf(" %2[^\n]", carta->estado);
    printf("Código da Carta (ex: A01): ");
    scanf("%3s", carta->codigo);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", carta->nome_cidade);
    printf("População: ");
    scanf("%lu", &carta->populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta->area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->num_pontos_turisticos);
    calcular_atributos(carta);
    printf("\n");
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta, int numero_carta) {
    printf("--- Carta %d ---\n", numero_carta);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome_cidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.num_pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta.pib_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
    printf("\n");
}

int main() {
    Carta carta1, carta2;
    int escolha;

    ler_carta(&carta1, 1);
    ler_carta(&carta2, 2);

    exibir_carta(carta1, 1);
    exibir_carta(carta2, 2);

    printf("Escolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("Opção: ");
    scanf("%d", &escolha);

    printf("\n--- Resultado da Comparação ---\n");

    if (escolha == 1) {
        printf("Comparando por População: Carta %d venceu (%lu)\n",
               (carta1.populacao > carta2.populacao) ? 1 : 2,
               (carta1.populacao > carta2.populacao) ? carta1.populacao : carta2.populacao);
    } else if (escolha == 2) {
        printf("Comparando por Área: Carta %d venceu (%.2f)\n",
               (carta1.area > carta2.area) ? 1 : 2,
               (carta1.area > carta2.area) ? carta1.area : carta2.area);
    } else if (escolha == 3) {
        printf("Comparando por PIB: Carta %d venceu (%.2f bilhões)\n",
               (carta1.pib > carta2.pib) ? 1 : 2,
               (carta1.pib > carta2.pib) ? carta1.pib : carta2.pib);
    } else if (escolha == 4) {
        printf("Comparando por Pontos Turísticos: Carta %d venceu (%d)\n",
               (carta1.num_pontos_turisticos > carta2.num_pontos_turisticos) ? 1 : 2,
               (carta1.num_pontos_turisticos > carta2.num_pontos_turisticos) ? carta1.num_pontos_turisticos : carta2.num_pontos_turisticos);
    } else {
        printf("Opção inválida!\n");
    }

    return 0;
}
