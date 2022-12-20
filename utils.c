#include <stdio.h>
#include <stdlib.h>
#include "includes/data.h"

/*Checks if STR contains only integer characters*/
int check_number(const char* str)
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
void remove_endline(char** str, const int n)
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
char *get_input_line(const char* text, const int len)
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
int get_input_number(const char* text,const int rangeMin,const int rangeMax)
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
int create_entry(char* input, struct address *entry)
{
    int c = 0;
    char *parts[4];
    for(int i = 0; i < 4; i ++)
    {
        parts[i] = (char*) malloc(sizeof(char*) * 30);
    }

    char* part = strtok(input, " ");
    while(part != NULL)
    {    
        strcpy(parts[c], part);
        part = strtok(NULL," ");
        c++;
    }
    if(c != 4)
    {
        printf("Netinkamas duomenų formatas (formatas: [vardas] [pavardė] [tel. nr] [paštas])\n");
        for(int i = 0; i < 4; i ++)
        {
            free(parts[i]);
        }
        return -1;
    }
    entry->name = parts[0];
    entry->surname = parts[1];
    entry->phone = parts[2];
    entry->email = parts[3];
    
    return 0;
}