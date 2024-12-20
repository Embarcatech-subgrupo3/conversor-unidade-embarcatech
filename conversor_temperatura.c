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
    FILE *entrada = fopen("entradas.txt", "r");
    FILE *saida = fopen("saidas.txt", "w");

    if (entrada == NULL || saida == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    fprintf(saida, "Resultados da conversão:\n");

    double temp_original;
    char unidade_original, unidade_convertida;

    while (fscanf(entrada, "%lf\n%c\n%c\n",
            &temp_original, &unidade_original, &unidade_convertida) == 3)
    {
        unidade_original = toupper(unidade_original);
        unidade_convertida = toupper(unidade_convertida);

        double temp_convertida;

        switch (unidade_original)
        {
            case 'C':
                temp_convertida = celsius(temp_original, unidade_convertida);
                break;
            case 'F':
                temp_convertida = fahrenheit(temp_original, unidade_convertida);
                break;
            case 'K':
                temp_convertida = kelvin(temp_original, unidade_convertida);
                break;
            default:
                fprintf(saida, "Unidade de temperatura inválida: %c\n",
                        unidade_original);
                continue;
        }

        if (temp_convertida != 0)
        {
            fprintf(saida, "%.2lf %c equivale a %.2lf %c\n",
                    temp_original, unidade_original, 
                    temp_convertida, unidade_convertida);
        }
        else
        {
            fprintf(saida, "Conversão de %c para %c não suportada.\n",
                    unidade_original, unidade_convertida);
        }
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}

// DEFINIÇÃO DAS FUNÇÕES
double celsius(double x, char y)
{   
    double temp_convertida = 0;

    if (y == 'F') // celsius para fahrenheit
    {   
        temp_convertida = (x * 1.8) + 32;
    }
    else if (y == 'K') // celsius para kelvin
    {   
        temp_convertida = x + 273.15;
    }

    return temp_convertida;
}

double fahrenheit(double x, char y)
{   
    double temp_convertida = 0;

    if (y == 'C') // fahrenheit para celsius
    {   
        temp_convertida = (x - 32) / 1.8;
    }
    else if (y == 'K') // fahrenheit para kelvin
    {   
        temp_convertida = (x - 32) / 1.8 + 273.15;
    }

    return temp_convertida;
}

double kelvin(double x, char y)
{   
    double temp_convertida = 0;

    if (y == 'C') // kelvin para celsius
    {
        temp_convertida = x - 273.15;
    }
    else if (y == 'F') // kelvin para fahrenheit
    {
        temp_convertida = (x - 273.15) * 1.8 + 32;
    }

    return temp_convertida;
}
