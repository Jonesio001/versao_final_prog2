//Tema: Educativo.
//Grupo: João Eduardo, Luana Pinheiro e Giovanni Marchan.
//versão 0.6 - 04/10/2022 14:00PM

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define coluna 20
#define linha 22

typedef struct {
    int i;
    int j;
    int vida;
    int fase;
} tipoPersonagem;

//Pronto
typedef struct {
    int i;
    int j;
    int valor;
    int correta;
    int valido;
} tipoNumero;

//Pronto
typedef struct {
    int iInicio;
    int iFim;
    int jInicio;
    int jFim;
    int iPorta;
    int jPorta;
    int iInterruptor;
    int jInterruptor;
    int desbloqueado;
    int portaAberta;
    tipoNumero numeros[5];

} tipoComodo;

//Pronto
tipoNumero criaNumeros(int i, int j, int valor, int correta, int valido){

    tipoNumero numero;
    numero.i = i;
    numero.j = j;
    numero.valor = valor;
    numero.correta = correta;
    numero.valido = valido;
    return numero;
}

//Pronto
void criaPersonagem(tipoPersonagem*p, int i, int j, int vida, int fase){
    p->i=i;
    p->j=j;
    p->vida=vida;
    p->fase=fase;
}

//Pronto
void criaComodo(tipoComodo*comodos){
    tipoComodo quarto1;
    quarto1.iInicio = 0;
    quarto1.iFim = 8;
    quarto1.jInicio = 0;
    quarto1.jFim = 7;
    quarto1.iPorta = 4;
    quarto1.jPorta = quarto1.jFim;
    quarto1.iInterruptor = 1;
    quarto1.jInterruptor = 1;
    quarto1.desbloqueado = 0;
    quarto1.portaAberta = 1;
    quarto1.numeros[1] = criaNumeros(2, 2, 1, 0, 0);
    quarto1.numeros[2] = criaNumeros(2, 5, 2, 1, 0);
    quarto1.numeros[3] = criaNumeros(6, 2, 3, 1, 0);
    quarto1.numeros[4] = criaNumeros(6, 5, 4, 0, 0);

    tipoComodo quarto2;
    quarto2.iInicio = quarto1.iInicio;
    quarto2.iFim = 8;
    quarto2.jInicio = 11;
    quarto2.jFim = coluna;
    quarto2.iPorta = 3;
    quarto2.jPorta = quarto2.jInicio;
    quarto2.iInterruptor = 7;
    quarto2.jInterruptor = 16;
    quarto2.desbloqueado = 0;
    quarto2.portaAberta = 0;
    quarto2.numeros[1] = criaNumeros(2, 13, 5, 1, 0);
    quarto2.numeros[2] = criaNumeros(2, 16, 6, 0, 0);
    quarto2.numeros[3] = criaNumeros(2, 19, 7, 1, 0);
    quarto2.numeros[4] = criaNumeros(4, 16, 8, 0, 0);

    tipoComodo quarto3;
    quarto3.iInicio = quarto2.iFim;
    quarto3.iFim = quarto3.iInicio+5;
    quarto3.jInicio = 12;
    quarto3.jFim = coluna;
    quarto3.iPorta = quarto3.iFim;
    quarto3.jPorta = quarto3.jInicio+3;
    quarto3.iInterruptor = 10;
    quarto3.jInterruptor = 19;
    quarto3.desbloqueado = 0;
    quarto3.portaAberta = 0;
    quarto3.numeros[1] = criaNumeros(9, 13, 10, 0, 0);
    quarto3.numeros[2] = criaNumeros(9, 16, 11, 1, 0);
    quarto3.numeros[3] = criaNumeros(12, 13, 12, 0, 0);
    quarto3.numeros[4] = criaNumeros(12, 16, 13, 1, 0);

    tipoComodo quarto4;
    quarto4.iInicio = 16;
    quarto4.iFim = quarto4.iInicio+6;
    quarto4.jInicio = 13;
    quarto4.jFim = coluna;
    quarto4.iPorta = quarto4.iInicio;
    quarto4.jPorta = quarto4.jInicio+2;
    quarto4.iInterruptor = 19;
    quarto4.jInterruptor = 17;
    quarto4.desbloqueado = 0;
    quarto4.portaAberta = 0;
    quarto4.numeros[1] = criaNumeros(17, 16, 16, 0, 0);
    quarto4.numeros[2] = criaNumeros(17, 19, 17, 1, 0);
    quarto4.numeros[3] = criaNumeros(21, 18, 18, 0, 0);
    quarto4.numeros[4] = criaNumeros(21, 14, 19, 1, 0);

    tipoComodo quarto5;
    quarto5.iInicio = 12;
    quarto5.iFim = linha;
    quarto5.jInicio = 0;
    quarto5.jFim = quarto5.jInicio+9;
    quarto5.iPorta = quarto5.iInicio+3;
    quarto5.jPorta = quarto5.jFim;
    quarto5.iInterruptor = 18;
    quarto5.jInterruptor = 3;
    quarto5.desbloqueado = 0;
    quarto5.portaAberta = 0;
    quarto5.numeros[1] = criaNumeros(14, 2, 41, 1, 0);
    quarto5.numeros[2] = criaNumeros(14, 7, 43, 1, 0);
    quarto5.numeros[3] = criaNumeros(20, 2, 33, 0, 0);
    quarto5.numeros[4] = criaNumeros(20, 7, 42, 0, 0);

    comodos[1] = quarto1;
    comodos[2] = quarto2;
    comodos[3] = quarto3;
    comodos[4] = quarto4;
    comodos[5] = quarto5;
}

//Pronto
void criaMapa(char*mapa, tipoComodo*comodos, int qtdcomodos){
    for (int i = 0; i <= linha; i++)
    {
        for (int j = 0; j <= coluna; j++)
        {
            for(int x=0; x<qtdcomodos; x++)
            {
                if(i>=comodos[x].iInicio && i <= comodos[x].iFim && j>=comodos[x].jInicio && j <= comodos[x].jFim)
                {
                    if (    i==comodos[x].iInicio && j!=comodos[x].jPorta || i==comodos[x].iInicio && j==comodos[x].jPorta && i!=comodos[x].iPorta ||
                            i==comodos[x].iFim    && j!=comodos[x].jPorta || i==comodos[x].iFim    && j==comodos[x].jPorta && i!=comodos[x].iPorta ||
                            j==comodos[x].jInicio && i!=comodos[x].iPorta || j==comodos[x].jInicio && i==comodos[x].iPorta && j!=comodos[x].jPorta ||
                            j==comodos[x].jFim    && i!=comodos[x].iPorta || j==comodos[x].jFim    && i==comodos[x].iPorta && j!=comodos[x].jPorta)
                    {
                        mapa[i*coluna+j] = '#';
                        break;
                    }
                    else if (j == comodos[x].jPorta && i == comodos[x].iPorta)
                    {
                        mapa[i*coluna+j] = '@';
                        break;
                    }
                    else if (j == comodos[x].jInterruptor && i == comodos[x].iInterruptor)
                    {
                        mapa[i*coluna+j] =',';
                        break;
                    }
                }
                else if (i == 0 || j == 0 || j == coluna || i == linha)
                    mapa[i*coluna+j] = '#';
                else
                    mapa[i*coluna+j] = '.';
            }
        }
    }
}

//Pronto
int ehComodo(int i, int j, tipoComodo*comodos, int*y){
    for(int x=1; x<6; x++)
    {
        if(i>=comodos[x].iInicio && i <= comodos[x].iFim && j>=comodos[x].jInicio && j <= comodos[x].jFim)
        {
            *y = x;
            return 1;
        }
        else
            continue;
    }
    return 0;
}

//Pronto
void desenhaMapa(tipoPersonagem p, char*mapa, tipoComodo*comodos, int qtdcomodos, int faseFinal, tipoNumero*numerosCorredor){
    for (int i = 0; i <= linha; i++)
    {
        for (int j = 0; j <= coluna; j++)
        {
            int x;
            if(ehComodo(i, j, comodos, &x)==1)
            {
                if(comodos[x].desbloqueado==1)
                    desenhaMapaComLuz(p, i, j, mapa);

                if(comodos[x].desbloqueado==2)
                    desenhaComodoComNumero(p, i, j, x, mapa, comodos);

                if(comodos[x].desbloqueado==0)
                    desenhaMapaNoEscuro(p, i, j, mapa);

            }else{
                if(faseFinal==0)
                    desenhaMapaNoEscuro(p, i, j, mapa);
                else if(faseFinal==1)
                    desenhaCorredorComNumero(p, i, j, mapa, numerosCorredor);
                else
                    desenhaMapaComLuz(p, i, j, mapa);
            }
        }
        printf("\n");
    }

    if(comodos[p.fase].desbloqueado==2){
        printf("\n\tSelecione quais letras contem o valor de um numero primo\n\n");
        printf("\t\t   A = %i   B = %i   C = %i   D = %i\n\n", comodos[p.fase].numeros[1].valor, comodos[p.fase].numeros[2].valor,
               comodos[p.fase].numeros[3].valor ,comodos[p.fase].numeros[4].valor);
    }

    if(faseFinal==1){
        printf("\n Para finalizar, agora os numeros ficaram um pouco mais altos para aumentar a dificuldade.");
        printf("\n\tSelecione quais letras contem o valor de um numero primo\n\n");
        printf("\t\t   A = %i   B = %i   C = %i   D = %i\n\n", numerosCorredor[0].valor, numerosCorredor[1].valor,
               numerosCorredor[2].valor, numerosCorredor[3].valor);
    }

    printf("\tTotal de vidas: %i", p.vida);
    printf("\nComando: w (cima)\td (direita)\ts (baixo)\ta (esquerda)\n");
    printf("Digite um comando: ");
}

//Pronto
void desenhaMapaComLuz(tipoPersonagem p, int i, int j, char*mapa){
    if(i==p.i && j==p.j)
        printf(" P");
    else
        printf(" %c", mapa[i*coluna+j]);
}

//Pronto
void desenhaComodoComNumero(tipoPersonagem p, int i, int j, int x, char*mapa, tipoComodo*comodos){

    if(j == p.j && i == p.i)
        printf(" P");

    else if (comodos[x].numeros[1].i == i && comodos[x].numeros[1].j == j)
        printf(" A");

    else if (comodos[x].numeros[2].i == i && comodos[x].numeros[2].j == j )
        printf(" B");

    else if (comodos[x].numeros[3].i == i && comodos[x].numeros[3].j == j )
        printf(" C");

    else if (comodos[x].numeros[4].i == i && comodos[x].numeros[4].j == j )
        printf(" D");

    else
        printf(" %c", mapa[i*coluna+j]);
}

//Pronto
void desenhaMapaNoEscuro(tipoPersonagem p, int i, int j, char*mapa){

    if(i==p.i && j==p.j)
        printf(" P");

    else if(i==p.i+1 && j>=p.j-1 && j<=p.j+1 || i==p.i-1 && j>=p.j-1 && j<=p.j+1 || i==p.i && j<=p.j+1 && j>=p.j-1 && j!=p.j)
    {
        if(mapa[i*coluna+j] != '#' && mapa[i*coluna+j] != '@')
        {
            if (mapa[i*coluna+j] == ',')
                printf(" ,");
            else
                printf(" .");
        }
        else if(mapa[i*coluna+j] == '#')
             printf(" #");

        else if(mapa[i*coluna+j] == '@')
            printf(" @");
    }
    else
        printf("  ");
}

//Pronto
void desenhaCorredorComNumero(tipoPersonagem p, int i, int j, char*mapa, tipoNumero*numerosCorredor){

    if(i==p.i && j==p.j)
        printf(" P");

    else if (numerosCorredor[0].i == i && numerosCorredor[0].j == j)
        printf(" A");

    else if (numerosCorredor[1].i == i && numerosCorredor[1].j == j)
        printf(" B");

    else if (numerosCorredor[2].i == i && numerosCorredor[2].j == j)
        printf(" C");

    else if (numerosCorredor[3].i == i && numerosCorredor[3].j == j)
        printf(" D");

    else
        printf(" %c", mapa[i*coluna+j]);

}

//Pronto
void movimentaPersonagem(char comando, tipoPersonagem*p, tipoComodo*comodos, int qtdcomodos){
    switch(comando)
    {
    case 'w':
        p->i -= 1;
        for(int x=0; x<qtdcomodos; x++)
        {
            if (p->i<1 ||
                    p->i == comodos[x].iInicio && p->j >= comodos[x].jInicio && p->j <= comodos[x].jFim && p->j!=comodos[x].jPorta ||
                    p->i == comodos[x].iFim    && p->j >= comodos[x].jInicio && p->j <= comodos[x].jFim && p->j!=comodos[x].jPorta
                    || p->j == comodos[x].jPorta  && p->i >= comodos[x].iInicio && p->i <= comodos[x].iFim && comodos[x].jPorta == comodos[x].jInicio
                    || p->j == comodos[x].jPorta  && p->i >= comodos[x].iInicio && p->i <= comodos[x].iFim && comodos[x].jPorta == comodos[x].jFim
                    ||  p->i == comodos[x].iPorta  && p->j == comodos[x].jPorta && comodos[x].portaAberta == 0)
                p->i += 1;

        }
        break;

    case 's':
        p->i += 1;
        for(int x=0; x<qtdcomodos; x++)
        {
            if (p->i >= linha ||
                    p->i == comodos[x].iInicio && p->j >= comodos[x].jInicio && p->j <= comodos[x].jFim && p->j!=comodos[x].jPorta ||
                    p->i == comodos[x].iFim    && p->j >= comodos[x].jInicio && p->j <= comodos[x].jFim && p->j!=comodos[x].jPorta
                    || p->j == comodos[x].jPorta  && p->i >= comodos[x].iInicio && p->i <= comodos[x].iFim && comodos[x].jPorta == comodos[x].jInicio
                    || p->j == comodos[x].jPorta  && p->i >= comodos[x].iInicio && p->i <= comodos[x].iFim && comodos[x].jPorta == comodos[x].jFim
                    || p->i == comodos[x].iPorta  && p->j == comodos[x].jPorta && comodos[x].portaAberta == 0)
            {
                p->i -= 1;
            }
        }
        break;

    case 'a':
        p->j -= 1;
        for(int x=0; x<qtdcomodos; x++)
        {
            if (p->j < 1 ||
                    p->j == comodos[x].jInicio && p->i >= comodos[x].iInicio && p->i <= comodos[x].iFim && p->i!=comodos[x].iPorta ||
                    p->j == comodos[x].jFim    && p->i >= comodos[x].iInicio && p->i <= comodos[x].iFim && p->i!=comodos[x].iPorta
                    || p->i == comodos[x].iPorta  && p->j >= comodos[x].jInicio && p->j <= comodos[x].jFim && comodos[x].iPorta == comodos[x].iFim
                    || p->i == comodos[x].iPorta  && p->j >= comodos[x].jInicio && p->j <= comodos[x].jFim && comodos[x].iPorta == comodos[x].iInicio
                    || p->i == comodos[x].iPorta  && p->j == comodos[x].jPorta && comodos[x].portaAberta == 0 )
            {
                p->j += 1;
            }
        }
        break;

    case 'd':
        p->j += 1;
        for(int x=0; x<qtdcomodos; x++)
        {
            if (p->j >= coluna ||
                    p->j == comodos[x].jInicio && p->i >= comodos[x].iInicio && p->i <= comodos[x].iFim && p->i!=comodos[x].iPorta ||
                    p->j == comodos[x].jFim    && p->i >= comodos[x].iInicio && p->i <= comodos[x].iFim && p->i!=comodos[x].iPorta
                    || p->i == comodos[x].iPorta  && p->j >= comodos[x].jInicio && p->j <= comodos[x].jFim && comodos[x].iPorta == comodos[x].iFim
                    || p->i == comodos[x].iPorta  && p->j >= comodos[x].jInicio && p->j <= comodos[x].jFim && comodos[x].iPorta == comodos[x].iInicio
                    || p->i == comodos[x].iPorta  && p->j == comodos[x].jPorta && comodos[x].portaAberta == 0
               )
            {
                p->j -= 1;
            }
        }
        break;

    default:
        printf("Comando invalido!\n");
        printf("Pressione uma tecla para continuar!\n");
        system("PAUSE");
    }
}

//Pronto
void jogar(){

    //Cria o struct que ira guardar as informacoes do personagem
    tipoPersonagem p;
    criaPersonagem(&p, 6, 5, 3, 1);

    //Cria o struct que ira guardar as informacoes dos comodos
    int qtdcomodos = 6;
    tipoComodo comodos[6];
    criaComodo(comodos);

    //Desenha o mapa de acordo com os comodos
    char mapa[linha][coluna];
    criaMapa(mapa, comodos, qtdcomodos);

    //Cria array que a armazena tiposNumero para o corredor
    tipoNumero numerosCorredor[4];
    numerosCorredor[0] = criaNumeros(2, 9, 79, 1, 0);
    numerosCorredor[1] = criaNumeros(9, 2, 67, 1, 0);
    numerosCorredor[2] = criaNumeros(11, 2, 87, 0, 0);
    numerosCorredor[3] = criaNumeros(19, 11, 72, 0, 0);

    //Outras variaveis
    int acertos=0;
    int faseFinal=0;

    //armazena nome do jogador
    char nome[50];
    printf("\nDigite seu nome para comecar: ");
    fflush(stdin);
    fgets(nome, 50, stdin);


    for( ; ; )
    {
        system("CLS");
        desenhaMapa(p, mapa, comodos, qtdcomodos, faseFinal, numerosCorredor);
        movimentaPersonagem(getch(), &p, comodos, qtdcomodos);

        if(p.i == comodos[p.fase].iInterruptor && p.j == comodos[p.fase].jInterruptor )
            comodos[p.fase].desbloqueado = 2;

        if(comodos[p.fase].desbloqueado == 2)
        {
            for(int y=1; y<5; y++){
                if (comodos[p.fase].numeros[y].i == p.i && comodos[p.fase].numeros[y].j == p.j && comodos[p.fase].numeros[y].valido==0) {

                    if(comodos[p.fase].numeros[y].correta == 1){
                        comodos[p.fase].numeros[y].valido=1;
                        acertos++;
                    } else {
                        comodos[p.fase].numeros[y].valido=1;
                        p.vida--;
                    }
                }
            }
        }
        if(acertos == 2 && p.fase<5) {
            comodos[p.fase].desbloqueado = 1;
            comodos[p.fase+1].portaAberta = 1;
            acertos=0;
            p.fase++;
        }
        if(acertos ==2 && p.fase==5 && faseFinal==0){
            comodos[p.fase].desbloqueado = 1;
            acertos=0;
            faseFinal=1;
        }

        if(faseFinal==1)
        {
            for(int y=0; y<4; y++){
                if (numerosCorredor[y].i == p.i && numerosCorredor[y].j == p.j && numerosCorredor[y].valido==0) {

                    if(numerosCorredor[y].correta == 1){
                        numerosCorredor[y].valido=1;
                        acertos++;
                    } else {
                        numerosCorredor[y].valido=1;
                        p.vida--;
                    }
                }
            }
        }

        if(acertos==2 && faseFinal==1){
            faseFinal=2;
            p.fase=6;
            acertos=0;
        }

        if(p.fase==6){
            system("CLS");
            printf("\tParabens voce ganhou e mostrou que sabe mesmo identificar os numeros primos.\n");
            attHistorico(nome, p);
            finalizarPartida();

        }

        if(p.vida==0){
            system("CLS");
            printf("\tInfelizmente voce perdeu, preste mais atencao ao valores da proxima vez.\n");
            attHistorico(nome, p);
            finalizarPartida();
        }
    }
}

void attHistorico(char nome[50], tipoPersonagem p){

    FILE*hist;
    hist = fopen("historico.txt", "a");

    for(int i=0; i<=strlen(nome); i++){

        if(nome[i]=='\n'){
            nome[i]='\0';
        }
    }

    char historico[50]= "Jogador: ";

    if(hist == NULL){
        printf("Nao foi possivel adicionar informacoes do jogador");
    }
    else{
        if(p.vida==0){
            char mensagem[20]= "    Status: Perdeu";
            strcat(historico, nome);
            strcat(historico, mensagem);
            strcat(historico, "\n");
            fputs(historico, hist);
        }
        else {
            char mensagem[20]= "    Status: Ganhou";
            strcat(historico, nome);
            strcat(historico, mensagem);
            strcat(historico, "\n");
            fputs(historico, hist);
        }
    }

    fclose(hist);
}

//Pronto
void finalizarPartida(){
    char resposta;
    printf("\t\t\tDeseja jogar novamente?\n\t\t\t (s) sim \/ (n) nao \n");
    scanf("%c", &resposta);

    while(resposta!='s'||resposta!='n'){
        switch(resposta){
            case 's':
                jogar();
                break;
            case 'n':
                menu();
                break;
            default:
                printf("\nOpcao invalida! Digite novamente: ");
                fflush(stdin);
                scanf("%c", &resposta);

        }
    }
}

void lerHistorico(){

    FILE*hist;
    hist = fopen("historico.txt", "r");
    char mostraHist[50];

    if(hist == NULL){
        printf("Nao foi possivel ver o historico");
    }
    else{
        fgets(mostraHist, 50, hist);
        while (!feof(hist)) // Enquanto não chegar no final do arquivo p
        {
            printf("%s",mostraHist);
            fgets(mostraHist, 50, hist);
        }

    }

    fclose(hist);
}

void howToPlay(){

    printf("\n\tVoce deve encontrar os numeros primos escondidos nas salas escura de uma casa misteriosa,\n");
    printf("\n\tMas primeiro voce tera de procurar os interruptores para ascender a luz de cada comodo.\n");
    printf("\n\tNumeros primos sao aqueles numeros que so sao divididos por eles mesmos e pelo numero 1\n");
    printf("\n\t\t\t\t\t\tBom jogo!\n");


}

void menu(){
    int opcao=0;

    for( ; ; )
    {
        system("cls");

        printf("Seja bem vindo ao caca numeros primos\n");
        printf("Pronto para comecar?\n");
        printf("\n1. Jogar");
        printf("\n2. Historico");
        printf("\n3. Como jogar");
        printf("\n4. Sair");

        printf("\n\nO que voce deseja fazer? \nSelecione uma das opcoes acima digitando seu numero: ");
        scanf("%i", &opcao);

        switch(opcao)
        {
            case 1:
                jogar();
                break;
            case 2:
                system("CLS");
                printf("\n");
                lerHistorico();
                break;
            case 3:
                system("CLS");
                howToPlay();
                break;
            case 4:
                exit(1);
                break;

            default:
                printf("\nOpção inválida!");
        }

        if (opcao!=4)
        {
            printf("\nPressione enter para continuar...");
            fflush(stdin);
            getchar();
        }

    }
}

void main(){

    menu();
}
