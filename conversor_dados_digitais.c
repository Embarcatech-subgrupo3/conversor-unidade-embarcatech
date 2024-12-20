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
    do {
    printf("\nPROGRAMA PARA CONVERTER DADOS DIGITAIS\n");
    printf("Unidades suportadas: bits (b), bytes (B), KB, MB, GB, TB\n");

    double valor;
    char unidade_origem[3];
    char unidade_destino[3];

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

        // Pergunta ao usuário se deseja fazer outra conversão
        printf("\nDeseja realizar outra conversão? (S para Sim / N para Não): ");
        scanf(" %c", &continuar);
        continuar = toupper(continuar);

    } while (continuar == 'S');

    printf("\nObrigado por usar o programa! Encerrando...\n");


    return 0;
}

double converterDados(double valor, char unidade_origem[3], char unidade_destino[3])
{
    return valor; // Função de conversão será implementada na próxima etapa
}
