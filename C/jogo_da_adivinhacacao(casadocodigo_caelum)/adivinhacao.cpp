#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

int main(){

    
    printf("********************************");
    printf("Bem Vindo ao Jogo da Adivinhacao");
    printf("********************************");

    int numerosecreto;
    numerosecreto = 42;

    //Imprimindo Somente o Numero Secreto
    printf("%d",42);

    //No Meio da Frase
    printf("O Numero Secreto %d e secreto");

    printf("O Numero Secreto he");

    int chute;

    printf("Qual e o seu chute");
    scanf("%d", &chute);

    printf("Voce chutou o numero %d", chute);

    if (chute == numerosecreto){
        printf("Parabens! voce acertou! \n");
    } else {
        if (chute > numerosecreto){
            printf ("Seu chute foi maior que o numero secreto\n");
        }
        if (chute < numerosecreto){
            printf ("Seu chute foi menor que o numero secreto\n");
        }
        
    }
    

}