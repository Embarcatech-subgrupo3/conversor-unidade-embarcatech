#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double valor;
char unidade, opcao;

// Função para converter metros por segundo (m/s) para outras unidades de velocidade
void convertemetros_por_segundo(double valor, char unidade) {
    if (unidade == 'K') {  // Para quilômetros por hora
        double kmh = valor * 3.6;
        printf("%.2f metros por segundo é equivalente a %.2f quilômetros por hora.\n", valor, kmh);
    } else if (unidade == 'M') {  // Para milhas por hora
        double mph = valor * 2.23694;
        printf("%.2f metros por segundo é equivalente a %.2f milhas por hora.\n", valor, mph);
    } else {
        printf("Unidade a ser convertida inválida.\n");
    }
}

// Função para converter quilômetros por hora (km/h) para outras unidades de velocidade
void convertequilometros_por_hora(double valor, char unidade) {
    if (unidade == 'M') {  // Para metros por segundo
        double mps = valor / 3.6;
        printf("%.2f quilômetros por hora é equivalente a %.2f metros por segundo.\n", valor, mps);
    } else if (unidade == 'S') {  // Para milhas por hora
        double mph = valor / 1.60934;
        printf("%.2f quilômetros por hora é equivalente a %.2f milhas por hora.\n", valor, mph);
    } else {
        printf("Unidade a ser convertida inválida.\n");
    }
}

// Função para converter milhas por hora (mph) para outras unidades de velocidade
void convertemilhas_por_hora(double valor, char unidade) {
    if (unidade == 'K') {  // Para quilômetros por hora
        double kmh = valor * 1.60934;
        printf("%.2f milhas por hora é equivalente a %.2f quilômetros por hora.\n", valor, kmh);
    } else if (unidade == 'S') {  // Para metros por segundo
        double mps = valor / 2.23694;
        printf("%.2f milhas por hora é equivalente a %.2f metros por segundo.\n", valor, mps);
    } else {
        printf("Unidade a ser convertida inválida.\n");
    }
}

void conversorVelocidade(void) {
    while (1) {
        printf("\nPROGRAMA PARA CONVERTER VELOCIDADES\n");
        printf("Unidades suportadas: Metros por segundo (M), Quilômetros por hora (K), Milhas por hora (S)\n");

        printf("\nInsira o valor e a unidade inicial (ex: 20 M): ");
        scanf("%lf %c", &valor, &opcao);
        opcao = toupper(opcao);

        printf("Para qual unidade deseja converter? (M, K, S): ");
        scanf(" %c", &unidade);
        unidade = toupper(unidade);

        switch (opcao) {
            case 'M':  // Metros por segundo
                convertemetros_por_segundo(valor, unidade);
                break;
            case 'K':  // Quilômetros por hora
                convertequilometros_por_hora(valor, unidade);
                break;
            case 'S':  // Milhas por hora
                convertemilhas_por_hora(valor, unidade);
                break;
            default:
                printf("Unidade inválida!\n");
                break;
        }

        char continuar;
        printf("\nDeseja realizar outra conversão? (S para Sim / N para Não): ");
        scanf(" %c", &continuar);
        if (toupper(continuar) != 'S') break;
    }

    printf("\nObrigado por usar o programa! Encerrando...\n");
}
