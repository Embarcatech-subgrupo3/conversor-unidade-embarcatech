#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

double valor, horas, minutos, segundos;
char un_convert, opcao;

// Função para converter horas em minutos ou segundos
void convertehoras(double horas, char un_convert) {
    if (un_convert == 'M') {
        minutos = horas * 60;
        printf("%.2f horas é equivalente a %.2f minutos.\n", horas, minutos);
    } else if (un_convert == 'S') {
        segundos = horas * 3600;
        printf("%.2f horas é equivalente a %.2f segundos.\n", horas, segundos);    
    } else {
        printf("Unidade a ser convertida inválida.\n");
    }
}

// Função para converter minutos em horas ou segundos
void converteminutos(double minutos, char un_convert) {
    if (un_convert == 'H') {
        horas = minutos / 60.0;
        printf("%.2f minutos é equivalente a %.2f horas.\n", minutos, horas);
    } else if (un_convert == 'S') {
        segundos = minutos * 60;
        printf("%.2f minutos é equivalente a %.2f segundos.\n", minutos, segundos);    
    } else {
        printf("Unidade a ser convertida inválida.\n");
    }
}

// Função para converter segundos em horas ou minutos
void convertesegundos(double segundos, char un_convert) {
    if (un_convert == 'H') {
        horas = segundos / 3600.0;
        printf("%.2f segundos é equivalente a %.2f horas.\n", segundos, horas);
    } else if (un_convert == 'M') {
        minutos = segundos / 60;
        printf("%.2f segundos é equivalente a %.2f minutos.\n", segundos, minutos);    
    } else {
        printf("Unidade a ser convertida inválida.\n");
    }
}

void conversorTempo(void) {
    while (1) {
        printf("\nPROGRAMA PARA CONVERTER TEMPO\n");
        printf("Unidades suportadas: Horas (H), Minutos (M), Segundos (S)\n");

        printf("\nInsira o valor e a unidade inicial (ex: 2.5 H): ");
        scanf("%lf %c", &valor, &opcao);
        opcao = toupper(opcao);

        printf("Para qual unidade deseja converter? (H, M, S): ");
        scanf(" %c", &un_convert);
        un_convert = toupper(un_convert);

        switch (opcao) {
            case 'H':
                convertehoras(valor, un_convert);
                break;
            case 'M':
                converteminutos(valor, un_convert);
                break;
            case 'S':
                convertesegundos(valor, un_convert);
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
