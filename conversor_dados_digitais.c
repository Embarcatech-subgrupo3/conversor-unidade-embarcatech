#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

double converterDados(double valor, char unidade_origem[3], char unidade_destino[3]);

int main(void)
{
    FILE *entrada = fopen("entradas.txt", "r");
    FILE *saida = fopen("saidas.txt", "w");

    if (entrada == NULL || saida == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    fprintf(saida, "Resultados das conversões de dados digitais:\n");

    double valor;
    char unidade_origem[3], unidade_destino[3];

    while (fscanf(entrada, "%lf %2s %2s\n", &valor, unidade_origem, unidade_destino) == 3)
    {
        // Chama a função de conversão
        double resultado = converterDados(valor, unidade_origem, unidade_destino);

        if (resultado < 0)
        {
            fprintf(saida, "Unidade inválida para %s para %s. Conversão não realizada.\n", unidade_origem, unidade_destino);
        }
        else
        {
            fprintf(saida, "%.2f %s equivale a %.3f %s\n", valor, unidade_origem, resultado, unidade_destino);
        }
    }

    fclose(entrada);
    fclose(saida);

    printf("Conversões completas. Resultados foram gravados em 'saidas.txt'.\n");

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
