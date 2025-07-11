#include <stdio.h>

int main() {
    // Carta 1
    char estado1;
    char codigo1[4];
    char nome_cidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int num_pontos_turisticos1;
    float densidade_populacional1;
    float pib_per_capita1;
    float super_poder1;

    // Carta 2
    char estado2;
    char codigo2[4];
    char nome_cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int num_pontos_turisticos2;
    float densidade_populacional2;
    float pib_per_capita2;
    float super_poder2;

    // Leitura dos dados da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nome_cidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &num_pontos_turisticos1);
    printf("\n");

    // Leitura dos dados da Carta 2
    printf("Digite os dados da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nome_cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &num_pontos_turisticos2);
    printf("\n");

    // Cálculo da Densidade Populacional e PIB per Capita para Carta 1
    densidade_populacional1 = (float)populacao1 / area1;
    pib_per_capita1 = pib1 * 1000000000.0 / populacao1; // Convertendo PIB para reais

    // Cálculo da Densidade Populacional e PIB per Capita para Carta 2
    densidade_populacional2 = (float)populacao2 / area2;
    pib_per_capita2 = pib2 * 1000000000.0 / populacao2; // Convertendo PIB para reais

    // Cálculo do Super Poder para Carta 1
    super_poder1 = (float)populacao1 + area1 + pib1 + num_pontos_turisticos1 + pib_per_capita1 + (1.0 / densidade_populacional1);

    // Cálculo do Super Poder para Carta 2
    super_poder2 = (float)populacao2 + area2 + pib2 + num_pontos_turisticos2 + pib_per_capita2 + (1.0 / densidade_populacional2);

    // Exibição dos dados da Carta 1
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nome_cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", num_pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);
    printf("\n");

    // Exibição dos dados da Carta 2
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nome_cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", num_pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);
    printf("\n");

    // Comparação das Cartas
    printf("Comparação de Cartas:\n");
    printf("População: Carta %d venceu (%d)\n", (populacao1 > populacao2) ? 1 : 2, (populacao1 > populacao2) ? 1 : 0);
    printf("Área: Carta %d venceu (%d)\n", (area1 > area2) ? 1 : 2, (area1 > area2) ? 1 : 0);
    printf("PIB: Carta %d venceu (%d)\n", (pib1 > pib2) ? 1 : 2, (pib1 > pib2) ? 1 : 0);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", (num_pontos_turisticos1 > num_pontos_turisticos2) ? 1 : 2, (num_pontos_turisticos1 > num_pontos_turisticos2) ? 1 : 0);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", (densidade_populacional1 < densidade_populacional2) ? 1 : 2, (densidade_populacional1 < densidade_populacional2) ? 1 : 0);
    printf("PIB per Capita: Carta %d venceu (%d)\n", (pib_per_capita1 > pib_per_capita2) ? 1 : 2, (pib_per_capita1 > pib_per_capita2) ? 1 : 0);
    printf("Super Poder: Carta %d venceu (%d)\n", (super_poder1 > super_poder2) ? 1 : 2, (super_poder1 > super_poder2) ? 1 : 0);

    return 0;
}
