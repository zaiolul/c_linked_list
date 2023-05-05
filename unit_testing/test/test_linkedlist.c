#include <unity/unity.h>

#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

node head;
node head_filled;
node arr[10]; //linked list element array representation
char buf[1024];

void setUp(void)
{
    setbuf(stdout, buf);
    head = NULL;
    
    head_filled = malloc(sizeof(struct Node));
    head_filled->next = NULL;
    strncpy(head_filled->name, "0", 2);
    arr[0] = head_filled;
    char buf[1];
    for(int i = 1; i < 10; i ++){
        
        node last = head_filled;
        node n = malloc(sizeof(struct Node));
        n->next = NULL;
        buf[0]= i + '0';
        strncpy(n->name, buf, sizeof(buf));
        
        while (last->next != NULL) {
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
    TEST_ASSERT_EQUAL_STRING("a", n->name);
    TEST_ASSERT_EQUAL_STRING("b", n->surname);
    TEST_ASSERT_EQUAL_STRING("c", n->phone);
    TEST_ASSERT_EQUAL_STRING("d", n->email);
    TEST_ASSERT_NULL(n->next);
}
void test_creates_new_node_input_incorrect_size()
{
    char buf[100];
    memset(buf, 'a', sizeof(buf));
    node n = create_node(buf, "b", "c", "d"); 
    TEST_ASSERT_EQUAL_STRING(buf, n->name); //should fail here, as n->name size is 30
    TEST_ASSERT_EQUAL_STRING("b", n->surname);
    TEST_ASSERT_EQUAL_STRING("c", n->phone);
    TEST_ASSERT_EQUAL_STRING("d", n->email);
    TEST_ASSERT_NULL(n->next);
   
}

void test_list_add_change_head_if_null()
{
    node n = malloc(sizeof(struct Node));
    list_add(&head, n);
    TEST_ASSERT_EQUAL_PTR(head, n);
    
}
void test_list_add_to_end()
{
    node first = malloc(sizeof(struct Node));
    first->next = NULL;
    node second = malloc(sizeof(struct Node));
    second->next = NULL;

    list_add(&head, first);
    list_add(&head, second);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_NOT_NULL(head->next);
    TEST_ASSERT_EQUAL_PTR(second, head->next);

}

void test_head_null_after_clear()
{
       
    list_clear(&head_filled);
    TEST_ASSERT_NULL(head_filled);
    
}

void test_delete_index_head_moves_pointer()
{
    node first = malloc(sizeof(struct Node));
    first->next = NULL;
    node second = malloc(sizeof(struct Node));
    second->next = NULL;
    list_add(&head, first);
    list_add(&head, second);

    list_delete_index(&head, 0);
    TEST_ASSERT_EQUAL_PTR(head, second);  
}

void test_delete_index_middle_change_pointers()
{  
    node first = malloc(sizeof(struct Node));
    first->next = NULL;

    node prev = malloc(sizeof(struct Node));
    prev->next = NULL;

    node to_delete = malloc(sizeof(struct Node));
    to_delete->next = NULL;

    node next = malloc(sizeof(struct Node));
    next->next = NULL;

    list_add(&head, first);
    list_add(&head, prev);
    list_add(&head, to_delete); //index 2
    list_add(&head, next);

    list_delete_index(&head, 2);
    TEST_ASSERT_EQUAL_PTR(prev->next, next);

    list_delete_index(&head, 2); //now delete last
    TEST_ASSERT_EQUAL_PTR(prev->next, NULL);

    free(first);
    free(prev);
  
}

void test_list_size_correct()
{
    int size = list_size(head);
    TEST_ASSERT_EQUAL_INT(0, size);

    node first = malloc(sizeof(struct Node));
    first->next = NULL;
    node second = malloc(sizeof(struct Node));
    second->next = NULL;

    head = first;
    first->next = second;

    size = list_size(head);
    TEST_ASSERT_EQUAL_INT(2, size);

    free(first);
    free(second);
}

void test_list_search_index_node_any_index()
{
    node first = list_search_index(head_filled,0);
    node mid = list_search_index(head_filled, 5);
    node last = list_search_index(head_filled, 999);
    TEST_ASSERT_EQUAL_PTR(arr[0], first);
    TEST_ASSERT_EQUAL_PTR(arr[5], mid);
    TEST_ASSERT_EQUAL_PTR(NULL, last);
}

void test_list_search_index_empty_list()
{
    node a = list_search_index(head,0);
    node b = list_search_index(head,100);
    TEST_ASSERT_EQUAL_PTR(NULL , a);
    TEST_ASSERT_EQUAL_PTR(NULL , b);
}
void test_list_search_field_finds_nodes()
{
    node found[2] = {0};

    strncpy(head_filled->name, "5", 2); // change first node name field value to 5 so search function finds 2 entries
    TEST_ASSERT_GREATER_OR_EQUAL(1,list_search_field(&found, head_filled, "5"));
    TEST_ASSERT_EQUAL_PTR(found[0], arr[0]);
    TEST_ASSERT_EQUAL_PTR(found[1], arr[5]);
}

void test_list_search_field_list_empty_do_nothing()
{
    node found[1] = {0};
    TEST_ASSERT_GREATER_OR_EQUAL(-1,list_search_field(&found, head, "test value"));
    TEST_ASSERT_EQUAL_PTR(NULL, found[0]);
}
void test_list_insert_index_end_place_before_last()
{
    node n = malloc(sizeof (struct Node));
    n->next = NULL;
    list_insert(&head_filled, n, 9);
    node b_last = head_filled;

    while(b_last->next->next != NULL){
        b_last = b_last->next;
    }

    TEST_ASSERT_EQUAL_PTR(b_last, n);
}   

void test_list_insert_index_invalid_index_do_nothing()
{
    node n = malloc(sizeof (struct Node));
    n->next = NULL;
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
    TEST_ASSERT_FALSE(flag);
}

void test_list_search_index_gets_node()
{
    node a = list_search_index(head_filled, 5);
    node b = list_search_index(head_filled, 999);
    TEST_ASSERT_EQUAL_PTR(arr[5], a);
    TEST_ASSERT_EQUAL_PTR(NULL, b);
}


void test_print_list_correct_output()
{

    char *expected = "\0: a b c d\n1: 1 2 3 4\n\n";
    
    struct Node a = {
        .name = "a",
        .surname = "b",
        .phone = "c",
        .email = "d",
    };
    struct Node b = {
        .name = "1",
        .surname = "2",
        .phone = "3",
        .email = "4",
    };

    head = &a;
    a.next = &b;

    char real[sizeof(buf)];
    print_list(head);
    snprintf(real, strlen(expected), "%s", buf);
    TEST_ASSERT_EQUAL_STRING(expected, real);
}