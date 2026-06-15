#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#endif

/*
    ALTERAÇÃO:

    Antes existia:

    #define MaxTam 100

    Como agora a lista é dinâmica, não existe mais um limite fixo.
    O valor abaixo representa apenas a capacidade inicial da lista.
*/
#define TamInicial 100

/*
    Este programa implementa uma lista sequencial dinâmica.

    Diferentemente da versão estática, onde o vetor possuía tamanho fixo,
    agora a memória é alocada dinamicamente utilizando malloc e pode ser
    aumentada utilizando realloc sempre que necessário.

    Dessa forma, a lista não fica limitada a uma quantidade fixa de
    elementos definida em tempo de compilação.
*/

/*
    Estrutura que representa a lista sequencial.

    ALTERAÇÃO:

    O vetor estático:

        int item[MaxTam];

    foi substituído por:

        int *item;

    Agora os elementos ficam armazenados em uma região de memória
    criada dinamicamente.

    A variável capacidade controla quantas posições estão atualmente
    disponíveis nessa região de memória.
*/
typedef struct
{
    int *item;
    int inicio;
    int fim;
    int capacidade;
} TipoLista;

/*
    Função responsável pela interação inicial com o usuário.

    Ela apresenta as operações disponíveis e retorna a opção escolhida.
*/
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

/*
    Insere um novo elemento no final da lista.

    ALTERAÇÃO:

    Quando a lista fica cheia, utilizamos realloc para aumentar
    automaticamente a quantidade de memória disponível.

    Neste exemplo, a capacidade é dobrada sempre que o vetor
    estiver completamente ocupado.
*/
void adicionar(TipoLista *Lista)
{
    if (Lista->fim == Lista->capacidade)
    {
        int novaCapacidade = Lista->capacidade * 2;

        int *novoVetor =
            (int *)realloc(
                Lista->item,
                novaCapacidade * sizeof(int));

        if (novoVetor == NULL)
        {
            printf("Erro ao realocar memória.\n");
            return;
        }

        Lista->item = novoVetor;
        Lista->capacidade = novaCapacidade;

        printf("Capacidade aumentada para %d posições.\n",
               Lista->capacidade);
    }

    printf("Qual valor você deseja adicionar à lista? ");
    scanf("%d", &Lista->item[Lista->fim]);

    Lista->fim++;

    printf("Valor adicionado com sucesso.\n");
}

/*
    Remove da lista o valor informado pelo usuário.

    Primeiro é realizada uma busca sequencial.

    Caso o valor seja encontrado, os elementos posteriores
    são deslocados uma posição para a esquerda.

    Complexidade: O(n)
*/
void remover(TipoLista *Lista)
{
    int A = 0;
    int B = -1;

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

/*
    Encontra e exibe o maior e o menor valor da lista.

    O primeiro elemento da lista é usado como referência inicial.

    Complexidade: O(n)
*/
void maior_menor(TipoLista *Lista)
{
    int menor = 0;
    int maior = 0;

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

/*
    Exibe todos os elementos da lista na ordem de inserção.

    Complexidade: O(n)
*/
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

/*
    Exibe o endereço de memória de cada elemento da lista.

    Como os elementos continuam armazenados em posições
    consecutivas da memória, é possível observar que os
    endereços seguem uma sequência.
*/
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
            printf("Valor %d está no endereço %p\n",
                   Lista->item[i],
                   (void *)&Lista->item[i]);
        }
    }
}

/*
    Função principal do programa.

    ALTERAÇÃO:

    A memória da lista é criada utilizando malloc.

    malloc reserva espaço para TamInicial inteiros.

    Quando o programa termina, a memória deve ser liberada
    utilizando free para evitar vazamentos de memória.
*/
int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil.utf8");

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    TipoLista Lista;

    /*
        ALTERAÇÃO:

        Alocação dinâmica da memória.

        malloc retorna o endereço inicial da região criada.

        Se retornar NULL significa que não foi possível
        reservar memória.
    */
    Lista.item = (int *)malloc(TamInicial * sizeof(int));

    if (Lista.item == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    Lista.inicio = 0;
    Lista.fim = 0;
    Lista.capacidade = TamInicial;

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

    /*
        ALTERAÇÃO:

        Toda memória obtida com malloc ou realloc deve ser
        devolvida ao sistema operacional utilizando free.

        Isso evita vazamentos de memória (memory leaks).
    */
    free(Lista.item);

    return 0;
}