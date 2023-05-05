
#include <unity/unity.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "mock_linkedlist.h"
#include "mock_io_utils.h"

char out_buf[1024];
char in_buf[1024];

char real_output[sizeof(out_buf)];

void setUp(void)
{
    setbuf(stdout, out_buf);  
   
}

void tearDown(void)
{
    
}

void test_create_entry_valid_input()
{
    create_node_ExpectAndReturn("a", "b", "c", "d", (node)0x111);
    node n;
    char str[] = "a b c d";
    int ret = create_entry(str, &n);

    TEST_ASSERT_EQUAL_INT(0, ret);
}

void test_create_entry_valid_input_node_fail()
{
    create_node_ExpectAndReturn("a", "b", "c", "d", NULL);
    node n;
    char str[] = "a b c d";
    int ret = create_entry(str, &n);

    TEST_ASSERT_EQUAL_INT(-1, ret);
}

void test_create_entry_invalid_input()
{
    node n;
    char str[] = "a b c";
    int ret = create_entry(str, &n);

    TEST_ASSERT_EQUAL_INT(-1, ret);
}

void test_get_input_number_valid_text()
{
    char *str = malloc(5);
    strcpy(str, "5");

    get_input_line_ExpectAndReturn(NULL, 100, str);
    check_number_ExpectAndReturn(str, 1);
    int ret = get_input_number("test", 1,10);

    TEST_ASSERT_EQUAL_INT(5, ret);
}

void test_get_input_number_valid_text_bad_range()
{
    char *str = malloc(5);
    strcpy(str, "5");

    get_input_line_ExpectAndReturn(NULL, 100, str);
    check_number_ExpectAndReturn(str, 1);
    int ret = get_input_number("test", 8,10);

    TEST_ASSERT_EQUAL_INT(-1, ret);
}

void test_get_input_number_invalid_text()
{
    char *str = malloc(10);
    strcpy(str, "5ab");

    get_input_line_ExpectAndReturn(NULL, 100, str);
    check_number_ExpectAndReturn(str, 0);
    int ret = get_input_number("test", 1,10);

    TEST_ASSERT_EQUAL_INT(-1, ret);
}

void test_add_valid_input()
{
    char real_output[sizeof(out_buf)];

    node head = NULL;
    char *str = malloc(20);
    strcpy(str, "a b c d");
    get_input_line_ExpectAndReturn("Įvesti adreso duomenis (formatas: [vardas] [pavardė] [tel. nr] [paštas])\n",
     100, str);

    node n = NULL;
    create_node_ExpectAndReturn("a", "b", "c", "d", n);
    list_add_Expect(&head, n);

    add(&head);

    // char *expected_output = "Adresas pridėtas.";
    // snprintf(real_output, strlen(expected_output) + 1, "%s", out_buf);
    // TEST_ASSERT_EQUAL_STRING(expected_output, real_output);

}

void test_add_invalid_input()
{
    node head = NULL;
    char *str = malloc(20);
    strcpy(str, "a b c");
    get_input_line_ExpectAndReturn("Įvesti adreso duomenis (formatas: [vardas] [pavardė] [tel. nr] [paštas])\n",
        100, str);

    struct Node n = {0};
    //returns before changing linked list
    add(&head);

    // char *expected_output = "Netinkamas duomenų formatas (formatas: [vardas] [pavardė] [tel. nr] [paštas])";
    // snprintf(real_output, strlen(expected_output) + 1, "%s", out_buf);
    // TEST_ASSERT_EQUAL_STRING(expected_output, real_output);
}

void test_add_pos_valid_input()
{
    node head = NULL;

    char *str = malloc(20);
    char *num = malloc(5);
    strcpy(str, "a b c d");
    strcpy(num, "0");

    
    check_number_ExpectAndReturn(num, 1);
    list_size_ExpectAndReturn(head, 1);
    get_input_line_ExpectAndReturn(NULL, 100, num);
     
    get_input_line_ExpectAndReturn("Įvesti adreso duomenis (formatas: [vardas] [pavardė] [tel. nr] [paštas])\n",
     100, str);

    node n = NULL;
    
    create_node_ExpectAndReturn("a", "b", "c", "d", n);
   
    list_insert_Expect(&head, n ,atoi(num));

    add_pos(&head);

    // char *expected_output = "Adresas įterptas.";
    // snprintf(real_output, strlen(expected_output) + 1, "%s", out_buf);
    // TEST_ASSERT_EQUAL_STRING(expected_output, real_output);
}

void test_add_pos_invalid_input_bad_entry()
{
    node head = NULL;

    char *str = malloc(20);
    char *num = malloc(5);
    strcpy(str, "a b"); // bad string
    strcpy(num, "0");

    check_number_ExpectAndReturn(num, 1);
    list_size_ExpectAndReturn(head, 1);
    get_input_line_ExpectAndReturn(NULL, 100, num);
     
    get_input_line_ExpectAndReturn("Įvesti adreso duomenis (formatas: [vardas] [pavardė] [tel. nr] [paštas])\n",
     100, str);
   
    add_pos(&head);

    // char *expected_output = "Netinkamas duomenų formatas (formatas: [vardas] [pavardė] [tel. nr] [paštas])";
    // snprintf(real_output, strlen(expected_output) + 1, "%s", out_buf);
    // TEST_ASSERT_EQUAL_STRING(expected_output, real_output);
}

void test_add_pos_invalid_input_bad_index()
{
    node n;
    node head = NULL;

    char *str = malloc(20);
    char *num = malloc(5);
    strcpy(str, "a b c d");
    strcpy(num, "999");
    
    list_size_ExpectAndReturn(head, 5);
    check_number_ExpectAndReturn(num, 1);
    get_input_line_ExpectAndReturn(NULL, 100, num);
    add_pos(&head);

    // char *expected_output = "Negalimas indeksas";
    // snprintf(real_output, strlen(expected_output) + 1, "%s", out_buf);
    // TEST_ASSERT_EQUAL_STRING(expected_output, real_output);
}

void test_print_all_handle_empty()
{
    node head;
   
    list_size_ExpectAndReturn(head, 0);

    print_all(head);

    // char *expected_output = "Sąrašas tuščias.\n";
    // snprintf(real_output, strlen(expected_output) + 1, "%s", out_buf);
    // TEST_ASSERT_EQUAL_STRING(expected_output, real_output);

}

void test_print_all_handle_not_empty()
{
    node head;
    
    list_size_ExpectAndReturn(head, 5);
    print_list_Expect(head);
    print_all(head);

    // char *expected_output = "Visas sąrašas:\n";
    // snprintf(real_output, strlen(expected_output) + 1, "%s", out_buf);
    // TEST_ASSERT_EQUAL_STRING(expected_output, real_output);
}

void test_delete_pos_list_empty()
{
    node head;
    list_size_ExpectAndReturn(head, 0);

    delete_pos(&head);

    // char *expected_output = "Sąrašas tuščias";
    // snprintf(real_output, strlen(expected_output) + 1, "%s", out_buf);
    // TEST_ASSERT_EQUAL_STRING(expected_output, real_output);
}

void test_delete_pos_valid_index()
{
    node head = NULL;
    char *num = malloc(5);
    strcpy(num, "5");

    list_size_ExpectAndReturn(head, 10);
    get_input_line_ExpectAndReturn(NULL, 100, num);
    check_number_ExpectAndReturn(num, 1);
    list_delete_index_Expect(&head, 5);

    delete_pos(&head);

    // char *expected_output = "Elementas sėkmingai ištrintas.\n";
    // snprintf(real_output, strlen(expected_output) + 1, "%s", out_buf);
    // TEST_ASSERT_EQUAL_STRING(expected_output, real_output);
}
void get_field_no_found()
{
    char *str = malloc(20);
    strcpy(str, "test");
    node head;

    get_input_line_ExpectAndReturn("Lauko reikšme (vardas, pavardė, telefonas arba paštas):", 100, str);
    list_search_field_ExpectAndReturn(NULL, head, str, 0);
    char *expected_output = "Įrašas nerastas.\n";
    snprintf(real_output, strlen(expected_output) + 1, "%s", out_buf);
    TEST_ASSERT_EQUAL_STRING(expected_output, real_output);

}

void get_field_entries_found()
{
    char *str = malloc(20);
    strcpy(str, "test");
    node head;

    get_input_line_ExpectAndReturn("Lauko reikšme (vardas, pavardė, telefonas arba paštas):", 100, str);
    list_search_field_ExpectAndReturn(NULL, head, str, 5);
    char *expected_output = "Rasti įrašai:\n";
    snprintf(real_output, strlen(expected_output) + 1, "%s", out_buf);
    TEST_ASSERT_EQUAL_STRING(expected_output, real_output);
}

void test_delete_pos_invalid_index()
{
    node head = NULL;
    char *num = malloc(5);
    strcpy(num, "99");

    list_size_ExpectAndReturn(head, 10);
    get_input_line_ExpectAndReturn(NULL, 100, num);
    check_number_ExpectAndReturn(num, 1);
    delete_pos(&head);
}

void test_delete_all_handle_empty()
{
    node head;
    list_size_ExpectAndReturn(head, 0);
    delete_all(&head);

}

void test_delete_all_handle_not_empty()
{
    node head;
    list_size_ExpectAndReturn(head, 10);
    list_clear_Expect(&head);
    delete_all(&head);

}
void test_load_start_calls_create_and_add()
{
    node head;
    node n;
    
    create_node_IgnoreAndReturn(n);
    list_add_Ignore();
}

