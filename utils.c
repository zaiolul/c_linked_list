#include <stdio.h>
#include <stdlib.h>

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

int get_input_number(char* text,int rangeMin, int rangeMax)
{
    if(text != NULL)
    {
        printf("%s [%d-%d]:\n", text,rangeMin, rangeMax);
    }
    
    char *line = get_input_line(text,100);
    
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