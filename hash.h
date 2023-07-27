#define tam 1113
#define iN 11
#define jN 10
#define iC 6
#define jC 11
#define iS 5
#define jS 11

typedef struct pessoa
{
    char pront[10];
    char nome[50];
    char cargo[25];
    int idade;
    char setor[25];
} Pessoa;

typedef struct dados
{
    Pessoa pessoa;
    struct dados *prox;
} Dados;

Dados* remover(Dados *dados);

char nomes[iN][jN] =
{
    {'G', 'a', 'b', 'r', 'i', 'e', 'l', '\0'},
    {'F', 'e', 'l', 'i', 'p', 'e', '\0'},
    {'J', 'e', 'n', 'n', 'i', 'f', 'e', 'r', '\0'},
    {'F', 'l', 'a', 'v', 'i', 'a', '\0'},
    {'J', 'u', 'l', 'i', 'a', '\0'},
    {'N', 'a', 't', 'a', 'l', 'y', 'e', '\0'},
    {'P', 'e', 'd', 'r', 'o', '\0'},
    {'J', 'o', 'a', 'o', '\0'},
    {'L', 'u', 'c', 'a', 's', '\0'},
    {'H', 'e', 'n', 'r', 'y', '\0'},
    {'C', 'a', 'r', 'l', 'a', '\0'},
};

char cargos[iC][jC] =
{
    {'M', 'e', 'd', 'i', 'c', 'o', '\0'},
    {'E', 'n', 'f', 'e', 'r', 'm', 'e', 'i', 'r', 'o', '\0'},
    {'S', 'o', 'c', 'o', 'r', 'r', 'i', 's', 't', 'a', '\0'},
    {'C', 'i', 'r', 'u', 'r', 'g', 'i', 'a', 'o', '\0'},
    {'P', 's', 'i', 'c', 'o', 'l', 'o', 'g', 'o', '\0'},
    {'T', 'e', 'r', 'a', 'p', 'e', 'l', 't', 'a', '\0'},
};

char setores[iS][jS] =
{
    {'A', 'l', 'a', ' ', 'A', '\0'},
    {'A', 'l', 'a', ' ', 'B', '\0'},
    {'A', 'l', 'a', ' ', 'C', '\0'},
    {'A', 'l', 'a', ' ', 'D', '\0'},
    {'A', 'l', 'a', ' ', 'E', '\0'},
};

typedef struct dados Dados;
typedef Dados* Hash[tam];


int funcaoHash(char pront[])
{
    char prontuario[8];

    for(int i = 2; i < strlen(pront); i++)
    {
        prontuario[i - 2] = pront[i];
    }

    int num = atoi(prontuario);

    return(num%tam);
}

void inicializaHash(Hash tab)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        tab[i] = NULL;
    }
}

void insereHash(Hash tab, Pessoa pessoa)
{
    int i = 0;

    int chave = funcaoHash(pessoa.pront);

    Dados* aux = tab[chave];

    while(aux != NULL)
    {
        if(strcmp(aux->pessoa.pront, pessoa.pront) == 0)
        {
            break;
        }
        aux = aux->prox;
    }
    if(aux == NULL)
    {
        aux = (Dados*)malloc(sizeof(Dados));
        aux->pessoa = pessoa;
        aux->prox = tab[chave];
        tab[chave] = aux;
    }
}

void buscaHash(Hash tab, char pront[])
{
    int pos = funcaoHash(pront);
    if(pos > tam || pos < 0)
    {
        printf("\nPosicao nao encontrada!");
        return;
    }
    else
    {
        imprimeColisao(tab,pos, pront);
    }
}

void imprimeColisao(Hash tab, int pos, char pront[])
{
    Dados* aux = tab[pos];
    int primeiro = 0;
    if(aux == NULL)
    {
        printf("Esta posicao esta vazia!");
        return;
    }
    else
    {
        if(aux != NULL)
        {
            cor(15);

            posicao(45, 11);

            if(strcmp(aux->pessoa.pront, pront) == 0)
            {
                printf("Prontuario: %s                               ",aux->pessoa.pront);
                posicao(45, 12);
                printf("Nome: %s                               ",aux->pessoa.nome);
                posicao(45, 13);
                printf("Cargo: %s                               ",aux->pessoa.cargo);
                posicao(45, 14);
                printf("Idade: %d                               ",aux->pessoa.idade);
                posicao(45, 15);
                printf("Setor: %s                               ",aux->pessoa.setor);
                posicao(45, 17);
                system("pause");
                primeiro = 1;
            }


            while(aux != NULL && primeiro != 1)
            {
                if(strcmp(aux->pessoa.pront, pront) != 0)
                    aux = aux->prox;
                else
                {
                    printf("Prontuario: %s                               ",aux->pessoa.pront);
                    posicao(45, 12);
                    printf("Nome: %s                               ",aux->pessoa.nome);
                    posicao(45, 13);
                    printf("Cargo: %s                               ",aux->pessoa.cargo);
                    posicao(45, 14);
                    printf("Idade: %d                               ",aux->pessoa.idade);
                    posicao(45, 15);
                    printf("Setor: %s                               ",aux->pessoa.setor);
                    posicao(45, 17);
                    system("pause");
                    break;
                }
            }
        }
    }
}

void removeHash(Hash tab, char pront[])
{
    int chave = funcaoHash(pront);

    int pos = chave;

    char ex[10];

    strcpy(ex, pront);

    if(chave > tam)
    {
        return;
    }
    else
    {
        if(tab[pos] == NULL)
        {
            return;
        }
        else
        {
            printf("\n\n\n");
            if(strcmp(tab[pos]->pessoa.pront, ex) == 0)
            {
                if(tab[pos]->prox == NULL)
                {
                    tab[pos] = NULL;
                    return;
                }
                if(tab[pos]->prox != NULL)
                {
                    tab[pos]->pessoa = tab[pos]->prox->pessoa;
                    tab[pos]->prox = tab[pos]->prox->prox;
                    return;
                }
            }
            else
            {
                if(strcmp(tab[pos]->pessoa.pront, ex) != 0)
                {
                    if(tab[pos]->prox == NULL)
                    {
                        return;
                    }
                    else
                    {
                        Dados* ant = NULL;
                        Dados* aux = tab[pos]->prox;
                        while(aux->prox != NULL  && strcmp(aux->pessoa.pront, ex) != 0)
                        {
                            ant = aux;
                            aux = aux->prox;
                        }
                        if(strcmp(aux->pessoa.pront, ex) != 0)
                        {
                            return;
                        }
                        else
                        {
                            if(ant == NULL)
                            {
                                tab[pos]->prox = aux->prox;
                            }
                            else
                            {
                                ant->prox = aux->prox;
                            }
                            aux = NULL;
                            free(aux);
                        }
                    }
                }
            }
        }
    }
}

void imprimeHash(Hash tab)
{
    int  i = 0,cont = 0;

    printf("\n");
    for(i = 0; i < tam; i++)
    {
        if(tab[i] != NULL)
        {
            cor(15);
            printf("[%d] = %s", i, tab[i]->pessoa.pront);
            Dados* aux = tab[i]->prox;

            while(aux!=NULL)
            {
                printf(" -> %s",aux->pessoa.pront);
                aux=aux->prox;
            }
            printf("\n");
        }
        else
        {
            printf("[%d] = \n", i);
        }

    }


    system("pause");
}


void linha(int q, int a)
{
    int j;
    for(j = 1; j <= q; j++)
        printf("%c",a);
}

void cor(WORD cor)
{
    HANDLE SaidaSTD = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(SaidaSTD, cor);
}

void posicao(int x, int y)
{
    HANDLE SaidaSTD = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(SaidaSTD, coord);
}

void indiceColisao(Hash tab)
{
    int i, cont = 0;
    posicao(25,1);
    printf("\nOcorreram colisoes nas posicoes\n");
    for(i = 0 ; i< tam; i++)
    {
        if(tab[i] != NULL && tab[i]->prox)
        {
            printf("%d\t",i);
        }
    }
    return;
}

void numeroAleatorio(Hash tab)
{
    int numero, cont = 0, pos;

    Pessoa pessoa;

    srand(time(NULL));

    pessoa.pront[0] = 'p';
    pessoa.pront[1] = 'e';


    char letra;

    while(cont != tam)
    {

        for(int i = 2; i < 9; i++)
        {
            numero = (rand()% 10);
            char letra = numero + '0';
            pessoa.pront[i] = letra;
        }

        pessoa.pront[9] = '\0';

        pos = (rand()% iN);


        for(int j = 0; j < jN; j++)
        {
            pessoa.nome[j] = nomes[pos][j];
        }

        pos = (rand()% iC);


        for(int j = 0; j < jC; j++)
        {
            pessoa.cargo[j] = cargos[pos][j];
        }

        pos = (rand()% iS);


        for(int j = 0; j < jS; j++)
        {
            pessoa.setor[j] = setores[pos][j];
        }

        insereHash(tab, pessoa);
        cont++;
    }
}

void removerTodos(Hash tab)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        while(!vazia(tab[i]))
        {
            tab[i] = remover(tab[i]);
        }
    }
}


Dados* remover(Dados *dados)
{
    if(dados == NULL)
    {
        return NULL;
    }
    else
    {
        remover(dados->prox);
        free(dados);
        return NULL;
    }
}


int vazia(Dados *lista)
{
    if(lista == NULL)
        return 1;
    return 0;
}



