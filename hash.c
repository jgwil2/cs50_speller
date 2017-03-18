#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"
#include "dictionary.h"

// linked list code
typedef struct listNode
{
    char word[LENGTH + 1];
    struct listNode* next;
} listNode;

// init table
void initTable(listNode* hashtable[])
{
    for (int i = 0; i < M; i++) {
        hashtable[i] = malloc(sizeof(listNode));
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
void addToList(listNode* slot, char* key)
{
    // check listNode at key, if it is blank insert,
    // else traverse and insert
    if (slot->word[0] == '\0')
    {
        strcpy(slot->word, key);
        return;
    }
    // make sure not to overwrite next listNode
    if (slot->next == NULL)
    {
        slot->next = malloc(sizeof(listNode));
        slot->next->word[0] = '\0';
        slot->next->next = NULL;
    }
    addToList(slot->next, key);
}

// given head of list and key, return true if key in list
bool searchList(listNode* slot, char* key)
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

// given head of list, return number of listNodes in list with data
int countList(listNode* slot)
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
void destroyList(listNode* slot)
{
    if (slot->next != NULL) {
        destroyList(slot->next);
    }
    free(slot);
}
