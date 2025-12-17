#include <stdio.h>   // Lib pra input e ouput de dados
#include <stdlib.h>  // Lib pra rand() e system cls
#include <locale.h>  // Lib pra regionalizacao
#include <conio.h>   // Lib pra usar o getch()
#include <time.h>    // Lib pra usar o srand() e clock
#include <windows.h> // Lib pra usar sleep()

#define MAX 10 // Setando valor "padrão" MAX

// Função de Menu
void menu()
{
    printf("\t===========================================================================================\n");
    printf("\t===========================================================================================\n");
    printf("\t============================        JOGO DA MEMORIA        ================================\n");
    printf("\t=====                                                                                 =====\n");
    printf("\t=====                              SEJA BEM VINDO(A)                                  =====\n");
    printf("\t=====                                                                                 =====\n");
    printf("\t===== >> O jogador deve memorizar e repetir a sequecia de forma correta...  <<        =====\n");
    printf("\t=====                                                                                 =====\n");
    printf("\t===== >> Os numeros irao aparecer e o jogador tera:   <<                              =====\n");
    printf("\t=====                                                                                 =====\n");
    printf("\t=====          >> 7s e 5 numeros para memorizar no modo FACIL... <<                   =====\n");
    printf("\t=====          >> 6s e 7 numeros para memorizar no modo MEDIO... <<                   =====\n");
    printf("\t=====          >> 5s e 10 numeros para memorizar no modo DIFICIL... <<                =====\n");
    printf("\t=====                                                                                 =====\n");
    printf("\t=====                                                                                 =====\n");
    printf("\t===========================================================================================\n");
    printf("\t===========================================================================================\n");
    printf("\n\n");
}

// Função própria do jogo
int jogoDaMemoria()
{

    int nivel, tamanho, tempo;    // Setando variáveis de nivel, tamanho e tempo
    int num[MAX], respostas[MAX]; // Arrays de numeros e respostas
    int acertos = 0;              // Variável de contabilização dos acertos
    char c;                       // Variável do getch()

    // Escolha do nível
    printf("\t===========================================================================================\n");
    printf("\t===========================================================================================\n");
    printf("\t============================        JOGO DA MEMORIA        ================================\n");
    printf("\t=====                                                                                 =====\n");
    printf("\t=====                              SELECAO DE NIVEIS                                  =====\n");
    printf("\t=====                                                                                 =====\n");
    printf("\t=====                               >> 1 - FACIL   <<                                 =====\n");
    printf("\t=====                               >> 2 - MEDIO   <<                                 =====\n");
    printf("\t=====                               >> 3 - DIFICIL <<                                 =====\n");
    printf("\t=====                                                                                 =====\n");
    printf("\t===========================================================================================\n");
    printf("\t===========================================================================================\n");

    scanf("%d", &nivel); // Captura da escolha do jogador

    switch (nivel)
    {
    case 1:
        tamanho = 5;
        tempo = 7;
        break;
    case 2:
        tamanho = 7;
        tempo = 6;
        break;
    case 3:
        tamanho = 10;
        tempo = 5;
        break;
    default:
        printf("Nivel invalido!\n");
        return 0;
    }

    printf("\n >> Pressione ENTER para iniciar... << ");
    while ((c = getch()) != 13)
        ; // Capturado ENTER do usuário

    // Geração dos números aleatórios
    for (int i = 0; i < tamanho; i++)
    {
        num[i] = (rand() % 30) + 1;
    }

    // Contagem regressiva
    int t = tempo;
    do
    {
        system("cls");
        printf("Memorize os numeros (%d segundos):\n\n", t);
        t--;

        for (int i = 0; i < tamanho; i++)
        {
            printf("%d  ", num[i]);
        }

        Sleep(1000);
    } while (t > 0);

    // Respostas do usuário
    system("cls");
    printf("Digite a sequencia correta:\n\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &respostas[i]);

        if (respostas[i] == num[i])
        {
            acertos++;
        }
    }

    // Resultados e mensagens
    system("cls");
    if (acertos == tamanho)
    {
        printf("\n\n");
        printf("\t===========================================================================================\n");
        printf("\t=====                          PARABENS!! VOCE GANHOU!!                               =====\n");
        printf("\t===========================================================================================\n");
    }
    else
    {
        printf("\n\n");
        printf("\t===========================================================================================\n");
        printf("\t=====               IIHHHHH, VOCE PERDEU... PRECISA DE OMEGA 3  KKKKK                 =====\n");
        printf("\t===========================================================================================\n");
        printf("\n\n");
        printf("\tA sequencia correta era: ");
        for (int i = 0; i < tamanho; i++)
        {
            printf("%d ", num[i]);
        }
    }

    system("pause");
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    menu();
    jogoDaMemoria();

    return 0;
}