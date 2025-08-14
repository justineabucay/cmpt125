#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =============================================================================
// PART 1: Array Fundamentals and 2D Arrays
// =============================================================================

// Exercise 1.1: Dynamic Array Implementation
typedef struct
{
    int *data;
    int capacity; // Total space allocated
    int count;    // Actual elements stored
} dynamic_array;

// Create a dynamic array with given capacity
dynamic_array *create_array(int capacity)
{
    dynamic_array *arr = malloc(sizeof(dynamic_array));
    if (arr == NULL)
        return NULL;

    arr->data = malloc(capacity * sizeof(int));
    if (arr->data == NULL)
    {
        free(arr);
        return NULL;
    }

    arr->capacity = capacity;
    arr->count = 0;
    return arr;
}

// Add element to array (if space available)
int add_element(dynamic_array *arr, int value)
{
    if (arr == NULL || arr->count >= arr->capacity)
    {
        return 0; // Failure
    }

    arr->data[arr->count] = value;
    arr->count++;
    return 1; // Success
}

// Print array information
void print_array_info(dynamic_array *arr)
{
    if (arr == NULL)
        return;

    printf("Capacity: %d, Count: %d\n", arr->capacity, arr->count);
    printf("Elements: ");
    for (int i = 0; i < arr->count; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

// Free dynamic array memory
void free_dynamic_array(dynamic_array *arr)
{
    if (arr != NULL)
    {
        free(arr->data);
        free(arr);
    }
}

// Exercise 1.2: 2D Array as 1D Implementation
// Convert 2D coordinates to 1D index
int coord_to_index(int x, int y, int width)
{
    return x + y * width;
}

// Convert 1D index back to 2D coordinates
void index_to_coord(int index, int width, int *x, int *y)
{
    *x = index % width;
    *y = index / width;
}

// Work with a "2D" image stored as 1D array
void image_processing_demo()
{
    int width = 8, height = 7;
    int *image = malloc(width * height * sizeof(int));

    // Initialize image to 0
    for (int i = 0; i < width * height; i++)
    {
        image[i] = 0;
    }

    // Set pixel at (6, 3) to value 255
    int index = coord_to_index(6, 3, width);
    image[index] = 255;

    // Read pixel at (6, 3)
    int value = image[index];
    printf("Pixel at (6,3) has value: %d\n", value);

    // Convert index back to coordinates
    int x, y;
    index_to_coord(index, width, &x, &y);
    printf("Index %d corresponds to coordinates (%d, %d)\n", index, x, y);

    free(image);
}

// =============================================================================
// PART 2: Struct Definition and Manipulation
// =============================================================================

// Define a Person struct
typedef struct
{
    char name[50];
    int age;
    float height;
    char city[30];
} Person;

// Create and initialize a person
Person create_person(const char *name, int age, float height, const char *city)
{
    Person p;
    strncpy(p.name, name, sizeof(p.name) - 1);
    p.name[sizeof(p.name) - 1] = '\0';
    strncpy(p.city, city, sizeof(p.city) - 1);
    p.city[sizeof(p.city) - 1] = '\0';
    p.age = age;
    p.height = height;
    return p;
}

// Print person information
void print_person(const Person *p)
{
    if (p == NULL)
        return;
    printf("Name: %s, Age: %d, Height: %.1f, City: %s\n",
           p->name, p->age, p->height, p->city);
}

// Find oldest person in an array
Person *find_oldest(Person *people, int count)
{
    if (people == NULL || count <= 0)
        return NULL;

    Person *oldest = &people[0];
    for (int i = 1; i < count; i++)
    {
        if (people[i].age > oldest->age)
        {
            oldest = &people[i];
        }
    }
    return oldest;
}

// Exercise 2.2: Student Management System
typedef struct
{
    int student_id;
    char name[50];
    float gpa;
    int credits;
} Student;

// Read students from file (simplified version)
Student *load_students(const char *filename, int *count)
{
    *count = 3;
    Student *students = malloc(3 * sizeof(Student));

    students[0] = (Student){12345, "John Doe", 3.5, 45};
    students[1] = (Student){23456, "Jane Smith", 3.8, 60};
    students[2] = (Student){34567, "Bob Johnson", 2.9, 30};

    return students;
}

// Find student by ID
Student *find_student_by_id(Student *students, int count, int id)
{
    if (students == NULL)
        return NULL;

    for (int i = 0; i < count; i++)
    {
        if (students[i].student_id == id)
        {
            return &students[i];
        }
    }
    return NULL; // Not found
}

// Calculate average GPA
float calculate_average_gpa(Student *students, int count)
{
    if (students == NULL || count <= 0)
        return 0.0;

    float sum = 0.0;
    for (int i = 0; i < count; i++)
    {
        sum += students[i].gpa;
    }
    return sum / count;
}

// Sort students by GPA (simple bubble sort)
void sort_by_gpa(Student *students, int count)
{
    if (students == NULL || count <= 1)
        return;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (students[j].gpa < students[j + 1].gpa)
            {
                // Swap students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// =============================================================================
// PART 3: Basic Linked Lists
// =============================================================================

// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Create a new node
Node *create_node(int data)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return NULL;

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert at beginning of list
Node *insert_at_beginning(Node *head, int data)
{
    Node *new_node = create_node(data);
    if (new_node == NULL)
        return head;

    new_node->next = head;
    return new_node; // New head
}

// Print the entire list
void print_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

// Find length of list
int list_length(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Free entire list
void free_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

// Insert at end of list
Node *insert_at_end(Node *head, int data)
{
    Node *new_node = create_node(data);
    if (new_node == NULL)
        return head;

    if (head == NULL)
    {
        return new_node;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

// Delete first occurrence of value
Node *delete_value(Node *head, int value)
{
    if (head == NULL)
        return NULL;

    // If head contains the value
    if (head->data == value)
    {
        Node *new_head = head->next;
        free(head);
        return new_head;
    }

    Node *current = head;
    while (current->next != NULL && current->next->data != value)
    {
        current = current->next;
    }

    if (current->next != NULL)
    {
        Node *to_delete = current->next;
        current->next = to_delete->next;
        free(to_delete);
    }

    return head;
}

// Find node with specific value
Node *find_node(Node *head, int value)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == value)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Reverse the linked list
Node *reverse_list(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; // New head
}

// =============================================================================
// PART 4: Complex Data Structures
// =============================================================================

// Course with dynamic student list
typedef struct
{
    char course_code[10];
    char title[100];
    int *student_ids;
    int student_count;
    int capacity;
} Course;

// Create a course with initial capacity
Course *create_course(const char *code, const char *title, int capacity)
{
    Course *course = malloc(sizeof(Course));
    if (course == NULL)
        return NULL;

    course->student_ids = malloc(capacity * sizeof(int));
    if (course->student_ids == NULL)
    {
        free(course);
        return NULL;
    }

    strncpy(course->course_code, code, sizeof(course->course_code) - 1);
    course->course_code[sizeof(course->course_code) - 1] = '\0';
    strncpy(course->title, title, sizeof(course->title) - 1);
    course->title[sizeof(course->title) - 1] = '\0';
    course->student_count = 0;
    course->capacity = capacity;

    return course;
}

// Add student to course
int add_student_to_course(Course *course, int student_id)
{
    if (course == NULL || course->student_count >= course->capacity)
    {
        return 0; // Course full
    }

    // Check if student already enrolled
    for (int i = 0; i < course->student_count; i++)
    {
        if (course->student_ids[i] == student_id)
        {
            return 0; // Already enrolled
        }
    }

    course->student_ids[course->student_count] = student_id;
    course->student_count++;
    return 1; // Success
}

// Remove student from course
int remove_student_from_course(Course *course, int student_id)
{
    if (course == NULL)
        return 0;

    for (int i = 0; i < course->student_count; i++)
    {
        if (course->student_ids[i] == student_id)
        {
            // Shift remaining students to fill gap
            for (int j = i; j < course->student_count - 1; j++)
            {
                course->student_ids[j] = course->student_ids[j + 1];
            }
            course->student_count--;
            return 1; // Success
        }
    }
    return 0; // Student not found
}

// Print course information
void print_course(const Course *course)
{
    if (course == NULL)
        return;

    printf("Course: %s - %s\n", course->course_code, course->title);
    printf("Students (%d/%d): ", course->student_count, course->capacity);
    for (int i = 0; i < course->student_count; i++)
    {
        printf("%d ", course->student_ids[i]);
    }
    printf("\n");
}

// Free course memory
void free_course(Course *course)
{
    if (course != NULL)
    {
        free(course->student_ids);
        free(course);
    }
}

// =============================================================================
// PART 5: Library Management System
// =============================================================================

typedef struct
{
    int book_id;
    char title[100];
    char author[50];
    int is_available;
} Book;

typedef struct
{
    Book *books;
    int count;
    int capacity;
} Library;

// Create library with initial capacity
Library *create_library(int capacity)
{
    Library *lib = malloc(sizeof(Library));
    if (lib == NULL)
        return NULL;

    lib->books = malloc(capacity * sizeof(Book));
    if (lib->books == NULL)
    {
        free(lib);
        return NULL;
    }

    lib->count = 0;
    lib->capacity = capacity;
    return lib;
}

// Add book to library
int add_book(Library *lib, int id, const char *title, const char *author)
{
    if (lib == NULL || lib->count >= lib->capacity)
    {
        return 0; // Library full
    }

    Book *book = &lib->books[lib->count];
    book->book_id = id;
    strncpy(book->title, title, sizeof(book->title) - 1);
    book->title[sizeof(book->title) - 1] = '\0';
    strncpy(book->author, author, sizeof(book->author) - 1);
    book->author[sizeof(book->author) - 1] = '\0';
    book->is_available = 1;

    lib->count++;
    return 1; // Success
}

// Find book by ID
Book *find_book(Library *lib, int book_id)
{
    if (lib == NULL)
        return NULL;

    for (int i = 0; i < lib->count; i++)
    {
        if (lib->books[i].book_id == book_id)
        {
            return &lib->books[i];
        }
    }
    return NULL;
}

// Check out book (set is_available to 0)
int checkout_book(Library *lib, int book_id)
{
    Book *book = find_book(lib, book_id);
    if (book == NULL || !book->is_available)
    {
        return 0; // Book not found or not available
    }

    book->is_available = 0;
    return 1; // Success
}

// Return book (set is_available to 1)
int return_book(Library *lib, int book_id)
{
    Book *book = find_book(lib, book_id);
    if (book == NULL)
    {
        return 0; // Book not found
    }

    book->is_available = 1;
    return 1; // Success
}

// List all available books
void list_available_books(Library *lib)
{
    if (lib == NULL)
        return;

    printf("Available Books:\n");
    printf("================\n");
    for (int i = 0; i < lib->count; i++)
    {
        if (lib->books[i].is_available)
        {
            printf("ID: %d, Title: %s, Author: %s\n",
                   lib->books[i].book_id,
                   lib->books[i].title,
                   lib->books[i].author);
        }
    }
    printf("\n");
}

// Free library memory
void free_library(Library *lib)
{
    if (lib != NULL)
    {
        free(lib->books);
        free(lib);
    }
}

// =============================================================================
// MAIN FUNCTION - Test All Implementations
// =============================================================================

int main()
{
    printf("=== Day 4 Data Structures Solutions ===\n\n");

    // Test Part 1: Dynamic Arrays
    printf("1. Testing Dynamic Arrays:\n");
    dynamic_array *arr = create_array(10);
    add_element(arr, 5);
    add_element(arr, 3);
    add_element(arr, 8);
    print_array_info(arr);
    free_dynamic_array(arr);

    printf("\n2. Testing 2D Array as 1D:\n");
    image_processing_demo();

    // Test Part 2: Structs
    printf("\n3. Testing Person Structs:\n");
    Person people[3];
    people[0] = create_person("Alice", 25, 5.6, "Vancouver");
    people[1] = create_person("Bob", 30, 6.0, "Toronto");
    people[2] = create_person("Carol", 22, 5.4, "Montreal");

    Person *oldest = find_oldest(people, 3);
    printf("Oldest person: ");
    print_person(oldest);

    // Test Part 3: Linked Lists
    printf("\n4. Testing Linked Lists:\n");
    Node *head = NULL;
    head = insert_at_beginning(head, 3);
    head = insert_at_beginning(head, 2);
    head = insert_at_beginning(head, 1);

    printf("List: ");
    print_list(head);
    printf("Length: %d\n", list_length(head));

    head = reverse_list(head);
    printf("Reversed: ");
    print_list(head);

    free_list(head);

    // Test Part 4: Course Management
    printf("\n5. Testing Course Management:\n");
    Course *course = create_course("CS101", "Introduction to Programming", 5);
    add_student_to_course(course, 12345);
    add_student_to_course(course, 23456);
    print_course(course);
    free_course(course);

    // Test Part 5: Library System
    printf("\n6. Testing Library System:\n");
    Library *lib = create_library(100);

    add_book(lib, 1, "The C Programming Language", "Kernighan & Ritchie");
    add_book(lib, 2, "Data Structures", "Weiss");

    checkout_book(lib, 1);
    list_available_books(lib);

    return_book(lib, 1);
    list_available_books(lib);

    free_library(lib);

    printf("All tests completed successfully!\n");
    return 0;
}