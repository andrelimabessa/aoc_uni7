//
//  main.c
//
//  Created by Andre Jackson Gomes Bessa on 11/11/17.
//  Copyright © 2017 Andre Jackson Gomes Bessa. All rights reserved.
//

#include <stdio.h>

//0x é utilizado para delclarar hexadecimais, no caso 0x1 representa o hexadacimal 1
//que possui a presentação binaria 0001
#define BIT_UM 0x1

//0x é utilizado para delclarar hexadecimais, no caso 0x1 representa o hexadacimal 0
//que possui a presentação binaria 0000
#define BIT_ZEROo 0x0

//0x é utilizado para delclarar hexadecimais, no caso 0xF representa o hexadacimal F
//que possui a presentação binaria 1111
#define NEGATIVO_4_BITS 0x8

typedef struct Multiplicao {
    //inteiro utilizando apenas 4 bits
    int A:4; 

    //inteiro utilizando apenas 4 bits
    int Q:4;
    
    //inteiro sem sinal utilizando apenas 1 bit
    unsigned int Q_1:1;

    //inteiro utilizando apenas 4 bits
    int M:4;
} multiplicao;

//Desloca os bits uma posição para a direita
void deslocamentoDireita(int x);

//Desloca os bits uma posição para a esquerda
void deslocamentoEsquerda(int x);

//Verifica se um número é negativo ou positivo degundo a notação 
//complementar a dois
int numeroNegativo(int numero);

//Dado um número inteiro ele é convertido para binário
void int2bin(int n);

int main(int argc, const char * argv[]) {

    multiplicao teste;

    //Carrega os "registradores"
    teste.A = 0;
    teste.Q = 3;
    teste.Q_1=0;
    teste.M=2;

    //Tradus de inteiro pra binário
    int2bin(teste.Q);

    //Verificar Q[0] e Q[-1]
    if(teste.Q & BIT_UM)
    {
        printf(" q[0] == 1 \n");
    }else{
        printf(" q[0] == 0 \n");
    }

    if(teste.Q_1 & BIT_UM)
    {
        printf(" q[-1] == 1 \n");
    }else{
        printf(" q[-1] == 0 \n");
    }

    //A = A - M
    if(numeroNegativo(teste.A)){
        printf(" A negativo \n");
    }else{
        printf(" A positivo \n");
    }

    deslocamentoDireita(-3);
    deslocamentoEsquerda(4);

    return 0;
}

//Desloca os bits uma posição para a direita
void deslocamentoDireita(int x){

    //Essa operação desloca todos os bits uma casa para a direita
    //logo 1001 vira 1100, ele repete o bit de sinal
    x >>= 1;

    printf("deslocamento direta %d \n", x);
}

//Desloca os bits uma posição para a esquerda
void deslocamentoEsquerda(int x){

    //Essa operação desloca todos os bits uma casa para a direita
    //logo 1001 vira 0010
    x <<= 1;

    printf("deslocamento esqueda %d \n", x);
}

//Esse método serve para testar se o quarto bit é 1(negativo)
//Para isso usamos a máscara 1000 (8) e realizamos a operaão &
int numeroNegativo(int numero){
    return numero & NEGATIVO_4_BITS;
}

//Apesar de receber um inteiro iremos passar para essa função apenas cadeias de 4 bits 
void int2bin(int n){

    static char bin[4];
    int original = n;

    /*
        Esse laço irá buscar excutar 4 iterações por conta que nosso número tem 4 bits

        Em cada iteração será feita a operação lógica And, depois os bits de N serão deslocados 
        uma posição para a esquerda exemplo:
        
        Dado que n = 5 (0101) And 8 (1000)

        - Iteração 1
            0101 (N)
            1000 (8)
          --------
            0000 => bin[0] = '0' 
            N = N << 1 (1010)

        - Iteração 2
            1010 (N)
            1000 (8)
          --------
            1000 => bin[1] = '1' 
            N = N << 1 (0100)
        
        Percebam, onde houver 1 & 1 haverá resultado 1
    */
    for(int x=0; x<4; x++)
    {
        bin[x] = n & 0x8 ? '1' : '0';
        n <<= 1;
    }

    printf(" O binário de %d é %s \n", original, bin);    
}