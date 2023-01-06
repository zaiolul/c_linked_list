#include "data.h"
node create_node(char name[], char surname[], char phone[], char email[]);
int list_size(node head);
void list_add(node *head, node entry);
void list_insert(node *head, node entry, int index);
void list_delete_index(node *head, int index);
void list_clear(node *head);
node list_search_index(node head, int index);
node list_search_field(node head, char* field);
int list_size(node head);
void print_list(node head);
