#ifndef HASH_H
#define HASH_H

// hashtable size
#define M 143093

// node for linked list
struct node;
typedef struct node node;

// init table
void initTable(node* hashtable[]);

// generate an int from a string for insertion into hashtable
int hash(char* key);

// given head of list and key, insert key into list
void addToList(node* slot, char* key);

// given head of list and key, return true if key in list
bool searchList(node* slot, char* key);

// given head of list, return number of nodes in list with data
int countList(node* slot);

// free all memory in list
void destroyList(node* slot);

#endif 