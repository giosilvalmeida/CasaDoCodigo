#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#define NUMERO_DE_TENTATIVAS 3

int main(){

    // imprime o cabecalho do nosso jogo
    printf("********************************");
    printf("Bem Vindo ao Jogo da Adivinhacao");
    printf("********************************");

    int chute;
    double pontos = 100;

    int acertou;

    srand(time(0));
    int numerosecreto = rand() % 100;

    printf("Qual o nivel de dificuldade\n");
    printf("(1) Facil (2) Medio (3) Dificil \n\n");
    printf("Escolha:");

    scanf("%d", &nivel);

    if (nivel == 1){

        totaldetentativas = 20;

    } else if (nivel == 2){

        totaldetentativas = 6;
    
    }
    

    for(int i = 1; i <= totaldetentativas; i++){

        printf("Tentativa %d de %d\n" i, totaldetentativas);

        printf("Qual e o seu %d. chute", i);
        scanf("%d", &chute);

        if(chute < 0){

            printf("Voce nao pode chutar numeros negativos");
            continue;
        }
        
        printf("Seu %d. chute foi %d\n", tentativas, chute);

        int acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if (acertou){

            printf("Parabens! voce acertou\n");
            break;
        
        }
        
        else if (maior){
            printf("Seu Chute foi maior que o numero secreto\n");
        }

        else{
            printf("Seu chute foi menor que o numero secreto\n");
        }
        

        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;

    }
    
    printf("Voce fex %.2f pontos\n", pontos);
    printf("Obrigado por jogar!\n");

}
