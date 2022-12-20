#include <stdlib.h>
#include <stdio.h>
#include "includes/linkedlist.h"
#include "includes/utils.h"

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
                    "abc"};
    char* surnames[] = {"ezglasbcxb",
                    "wkpbhioemx",
                    "pnfoaichrj",
                    "twzcdvaxgc",
                    "btteeughrs",
                    "rkgcgbsoag",
                    "yfbvjaoxat",
                    "jbpcuksyjj",
                    "fzogbodtbi",
                    "def"};
    char* phones[] = {"564877830",
                    "755581126",
                    "531614666",
                    "814173637",
                    "892200388",
                    "547572403",
                    "813277950",
                    "116455191",
                    "113166087",
                    "123"};
    char* emails[] = {"@564877830",
                    "@755581126",
                    "@531614666",
                    "@814173637",
                    "@892200388",
                    "@547572403",
                    "@813277950",
                    "@116455191",
                    "@113166087",
                    "@email"};
    node head = NULL;
    int n = 10;

    for(int i = 0; i < n; i ++)
    {
        struct address a;
        a.name = names[i];
        a.surname = surnames[i];
        a.phone = phones[i];
        a.email = emails[i];
        list_add(&head,a);
    }  
   
    int opt;
    int index;
    char *line;
    struct address *found;

    int run = 1;

    printf("---------Pradžia---------\n");

    do
    {
        
        printf("\n----------------------------\n");
        printf("1: Įvesti adresą\n");
        printf("2: Ieškoti pagal vietą\n"); 
        printf("3: Ieškoti pagal lauką (vardas, pavardė, tel. nr arba paštas)\n");
        printf("4: Spausdinti visą adresyną\n");
        printf("5: ištrinti adresą\n");
        printf("6: ištrinti visą adresyną\n");
        printf("0: Baigti darbą\n");
        printf("----------------------------\n");
    
        opt = get_input_number(NULL,0, 7);       
        
        switch(opt)
        {
            case 0:
                printf("--------Darbas baigtas--------\n");
                run = 0;
                break;

            case 1:
                char *line = get_input_line("Įvesti adreso duomenis (formatas: [vardas] [pavardė] [tel. nr] [paštas])\n", 100);
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
                    printf("Netinkamas duomenų formatas (formatas: [vardas] [pavardė] [tel. nr] [paštas])\n");
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

                index = get_input_number("Įvesti ieškomo adreso vietą", 0, list_size(head) - 1);
                if(index == -1)
                {
                    continue;
                }

                found = list_search_index(head, index);
                printf("%d-oje vietoje esantis įrašas:\n \"%s %s %s %s\"\n", index, found->name, found->surname, found->phone, found->email);

                break;                 

            case 3:
                line = get_input_line("Lauko reikšme (vardas, pavardė, telefonas arba paštas):", 100);
                found = list_search_field(head, line);
                if(found != NULL)
                {
                    printf("Rastas įrašas:\n \"%s %s %s %s\"\n", found->name, found->surname, found->phone, found->email);
                }
                else
                {
                    printf("Įrašas nerastas.\n");
                }
                free(line);
                
                break;

            case 4:
                if(list_size(head) == 0)
                {
                    printf("Sąrašas tuščias.\n");
                }
                else
                {
                    printf("Visas sąrašas:\n");
                    print_list(head);
                }
                break;
            
            case 5:
                index = get_input_number("Įvesti norimo ištrinti adreso vietą", 0, list_size(head) - 1);
                if(index == -1)
                {
                    continue;
                }

                list_delete_index(&head, index);
                printf("Elementas sėkmingai ištrintas.\n");

                break;

            case 6:
                list_clear(&head);
                printf("Sąrašas sėkmingai išvalytas.\n");

                break;
        }   
        fflush(stdout);
    }
    while(run);
    return 0;
}
