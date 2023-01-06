#include <stdio.h>
#include <stdlib.h>
#include "includes/linkedlist.h"


/*Checks if STR contains only integer characters*/
int check_number(char* str)
{
    char* temp = str;
    while(*temp != '\0')
    {
        if(*temp > 57 || *temp < 48 )
        {
            return -1;
        }
        temp++;
    }
    return 0;
}

/*Remove all endline characters from STR*/
void remove_endline(char** str, int n)
{
    for(int i = n - 1; i > 0; i --)
    {
        char x = (*str)[i];
        if((*str)[i] == '\n')
        {
            
            (*str)[i] = '\0';
        }
    }
}

/*Gets input of length LEN frothe number value of itm stdin, prints TEXT to stdout*/
char *get_input_line(char* text, int len)
{
    if(text != NULL)
    {
        printf("%s \n", text);
    }
    printf("> ");

    size_t size = len;
    char *line = (char* )malloc(sizeof(char*) * len);
    int charCount = getdelim(&line, &size, '\n', stdin);

    if(charCount < 0)
    {
        printf("Skaitymo klaida");
        return NULL;
    }
    
    remove_endline(&line, charCount);
    return line;
}

/*Gets input from stdin and transforms it to a number, prints TEXT to stdout*/
int get_input_number(char* text, int rangeMin, int rangeMax)
{
    if(text != NULL)
    {
        printf("%s [%d-%d]:\n", text,rangeMin, rangeMax);
    }
    
    char *line = get_input_line(NULL,100);
    
    int check = check_number(line) ;
    int index = atoi(line);
    free(line);
    if(check < 0 || index < 0 || index > rangeMax)
    {
        printf("Bloga įvestis: galimi tik skaičiai intervale [%d-%d]\n", rangeMin, rangeMax);
        return -1;
    }
    
    return index;
}
/*Inserts data to ENTRY from INPUT*/
int create_entry(char* input, node* entry)
{
    int c = 0;
    int failed = 0;
    char parts[4][50];

    char* part = strtok(input, " ");
    while(part != NULL)
    {   
        if(c > 3)
        {
            failed = 1;
            break;
        } 
        strncpy(parts[c], part, 50);
        part = strtok(NULL," ");
        c++;
        
    }
    
    if(c != 4 || failed)
    {
    
        printf("Netinkamas duomenų formatas (formatas: [vardas] [pavardė] [tel. nr] [paštas])\n");
        return -1;
    
    }
    node n = create_node(parts[0], parts[1], parts[2], parts[3]);

    *entry = create_node(parts[0], parts[1], parts[2], parts[3]);

    
    return 0;
}
/*Prints program usage*/
void print_usage()
{
    printf("\n----------------------------\n");
    printf("1: Įvesti adresą\n");
    printf("2: Įterpti adresą\n");
    printf("3: Ieškoti pagal vietą\n"); 
    printf("4: Ieškoti pagal lauką (vardas, pavardė, tel. nr arba paštas)\n");
    printf("5: Spausdinti visą adresyną\n");
    printf("6: Ištrinti adresą\n");
    printf("7: Ištrinti visą adresyną\n");
    printf("0: Baigti darbą\n");
    printf("----------------------------\n");
}
/*Adds entry*/
void add(node* head)
{
    char *line = get_input_line("Įvesti adreso duomenis (formatas: [vardas] [pavardė] [tel. nr] [paštas])\n", 100);
    node n;
    int status = create_entry(line, &n);
    if(status < 0)
    {
        return;
    }
    
    list_add(head, n);
    free(line);
    printf("Adresas pridėtas.\n");

}
/*Adds entry by pos*/
void add_pos(node* head)
{
    int index = get_input_number("Įterpimo vieta:", 0, list_size(*head) - 1);
    if(index == -1)
    {
        return;
    }
    char* line = get_input_line("Įvesti adreso duomenis (formatas: [vardas] [pavardė] [tel. nr] [paštas])\n", 100);

    node n;
    int status = create_entry(line, &n);

    if(status < 0)
    {
        return;
    }

    list_insert(head, n, index);
    printf("Adresas įterptas.");
    free(line);
}
/*Gets entry by pos*/
void get_pos(node head)
{
    int index = get_input_number("Įvesti ieškomo adreso vietą:", 0, list_size(head) - 1);
    if(index == -1)
    {
        return;
    }

    node found = list_search_index(head, index);
    printf("%d-oje vietoje esantis įrašas:\n \"%s %s %s %s\"\n", index, found->name, found->surname, found->phone, found->email);
}
/*Gets entry by field*/
void get_field(node head)
{
    char* line = get_input_line("Lauko reikšme (vardas, pavardė, telefonas arba paštas):", 100);
    node found = list_search_field(head, line);
    if(found != NULL)
    {
        printf("Rastas įrašas:\n \"%s %s %s %s\"\n", found->name, found->surname, found->phone, found->email);
    }
    else
    {
        printf("Įrašas nerastas.\n");
    }
    free(line);
                
}
/*Prints the list*/
void print_all(node head)
{
    if(list_size(head) == 0)
    {
        printf("Sąrašas tuščias.\n");
    }
    else
    {
        printf("Visas sąrašas:\n");
        print_list(head);
    }
}
/*Deletes entry at position*/
void delete_pos(node* head)
{
    int size = list_size(*head);
    if(size == 0)
    {
        printf("Sąrašas tuščias");
        return;
    }
    int index = get_input_number("Įvesti norimo ištrinti adreso vietą", 0, size - 1);
    if(index == -1)
    {
        return;
    }

    list_delete_index(head, index);
    printf("Elementas sėkmingai ištrintas.\n");
}
/*Clears list*/
void delete_all(node* head)
{
    if(list_size(*head) == 0)
    {
        printf("Sąrašas tuščias");
        return;
    }
    list_clear(head);
    printf("Sąrašas sėkmingai išvalytas.\n");

}
/*Fill up address book with 10 entries. Just filler data.*/
void load_start_entries(node* head)
{
    for(int i = 0; i < 10; i ++)
    {
        char name[30];
        char surname[30];
        char phone[30];
        char email[50];

        strcpy(name, "Varx");
        strcpy(surname, "Pavx");
        strcpy(phone, "86x");
        strcpy(email, "mail@x");

        name[3] = i + '0';
        surname[3] = i + '0';
        phone[2] = i + '0';
        email[5] = i + '0';
        node n = create_node(name, surname, phone, email);
        list_add(head, n);
    }
}