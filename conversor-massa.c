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

// Função de teste unitário usando arquivo
void testeUnitarioComArquivo(const char *massaconversor) {
    printf("Iniciando testes unitários a partir do arquivo %s...\n", massaconversor);

    // Abrindo o arquivo de teste
    FILE *arquivo = fopen(massaconversor, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", massaconversor);
        return;
    }

    double valor;
    int origem, destino;
    double resultadoEsperado, resultadoCalculado;

    // Lê cada linha do arquivo e executa os testes
    while (fscanf(arquivo, "%lf %d %d %lf", &valor, &origem, &destino, &resultadoEsperado) != EOF) {
        resultadoCalculado = realizarConversao(origem, destino, valor);

        // Compara o resultado calculado com o esperado
        printf("Testando: %lf %d -> %d\n", valor, origem, destino);
        printf("Resultado esperado: %.2f, Resultado calculado: %.2f\n", resultadoEsperado, resultadoCalculado);

        if (resultadoCalculado == resultadoEsperado) {
            printf("Teste passed!\n");
        } else {
            printf("Teste failed!\n");
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Testes unitários concluídos.\n");
}

int main() {
    int choice, destChoice;
    double value, result;
    char cont;

    // Chama a função de teste unitário usando arquivo
    testeUnitarioComArquivo("conversor-massa.txt");

    do {
        // Menu de opções para escolher a unidade de origem
        printf("Escolha a unidade de origem:\n");
        printf("1. Quilograma (kg)\n");
        printf("2. Grama (g)\n");
        printf("3. Tonelada (t)\n");
        scanf("%d", &choice);

        // Verificação de escolha válida
        if (choice < 1 || choice > 3) {
            printf("Opção inválida! Tente novamente.\n");
            continue;
        }

        // Solicita ao usuário o valor a ser convertido
        printf("Digite o valor para conversão: ");
        scanf("%lf", &value);
        if (value <= 0) {
            printf("O valor deve ser maior que zero! Tente novamente.\n");
            continue;
        }

        // Menu de opções para escolher a unidade de destino
        printf("Escolha a unidade de destino:\n");
        printf("1. Quilograma (kg)\n");
        printf("2. Grama (g)\n");
        printf("3. Tonelada (t)\n");
        scanf("%d", &destChoice);

        // Verificação de escolha válida
        if (destChoice < 1 || destChoice > 3) {
            printf("Opção inválida! Tente novamente.\n");
            continue;
        }

        // Chama a função de conversão
        result = realizarConversao(choice, destChoice, value);

        // Exibe o resultado da conversão
        printf("Resultado da conversão: %.2f\n", result);

        // Pergunta se o usuário deseja fazer outra conversão
        printf("Deseja realizar outra conversão? (s/n): ");
        scanf(" %c", &cont); // O espaço antes do %c serve para capturar o \n residual
    } while (cont == 's' || cont == 'S');
    
    return 0;
}