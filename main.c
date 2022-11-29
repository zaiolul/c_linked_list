#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "includes/linkedlist.h"

void remove_endline(char** str, int n)
{
    for(int i = n - 1; i > 0; i --)
    {
        char x = str[i];
        if((*str)[i] == '\n')
        {
            
            (*str)[i] = ' ';
        }
    }
}

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
   
   

    int len = 100;
    int charCount;
    int opt;
    char *line;

    printf("Pradzia\n");
    do
    {
        
        printf("\n1: ivesti adresa\n");
        printf("2: istrinti adresa\n");
        printf("3: ieskoti pagal vieta\n");
        printf("4: spausdinti visa adresa\n");
        printf("9: baigti\n");
    
        line = (char* )malloc(sizeof(char*) * len);
        charCount = getline(&line, &len, stdin);
        remove_endline(&line, charCount);

        printf("INPUT(%d): %s \n", charCount - 1, line);
        
        if(charCount - 1 > 1 || (line[0] - '0') == 0)
        {
            printf("Netinkamas pasirinkimas: tik 1 skaiciaus simbolis\n");
            continue;
        }
        opt = line[0] - '0';
       
        printf("OPT: %d\n", opt);
        switch(opt)
        {
            case 9:
                printf("Darbas baigtas\n");
                return 0;

            case 1:
                printf("Ivesti adreso duomenis (formatas: [vardas] [pavarde] [tel. nr] [pastas])\n");

                line = (char* )malloc(sizeof(char*) * len);
                charCount = getdelim(&line, &len, '\n', stdin);
                remove_endline(&line, charCount);
                puts(line);
                char* words = strtok(line, " ");

                int c = 0;
                char *parts[4];
               
                while(words != NULL)
                {
                      
                    parts[c] = words;
                    words = strtok(NULL," ");
                    c++;
                    if(c > 4)
                    {
                        printf("Netinkamas duomenu formatas (Vardas Pavarde Telefonas Pastas)\n");
                        continue;
                    }
                    
                }
                struct address ad;
                
                ad.name = parts[0];
                ad.surname = parts[1];
                ad.phone = parts[2];
                ad.email = parts[3];
            
                //printf("Ivestas: %s %s %s %s\n", ad.name, ad.surname, ad.phone, ad.email);
                list_add(&head, ad);
                
                
                break;
                
            case 3:
            int size = list_size(head);
                printf("Ivesti ieskomo adreso vieta (0-%d):\n", size);
                
                line = (char* )malloc(sizeof(char*) * len);

                charCount = getdelim(&line, &len, '\n', stdin);
               
                if(charCount - 1 > 1 || line[0] - '0' > size - 1)
                {
                    printf("Netinkamas pasirinkimas: tik 1  skaiciaus simbolis\n");
                    continue;
                }
                int index = line[0] - '0';
                struct address *found = list_search_index(head, index);
             
                fflush(stdout);
                printf("%d vietoje esantis irasas:\n \"%s %s %s %s\"\n", index, found->name, found->surname, found->phone, found->email);
                break;                 


            case 4:
                printf("Visas sarasas:\n");
                print_list(head);
               
        }   
        
    }
    while(1);
    return 0;
}