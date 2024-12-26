// conversor de volume
//21/12/2024
// Unidades de volume (litro, mililitro, metros cúbicos)
#include<stdio.h>
#include<math.h>


double valor, resultado;
char unidade_inicial, unidade_final;

int main() {
    //inicio: pedi ao usuario para iserir o valor a ser convertido
   
    printf("digite o valor a ser convertido         ");
    scanf("%lf", &valor);
    getchar(); //limpar o teclado

    // iserir a unidade inicial
    printf(" Digite a unidade inicial:  l para litros,   m para mililitro,     c para metros cubicos    ");
    scanf("%c", &unidade_inicial);
    getchar();

    // unidade final
    printf("Digite a unidade final:  l para litros,  m para mililitro,  c para metros cubicos");
    scanf("%c", &unidade_final);


    //fuçao para converter de acordo com a unidade escolhida
    switch (unidade_inicial)
    {
    case 'l': // se a unidade inicial for litros
        switch(unidade_final){
            case 'm': //se a unidade final for mililitro
                resultado = valor*1000;
            break;
            case 'c': //se a unidade final for metros cubicos 
                 resultado = valor*1000;
            break;
    default:
    printf("unidade final inválida. \n");
    return 1;    }
    break;

    case 'm': // se a unidade inicial for mililitro
        switch(unidade_final){
            case 'l': //se a unidade final for litro
                resultado = valor/1000;
            break;
            case 'c': //se a unidade final for metros cubicos 
                 resultado = valor/1000000;
            break;
    default:
    printf("unidade final inválida. \n");
    return 1;    
    }
    break;

    case 'c': // se a unidade inicial for metros cubicos
        switch(unidade_final){
            case 'm': //se a unidade final for mililitro
                resultado = valor*1000000;
            break;
            case 'l': //se a unidade final for litros
                resultado = valor*1000;
            break;
    default:
    printf("unidade final inválida. \n");
    return 1;    
    }
    break;

    default: 
    

    // mostrar o resultado da conversão
    printf("%.2lf%c\n", resultado, unidade_final);

    return 1;
    }
}