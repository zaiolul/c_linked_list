#include "data.h"

node create_node(struct address entry);
int list_size(node head);
void add(node *head, struct address entry);
void insert(node *head, struct address entry, int index);
void delete_index(node *head, int index);
void delete_list(node *head);
struct address search_index(node head, int index);
int list_size(node head);
void print_list(node head);
