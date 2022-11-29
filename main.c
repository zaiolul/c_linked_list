#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

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
    int n = 10;
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
    
        add(&head,a);
    }
   
    // struct address test;
    // test.name = "test";
    // test.surname = "test";
    // test.phone = "test";
    // test.email= "test";

    // print_list(head);
    // insert(&head, test, 0);
    // insert(&head, test, 10);
    // insert(&head, test, 5);
    // putc('\n', stdout);
    // print_list(head);

    // delete_index(&head, 0);
    // delete_index(&head, list_size(head) - 1);
    // delete_index(&head, 4);
    // print_list(head);

    // //delete_list(&head);
    // print_list(head);
    // printf("%d\n", list_size(head));

    // struct address found = search_index(head, 3);
    // printf("%s %s %s %s\n", found.name, found.surname, found.phone, found.email  );
    // printf("Done");
    int opt;
    char *line = NULL;
    int len = 0;
    printf("Pradzia");
    while(opt != 0)
    {
        printf("1: ivesti adresa");
        printf("2: istrinti adresa");
        printf("3: ieskoti pagal vieta");
        printf("0: baigti");

        
    }
    return 0;
}