
#include <unity/unity.h>
#include "io_utils.h"

void setUp()
{

}
void tearDown()
{
    
}

void test_remove_endline_removes_all()
{
    char *real = malloc(20);
    strcpy(real, "message\naaa\n");
    char *expected = "message";
    
    remove_endline(&real,strlen(real));
    TEST_ASSERT_EQUAL_STRING(expected, real);
    free(real);
}

void test_remove_endline_no_endline_do_nothing()
{
    char *real = malloc(20);
    strcpy(real, "message");
    char *expected = "message";
    remove_endline(&real,strlen(real));
    TEST_ASSERT_EQUAL_STRING(expected, real);
    free(real);
}

void test_check_number_valid()
{
    TEST_ASSERT_TRUE(check_number("123"));
    TEST_ASSERT_TRUE(check_number("0001"));
}

void test_check_number_invalid()
{
    TEST_ASSERT_FALSE(check_number("_123"));
    TEST_ASSERT_FALSE(check_number("000x1"));
    TEST_ASSERT_FALSE(check_number(""));
}
