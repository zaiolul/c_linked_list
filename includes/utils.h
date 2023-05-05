#ifndef UTILS_H
#define UTILS_H
#include "linkedlist.h"
int get_input_number(char* text, int rangeMin, int rangeMax);
int create_entry(char* input, node* entry);
void add_pos(node* head);
void add(node* head);
void delete_pos(node* head);
void delete_all(node* head);
void get_pos(node head);
void get_field(node head);
void print_all(node head);
void load_start_entries(node* head);
void print_usage();

#endif