
#include <stdio.h>
#include <stdlib.h>

// Funções de conversão
double kgToGram(double kg) {
    return kg * 1000;
}

double kgToTonelada(double kg) {
    return kg / 1000;
}

double gramToKg(double gram) {
    return gram / 1000;
}

double gramToTonelada(double gram) {
    return gram / 1000000;
}

double toneladaToKg(double tonelada) {
    return tonelada * 1000;
}

double toneladaToGram(double tonelada) {
    return tonelada * 1000000;
}

// Função para realizar conversões baseadas nas escolhas
double realizarConversao(int choice, int destChoice, double value) {
    double result;

    switch (choice) {
        case 1: // Quilograma
            if (destChoice == 1) {
                result = value;
            } else if (destChoice == 2) {
                result = kgToGram(value);
            } else if (destChoice == 3) {
                result = kgToTonelada(value);
            }
            break;
        case 2: // Grama
            if (destChoice == 1) {
                result = gramToKg(value);
            } else if (destChoice == 2) {
                result = value;
            } else if (destChoice == 3) {
                result = gramToTonelada(value);
            }
            break;
        case 3: // Tonelada
            if (destChoice == 1) {
                result = toneladaToKg(value);
            } else if (destChoice == 2) {
                result = toneladaToGram(value);
            } else if (destChoice == 3) {
                result = value;
            }
            break;
        default:
            printf("Opção inválida\n");
            result = -1; // Indicador de erro
            break;
    }

    return result;
}

// Função de teste unitário usando entrada do terminal
void conversorMassa() {
    double valor;
    int origem, destino;
    double resultadoCalculado;

    // Lê cada entrada do terminal e executa a conversão
    printf("Insira valor, unidade de origem (1-kg, 2-g, 3-t) e unidade de destino (1-kg, 2-g, 3-t), separados por espaços:\n");
    if (scanf("%lf %d %d", &valor, &origem, &destino) != 3) {
        printf("Entrada inválida.\n");
        return;
    }

    resultadoCalculado = realizarConversao(origem, destino, valor);

    // Exibe o resultado com a unidade de destino
    const char* unidades[] = {"kg", "g", "t"};
    if (destino >= 1 && destino <= 3) {
        printf("Resultado obtido da conversão: %.2f %s\n", resultadoCalculado, unidades[destino - 1]);
    } else {
        printf("Unidade de destino inválida.\n");
    }
}


