#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


double valor, horas, minutos, segundos;
char un_convert, opcao;


// Função para converter horas em minutos ou segundos
void convertehoras(FILE *saida, double horas, char un_convert){
    if(un_convert == 'M'){
    minutos = horas*60;
    fprintf(saida, "%.2f horas é equivalente a %.2f minutos.\n", horas, minutos);
    }
    else if (un_convert == 'S') {
    segundos = horas*3600;
    fprintf(saida, "%.2f horas é equivalente a %.2f segundos.\n", horas, segundos);    
    }
    else {
        fprintf(saida, "Unidade a ser convertida invalida.\n");
    }
}

// Função para converter minutos em horas ou segundos
void converteminutos(FILE *saida, double minutos, char un_convert){
    if(un_convert =='H'){
    horas = minutos/60.0;
    fprintf(saida, "%.2f minutos é equivalente a %.2f horas.\n", minutos, horas);
    }
    else if (un_convert =='S') {
    segundos = minutos*60;
    fprintf(saida, "%.2f minutos é equivalente a %.2f segundos.\n", minutos, segundos);    
    }
    else {
        fprintf(saida, "Unidade a ser convertida invalida.\n");
    }
}

// Função para converter segundos em horas ou minutos
void convertesegundos(FILE *saida, double segundos, char un_convert){
    if(un_convert == 'H'){
    horas = segundos/3600.0;
    fprintf(saida, "%.2f segundos é equivalente a %.2f horas.\n", segundos, horas);
    }
    else if (un_convert == 'M'){
    minutos = segundos/60;
    fprintf(saida, "%.2f segundos é equivalente a %.2f minutos.\n", segundos, minutos);    
    }
    else {
        fprintf(saida, "Unidade a ser convertida invalida.\n");
    }
}

int main(void) {

    FILE *entrada = fopen("entradadedados.txt", "r");
    FILE *saida = fopen("saida.txt", "w");

    if (entrada == NULL || saida == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    fprintf(saida, "Resultado da conversão:\n");

    while (fscanf(entrada, "%lf %c %c\n",
            &valor, &opcao, &un_convert) == 3)
    {

    opcao = toupper(opcao);
    un_convert = toupper(un_convert);
    
    switch (opcao) {
        case 'H':
            convertehoras(saida, valor, un_convert);
            break;
        case 'M':
            converteminutos(saida, valor, un_convert);
            break;
        case 'S':
            convertesegundos(saida, valor, un_convert);
            break;
        default:
            printf("Unidade invalida!\n");
            break;
    }}
    fclose(entrada);
    fclose(saida);

    return 0;
}
