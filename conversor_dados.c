// conversor_dados_digitais.c
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

double converterDados(double valor, char unidade_origem[3], char unidade_destino[3]);

int main(void)
{
    char continuar;

    FILE *entrada = fopen("entradas_dados.txt", "r");
    FILE *saida = fopen("saidas_dados.txt", "w");

    if (entrada == NULL || saida == NULL)
    {
        printf("Erro ao abrir arquivo.");
        return 1;
    }

    fprintf(saida, "Resultados da conversão:\n");

    double valor;
    char unidade_origem[3], unidade_destino[3];

    while (fscanf(entrada, "%lf %2s %2s", &valor, unidade_origem, unidade_destino) == 3)
    {
        double resultado = converterDados(valor, unidade_origem, unidade_destino);

        if (resultado < 0)
        {
            fprintf(saida, "Unidade inválida: %s ou %s\n", unidade_origem, unidade_destino);
            continue;
        }

        fprintf(saida, "%.2f %s equivale a %.3f %s\n", valor, unidade_origem, resultado, unidade_destino);
    }

    fclose(entrada);
    fclose(saida);

    do {
        printf("\nPROGRAMA PARA CONVERTER DADOS DIGITAIS\n");
        printf("Unidades suportadas: bits (b), bytes (B), KB, MB, GB, TB\n");

        printf("\nInsira o valor e a unidade de origem (ex: 1024 KB): ");
        scanf("%lf %2s", &valor, unidade_origem);

        printf("Para qual unidade deseja converter? (b, B, KB, MB, GB, TB): ");
        scanf("%2s", unidade_destino);

        double resultado = converterDados(valor, unidade_origem, unidade_destino);

        if (resultado < 0)
        {
            printf("Unidade inválida. Encerrando...\n");
            exit(EXIT_FAILURE);
        }

        printf("\n%.2f %s equivale a %.3f %s\n", valor, unidade_origem, resultado, unidade_destino);

        printf("\nDeseja realizar outra conversão? (S para Sim / N para Não): ");
        scanf(" %c", &continuar);
        continuar = toupper(continuar);

    } while (continuar == 'S');

    printf("\nObrigado por usar o programa! Encerrando...\n");

    return 0;
}

double converterDados(double valor, char unidade_origem[3], char unidade_destino[3])
{
    double fator_origem = 1.0;
    double fator_destino = 1.0;

    if (strcmp(unidade_origem, "b") == 0)
        fator_origem = 1.0 / 8;
    else if (strcmp(unidade_origem, "B") == 0)
        fator_origem = 1.0;
    else if (strcmp(unidade_origem, "KB") == 0)
        fator_origem = 1024.0;
    else if (strcmp(unidade_origem, "MB") == 0)
        fator_origem = 1024.0 * 1024.0;
    else if (strcmp(unidade_origem, "GB") == 0)
        fator_origem = 1024.0 * 1024.0 * 1024.0;
    else if (strcmp(unidade_origem, "TB") == 0)
        fator_origem = 1024.0 * 1024.0 * 1024.0 * 1024.0;

    if (strcmp(unidade_destino, "b") == 0)
        fator_destino = 1.0 / 8;
    else if (strcmp(unidade_destino, "B") == 0)
        fator_destino = 1.0;
    else if (strcmp(unidade_destino, "KB") == 0)
        fator_destino = 1024.0;
    else if (strcmp(unidade_destino, "MB") == 0)
        fator_destino = 1024.0 * 1024.0;
    else if (strcmp(unidade_destino, "GB") == 0)
        fator_destino = 1024.0 * 1024.0 * 1024.0;
    else if (strcmp(unidade_destino, "TB") == 0)
        fator_destino = 1024.0 * 1024.0 * 1024.0 * 1024.0;

    return (valor * fator_origem) / fator_destino;
}
