// Implements a dictionary's functionality
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 17602;

// Hash table
node *table[17602];

// dict size
unsigned int numberWords = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int i = hash(word);

    for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // return ((int) tolower(word[0]))-97;

    unsigned int result;

    result = (!!word[0]) * (677 * (tolower(word[0]) - 97));
    result += (word[0] && word[1]) * (27 * (tolower(word[1]) - 97));
    return result;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }

    char pWord[46];

    while (fscanf(inptr, "%s", pWord) != EOF)
    {
        int i = hash(pWord);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload();
            return false;
        }

        // Definir o valor e ponteiro no nosso node
        strcpy(n->word, pWord);
        node *aux = table[i];
        n->next = aux;
        table[i] = n;
        numberWords++;
    }

    fclose(inptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return numberWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    for (int i = 0; i < N; i++)
    {

        while (table[i] != NULL)
        {
            // Nós apontamos para o próximo nó primeiro
            node *tmp = table[i]->next;

            // Então, podemos liberar o primeiro nó free(list);
            free(table[i]);
            // Agora podemos definir a lista para apontar para o próximo nó
            table[i] = tmp;

            // Se a lista for nula, quando não houver mais nós restantes, nosso loop while irá parar
        }
    }

    return true;
}
