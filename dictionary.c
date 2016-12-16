/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"
#include "hash.h"

// declare table in file scope
node* hashtable[M];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO string to lower case should be separate function
    char key[LENGTH + 1];
    memset(key, 0, sizeof(key));
    strcpy(key, word);
    for (int i = 0; i < sizeof(key); i++)
    {
        if (isupper(key[i]))
        {
            key[i] = tolower(key[i]);
        }
    }
    return searchList(hashtable[hash(key)], key);
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    initTable(hashtable);
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    int hashIndex = 0;
    int wordIndex = 0;
    char word[LENGTH + 1];
    memset(word, 0, sizeof(word));
    // get characters and add to node->word until newline,
    // then add null and reset index
    // FIXME file must terminate with newline
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        if (c != '\n') {
            word[wordIndex] = c;
            wordIndex++;
        }
        else {
            addToList(hashtable[hash(word)], word);
            memset(word, 0, sizeof(word));
            wordIndex = 0;
            hashIndex++;
        }
    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    int counterList = 0;
    for (int i = 0; i < M; i++)
    {
        counterList = counterList + countList(hashtable[i]);
    }
    return counterList;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < M; i++)
    {
        destroyList(hashtable[i]);
    }
    return true;
}
