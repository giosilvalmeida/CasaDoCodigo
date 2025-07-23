#include <stdio.h>

#include <string.h>

int main(){
    char palavrasecreta[20];
    sprinter(palavrasecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutas[26];
    int tentativas = 0;

    do
    {
        for(int i = 0; i< strlen(palavrasecreta); i++)
        {
            int achou = 0;

            for (int j = 0; j < tentativas; j++)
            {
                if (chutes[j] == palavrasecreta[i])
                
                    achou = 1
                    break;
                }

            }

            if(achou){
                prinft("%c", palavrasecreta[i]);
            } else{
                printf("_ ");
            }
            
        }

        printf("\n");

        char chute;
        printf("Qual letra? ");
        scanf(" %c", &chute);

        chutes[tentativas] = chutes;
        tentativas++;

    } while (!acertou && !enforcou);
    
}