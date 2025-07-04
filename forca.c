#include <stdio.h>
#include <std.lib>
#include <string.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[TAMANHO_PALAVRA];
char chute[26];
int chutesdados = 0;

int letraexistente(char letra){
    for (j = 0; j < strlen(palavrasecreta); j++)
    {
        if (letra == palavrasecreta[j])
        {
            return 1;
        }
        
    }

    return 0;
    
}

int letraexiste(char letra){

    for (j = 0; j < strlen(palavrasecreta); j++)
    {
        if (letra == palavrasecreta[j])
        {
            return 1;
        }
        
    }

    return 0;
    
}

int chuteserrados(){
    
    int erros = 0;

    for (i = 0; i < chutesdados; i++)
    {
        if (!letraexixtente(chutes[i]))
        {
            erros++;
        }
        
    }

    return erros;

}

int enforcou(){

    int erros = 0;

    for (int i = 0; i < chutesdados; i++)
    {
        int existe = 0;

        for (int j = 0; j <strlen(palavrasecreta); j++){
            
            if(chutes[i] == palavrasecreta[j]){
                existe = 1;
                break;
            }
        }

        if (!existe) erros++;
    
        
    }

    return erros >=5;
    
}

int ganhou(){
    for (int i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }

    return 1;
    
}

void abertura(){

        printf("/**************/\n");
        printf("/ Jogo de Forca */\n");
        printf("/******************/\n\n");
    }
    
void chuta(){
        char chute;
        printf ("Qual Letra?");
        scanf("%c", &chute);

        chutes[chutesdados] = chute;
        chutesdados++;

}

int jachutou(char letra){
        int achou = 0;
        for(int j = 0; j < tentativas; j++){
            if(chutes[j] == letra){
                achou = 1;
                break;
            }
        }

        return achou;

}

void desenhaforca(){

     int erros = chuteserrados();
 
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");
 
    for(int i = 0; i < strlen(palavrasecreta); i++) {
 
        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
 
    }
    printf("\n");
 
}

void escolhepalavra(){
        FILE* f;

        f = fopen("palavras.txt", "r");

        if (f == 0){
            printf("Banco de dados de palavras nao disponivel \n\n\");
         
                exit(1);
        }
                
        int qtddepalavras;
        fscanf(f, "%d", &qtddepalavras);

        for(int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavrasecreta);
        }

        fclose(f);
        
    } 

void adicionapalavra(){
    char quer;

    printf("voce deseja adicionar uma nova palavra no jogo (S/N)?"):
        scanf("%c", &quer);
    
    if (quer == `S`){
        char novapalavra[20];

        printf("Digite a Nova palavra, em Letras maiusculas: ");
        scanf("%s", novapalavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");
        if(if == 0){
        printf("Banco de Dados de palavras nao disponiveis \n\n");
        exit(1);
        }

        int qtd;
        fscanf(f,"%d",&qtd);
        qtd++;
        fseek(f,0, SEEK_SET);
        fprintf(f,"%d", qtd);
        
        fseek(f, 0, SEEK_END);
        fprintf(f,"\n%s", novapalvra);

        fclose(f);
    }


}

int main(){

abertura();
escolhepalavra();

do {

desenhaforca();
chuta();

    } while (!ganhou() && !enforcou());
     adicionarpalvra();
}


