#include <stdio.h>

    int opcao;
    double valor, horas, minutos, segundos;
    char un_convert;


// Função para converter horas em minutos ou segundos
void convertehoras(double horas, char un_convert){
    if(un_convert == 'M'){
    minutos = horas*60;
    printf("%.2f horas é equivalente a %.2f minutos.\n", horas, minutos);
    }
    else if (un_convert == 'S') {
    segundos = horas*3600;
    printf("%.2f horas é equivalente a %.2f segundos.\n", horas, segundos);    
    }
    else {
        printf("Unidade a ser convertida invalida.\n");
    }
}

// Função para converter minutos em horas ou segundos
void converteminutos(double minutos, char un_convert){
    if(un_convert =='H'){
    horas = minutos/60.0;
    printf("%.2f minutos é equivalente a %.2f horas.\n", minutos, horas);
    }
    else if (un_convert =='S') {
    segundos = minutos*60;
    printf("%.2f minutos é equivalente a %.2f segundos.\n", minutos, segundos);    
    }
    else {
        printf("Unidade a ser convertida invalida.\n");
    }
}

// Função para converter segundos em horas ou minutos
void convertesegundos(double segundos, char un_convert){
    if(un_convert == 'H'){
    horas = segundos/3600.0;
    printf("%.2f segundos é equivalente a %.2f horas.\n", segundos, horas);
    }
    else if (un_convert == 'M'){
    minutos = segundos/60;
    printf("%.2f segundos é equivalente a %.2f minutos.\n", segundos, minutos);    
    }
    else {
        printf("Unidade a ser convertida invalida.\n");
    }
}

int main() {

//Seleção do valor da unidade que será convertida

    printf("Conversor de Unidades de Tempo.\n");
    printf("Digite o valor que deseja converter: ");
    scanf("%lf", &valor);

//Seleção de qual unidade a ser convertida 

    printf("Qual sua unidade de origem? Digite uma opção de 1 a 3:\n");
    printf("1. Para converter horas\n");
    printf("2. Para converter minutos\n");
    printf("3. Para converter segundos\n");
    scanf("%d", &opcao);
    
//Seleção de para qual unidade o valor será convertido   
    
    printf("Selecione para qual unidade o valor será convertido:\n"); 
    printf("H para horas, M para minutos, S para segundos): ");
    scanf(" %c", &un_convert);

    switch (opcao) {
        case 1:
            convertehoras(valor, un_convert);
            break;
        case 2:
            converteminutos(valor, un_convert);
            break;
        case 3:
            convertesegundos(valor, un_convert);
            break;
        default:
            printf("Unidade invalida!\n");
            break;
    }

    return 0;
}
