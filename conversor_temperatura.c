// Conversor de temperatura
// 16/12/2024

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

// PROTÓTIPO DAS FUNÇÕES
double celsius(double x, char y);
double fahrenheit(double x, char y);
double kelvin(double x, char y);

int main(void)
{   
    printf("PROGRAMA PARA CONVERTER PARA CELSIUS, FAHRENHEIT OU KELVIN\n");
    sleep(1); // delay de um segundo
    printf("Exemplos de entradas válidas: 30C | 70.8F | 10.2K\n");
    sleep(1);

    double temp_original;
    char unidade_original;
    printf("Insira a temperatura com a formatação especificada: ");
    scanf("%lf%c", &temp_original, &unidade_original);
    
    char c;
    while ((c = getchar()) != '\n' && c != EOF) // limpa o buffer
        ;

    char unidade_convertida;
    double temp_convertida;

    unidade_original = toupper(unidade_original);

    switch(unidade_original)
    {
        case 'C':
            printf("Deseja converter para Fahrenheit ou Kelvin? (F/K): ");
            scanf("%c", &unidade_convertida);
            unidade_convertida = toupper(unidade_convertida);
            temp_convertida = celsius(temp_original, unidade_convertida);
            break;
        case 'F':
            printf("Deseja converter para Celsius ou Kelvin? (C/K): ");
            scanf("%c", &unidade_convertida);
            unidade_convertida = toupper(unidade_convertida);
            temp_convertida = fahrenheit(temp_original, unidade_convertida);
            break;
        case 'K':
            printf("Deseja converter para Celsius ou Fahrenheit? (C/F): ");
            scanf("%c", &unidade_convertida);
            unidade_convertida = toupper(unidade_convertida);
            temp_convertida = kelvin(temp_original, unidade_convertida);
            break;
        default:
            printf("Entrada inválida.\n");
            printf("Encerrando...\n");
            sleep(1);
            exit(EXIT_FAILURE); // encerra o programa
            break;
    }

    printf("%.2lf%c equivale a %.2lf%c\n", temp_original, unidade_original, 
        temp_convertida, unidade_convertida);

    return 0;
}

// DEFINIÇÃO DAS FUNÇÕES
double celsius(double x, char y)
{   
    double temp_convertida;

    if (y == 'F') // celsius para fahrenheit
    {   
     temp_convertida = (x * 1.8f) + 32;
    }
    else if (y == 'K') // celsius para kelvin
    {   
        temp_convertida = x + 273.15;
    }

    return temp_convertida;
}

double fahrenheit(double x, char y)
{   
    double temp_convertida;

    if (y == 'C') // fahrenheit para celsius
    {   
        temp_convertida = (x - 32.0)/1.8f;
    }
    else if (y == 'K') // fahrenheit para kelvin
    {   
        temp_convertida = (x - 32)/1.8f;
        temp_convertida += 273.15f;
    }

    return temp_convertida;
}

double kelvin(double x, char y)
{   
    double temp_convertida;

    if (y == 'F') // kelvin para fahrenheit
    {
        temp_convertida = ((x - 273.15f) * 1.8f) + 32;
    }
    else if (y == 'C') // kelvin para celsius
    {
        temp_convertida = x - 273.15f;
        temp_convertida = temp_convertida * 1.8f + 32;
    }

    return temp_convertida;
}