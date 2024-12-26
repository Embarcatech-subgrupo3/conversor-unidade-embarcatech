// conversor de volume
//21/12/2024
// Unidades de volume (litro, mililitro, metros cúbicos)
#include <stdio.h>
#include <stdlib.h>

double valor, resultado;
char unidade_inicial, unidade_final;

int main()
{
    FILE *entrada = fopen("test_cases_1000.txt", "r");
    FILE *saida = fopen("output.txt", "w");

    if (entrada == NULL || saida == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    while (fscanf(entrada, "%lf\n%c\n%c\n", &valor, &unidade_inicial, &unidade_final) == 3)
    {
        // Função para converter de acordo com a unidade escolhida
        switch (unidade_inicial)
        {
        case 'l': // se a unidade inicial for litros
            switch (unidade_final)
            {
            case 'm': // se a unidade final for mililitro
                resultado = valor * 1000;
                break;
            case 'c': // se a unidade final for metros cubicos
                resultado = valor / 1000;
                break;
            default:
                fprintf(saida, "unidade final inválida\n");
                continue;
            }
            break;

        case 'm': // se a unidade inicial for mililitro
            switch (unidade_final)
            {
            case 'l': // se a unidade final for litro
                resultado = valor / 1000;
                break;
            case 'c': // se a unidade final for metros cubicos
                resultado = valor / 1000000;
                break;
            default:
                fprintf(saida, "unidade final inválida\n");
                continue;
            }
            break;

        case 'c': // se a unidade inicial for metros cubicos
            switch (unidade_final)
            {
            case 'm': // se a unidade final for mililitro
                resultado = valor * 1000000;
                break;
            case 'l': // se a unidade final for litros
                resultado = valor * 1000;
                break;
            default:
                fprintf(saida, "unidade final inválida\n");
                continue;
            }
            break;

        default:
            fprintf(saida, "unidade inicial inválida\n");
            continue;
        }

        // Escreve o resultado no arquivo de saída
        fprintf(saida, "%.2lf %c\n", resultado, unidade_final);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}