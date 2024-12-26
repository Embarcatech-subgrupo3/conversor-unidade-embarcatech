#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double valor;
char unidade, opcao;

// Função para converter metros por segundo (m/s) para outras unidades de velocidade
void convertemetros_por_segundo(FILE *saida, double valor, char unidade) {
    if (unidade == 'K') {  // Para quilômetros por hora
        double kmh = valor * 3.6;
        fprintf(saida, "%.2f metros por segundo é equivalente a %.2f quilômetros por hora.\n", valor, kmh);
    }
    else if (unidade == 'M') {  // Para milhas por hora
        double mph = valor * 2.23694;
        fprintf(saida, "%.2f metros por segundo é equivalente a %.2f milhas por hora.\n", valor, mph);
    }
    else {
        fprintf(saida, "Unidade a ser convertida inválida.\n");
    }
}

// Função para converter quilômetros por hora (km/h) para outras unidades de velocidade
void convertequilometros_por_hora(FILE *saida, double valor, char unidade) {
    if (unidade == 'M') {  // Para metros por segundo
        double mps = valor / 3.6;
        fprintf(saida, "%.2f quilômetros por hora é equivalente a %.2f metros por segundo.\n", valor, mps);
    }
    else if (unidade == 'S') {  // Para milhas por hora
        double mph = valor / 1.60934;
        fprintf(saida, "%.2f quilômetros por hora é equivalente a %.2f milhas por hora.\n", valor, mph);
    }
    else {
        fprintf(saida, "Unidade a ser convertida inválida.\n");
    }
}

// Função para converter milhas por hora (mph) para outras unidades de velocidade
void convertemilhas_por_hora(FILE *saida, double valor, char unidade) {
    if (unidade == 'K') {  // Para quilômetros por hora
        double kmh = valor * 1.60934;
        fprintf(saida, "%.2f milhas por hora é equivalente a %.2f quilômetros por hora.\n", valor, kmh);
    }
    else if (unidade == 'S') {  // Para metros por segundo
        double mps = valor / 2.23694;
        fprintf(saida, "%.2f milhas por hora é equivalente a %.2f metros por segundo.\n", valor, mps);
    }
    else {
        fprintf(saida, "Unidade a ser convertida inválida.\n");
    }
}

int main(void) {

    FILE *entrada = fopen("entrada_velocidade.txt", "r");
    FILE *saida = fopen("saida.txt", "w");

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    fprintf(saida, "Resultado da conversão de velocidade:\n");

    while (fscanf(entrada, "%lf %c %c\n", &valor, &opcao, &unidade) == 3) {
        opcao = toupper(opcao);
        unidade = toupper(unidade);

        switch (opcao) {
            case 'M':  // Metros por segundo
                convertemetros_por_segundo(saida, valor, unidade);
                break;
            case 'K':  // Quilômetros por hora
                convertequilometros_por_hora(saida, valor, unidade);
                break;
            case 'S':  // Milhas por hora
                convertemilhas_por_hora(saida, valor, unidade);
                break;
            default:
                fprintf(saida, "Unidade inválida!\n");
                break;
        }
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}

    