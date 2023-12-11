#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

struct informacao_de_contato
{
    char nome[200];
    char numero[200];
    char email[200];
};

struct informacao_de_contato contato[3];
int i = 0;

char *conversor(char *name)
{
    int j = 0;
    for (i = 0; i < 3; i++)
    {
        if (strcmp(name, contato[i].nome) == 0)
        {
            j = i;
            return contato[j].numero;
        }
    }

    return 0;
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    char *x;
    char name[200];
    char resultado[200];

    for (i = 0; i < 3; i++)
    {

        printf("Digite o %d nome:", i + 1);
        gets(contato[i].nome);

        fflush(stdin);

        printf("Digite o telefone:");
        gets(contato[i].numero);

        fflush(stdin);

        printf("Digite o email:");
        gets(contato[i].email);
        puts("");
    }
    fflush(stdin);
    printf("Digite o nome para achar contato:");
    gets(name);
    fflush(stdin);

    x = conversor(name);

    if (x == 0)
    {
        printf("Contato não encontrado.\n");
    }
    else
    {
        printf("Telefone de %s é: %s\n", name, x);
    }

    return 0;
}
