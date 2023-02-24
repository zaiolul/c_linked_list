
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../includes/linkedlist.h"

/*Creates a node with NAME, SURNAME, PHONE, EMAIL as data*/
node create_node(char name[], char surname[], char phone[], char email[])
{
	node n	= (node)malloc(sizeof(struct Node));
	n->next = NULL;
	strncpy(n->name, name, 30);
	strncpy(n->surname, surname, 30);
	strncpy(n->phone, phone, 30);
	strncpy(n->email, email, 50);

	return n;
}
/*adds node ENTRY to list starting with HEAD*/
void list_add(node *head, node entry)
{
	node last = *head;

	if (*head == NULL) {
		*head = entry;
	} else {
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = entry;
	}
}

/*Gets the size of list*/
int list_size(node head)
{
	int count = 0;
	node n = head;
	while(n != NULL){
		count++;
		n = n->next;
	}
	return count;
}
/*Inserts a node ENTRY at INDEX in a list starting with HEAD*/
void list_insert(node *head, node entry, int index)
{
	int size = list_size(*head);
	if (index > size - 1 || index < 0) {
		printf("Negalimas indeksas");
		return;
	}
	if(index == 0){
		entry->next = *head;
		*head = entry;
		return;
	}
	node prev = *head;
	node n = (*head)->next;
	int i = 1;

	while(n != NULL){
		if (i == index) {
			entry->next = n;
			prev->next  = entry;
			break;
		}
		i++;
		prev = n;
		n = n->next;
	}
	
}

/*Removes a node from list at INDEX*/
void list_delete_index(node *head, int index)
{	
	if(index == 0){
		
		node temp;
		temp  = *head;
		*head = (*head)->next;
		free(temp);
		return;
	}

	int i = 1;
	node prev = *head;
	node n = (*head)->next;

	while(n != NULL){
		if(i == index){
			prev->next = n->next;
			free(n);
			return;
		}
		i++;
		prev = n;
		n = n->next;
	}
}
/*Removes all nodes from list*/
void list_clear(node *head)
{
	while (*head != NULL) {
		node temp = *head;
		*head	  = (*head)->next;
		free(temp);
	}
}
/*Searches for node in list at INDEX*/
node list_search_index(node head, int index)
{
	if (index < 0 && index > list_size(head) - 1) {
		return NULL;
	}

	int i = 0;
	node n = head;

	while(n != NULL)
	{
		if(i == index)
		{
			return n;
		}
		n = n->next;
		i ++;
	}

	return NULL;
}
/*Searches for node in list by FIELD*/
int list_search_field(node found[], node head, char *field)
{
	int size = list_size(head);
	if(size == 0){
		return -1;
	}

	node n = head;
	int i = 0;

	while (n != NULL) {
		if (strcmp(n->name, field) == 0 || strcmp(n->surname, field) == 0 ||
		    strcmp(n->phone, field) == 0 || strcmp(n->email, field) == 0) {
			found[i] = n;
			i ++;
		}
		n = n->next;
		
	}
	if(i > 0){
		return i;
	} else{
		return -1;
	}
}

/*Prints the list to stdout*/
void print_list(node head)
{
	int i = 0;
	node n = head;
	while (n != NULL) {
		printf("%d: %s %s %s %s\n", i, n->name, n->surname, n->phone, n->email);
		i++;
		n = n->next;
	}
	putc('\n', stdout);
}
