#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{
    struct Node* next;
    char name[30];
    char surname[30];
    char phone[30];
    char email[50];
};
typedef struct Node *node;

node create_node(char name[], char surname[], char phone[], char email[]);
int list_size(node head);
void list_add(node *head, node entry);
void list_insert(node *head, node entry, int index);
void list_delete_index(node *head, int index);
void list_clear(node *head);
node list_search_index(node head, int index);
int list_search_field(node found[], node head, char* field);
int list_size(node head);
void print_list(node head);
#endif
