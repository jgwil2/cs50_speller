#ifndef HASH_H
#define HASH_H

// hashtable size
#define M 143093

// node for linked list
struct listNode;
typedef struct listNode listNode;

// init table
void initTable(listNode* hashtable[]);

// generate an int from a string for insertion into hashtable
int hash(char* key);

// given head of list and key, insert key into list
void addToList(listNode* slot, char* key);

// given head of list and key, return true if key in list
bool searchList(listNode* slot, char* key);

// given head of list, return number of listNodes in list with data
int countList(listNode* slot);

// free all memory in list
void destroyList(listNode* slot);

#endif
