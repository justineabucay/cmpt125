/*
 * testDriver.c
 *
 * Test driver for the intArray_t data structure
 * Tests all functions with various edge cases and normal operations
 *
 * Author: Test Driver
 * Date: July 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dataStructure.h"

// Test result tracking
static int tests_passed = 0;
static int tests_failed = 0;

// Helper function to print test results
void print_test_result(const char *test_name, int passed)
{
    if (passed)
    {
        printf("✓ PASS: %s\n", test_name);
        tests_passed++;
    }
    else
    {
        printf("✗ FAIL: %s\n", test_name);
        tests_failed++;
    }
}

// Helper function to compare arrays
int arrays_equal(intArray_t *ia, int *expected, unsigned int expected_count)
{
    if (ia->elementCount != expected_count)
        return 0;
    for (unsigned int i = 0; i < expected_count; i++)
    {
        if (ia->data[i] != expected[i])
            return 0;
    }
    return 1;
}

// Test intArray_create function
void test_intArray_create()
{
    printf("\n=== Testing intArray_create ===\n");

    // Test 1: Normal creation
    intArray_t *ia1 = intArray_create(10);
    print_test_result("Create array with size 10",
                      ia1 != NULL && ia1->size == 10 && ia1->elementCount == 0);
    if (ia1)
        intArray_destroy(ia1);

    // Test 2: Create with size 1
    intArray_t *ia2 = intArray_create(1);
    print_test_result("Create array with size 1",
                      ia2 != NULL && ia2->size == 1 && ia2->elementCount == 0);
    if (ia2)
        intArray_destroy(ia2);

    // Test 3: Create with size 0 (should fail)
    intArray_t *ia3 = intArray_create(0);
    print_test_result("Create array with size 0 (should fail)", ia3 == NULL);

    // Test 4: Create large array
    intArray_t *ia4 = intArray_create(1000);
    print_test_result("Create large array (size 1000)",
                      ia4 != NULL && ia4->size == 1000 && ia4->elementCount == 0);
    if (ia4)
        intArray_destroy(ia4);
}

// Test intArray_destroy function
void test_intArray_destroy()
{
    printf("\n=== Testing intArray_destroy ===\n");

    // Test 1: Destroy valid array
    intArray_t *ia1 = intArray_create(5);
    intArrayResult_t result1 = intArray_destroy(ia1);
    print_test_result("Destroy valid array", result1 == INTARR_OK);

    // Test 2: Destroy NULL pointer
    intArrayResult_t result2 = intArray_destroy(NULL);
    print_test_result("Destroy NULL pointer", result2 == INTARR_BADPARAM);
}

// Test intArray_append function
void test_intArray_append()
{
    printf("\n=== Testing intArray_append ===\n");

    intArray_t *ia = intArray_create(5);

    // Test 1: Append to empty array
    intArrayResult_t result1 = intArray_append(ia, 10);
    print_test_result("Append to empty array",
                      result1 == INTARR_OK && ia->elementCount == 1 && ia->data[0] == 10);

    // Test 2: Append multiple elements
    intArray_append(ia, 20);
    intArray_append(ia, 30);
    int expected[] = {10, 20, 30};
    print_test_result("Append multiple elements",
                      ia->elementCount == 3 && arrays_equal(ia, expected, 3));

    // Test 3: Fill array to capacity
    intArray_append(ia, 40);
    intArray_append(ia, 50);
    print_test_result("Fill array to capacity", ia->elementCount == 5);

    // Test 4: Try to append when full (should fail)
    intArrayResult_t result4 = intArray_append(ia, 60);
    print_test_result("Append when full (should fail)",
                      result4 == INTARR_ERROR && ia->elementCount == 5);

    // Test 5: Append to NULL array
    intArrayResult_t result5 = intArray_append(NULL, 100);
    print_test_result("Append to NULL array", result5 == INTARR_BADPARAM);

    if(ia != NULL)
        intArray_destroy(ia);
}

// Test intArray_remove function
void test_intArray_remove()
{
    printf("\n=== Testing intArray_remove ===\n");

    intArray_t *ia = intArray_create(5);

    // Fill array with test data
    for (int i = 0; i < 5; i++)
    {
        intArray_append(ia, (i + 1) * 10); // 10, 20, 30, 40, 50
    }

    // Test 1: Remove from middle
    intArrayResult_t result1 = intArray_remove(ia, 2); // Remove 30
    int expected1[] = {10, 20, 50, 40};                // Last element moved to position 2
    print_test_result("Remove from middle",
                      result1 == INTARR_OK && ia->elementCount == 4 &&
                          ia->data[2] == 50); // Last element moved to removed position

    // Test 2: Remove first element
    intArrayResult_t result2 = intArray_remove(ia, 0); // Remove 10
    print_test_result("Remove first element",
                      result2 == INTARR_OK && ia->elementCount == 3 &&
                          ia->data[0] == 40); // Last element moved to position 0

    // Test 3: Remove last element
    intArrayResult_t result3 = intArray_remove(ia, 2); // Remove last element
    print_test_result("Remove last element",
                      result3 == INTARR_OK && ia->elementCount == 2);

    // Test 4: Remove out of bounds
    intArrayResult_t result4 = intArray_remove(ia, 10);
    print_test_result("Remove out of bounds", result4 == INTARR_BADPARAM);

    // Test 5: Remove from NULL array
    intArrayResult_t result5 = intArray_remove(NULL, 0);
    print_test_result("Remove from NULL array", result5 == INTARR_BADPARAM);

    intArray_destroy(ia);

    // Test 6: Remove from empty array
    intArray_t *empty_ia = intArray_create(5);
    intArrayResult_t result6 = intArray_remove(empty_ia, 0);
    print_test_result("Remove from empty array", result6 == INTARR_BADPARAM);
    intArray_destroy(empty_ia);
}

// Test intArray_modify function
void test_intArray_modify()
{
    printf("\n=== Testing intArray_modify ===\n");

    intArray_t *ia = intArray_create(3);
    intArray_append(ia, 10);
    intArray_append(ia, 20);
    intArray_append(ia, 30);

    // Test 1: Modify middle element
    intArrayResult_t result1 = intArray_modify(ia, 99, 1);
    print_test_result("Modify middle element",
                      result1 == INTARR_OK && ia->data[1] == 99);

    // Test 2: Modify first element
    intArrayResult_t result2 = intArray_modify(ia, 11, 0);
    print_test_result("Modify first element",
                      result2 == INTARR_OK && ia->data[0] == 11);

    // Test 3: Modify last element
    intArrayResult_t result3 = intArray_modify(ia, 33, 2);
    print_test_result("Modify last element",
                      result3 == INTARR_OK && ia->data[2] == 33);

    // Test 4: Modify out of bounds
    intArrayResult_t result4 = intArray_modify(ia, 100, 10);
    print_test_result("Modify out of bounds", result4 == INTARR_BADPARAM);

    // Test 5: Modify NULL array
    intArrayResult_t result5 = intArray_modify(NULL, 100, 0);
    print_test_result("Modify NULL array", result5 == INTARR_BADPARAM);

    intArray_destroy(ia);
}

// Test intArray_find function
void test_intArray_find()
{
    printf("\n=== Testing intArray_find ===\n");

    intArray_t *ia = intArray_create(5);
    intArray_append(ia, 10);
    intArray_append(ia, 20);
    intArray_append(ia, 30);
    intArray_append(ia, 20); // Duplicate
    intArray_append(ia, 40);

    // Test 1: Find existing element (first occurrence)
    unsigned int index1;
    intArrayResult_t result1 = intArray_find(ia, 20, &index1);
    print_test_result("Find existing element (first occurrence)",
                      result1 == INTARR_OK && index1 == 1);

    // Test 2: Find first element
    unsigned int index2;
    intArrayResult_t result2 = intArray_find(ia, 10, &index2);
    print_test_result("Find first element",
                      result2 == INTARR_OK && index2 == 0);

    // Test 3: Find last element
    unsigned int index3;
    intArrayResult_t result3 = intArray_find(ia, 40, &index3);
    print_test_result("Find last element",
                      result3 == INTARR_OK && index3 == 4);

    // Test 4: Find non-existent element
    unsigned int index4 = 999; // Should remain unchanged
    intArrayResult_t result4 = intArray_find(ia, 100, &index4);
    print_test_result("Find non-existent element",
                      result4 == INTARR_NOTFOUND && index4 == 999);

    // Test 5: Find in NULL array
    unsigned int index5;
    intArrayResult_t result5 = intArray_find(NULL, 10, &index5);
    print_test_result("Find in NULL array", result5 == INTARR_BADPARAM);

    intArray_destroy(ia);
}

// Test intArray_sort function
void test_intArray_sort()
{
    printf("\n=== Testing intArray_sort ===\n");

    intArray_t *ia = intArray_create(6);
    intArray_append(ia, 30);
    intArray_append(ia, 10);
    intArray_append(ia, 50);
    intArray_append(ia, 20);
    intArray_append(ia, 40);
    intArray_append(ia, 10); // Duplicate

    // Test 1: Sort unsorted array
    intArrayResult_t result1 = intArray_sort(ia);
    int expected[] = {10, 10, 20, 30, 40, 50};
    print_test_result("Sort unsorted array",
                      result1 == INTARR_OK && arrays_equal(ia, expected, 6));

    // Test 2: Sort already sorted array
    intArrayResult_t result2 = intArray_sort(ia);
    print_test_result("Sort already sorted array",
                      result2 == INTARR_OK && arrays_equal(ia, expected, 6));

    intArray_destroy(ia);

    // Test 3: Sort single element
    intArray_t *ia2 = intArray_create(1);
    intArray_append(ia2, 42);
    intArrayResult_t result3 = intArray_sort(ia2);
    print_test_result("Sort single element",
                      result3 == INTARR_OK && ia2->data[0] == 42);
    intArray_destroy(ia2);

    // Test 4: Sort empty array
    intArray_t *ia3 = intArray_create(5);
    intArrayResult_t result4 = intArray_sort(ia3);
    print_test_result("Sort empty array",
                      result4 == INTARR_OK && ia3->elementCount == 0);
    intArray_destroy(ia3);

    // Test 5: Sort NULL array
    intArrayResult_t result5 = intArray_sort(NULL);
    print_test_result("Sort NULL array", result5 == INTARR_BADPARAM);
}

// Test intArray_copy function
void test_intArray_copy()
{
    printf("\n=== Testing intArray_copy ===\n");

    intArray_t *ia = intArray_create(3);
    intArray_append(ia, 10);
    intArray_append(ia, 20);
    intArray_append(ia, 30);

    // Test 1: Copy non-empty array
    intArray_t *copy1 = intArray_copy(ia);
    int expected[] = {10, 20, 30};
    print_test_result("Copy non-empty array",
                      copy1 != NULL && copy1->size == ia->size &&
                          copy1->elementCount == ia->elementCount &&
                          arrays_equal(copy1, expected, 3) && copy1->data != ia->data);

    // Test 2: Modify original, copy should be unchanged
    intArray_modify(ia, 99, 1);
    print_test_result("Copy independent of original",
                      copy1->data[1] == 20 && ia->data[1] == 99);

    if (copy1)
        intArray_destroy(copy1);
    intArray_destroy(ia);

    // Test 3: Copy empty array
    intArray_t *empty_ia = intArray_create(5);
    intArray_t *copy2 = intArray_copy(empty_ia);
    print_test_result("Copy empty array",
                      copy2 != NULL && copy2->size == 5 && copy2->elementCount == 0);
    if (copy2)
        intArray_destroy(copy2);
    intArray_destroy(empty_ia);

    // Test 4: Copy NULL array
    intArray_t *copy3 = intArray_copy(NULL);
    print_test_result("Copy NULL array", copy3 == NULL);
}

// Test intArray_print function
void test_intArray_print()
{
    printf("\n=== Testing intArray_print ===\n");

    intArray_t *ia = intArray_create(5);
    intArray_append(ia, 8);
    intArray_append(ia, -45);
    intArray_append(ia, 27);
    intArray_append(ia, 0);
    intArray_append(ia, -22);

    // Test 1: Print non-empty array
    printf("Expected output:\n");
    printf("Printing intArray_t of size 5 with 5 elements\n");
    printf("\tarray: 8 -45 27 0 -22 (end)\n");
    printf("Actual output:\n");
    intArrayResult_t result1 = intArray_print(ia);
    print_test_result("Print non-empty array", result1 == INTARR_OK);

    intArray_destroy(ia);

    // Test 2: Print empty array
    intArray_t *empty_ia = intArray_create(3);
    printf("Expected output for empty array:\n");
    printf("Printing intArray_t of size 3 with 0 elements\n");
    printf("\tarray: (end)\n");
    printf("Actual output:\n");
    intArrayResult_t result2 = intArray_print(empty_ia);
    print_test_result("Print empty array", result2 == INTARR_OK);
    intArray_destroy(empty_ia);

    // Test 3: Print NULL array
    intArrayResult_t result3 = intArray_print(NULL);
    print_test_result("Print NULL array", result3 == INTARR_BADPARAM);
}

// Test JSON file I/O functions
void test_json_io()
{
    printf("\n=== Testing JSON I/O ===\n");

    intArray_t *ia = intArray_create(5);
    intArray_append(ia, 100);
    intArray_append(ia, 200);
    intArray_append(ia, 300);

    // Test 1: Write to JSON file
    intArrayResult_t result1 = intArray_write_to_json(ia, "test_output.json");
    print_test_result("Write to JSON file", result1 == INTARR_OK);

    // Test 2: Load from JSON file
    intArray_t *loaded = intArray_load_from_json("test_output.json");
    int expected[] = {100, 200, 300};
    print_test_result("Load from JSON file",
                      loaded != NULL && loaded->elementCount == 3 &&
                          arrays_equal(loaded, expected, 3));

    if (loaded)
        intArray_destroy(loaded);
    intArray_destroy(ia);

    // Test 3: Write empty array (should fail)
    intArray_t *empty_ia = intArray_create(5);
    intArrayResult_t result3 = intArray_write_to_json(empty_ia, "empty_test.json");
    print_test_result("Write empty array (should fail)", result3 == INTARR_ERROR);
    intArray_destroy(empty_ia);

    // Test 4: Write with NULL filename
    intArray_t *ia2 = intArray_create(1);
    intArray_append(ia2, 42);
    intArrayResult_t result4 = intArray_write_to_json(ia2, NULL);
    print_test_result("Write with NULL filename", result4 == INTARR_BADPARAM);
    intArray_destroy(ia2);

    // Test 5: Load with NULL filename
    intArray_t *loaded2 = intArray_load_from_json(NULL);
    print_test_result("Load with NULL filename", loaded2 == NULL);

    // Test 6: Load non-existent file
    intArray_t *loaded3 = intArray_load_from_json("nonexistent.json");
    print_test_result("Load non-existent file", loaded3 == NULL);

    // Clean up test files
    remove("test_output.json");
    remove("empty_test.json");
}

// Comprehensive test with real-world scenario
void test_comprehensive_scenario()
{
    printf("\n=== Comprehensive Test Scenario ===\n");

    // Create array and add some data
    intArray_t *numbers = intArray_create(10);

    // Add numbers: 50, 30, 70, 20, 60, 40
    intArray_append(numbers, 50);
    intArray_append(numbers, 30);
    intArray_append(numbers, 70);
    intArray_append(numbers, 20);
    intArray_append(numbers, 60);
    intArray_append(numbers, 40);

    // Find and modify
    unsigned int index;
    if (intArray_find(numbers, 70, &index) == INTARR_OK)
    {
        intArray_modify(numbers, 75, index);
    }

    // Sort the array
    intArray_sort(numbers);

    // Expected: 20, 30, 40, 50, 60, 75
    int expected[] = {20, 30, 40, 50, 60, 75};
    print_test_result("Comprehensive scenario",
                      arrays_equal(numbers, expected, 6));

    // Save to file
    intArray_write_to_json(numbers, "comprehensive_test.json");

    // Load and verify
    intArray_t *loaded = intArray_load_from_json("comprehensive_test.json");
    print_test_result("Save/Load comprehensive test",
                      loaded != NULL && arrays_equal(loaded, expected, 6));

    if (loaded)
        intArray_destroy(loaded);
    intArray_destroy(numbers);
    remove("comprehensive_test.json");
}

int main()
{
    printf("==========================================\n");
    printf("  intArray_t Data Structure Test Suite\n");
    printf("==========================================\n");

    test_intArray_create();
    test_intArray_destroy();
    test_intArray_append();
    test_intArray_remove();
    test_intArray_modify();
    test_intArray_find();
    test_intArray_sort();
    test_intArray_copy();
    test_intArray_print();
    test_json_io();
    test_comprehensive_scenario();

    printf("\n==========================================\n");
    printf("              TEST SUMMARY\n");
    printf("==========================================\n");
    printf("Tests Passed: %d\n", tests_passed);
    printf("Tests Failed: %d\n", tests_failed);
    printf("Total Tests:  %d\n", tests_passed + tests_failed);

    if (tests_failed == 0)
    {
        printf("\n🎉 ALL TESTS PASSED! 🎉\n");
        return 0;
    }
    else
    {
        printf("\n❌ %d TEST(S) FAILED ❌\n", tests_failed);
        return 1;
    }
}