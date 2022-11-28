#include <stdio.h>
#include <stdlib.h>

struct address
{
    char* name;
    char* surname;
    char* phone;
    char* email;
};

struct Node
{
    struct Node* next;
    struct address entry;
   // int index;
};
typedef struct Node *node;

//FUNCTION PROTOTYPES
node create_node(struct address entry);
int list_size(node head);
//-------------------

void add(node *head, struct address entry)
{
    node last = *head;
    node n = create_node(entry);
   
    if(*head == NULL)
    {
        *head = n;
        //n->index = 0;
    }
    else
    {
        while(last->next != NULL)
        {
            last = last->next;
        }
       // n->index = last->index + 1;
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
        prev = d;
        i++;
    }
}
node create_node(struct address entry)
{
     node n = (node)malloc(sizeof(struct Node));
     n->next = NULL;
     n->entry = entry;
     return n;
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
    node n = head;
    int i = 0;
    while(n != NULL)
    {
        struct address ad = n->entry;
        printf("%d %s %s %s %s\n",
            i, ad.name, ad.surname, ad.phone, ad.email);
        n = n->next;
        i ++; 
    }
}


int main()
{
    node head = NULL;
    int n = 10;
    for(int i = 0; i < n; i ++)
    {
        struct address a;
        a.name = "vardenis";
        a.surname = "pavardenis";
        a.phone = "86000";
        a.email = "varpavar@domain";
    
        add(&head,a);
    }
   
    struct address test;
    test.name = "test";
    test.surname = "test";
    test.phone = "test";
    test.email= "test";

    print_list(head);
    insert(&head, test, 0);
    insert(&head, test, 10);
    insert(&head, test, 5);
    putc('\n', stdout);
    print_list(head);
    printf("Done");
    return 0;
}

