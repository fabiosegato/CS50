#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Use malloc para alocar espaço suficiente para uma matriz com 3 inteiros
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    // Defina os valores em nosso array
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Agora, se quisermos armazenar outro valor, podemos alocar mais memória
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
         free(list);
         return 1;
    }

    // Copie a lista de tamanho 3 para a lista de tamanho 4
    for(int i = 0; i < 3; i++)
    {
         tmp[i] = list[i];
    }

    // Adicionar novo número à lista de tamanho 4
    tmp[3] = 4;

    // Lista original liberada de tamanho 3
    free(list);

    // Lembre-se da nova lista de tamanho 4
    list = tmp;

    // Imprimir lista
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free nova lista
    free(list);
}