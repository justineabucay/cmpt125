/*
 * test_driver.c
 *
 * Test driver for the doubly-headed singly-linked list (DHSL) data structure
 * Tests all functions defined in dataStructure.h
 *
 * Compile with: gcc -o test_driver test_driver.c dataStructure.c
 * Run with: ./test_driver
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dataStructure.h"

// Test counter for tracking test results
int tests_passed = 0;
int tests_failed = 0;

// Helper function to print test results
void print_test_result(const char *test_name, int passed)
{
    if (passed)
    {
        printf("✓ %s: PASSED\n", test_name);
        tests_passed++;
    }
    else
    {
        printf("✗ %s: FAILED\n", test_name);
        tests_failed++;
    }
}

// Test list_create function
void test_list_create()
{
    printf("\n=== Testing list_create ===\n");

    list_t *list = list_create();
    int passed = (list != NULL &&
                  list->head == NULL &&
                  list->tail == NULL &&
                  list->elementCount == 0);

    print_test_result("list_create - creates empty list", passed);

    if (list)
    {
        list_destroy(list);
    }
}

// Test element_create function
void test_element_create()
{
    printf("\n=== Testing element_create ===\n");

    element_t *elem = element_create(42);
    int passed = (elem != NULL &&
                  elem->val == 42 &&
                  elem->next == NULL);

    print_test_result("element_create - creates element with correct value", passed);

    if (elem)
    {
        free(elem);
    }
}

// Test list_append function
void test_list_append()
{
    printf("\n=== Testing list_append ===\n");

    list_t *list = list_create();

    // Test appending to empty list
    listResult_t result = list_append(list, 10);
    int test1 = (result == LIST_OK &&
                 list->elementCount == 1 &&
                 list->head != NULL &&
                 list->tail != NULL &&
                 list->head == list->tail &&
                 list->head->val == 10);
    print_test_result("list_append - append to empty list", test1);

    // Test appending to non-empty list
    result = list_append(list, 20);
    int test2 = (result == LIST_OK &&
                 list->elementCount == 2 &&
                 list->head->val == 10 &&
                 list->tail->val == 20 &&
                 list->head->next == list->tail);
    print_test_result("list_append - append to non-empty list", test2);

    // Test appending multiple elements
    list_append(list, 30);
    list_append(list, 40);
    int test3 = (list->elementCount == 4 &&
                 list->tail->val == 40);
    print_test_result("list_append - multiple appends", test3);

    // Test NULL parameter
    result = list_append(NULL, 50);
    int test4 = (result == LIST_NULL_PARAM);
    print_test_result("list_append - NULL parameter handling", test4);

    list_destroy(list);
}

// Test list_prepend function
void test_list_prepend()
{
    printf("\n=== Testing list_prepend ===\n");

    list_t *list = list_create();

    // Test prepending to empty list
    listResult_t result = list_prepend(list, 100);
    int test1 = (result == LIST_OK &&
                 list->elementCount == 1 &&
                 list->head != NULL &&
                 list->tail != NULL &&
                 list->head == list->tail &&
                 list->head->val == 100);
    print_test_result("list_prepend - prepend to empty list", test1);

    // Test prepending to non-empty list
    result = list_prepend(list, 200);
    int test2 = (result == LIST_OK &&
                 list->elementCount == 2 &&
                 list->head->val == 200 &&
                 list->tail->val == 100 &&
                 list->head->next == list->tail);
    print_test_result("list_prepend - prepend to non-empty list", test2);

    // Test NULL parameter
    result = list_prepend(NULL, 300);
    int test3 = (result == LIST_NULL_PARAM);
    print_test_result("list_prepend - NULL parameter handling", test3);

    list_destroy(list);
}

// Test list_removeFront function
void test_list_removeFront()
{
    printf("\n=== Testing list_removeFront ===\n");

    list_t *list = list_create();

    // Test removing from empty list
    listResult_t result = list_removeFront(list);
    int test1 = (result == LIST_ERROR);
    print_test_result("list_removeFront - remove from empty list", test1);

    // Add elements and test removal
    list_append(list, 1);
    list_append(list, 2);
    list_append(list, 3);

    // Remove front element
    result = list_removeFront(list);
    int test2 = (result == LIST_OK &&
                 list->elementCount == 2 &&
                 list->head->val == 2);
    print_test_result("list_removeFront - remove from multi-element list", test2);

    // Remove until one element left
    list_removeFront(list);
    int test3 = (list->elementCount == 1 &&
                 list->head->val == 3 &&
                 list->head == list->tail);
    print_test_result("list_removeFront - remove until one element", test3);

    // Remove last element
    result = list_removeFront(list);
    int test4 = (result == LIST_OK &&
                 list->elementCount == 0 &&
                 list->head == NULL &&
                 list->tail == NULL);
    print_test_result("list_removeFront - remove last element", test4);

    // Test NULL parameter
    result = list_removeFront(NULL);
    int test5 = (result == LIST_NULL_PARAM);
    print_test_result("list_removeFront - NULL parameter handling", test5);

    list_destroy(list);
}

// Test list_get function
void test_list_get()
{
    printf("\n=== Testing list_get ===\n");

    list_t *list = list_create();

    // Test get from empty list
    element_t *elem = list_get(list, 1);
    int test1 = (elem == NULL);
    print_test_result("list_get - get from empty list", test1);

    // Add elements
    list_append(list, 10);
    list_append(list, 20);
    list_append(list, 30);

    // Test valid positions
    elem = list_get(list, 1);
    int test2 = (elem != NULL && elem->val == 10);
    print_test_result("list_get - get first element (position 1)", test2);

    elem = list_get(list, 2);
    int test3 = (elem != NULL && elem->val == 20);
    print_test_result("list_get - get middle element (position 2)", test3);

    elem = list_get(list, 3);
    int test4 = (elem != NULL && elem->val == 30);
    print_test_result("list_get - get last element (position 3)", test4);

    // Test invalid positions
    elem = list_get(list, 0);
    int test5 = (elem == NULL);
    print_test_result("list_get - invalid position 0", test5);

    elem = list_get(list, 4);
    int test6 = (elem == NULL);
    print_test_result("list_get - position out of range", test6);

    // Test NULL parameter
    elem = list_get(NULL, 1);
    int test7 = (elem == NULL);
    print_test_result("list_get - NULL parameter handling", test7);

    list_destroy(list);
}

// Test list_find function
void test_list_find()
{
    printf("\n=== Testing list_find ===\n");

    list_t *list = list_create();

    // Test find in empty list
    element_t *elem = list_find(list, 42);
    int test1 = (elem == NULL);
    print_test_result("list_find - find in empty list", test1);

    // Add elements including duplicates
    list_append(list, 10);
    list_append(list, 20);
    list_append(list, 30);
    list_append(list, 20); // duplicate

    // Test finding existing elements
    elem = list_find(list, 10);
    int test2 = (elem != NULL && elem->val == 10);
    print_test_result("list_find - find first element", test2);

    elem = list_find(list, 30);
    int test3 = (elem != NULL && elem->val == 30);
    print_test_result("list_find - find last unique element", test3);

    // Test finding first occurrence of duplicate
    elem = list_find(list, 20);
    int test4 = (elem != NULL && elem->val == 20);
    print_test_result("list_find - find first occurrence of duplicate", test4);

    // Test finding non-existent element
    elem = list_find(list, 999);
    int test5 = (elem == NULL);
    print_test_result("list_find - element not found", test5);

    // Test NULL parameter
    elem = list_find(NULL, 10);
    int test6 = (elem == NULL);
    print_test_result("list_find - NULL parameter handling", test6);

    list_destroy(list);
}

// Test list_print function
void test_list_print()
{
    printf("\n=== Testing list_print ===\n");

    list_t *list = list_create();

    // Test printing empty list
    printf("Expected output: {}\n");
    printf("Actual output: ");
    listResult_t result = list_print(list);
    int test1 = (result == LIST_OK);
    print_test_result("list_print - empty list", test1);

    // Test printing list with elements
    list_append(list, 1);
    list_append(list, 2);
    list_append(list, 3);

    printf("Expected output: {1, 2, 3}\n");
    printf("Actual output: ");
    result = list_print(list);
    int test2 = (result == LIST_OK);
    print_test_result("list_print - list with elements", test2);

    // Test NULL parameter
    result = list_print(NULL);
    int test3 = (result == LIST_NULL_PARAM);
    print_test_result("list_print - NULL parameter handling", test3);

    list_destroy(list);
}

// Test list_destroy function
void test_list_destroy()
{
    printf("\n=== Testing list_destroy ===\n");

    list_t *list = list_create();

    // Test destroying empty list
    listResult_t result = list_destroy(list);
    int test1 = (result == LIST_OK);
    print_test_result("list_destroy - destroy empty list", test1);

    // Test destroying list with elements
    list = list_create();
    list_append(list, 1);
    list_append(list, 2);
    list_append(list, 3);

    result = list_destroy(list);
    int test2 = (result == LIST_OK);
    print_test_result("list_destroy - destroy list with elements", test2);

    // Test NULL parameter
    result = list_destroy(NULL);
    int test3 = (result == LIST_ERROR);
    print_test_result("list_destroy - NULL parameter handling", test3);
}

// Comprehensive integration test
void test_integration()
{
    printf("\n=== Integration Test ===\n");

    list_t *list = list_create();

    // Build a list: prepend 5, append 10, 15, prepend 0
    list_prepend(list, 5);
    list_append(list, 10);
    list_append(list, 15);
    list_prepend(list, 0);

    // Expected: {0, 5, 10, 15}
    printf("List after operations: ");
    list_print(list);

    int test1 = (list->elementCount == 4 &&
                 list->head->val == 0 &&
                 list->tail->val == 15);
    print_test_result("Integration - list building", test1);

    // Remove front twice
    list_removeFront(list); // Remove 0
    list_removeFront(list); // Remove 5

    // Expected: {10, 15}
    printf("List after removing front twice: ");
    list_print(list);

    int test2 = (list->elementCount == 2 &&
                 list->head->val == 10 &&
                 list->tail->val == 15);
    print_test_result("Integration - after removals", test2);

    list_destroy(list);
}

int main()
{
    printf("=== DHSL Data Structure Test Driver ===\n");
    printf("Testing all functions in dataStructure.h\n");

    // Run all tests
    test_list_create();
    test_element_create();
    test_list_append();
    test_list_prepend();
    test_list_removeFront();
    test_list_get();
    test_list_find();
    test_list_print();
    test_list_destroy();
    test_integration();

    // Print final results
    printf("\n=== Test Summary ===\n");
    printf("Tests Passed: %d\n", tests_passed);
    printf("Tests Failed: %d\n", tests_failed);
    printf("Total Tests: %d\n", tests_passed + tests_failed);

    if (tests_failed == 0)
    {
        printf("🎉 All tests passed!\n");
        return 0;
    }
    else
    {
        printf("❌ Some tests failed. Check implementation.\n");
        return 1;
    }
}