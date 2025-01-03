#include <stdio.h>

// Protótipo das funções
double converter_unidades(double a, int b, int c);

void conversorComprimento(void)
{
    double valor_original;
    int unidade_original;
    double valor_convertido;
    int unidade_convertida;

    // Mensagens iniciais
    printf("Programa para converter 1-metro, 2-centimetro ou 3-milimetro\n");
    printf("Exemplo de entradas válidas:\n");
    printf("7\n2 (7 metros para centímetros)\n");
    printf("60.5\n1 (60.5 centímetros para metros)\n");
    printf("4.3\n3 (4.3 milímetros para metros)\n");

    // Ler dados pelo terminal

        // Inicializar os dados
        printf("\nInsira o valor sem a unidade: ");
        scanf("%lf", &valor_original);

        printf("\nDigite a unidade do valor digitado(1-M/2-CM/3-MM): ");
        scanf("%d", &unidade_original);

        printf("\nDigite a unidade para qual será convertido(1-M/2-CM/3-MM): ");
        scanf("%d", &unidade_convertida);

        if (unidade_original < 1 || unidade_original > 3 || unidade_convertida < 1 || unidade_convertida > 3)
        {
            printf("Unidades inválidas. Por favor, tente novamente.\n");
 
        } // Erro para entrada invalida

        valor_convertido = converter_unidades(valor_original, unidade_original, unidade_convertida);

        // Exibe o resultado
        printf("\nValor convertido: %.2f ", valor_convertido);
        if (unidade_convertida == 1) 
            printf("metros\n");
        else if (unidade_convertida == 2) 
            printf("centímetros\n");
        else if (unidade_convertida == 3) 
            printf("milímetros\n");

}

double converter_unidades(double valor, int unidade_origem, int unidade_destino) 
{
    // Convertendo para metros como unidade padrao
    if (unidade_origem == 2) 
        valor /= 100.0;      // Centímetros para metros
    else if (unidade_origem == 3) 
        valor /= 1000.0; // Milímetros para metros

    // Convertendo metros para a unidade escolhida
    if (unidade_destino == 2) 
        valor *= 100.0;      // Metros para centímetros
    else if (unidade_destino == 3) 
        valor *= 1000.0; // Metros para milímetros

    return valor;
}
