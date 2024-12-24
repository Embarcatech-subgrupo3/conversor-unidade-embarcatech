#include <stdio.h>
#include <stdlib.h>
// #include "conversor-comprimento.h"
// #include "conversor-temperatura.h"
// #include "conversor-massa.h"
// #include "conversor-volume.h"
// #include "conversor-velocidade.h"
// #include "conversor-potencia.h"
// #include "conversor-area.h"
// #include "conversor-tempo.h"
// #include "conversor-dados.h"


// menu para mostrar as opções
void mostrarMenu() {
    printf("\n=== Conversor de Unidades ===\n");
    printf("1. Conversor de Comprimento\n");
    printf("2. Conversor de Massa\n");
    printf("3. Conversor de Volume\n");
    printf("4. Conversor de Temperatura\n");
    printf("5. Conversor de Velocidade\n");
    printf("6. Conversor de Potência\n");
    printf("7. Conversor de Área\n");
    printf("8. Conversor de Tempo\n");
    printf("9. Conversor de Dados Digitais\n");
    printf("10. Sair\n");
    printf("Selecione uma opção: ");
}

int main() {
    int opcao;

    do {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n=== Conversor de Comprimento ===\n");
                conversorComprimento();
                break;
            case 2:
                printf("\n=== Conversor de Massa ===\n");
                conversorMassa();
                break;
            case 3:
                printf("\n=== Conversor de Volume ===\n");
                conversorVolume();
                break;
            case 4:
                printf("\n=== Conversor de Temperatura ===\n");
                conversorTemperatura();
                break;
            case 5:
                printf("\n=== Conversor de Velocidade ===\n");
                conversorVelocidade();
                break;
            case 6:
                printf("\n=== Conversor de Potência ===\n");
                conversorPotencia();
                break;
            case 7:
                printf("\n=== Conversor de Área ===\n");
                conversorArea();
                break;
            case 8:
                printf("\n=== Conversor de Tempo ===\n");
                conversorTempo();
                break;
            case 9:
                printf("\n=== Conversor de Dados Digitais ===\n");
                conversorDados();
                break;
            case 10:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 10); // programa só finaliza quando tentar sair

    return 0;
}
