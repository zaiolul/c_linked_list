#include "../includes/linkedlist.h"




node head;

node head_filled;

node arr[10];



void setUp(void)

{

    head = 

          ((void *)0)

              ;



    head_filled = malloc(sizeof(struct Node));

    head_filled->next = 

                       ((void *)0)

                           ;

    strncpy(head_filled->name, "0", 2);

    arr[0] = head_filled;

    char buf[1];

    for(int i = 1; i < 10; i ++){



        node last = head_filled;

        node n = malloc(sizeof(struct Node));

        n->next = 

                 ((void *)0)

                     ;

        buf[0]= i + '0';

        strncpy(n->name, buf, sizeof(buf));



        while (last->next != 

                            ((void *)0)

                                ) {

   last = last->next;

  }



        last->next = n;

        arr[i] = n;

    }

}



void tearDown(void)

{



}

void test_creates_new_node_input_correct_size()

{



    node n = create_node("a", "b", "c", "d");

    

   UnityAssertEqualString((const char*)((

   "a"

   )), (const char*)((

   n->name

   )), (((void *)0)), (UNITY_UINT)(45))

                                         ;

    

   UnityAssertEqualString((const char*)((

   "b"

   )), (const char*)((

   n->surname

   )), (((void *)0)), (UNITY_UINT)(46))

                                            ;

    

   UnityAssertEqualString((const char*)((

   "c"

   )), (const char*)((

   n->phone

   )), (((void *)0)), (UNITY_UINT)(47))

                                          ;

    

   UnityAssertEqualString((const char*)((

   "d"

   )), (const char*)((

   n->email

   )), (((void *)0)), (UNITY_UINT)(48))

                                          ;

    

   do { if ((((

   n->next

   )) == ((void *)0))) { } else { UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(49)))); } } while (0)

                            ;



}

void test_creates_new_node_input_incorrect_size()

{

    char buf[100];

    memset(buf, 'a', sizeof(buf));

    node n = create_node(buf, "b", "c", "d");

    

   UnityAssertEqualString((const char*)((

   buf

   )), (const char*)((

   n->name

   )), (((void *)0)), (UNITY_UINT)(69))

                                         ;

    

   UnityAssertEqualString((const char*)((

   "b"

   )), (const char*)((

   n->surname

   )), (((void *)0)), (UNITY_UINT)(70))

                                            ;

    

   UnityAssertEqualString((const char*)((

   "c"

   )), (const char*)((

   n->phone

   )), (((void *)0)), (UNITY_UINT)(71))

                                          ;

    

   UnityAssertEqualString((const char*)((

   "d"

   )), (const char*)((

   n->email

   )), (((void *)0)), (UNITY_UINT)(72))

                                          ;

    

   do { if ((((

   n->next

   )) == ((void *)0))) { } else { UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(73)))); } } while (0)

                            ;



}



void test_list_add_change_head_if_null()

{

    node n = malloc(sizeof(struct Node));

    list_add(&head, n);

    

   UnityAssertEqualNumber((UNITY_INT64)((

   head

   )), (UNITY_INT64)((

   n

   )), (((void *)0)), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_HEX64)

                                 ;

    free(n);

}

void test_list_add_to_end()

{

    node first = malloc(sizeof(struct Node));

    first->next = 

                 ((void *)0)

                     ;

    node second = malloc(sizeof(struct Node));

    second->next = 

                  ((void *)0)

                      ;



    list_add(&head, first);

    list_add(&head, second);

    

   do { if ((((

   head

   )) != ((void *)0))) { } else { UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(93)))); } } while (0)

                             ;

    

   do { if ((((

   head->next

   )) != ((void *)0))) { } else { UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(94)))); } } while (0)

                                   ;

    

   UnityAssertEqualNumber((UNITY_INT64)((

   second

   )), (UNITY_INT64)((

   head->next

   )), (((void *)0)), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_HEX64)

                                            ;



}



void test_head_null_after_clear()

{



    list_clear(&head_filled);

    

   do { if ((((

   head_filled

   )) == ((void *)0))) { } else { UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(103)))); } } while (0)

                                ;



}



void test_delete_index_head_moves_pointer()

{

    node first = malloc(sizeof(struct Node));

    first->next = 

                 ((void *)0)

                     ;

    node second = malloc(sizeof(struct Node));

    second->next = 

                  ((void *)0)

                      ;

    list_add(&head, first);

    list_add(&head, second);



    list_delete_index(&head, 0);

    

   UnityAssertEqualNumber((UNITY_INT64)((

   head

   )), (UNITY_INT64)((

   second

   )), (((void *)0)), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_HEX64)

                                      ;

}



void test_delete_index_middle_change_pointers()

{

    node first = malloc(sizeof(struct Node));

    first->next = 

                 ((void *)0)

                     ;



    node prev = malloc(sizeof(struct Node));

    prev->next = 

                ((void *)0)

                    ;



    node to_delete = malloc(sizeof(struct Node));

    to_delete->next = 

                     ((void *)0)

                         ;



    node next = malloc(sizeof(struct Node));

    next->next = 

                ((void *)0)

                    ;



    list_add(&head, first);

    list_add(&head, prev);

    list_add(&head, to_delete);

    list_add(&head, next);



    list_delete_index(&head, 2);

    

   UnityAssertEqualNumber((UNITY_INT64)((

   prev->next

   )), (UNITY_INT64)((

   next

   )), (((void *)0)), (UNITY_UINT)(140), UNITY_DISPLAY_STYLE_HEX64)

                                          ;



    list_delete_index(&head, 2);

    

   UnityAssertEqualNumber((UNITY_INT64)((

   prev->next

   )), (UNITY_INT64)((((void *)0))), (((void *)0)), (UNITY_UINT)(143), UNITY_DISPLAY_STYLE_HEX64)

                                          ;



    free(first);

    free(prev);



}



void test_list_size_correct()

{

    int size = list_size(head);

    

   UnityAssertEqualNumber((UNITY_INT)((

   0

   )), (UNITY_INT)((

   size

   )), (((void *)0)), (UNITY_UINT)(153), UNITY_DISPLAY_STYLE_INT)

                                 ;



    node first = malloc(sizeof(struct Node));

    first->next = 

                 ((void *)0)

                     ;

    node second = malloc(sizeof(struct Node));

    second->next = 

                  ((void *)0)

                      ;



    head = first;

    first->next = second;



    size = list_size(head);

    

   UnityAssertEqualNumber((UNITY_INT)((

   2

   )), (UNITY_INT)((

   size

   )), (((void *)0)), (UNITY_UINT)(164), UNITY_DISPLAY_STYLE_INT)

                                 ;



    free(first);

    free(second);

}



void test_list_search_index_node_any_index()

{

    node first = list_search_index(head_filled,0);

    node mid = list_search_index(head_filled, 5);

    node last = list_search_index(head_filled, 999);

    

   UnityAssertEqualNumber((UNITY_INT64)((

   arr[0]

   )), (UNITY_INT64)((

   first

   )), (((void *)0)), (UNITY_UINT)(175), UNITY_DISPLAY_STYLE_HEX64)

                                       ;

    

   UnityAssertEqualNumber((UNITY_INT64)((

   arr[5]

   )), (UNITY_INT64)((

   mid

   )), (((void *)0)), (UNITY_UINT)(176), UNITY_DISPLAY_STYLE_HEX64)

                                     ;

    

   UnityAssertEqualNumber((UNITY_INT64)((((void *)0))), (UNITY_INT64)((

   last

   )), (((void *)0)), (UNITY_UINT)(177), UNITY_DISPLAY_STYLE_HEX64)

                                    ;

}



void test_list_search_index_empty_list()

{

    node a = list_search_index(head,0);

    node b = list_search_index(head,100);

    

   UnityAssertEqualNumber((UNITY_INT64)((((void *)0))), (UNITY_INT64)((

   a

   )), (((void *)0)), (UNITY_UINT)(184), UNITY_DISPLAY_STYLE_HEX64)

                                  ;

    

   UnityAssertEqualNumber((UNITY_INT64)((((void *)0))), (UNITY_INT64)((

   b

   )), (((void *)0)), (UNITY_UINT)(185), UNITY_DISPLAY_STYLE_HEX64)

                                  ;

}

void test_list_search_field_finds_nodes()

{

    node found[2] = {0};



    strncpy(head_filled->name, "5", 2);

    

   UnityAssertGreaterOrLessOrEqualNumber((UNITY_INT) ((

   1

   )), (UNITY_INT) ((

   list_search_field(&found, head_filled, "5")

   )), UNITY_GREATER_OR_EQUAL, (((void *)0)), (UNITY_UINT)(192), UNITY_DISPLAY_STYLE_INT)

                                                                              ;

    

   UnityAssertEqualNumber((UNITY_INT64)((

   found[0]

   )), (UNITY_INT64)((

   arr[0]

   )), (((void *)0)), (UNITY_UINT)(193), UNITY_DISPLAY_STYLE_HEX64)

                                          ;

    

   UnityAssertEqualNumber((UNITY_INT64)((

   found[1]

   )), (UNITY_INT64)((

   arr[5]

   )), (((void *)0)), (UNITY_UINT)(194), UNITY_DISPLAY_STYLE_HEX64)

                                          ;

}



void test_list_search_field_list_empty_do_nothing()

{

    node found[1] = {0};

    

   UnityAssertGreaterOrLessOrEqualNumber((UNITY_INT) ((

   -1

   )), (UNITY_INT) ((

   list_search_field(&found, head, "test value")

   )), UNITY_GREATER_OR_EQUAL, (((void *)0)), (UNITY_UINT)(200), UNITY_DISPLAY_STYLE_INT)

                                                                                 ;

    

   UnityAssertEqualNumber((UNITY_INT64)((((void *)0))), (UNITY_INT64)((

   found[0]

   )), (((void *)0)), (UNITY_UINT)(201), UNITY_DISPLAY_STYLE_HEX64)

                                        ;

}

void test_list_insert_index_end_place_before_last()

{

    node n = malloc(sizeof (struct Node));

    n->next = 

             ((void *)0)

                 ;

    list_insert(&head_filled, n, 9);

    node b_last = head_filled;



    while(b_last->next->next != 

                               ((void *)0)

                                   ){

        b_last = b_last->next;

    }



    

   UnityAssertEqualNumber((UNITY_INT64)((

   b_last

   )), (UNITY_INT64)((

   n

   )), (((void *)0)), (UNITY_UINT)(214), UNITY_DISPLAY_STYLE_HEX64)

                                   ;

}



void test_list_insert_index_invalid_index_do_nothing()

{

    node n = malloc(sizeof (struct Node));

    n->next = 

             ((void *)0)

                 ;

    list_insert(&head_filled, n, 999);

    node b_last = head_filled;



    int i = 0;

    int flag = 0;

    while(head_filled){

        if(head_filled != arr[i]){

            flag = 1;

            break;

        }

        i++;

        head_filled = head_filled->next;

    }

    

   do { if (!(

   flag

   )) { } else { UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(234))); } } while (0)

                          ;

}



void test_list_search_index_gets_node()

{

    node a = list_search_index(head_filled, 5);

    node b = list_search_index(head_filled, 999);

    

   UnityAssertEqualNumber((UNITY_INT64)((

   arr[5]

   )), (UNITY_INT64)((

   a

   )), (((void *)0)), (UNITY_UINT)(241), UNITY_DISPLAY_STYLE_HEX64)

                                   ;

    

   UnityAssertEqualNumber((UNITY_INT64)((((void *)0))), (UNITY_INT64)((

   b

   )), (((void *)0)), (UNITY_UINT)(242), UNITY_DISPLAY_STYLE_HEX64)

                                 ;

}
