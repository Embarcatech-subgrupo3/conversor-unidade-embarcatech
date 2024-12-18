#include <stdio.h>

    int opcao;
    double horas, minutos, segundos;


// Função para converter horas em minutos e segundos
void convertehoras(double horas){
    minutos = horas*60;
    segundos = horas*3600;
    printf("%.2f horas é equivalente a %.2f minutos ou %.2f segundos.\n", horas, minutos, segundos);
}

// Função para converter minutos em horas e segundos
void converteminutos(double minutos){
    horas = minutos/60.0;
    segundos = minutos*60;
    printf("%.2f minutos é equivalente a %.2f horas ou %.2f segundos.\n", minutos, horas, segundos);
}

// Função para converter segundos em horas e minutos
void convertesegundos(double segundos){
    horas = segundos/3600.0;
    minutos = segundos/60;
    printf("%.2f segundos é equivalente a %.2f horas ou %.2f minutos.\n", segundos, horas, minutos);
}

int main() {

//Seleção de qual unidade será convertida

    printf("Conversor de unidades de tempo, digite uma opção de 1 a 3:\n");
    printf("1. Para converter horas em minutos e segundos\n");
    printf("2. Para converter minutos em horas e segundos\n");
    printf("3. Para converter segundos em horas e minutos\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            
            printf("Digite o valor em horas: ");
            scanf("%lf", &horas);
            
            convertehoras(horas);
            break;
        case 2:
            
            printf("Digite o valor em minutos: ");
            scanf("%lf", &minutos);
            
            converteminutos(minutos);
            break;
        case 3:
            
            printf("Digite o valor em segundos: ");
            scanf("%lf", &segundos);
            
            convertesegundos(segundos);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}
