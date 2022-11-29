#include "data.h"
#include <stdlib.h>
#include <stdio.h>

//FUNCTION PROTOTYPES
node create_node(struct address entry);
int list_size(node head);
//-------------------
node create_node(struct address entry)
{
     node n = (node)malloc(sizeof(struct Node));
     n->next = NULL;
     n->entry = entry;
     return n;
}

void add(node *head, struct address entry)
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
void insert(node *head, struct address entry, int index)
{
    int size = list_size(*head);
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
            else if(d->next== NULL)
            {
                add(head, entry);
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

void delete_index(node *head, int index)
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

void delete_list(node *head)
{
    while(*head != NULL)
    {
        node temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

struct address search_index(node head, int index)
{
    int i = 0;
    struct address *ptr = NULL;
    for(node d = head; d != NULL; d = d->next)
    {
        if(i == index)
        {
            return d->entry;
        }
        i ++;
    }
    return *ptr;
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
    for(node d = head; d != NULL; d = d->next)
    {
        struct address ad = d->entry;
        printf("%d %s %s %s %s\n",
            i, ad.name, ad.surname, ad.phone, ad.email);
        i ++; 
    }
    putc('\n', stdout);
}




