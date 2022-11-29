#include "data.h"

node create_node(struct address entry);
int list_size(node head);
void list_add(node *head, struct address entry);
void list_insert(node *head, struct address entry, int index);
void list_delete_index(node *head, int index);
void list_clear(node *head);
struct address *list_search_index(node head, int index);
int list_size(node head);
void print_list(node head);
