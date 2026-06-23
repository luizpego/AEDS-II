#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define MaxTam 100

typedef struct
{
    int item[MaxTam];
    int inicio;
    int fim;
} TipoLista;

int menu()
{
    int A = 0;

    printf("\n========== MENU ==========\n");
    printf("1 - Inserir dado\n");
    printf("2 - Remover dado\n");
    printf("3 - Exibir maior e menor valor\n");
    printf("4 - Exibir dados na ordem de entrada\n");
    printf("5 - Exibir endereço de memória dos valores da lista\n");
    printf("0 - Sair\n");
    printf("==========================\n");
    printf("Qual opção você deseja? ");
    scanf("%d", &A);

    return A;
}

void adicionar(TipoLista *Lista)
{
    if (Lista->fim == MaxTam)
    {
        printf("A lista está cheia.\n");
    }
    else
    {
        printf("Qual valor você deseja adicionar à lista? ");
        scanf("%d", &Lista->item[Lista->fim]);

        Lista->fim++;

        printf("Valor adicionado com sucesso.\n");
    }
}

void remover(TipoLista *Lista)
{
    int A = 0, B = -1;

    if (Lista->inicio == Lista->fim)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        printf("Qual valor você deseja remover? ");
        scanf("%d", &A);

        for (int j = Lista->inicio; j < Lista->fim; j++)
        {
            if (Lista->item[j] == A)
            {
                B = j;
                break;
            }
        }

        if (B == -1)
        {
            printf("Valor não encontrado.\n");
        }
        else
        {
            for (int i = B; i < Lista->fim - 1; i++)
            {
                Lista->item[i] = Lista->item[i + 1];
            }

            Lista->fim--;

            printf("Valor removido com sucesso.\n");
        }
    }
}

void maior_menor(TipoLista *Lista)
{
    int menor = 0, maior = 0;

    if (Lista->inicio == Lista->fim)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        maior = Lista->item[Lista->inicio];
        menor = Lista->item[Lista->inicio];

        for (int i = Lista->inicio + 1; i < Lista->fim; i++)
        {
            if (Lista->item[i] > maior)
            {
                maior = Lista->item[i];
            }

            if (Lista->item[i] < menor)
            {
                menor = Lista->item[i];
            }
        }

        printf("O maior valor é: %d\n", maior);
        printf("O menor valor é: %d\n", menor);
    }
}

void exibir(TipoLista *Lista)
{
    if (Lista->inicio == Lista->fim)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        printf("Valores da lista: ");

        for (int i = Lista->inicio; i < Lista->fim; i++)
        {
            printf("%d ", Lista->item[i]);
        }

        printf("\n");
    }
}

void exibir_endereco_memoria(TipoLista *Lista)
{
    if (Lista->inicio == Lista->fim)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        printf("Endereços de memória dos valores da lista:\n");

        for (int i = Lista->inicio; i < Lista->fim; i++)
        {
            printf("Valor %d está no endereço %p\n", Lista->item[i], (void *)&Lista->item[i]);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil.utf8");

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    TipoLista Lista;

    Lista.inicio = 0;
    Lista.fim = 0;

    int Menu = 0;

    do
    {
        Menu = menu();

        switch (Menu)
        {
        case 1:
            adicionar(&Lista);
            break;

        case 2:
            remover(&Lista);
            break;

        case 3:
            maior_menor(&Lista);
            break;

        case 4:
            exibir(&Lista);
            break;

        case 5:
            exibir_endereco_memoria(&Lista);
            break;

        case 0:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opção inválida.\n");
            break;
        }

        system("pause");
        system("cls");

    } while (Menu != 0);

    return 0;
}