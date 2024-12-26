#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double valor, resultado;
char unidade_inicial, unidade_final;

void conversorVolume()
{
    while (1)
    {
        printf("\nPROGRAMA PARA CONVERTER VOLUMES\n");
        printf("Unidades suportadas: litro (l), mililitro (m), metros cúbicos (c)\n");

        printf("\nInsira o valor e a unidade inicial (ex: 1000 l): ");
        scanf("%lf %c", &valor, &unidade_inicial);

        printf("Para qual unidade deseja converter? (l, m, c): ");
        scanf(" %c", &unidade_final);

        // Função para converter de acordo com a unidade escolhida
        switch (unidade_inicial)
        {
        case 'l': // se a unidade inicial for litros
            switch (unidade_final)
            {
            case 'm': // se a unidade final for mililitro
                resultado = valor * 1000;
                break;
            case 'c': // se a unidade final for metros cúbicos
                resultado = valor / 1000;
                break;
            default:
                printf("Unidade final inválida\n");
                continue;
            }
            break;

        case 'm': // se a unidade inicial for mililitro
            switch (unidade_final)
            {
            case 'l': // se a unidade final for litro
                resultado = valor / 1000;
                break;
            case 'c': // se a unidade final for metros cúbicos
                resultado = valor / 1000000;
                break;
            default:
                printf("Unidade final inválida\n");
                continue;
            }
            break;

        case 'c': // se a unidade inicial for metros cúbicos
            switch (unidade_final)
            {
            case 'm': // se a unidade final for mililitro
                resultado = valor * 1000000;
                break;
            case 'l': // se a unidade final for litros
                resultado = valor * 1000;
                break;
            default:
                printf("Unidade final inválida\n");
                continue;
            }
            break;

        default:
            printf("Unidade inicial inválida\n");
            continue;
        }

        // Exibe o resultado
        printf("\n%.2lf %c equivale a %.2lf %c\n", valor, unidade_inicial, resultado, unidade_final);

        char continuar;
        printf("\nDeseja realizar outra conversão? (S para Sim / N para Não): ");
        scanf(" %c", &continuar);
        if (toupper(continuar) != 'S') break;
    }

    printf("\nObrigado por usar o programa! Encerrando...\n");
}
