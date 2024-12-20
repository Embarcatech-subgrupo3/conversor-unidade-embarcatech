// conversor_dados_digitais.c
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main(void)
{
    printf("\nPROGRAMA PARA CONVERTER DADOS DIGITAIS\n");
    sleep(1);
    printf("Unidades suportadas: bits (b), bytes (B), KB, MB, GB, TB\n");

    double valor;
    char unidade_origem[3];
    char unidade_destino[3];

    printf("\nInsira o valor e a unidade de origem (ex: 1024 KB): ");
    scanf("%lf %2s", &valor, unidade_origem);

    printf("Para qual unidade deseja converter? (b, B, KB, MB, GB, TB): ");
    scanf("%2s", unidade_destino);

    return 0;
}
