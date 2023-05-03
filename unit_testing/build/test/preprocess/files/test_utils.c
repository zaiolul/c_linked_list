#include "build/test/mocks/mock_utils.h"
#include "../includes/linkedlist.h"






void setUp(void)

{



}



void tearDown(void)

{



}



void test_is_number_true()

{

    check_number_CMockExpectAndReturn(20, "123", 1);

    

   do { if ((

   check_number("123")

   )) { } else { UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(21))); } } while (0)

                                        ;

    check_number_CMockExpectAndReturn(22, "0", 1);

    

   do { if ((

   check_number("0")

   )) { } else { UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(23))); } } while (0)

                                      ;



}

void test_is_number_false()

{

    check_number_CMockExpectAndReturn(28, "a123", 0);

    

   do { if (!(

   check_number("a123")

   )) { } else { UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(29))); } } while (0)

                                          ;

    check_number_CMockExpectAndReturn(30, "5894_", 0);

    

   do { if (!(

   check_number("5894_")

   )) { } else { UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(31))); } } while (0)

                                           ;

}

void test_start_entries_loaded()

{



    node head = 

               ((void *)0)

                   ;

    load_start_entries_CMockExpect(37, &head);

    load_start_entries(&head);

    

   UnityAssertEqualNumber((UNITY_INT)((

   10

   )), (UNITY_INT)((

   list_size(head)

   )), (((void *)0)), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT)

                                             ;

}
