#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "dictionary.h"

// linked list code
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
} node;

// init table
void initTable(node* hashtable[])
{
    for (int i = 0; i < M; i++) {
        hashtable[i] = malloc(sizeof(node));
        hashtable[i]->word[0] = '\0';
        hashtable[i]->next = NULL;
    }
}

// generate an int from a string for insertion into hashtable
int hash(char* key)
{
    const int R = 31;
    int hash = 0;
    for (int i = 0; i < sizeof(key); i++)
    {
        hash = (R * hash + key[i]) % M;
    }
    return hash;
}

// given head of list and key, insert key into list
void addToList(node* slot, char* key)
{
    // check node at key, if it is blank insert,
    // else traverse and insert
    if (slot->word[0] == '\0')
    {
        strcpy(slot->word, key);
        return;
    }
    // make sure not to overwrite next node
    if (slot->next == NULL)
    {
        slot->next = malloc(sizeof(node));
        slot->next->word[0] = '\0';
        slot->next->next = NULL;
    }
    addToList(slot->next, key);
}

// given head of list and key, return true if key in list
bool searchList(node* slot, char* key)
{
    if (strcmp(slot->word, key) == 0)
    {
        return true;
    }
    if (slot->next != NULL)
    {
        return searchList(slot->next, key);
    }
    return false;
}

// given head of list, return number of nodes in list with data
int countList(node* slot)
{
    if (slot->word[0] != '\0' && slot->next != NULL)
    {
        return 1 + countList(slot->next);
    }
    else if (slot->word[0] != '\0' && slot->next == NULL)
    {
        return 1;
    }
    else {
        return 0;
    }
}

// free all memory in list
void destroyList(node* slot)
{
    if (slot->next != NULL) {
        destroyList(slot->next);
    }
    free(slot);
}
