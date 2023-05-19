#include <stdio.h>
#include <stdlib.h>

// Representando um nó

typedef struct node
{
     int number; struct node *next;
}
node;

node* add_node_first(node *pList,node *pN,int pNumber);

int main(void)
{
    // Lista de tamanho 0. Inicializamos o valor para NULL explicitamente, então há
    // nenhum valor de lixo para nossa variável de lista
    node *list = NULL;
    node *n = NULL;

    list = add_node_first(list,n,1);
    list = add_node_first(list,n,2);
    list = add_node_first(list,n,3);
    list = add_node_first(list,n,3);
    list = add_node_first(list,n,3);
    list = add_node_first(list,n,89);

    for(node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // Libere a lista, usando um loop while e uma variável temporária para apontar
    // para o próximo nó antes de liberar o atua
    while(list != NULL)
    {
        // Nós apontamos para o próximo nó primeiro
        node *tmp = list->next;

        // Então, podemos liberar o primeiro nó free(list);
        free(list);
        // Agora podemos definir a lista para apontar para o próximo nó
        list = tmp;

        // Se a lista for nula, quando não houver mais nós restantes, nosso loop while irá parar
    }
}

node* add_node_first(node *pList,node *pN,int pNumber){

    pN = malloc(sizeof(node));
    if(pN == NULL)
    {
       free(pList);
       return NULL;
    }

    // Definir o valor e ponteiro no nosso node
    pN->number = pNumber;
    node *aux = pList;
    pN->next = aux;
    pList = pN;
    return pList;

}