
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../includes/data.h"

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
	for (node d = head; d != NULL; d = d->next) {
		count++;
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

	node prev = NULL;
	int i	  = 0;
	for (node d = *head; d != NULL; d = d->next) {
		if (i == index) {
			if (d == *head) {
				entry->next = *head;
				*head	    = entry;
			} else {
				entry->next = d;
				prev->next  = entry;
			}
			break;
		}
		i++;
		prev = d;
	}
}

/*Removes a node from list at INDEX*/
void list_delete_index(node *head, int index)
{
	node prev = NULL;

	int i = 0;
	for (node d = *head; d != NULL; d = d->next) {
		if (i == index) {
			if (d == *head) {
				node temp;
				temp  = *head;
				*head = (*head)->next;
				free(temp);
			} else {
				prev->next = d->next;
				free(d);
			}
			return;
		}
		i++;
		prev = d;
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
	node n = NULL;
	if (index < 0 && index > list_size(head) - 1) {
		return NULL;
	}
	int i = 0;

	for (node d = head; d != NULL; d = d->next) {
		if (i == index) {
			return d;
		}
		i++;
	}
	return n;
}
/*Searches for node in list by FIELD*/
node list_search_field(node head, char *field)
{
	node n	 = head;
	while (n != NULL) {
		if (strcmp(n->name, field) == 0 || strcmp(n->surname, field) == 0 ||
		    strcmp(n->phone, field) == 0 || strcmp(n->email, field) == 0) {
			return n;
		}
		n = n->next;
	}

	return NULL;
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
