#include "includes/data.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

node create_node(struct address entry)
{
     node n = (node)malloc(sizeof(struct Node));
     n->next = NULL;
     n->entry = entry;
     return n;
}

void list_add(node *head, struct address entry)
{
    node last = *head;
    node n = create_node(entry);
   
    if(*head == NULL)
    {
        *head = n;
    }
    else
    {
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = n;
    }
}
void list_insert(node *head, struct address entry, int index)
{
    
    int size = list_size(*head);
    if(index > size - 1 || index < 0)
    {
        printf("Negalimas indeksas");
        return;
    }

    node n = create_node(entry);
    node prev = NULL;
    int i = 0;
    for(node d = *head; d != NULL; d = d->next)
    {
        if(i == index)
        {
            if(d == *head)
            {
                n->next = *head;
                *head = n;  
            } 
            else
            {
                n->next = d;
                prev->next = n;
            }
        }
        i++;
        prev = d;
    }
}

void list_delete_index(node *head, int index)
{
    node prev = NULL;
    
    int i = 0;
    for(node d = *head; d != NULL; d = d->next)
    {
        if(i == index)
        {
            if(d == *head)
            {
                node temp;
                temp = *head;
                *head = (*head)->next;
                free(temp);                
            } 
            else
            {
                prev->next = d->next;
                free(d);
            }
            return;
        }
        i++;
        prev = d;
    }
}

void list_clear(node *head)
{
    while(*head != NULL)
    {
        node temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

struct address *list_search_index(node head, int index)
{
    if(index < 0 && index > list_size(head) - 1)
    {
        return NULL;
    }
    int i = 0;
    struct address *ptr = NULL;
    for(node d = head; d != NULL; d = d->next)
    {
        if(i == index)
        {
            ptr = &(d->entry);
            return ptr;
        }
        i ++;
    }
}

struct address* list_search_field(node head, char* field)
{
    struct address *ptr = NULL;
    node n = head;
    while(n != NULL)
    {
       
        if(strcmp(n->entry.name, field) == 0 ||strcmp(n->entry.surname, field) == 0
        || strcmp(n->entry.phone, field) == 0 || strcmp(n->entry.email, field) == 0)
        {
            ptr = &(n->entry);
            return ptr;
        }
        n = n->next;
    }
   
    return NULL;
}
int list_size(node head)
{
    int count = 0;
    for(node d = head; d != NULL; d = d->next)
    {
        count ++;
    }
    return count;
}

void print_list(node head)
{
    int i = 0;
    node n = head;
    while(n != NULL)
    {
        struct address ad = n->entry;
        printf("%d: %s %s %s %s\n",
            i, ad.name, ad.surname, ad.phone, ad.email);
        i ++; 
        n = n->next;
    }
    putc('\n', stdout);
}




