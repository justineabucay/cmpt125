
// exercise 1.1: array vs. element count
typedef struct {
    int* data; 
    int capacity;
    int count;
} dynamic_array;

// Create a dynamic array with given capacity
dynamic_array *create_array(int capacity);

// Add element to array (if space available)
int add_element(dynamic_array *arr, int value);


// Print array information
void print_array_info(dynamic_array *arr);

int coord_to_index(int x, int y, int width);

void index_to_coord(int index, int width, int *x, int *y);

void image_processing_demo();
