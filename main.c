#include <stdlib.h>
#include <stdio.h>
#include "includes/linkedlist.h"
int get_input_number(char* text,int rangeMin, int rangeMax);
void remove_endline(char** str, int n);
char *get_input_line(char* text, int len);

int main()
{
    char* names[] = {"ezglasbcxb",
                    "wkpbhioemx",
                    "pnfoaichrj",
                    "twzcdvaxgc",
                    "btteeughrs",
                    "rkgcgbsoag",
                    "yfbvjaoxat",
                    "jbpcuksyjj",
                    "fzogbodtbi",
                    "vlivrfueko"};
    char* surnames[] = {"ezglasbcxb",
                    "wkpbhioemx",
                    "pnfoaichrj",
                    "twzcdvaxgc",
                    "btteeughrs",
                    "rkgcgbsoag",
                    "yfbvjaoxat",
                    "jbpcuksyjj",
                    "fzogbodtbi",
                    "vlivrfueko"};
    char* phones[] = {"564877830",
                    "755581126",
                    "531614666",
                    "814173637",
                    "892200388",
                    "547572403",
                    "813277950",
                    "116455191",
                    "113166087",
                    "029384632"};
    char* emails[] = {"@564877830",
                    "@755581126",
                    "@531614666",
                    "@814173637",
                    "@892200388",
                    "@547572403",
                    "@813277950",
                    "@116455191",
                    "@113166087",
                    "@029384632"};
    node head = NULL;
    int n = 2;

    for(int i = 0; i < n; i ++)
    {
        struct address a;
        a.name = names[i];
    
        a.surname = surnames[i];
        //sprintf(a.surname, "%d", i);
        a.phone = phones[i];
        //sprintf(a.phone, "%d", i);
        a.email = emails[i];
        //sprintf(a.email, "%d", i);
    
        list_add(&head,a);
    }  
   
   

  
    int opt;
    int index;
    char *line;
    struct address *found;

    int run = 1;

    printf("Pradzia\n");
    do
    {
        
        printf("\n----------------------------\n");
        printf("1: ivesti adresa\n");
        printf("2: ieskoti pagal vieta\n"); 
        printf("3: ieskoti pagal lauka (vardas, pavarde, tel. nr arba pastas)\n");
        printf("4: spausdinti visa adresyna\n");
        printf("5: istrinti adresa\n");
        printf("6: istrinti visa adresyna\n");
        printf("0: baigti\n");
        printf("----------------------------\n");
        
    
        opt = get_input_number(NULL,0, 7);       
        
        switch(opt)
        {
            case 0:
                printf("Darbas baigtas\n");
                run = 0;
                break;

            case 1:
                char *line = get_input_line("Ivesti adreso duomenis (formatas: [vardas] [pavarde] [tel. nr] [pastas])\n", 100);
                char* words = strtok(line, " ");

                int c = 0;
                char *parts[4];
                
                int failed = 0; //for while below
                while(words != NULL)
                {    
                    parts[c] = words;
                    words = strtok(NULL," ");
                    c++;
                    if(c > 4)
                    {
                        printf("Netinkamas duomenu formatas (Vardas Pavarde Telefonas Pastas)\n");
                        failed = 1;
                        break;
                    }
                }
                
                if(failed == 1)
                {
                    continue;
                }
                struct address ad;
                
                ad.name = parts[0];
                ad.surname = parts[1];
                ad.phone = parts[2];
                ad.email = parts[3];
            
                //printf("Ivestas: %s %s %s %s\n", ad.name, ad.surname, ad.phone, ad.email);
                list_add(&head, ad);
                
                
                break;
                
            case 2:

                index = get_input_number("Ivesti ieskomo adreso vieta", 0, list_size(head) - 1);
                if(index == -1)
                {
                    continue;
                }
                struct address *found = list_search_index(head, index);
             
                
                printf("%d-oje vietoje esantis irasas:\n \"%s %s %s %s\"\n", index, found->name, found->surname, found->phone, found->email);
                break;                 

            case 3:
                line = get_input_line("Lauko reiksme (vardas, pavarde, telefonas arba pastas):", 100);
                found = list_search_field(head, line);
                if(found != NULL)
                {
                    printf("Rastas irasas:\n \"%s %s %s %s\"\n", index, found->name, found->surname, found->phone, found->email);
                }
                else
                {
                    printf("Irasas nerastas.\n");
                }
                
                break;

            case 4:
                if(list_size(head) == 0)
                {
                    printf("Sarasas tuscias.\n");
                }
                else
                {
                    printf("Visas sarasas:\n");
                    print_list(head);
                }
                break;
            
            case 5:
                index = get_input_number("Ivesti norimo istrinti adreso vieta", 0, list_size(head) - 1);
                if(index == -1)
                {
                    continue;
                }

                list_delete_index(&head, index);
                printf("Elementas sekmingai istrintas.\n");
                break;

            case 6:
                list_clear(&head);
                printf("Sarasas sekmingai isvalytas.\n");
                break;
        }   
        fflush(stdout);
    }
    while(run);
    return 0;
}

void remove_endline(char** str, int n)
{
    for(int i = n - 1; i > 0; i --)
    {
        char x = (*str)[i];
        if((*str)[i] == '\n')
        {
            
            (*str)[i] = ' ';
        }
    }
}

int get_input_number(char* text,int rangeMin, int rangeMax)
{
    if(text != NULL)
    {
        printf("%s [%d-%d]:\n", text,rangeMin, rangeMax);
    }

    char *line = get_input_line(text,1);

    int index = atoi(line);
    free(line);
    if(index < 0 || index > rangeMax)
    {
        printf("Bloga ivestis: galimi tik skaiciai intervale [%d-%d]\n", rangeMin, rangeMax);
        return -1;
    }
   
    
    return index;
}
char *get_input_line(char* text, int len)
{
    if(text != NULL)
    {
        printf("%s \n", text);
    }
    printf("> ");
    char *line = (char* )malloc(sizeof(char*) * len);
    int charCount = getdelim(&line, &len, '\n', stdin);
    remove_endline(&line, charCount);
    return line;
}