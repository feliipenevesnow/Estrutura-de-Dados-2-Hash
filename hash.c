# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <windows.h>
# include <time.h>
# include <conio.h>
# include "hash.h"

void imprimirMenu(int *op)
{
    int i = 0;

    system("cls");

    cor(9);

    posicao(1,1);
    linha(1,201);
    linha(41,205);
    linha(1,187);

    for(i = 0; i < 16; i++)
    {

        if(i % 2 == 0)
        {
            posicao(1,2+i);
            printf("%c", 186);

            cor(15);
            posicao(5, 2+i);

            switch(i)
            {
            case 0:
                printf("Tabela Hash - Por Felipe Neves");
                break;
            case 2:
                printf("1. Inserir.");
                break;
            case 4:
                printf("2. Remover por chave.");
                break;
            case 6:
                printf("3. Encontrar por chave.");
                break;
            case 8:
                printf("4. Listar todas posicoes.");
                break;
            case 10:
                printf("5. Gerar numeros aleatorios.");
                break;
            case 12:
                printf("6. Remover todos numeros.");
                break;
            case 14:
                printf("7. Sair.");
                break;
            }

            cor(9);
            posicao(43, 2+i);
            printf("%c", 186);
        }
        else
        {
            posicao(1,2+i);
            printf("%c", 204);

            linha(41,205);

            posicao(43, 2+i);
            printf("%c", 185);
        }
    }

    posicao(1,1+i);
    linha(1,200);
    linha(41,205);
    linha(1,188);

    //--------------------

    posicao(44,1);
    linha(1,201);
    linha(41,205);
    linha(1,187);

    posicao(44,2);
    printf("%c", 204);

    posicao(86, 2);
    printf("%c", 185);

    posicao(44, 3);
    linha(1,200);
    linha(41,205);
    linha(1,188);


    cor(15);
    posicao(46,2);
    printf(" Digite uma opcao: ");
    scanf("%d", op);

    posicao(1,17);
}

void imprimirMensagemInserirNumero(Pessoa *pessoa)
{
    int i = 0, idade = 0;

// Quadrado grande mensagem

    cor(9);
    posicao(44,4 + i);
    linha(1,201);
    linha(41,205);
    linha(1,187);

    for(i = 0; i < 3; i++)
    {
        posicao(44,5+i);
        printf("%c", 186);

        posicao(86, 5+i);
        printf("%c", 186);
    }

    posicao(44, 5+i);
    linha(1,200);
    linha(41,205);
    linha(1,188);

// Quadrado Menor

    cor(9);
    posicao(44,4);
    linha(1,201);
    linha(12,205);
    linha(1,203);


    posicao(44,5);
    printf("%c", 186);

    posicao(86, 5);
    printf("%c", 186);


    posicao(44, 6);
    linha(1,204);
    linha(12,205);
    linha(1,188);

    cor(15);
    posicao(46,5);
    printf("Inserir");

    posicao(46,7);
    printf("Digite um prontuario: ");
    fflush(stdin);
    scanf("%[^\n]", pessoa->pront);

    posicao(46,7);
    printf("Digite o nome:                         ");
    posicao(61,7);
    fflush(stdin);
    scanf("%[^\n]", pessoa->nome);

    posicao(46,7);
    printf("Digite o cargo:                         ");
    posicao(62,7);
    fflush(stdin);
    scanf("%[^\n]", pessoa->cargo);

    posicao(46,7);
    printf("Digite a idade:                         ");
    posicao(62,7);
    scanf("%d", &idade);
    pessoa->idade = idade;

    posicao(46,7);
    printf("Digite o setor:                         ");
    posicao(62,7);
    fflush(stdin);
    scanf("%[^\n]", pessoa->setor);

    posicao(45,11);
    system("pause");
}

void imprimirMensagemDigiteProntuarioRemover(char pront[])
{
    int i = 0, idade = 0;

// Quadrado grande mensagem

    cor(9);
    posicao(44,4 + i);
    linha(1,201);
    linha(41,205);
    linha(1,187);

    for(i = 0; i < 3; i++)
    {
        posicao(44,5+i);
        printf("%c", 186);

        posicao(86, 5+i);
        printf("%c", 186);
    }

    posicao(44, 5+i);
    linha(1,200);
    linha(41,205);
    linha(1,188);

// Quadrado Menor

    cor(9);
    posicao(44,4);
    linha(1,201);
    linha(12,205);
    linha(1,203);


    posicao(44,5);
    printf("%c", 186);

    posicao(86, 5);
    printf("%c", 186);


    posicao(44, 6);
    linha(1,204);
    linha(12,205);
    linha(1,188);

    cor(15);
    posicao(46,5);
    printf("Remover");

    posicao(46,7);
    printf("Digite um prontuario: ");
    fflush(stdin);
    scanf("%[^\n]", pront);

    posicao(45,11);
    system("pause");
}

void imprimirMensagemDigiteProntuarioEncontrar(char pront[])
{
    int i = 0, idade = 0;

// Quadrado grande mensagem

    cor(9);
    posicao(44,4 + i);
    linha(1,201);
    linha(41,205);
    linha(1,187);

    for(i = 0; i < 3; i++)
    {
        posicao(44,5+i);
        printf("%c", 186);

        posicao(86, 5+i);
        printf("%c", 186);
    }

    posicao(44, 5+i);
    linha(1,200);
    linha(41,205);
    linha(1,188);

// Quadrado Menor

    cor(9);
    posicao(44,4);
    linha(1,201);
    linha(12,205);
    linha(1,203);


    posicao(44,5);
    printf("%c", 186);

    posicao(86, 5);
    printf("%c", 186);


    posicao(44, 6);
    linha(1,204);
    linha(12,205);
    linha(1,188);

    cor(15);
    posicao(46,5);
    printf("Encontrar");

    posicao(46,7);
    printf("Digite um prontuario: ");
    fflush(stdin);
    scanf("%[^\n]", pront);

    posicao(45,11);
    system("pause");
}

void imprimirMensagemOpcaoInvalida()
{
    int i = 0;

// Quadrado grande mensagem

    cor(9);
    posicao(44,4 + i);
    linha(1,201);
    linha(41,205);
    linha(1,187);

    for(i = 0; i < 4; i++)
    {
        posicao(44,5+i);
        printf("%c", 186);

        posicao(86, 5+i);
        printf("%c", 186);
    }

    posicao(44, 5+i);
    linha(1,200);
    linha(41,205);
    linha(1,188);

// Quadrado Menor

    cor(9);
    posicao(44,4);
    linha(1,201);
    linha(12,205);
    linha(1,203);


    posicao(44,5);
    printf("%c", 186);

    posicao(86, 5);
    printf("%c", 186);


    posicao(44, 6);
    linha(1,204);
    linha(12,205);
    linha(1,188);

    cor(15);
    posicao(46,5);
    printf("Atencao: ");

    posicao(46,7);
    printf("Opcao invalidade digitada. ");
    posicao(46,8);
    printf("Digite novamente!");

    posicao(45,11);
    system("pause");
}

void main()
{
    Hash tab;

    inicializaHash(tab);

    int op = 0, num = 0;
    Pessoa pessoa;
    char pront[10];

    do
    {
        imprimirMenu(&op);

        switch(op)
        {
        case 1:

            imprimirMensagemInserirNumero(&pessoa);
            insereHash(tab, pessoa);
            break;
        case 2:
            imprimirMensagemDigiteProntuarioRemover(pront);
            removeHash(tab, pront);
            break;
        case 3:
            imprimirMensagemDigiteProntuarioEncontrar(pront);
            buscaHash(tab,pront);
            break;
        case 4:
            imprimeHash(tab);
            break;
        case 5:
            numeroAleatorio(tab);
            break;
        case 6:
            removerTodos(tab);
            break;
        case 7:
            break;
        default:
            imprimirMensagemOpcaoInvalida();
            break;
        }

    }
    while (op != 7);



}
