#include <stdlib.h>
#include <stdio.h>
#include "includes/linkedlist.h"
#include "includes/utils.h"
void load_start_entries(node* head);


int main()
{
    node head = NULL;
    load_start_entries(&head);

    int opt; //current chosen option
    int index; //index of found entry 
    char *line; // input line
    struct address *found; //found entry 
    struct address ad; // new entry to add/insert
    int size; //address size
    int status; //var for function return result
    int run = 1;
    printf("---------Pradžia---------\n");

    do
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
    
        opt = get_input_number(NULL,0, 7);       
        size = list_size(head);

        switch(opt)
        {
            case 0:
                printf("--------Darbas baigtas--------\n");
                run = 0;
                break;

            case 1:
                line = get_input_line("Įvesti adreso duomenis (formatas: [vardas] [pavardė] [tel. nr] [paštas])\n", 100);
                ad;

                status = create_entry(line, &ad);
                if(status < 0)
                {
                    break;
                }
                
                list_add(&head, ad);
                free(line);
                printf("Adresas pridėtas.\n");

                break;

            case 2:
                index = get_input_number("Įterpimo vieta:", 0, list_size(head) - 1);
                if(index == -1)
                {
                    continue;
                }
                line = get_input_line("Įvesti adreso duomenis (formatas: [vardas] [pavardė] [tel. nr] [paštas])\n", 100);

                
                status = create_entry(line, &ad);

                if(status < 0)
                {
                    break;
                }

                list_insert(&head, ad, index);
                printf("Adresas įterptas.");
                free(line);
                break;

            case 3:

                index = get_input_number("Įvesti ieškomo adreso vietą:", 0, list_size(head) - 1);
                if(index == -1)
                {
                    continue;
                }

                found = list_search_index(head, index);
                printf("%d-oje vietoje esantis įrašas:\n \"%s %s %s %s\"\n", index, found->name, found->surname, found->phone, found->email);

                break;                 

            case 4:
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

            case 5:
                if(size == 0)
                {
                    printf("Sąrašas tuščias.\n");
                }
                else
                {
                    printf("Visas sąrašas:\n");
                    print_list(head);
                }
                break;
            
            case 6:
                
                if(size == 0)
                {
                    printf("Sąrašas tuščias");
                    continue;
                }
                index = get_input_number("Įvesti norimo ištrinti adreso vietą", 0, size - 1);
                if(index == -1)
                {
                    continue;
                }

                list_delete_index(&head, index);
                printf("Elementas sėkmingai ištrintas.\n");

                break;

            case 7:
                if(size == 0)
                {
                    printf("Sąrašas tuščias");
                    continue;
                }
                list_clear(&head);
                printf("Sąrašas sėkmingai išvalytas.\n");

                break;
        }
        fflush(stdout);
    }
    while(run);
    list_clear(&head);
    free(head);
   
    return 0;
}
/*Fill up address book with 10 entries. Just filler data.*/
void load_start_entries(node* head)
{
  
   
    for(int i = 0; i < 10; i ++)
    {
        char* name = (char*) malloc(sizeof(char)*10);
        char* surname = (char*) malloc(sizeof(char)*10);
        char* phone = (char*) malloc(sizeof(char)*10);
        char* email = (char*) malloc(sizeof(char)*10);

        strcpy(name, "Varx");
        strcpy(surname, "Pavx");
        strcpy(phone, "86x");
        strcpy(email, "mail@x");

        name[3] = i + '0';
        surname[3] = i + '0';
        phone[2] = i + '0';
        email[5] = i + '0';
        struct address ad = 
        {
            ad.name = name,
            ad.surname = surname,
            ad.phone = phone,
            ad.email = email
        };
        list_add(head, ad);
    }
}
