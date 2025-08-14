#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *posts; 
    int width;
    int height;
    int total_posts; 
} Grid; 

// initialize the grid with dynamic array
Grid *create_grid(int width, int height){
    Grid *grid = malloc(sizeof(Grid)); 
    if(grid == NULL) return NULL; 

    grid->width = width;
    grid->height = height;
    grid->total_posts = width * height; 

    grid->posts = malloc(grid->total_posts * sizeof(int));
    if(grid->posts == NULL) {
        free(grid); 
        return grid;
    }

    for(unsigned int i = 0; i < grid->total_posts; i++)
        grid->posts[i] = 0;

    return grid;

}

int coord_to_index(int width, int x, int y){
    return y * width + x; 
}

void index_to_coord(int index, int width, int *x, int *y){
    *x = index % width;
    *y = index / width;
}

int add_post(Grid *grid, int x, int y, int post_id){
   if(grid == NULL || x < 0 || x >= grid->width || y < 0 || y >= grid->height) return 0;

   int index = coord_to_index(grid->width, x, y); 
   grid->posts[index] = post_id;
   return 1;
}

int get_post(Grid *grid, int x, int y){
    if (grid == NULL || x < 0 || x >= grid->width || y < 0 || y >= grid->height)
        return -1;

    int index = coord_to_index(grid->width, x, y); 
    return grid->posts[index];

}

// printing the grid
void print(Grid *grid){
    if(grid == NULL) return;

    printf("printing the %dx%d grid system\n", grid->width, grid->height);
    for(unsigned int y = 0; y < grid->height; y++){
        for(unsigned int x = 0; x < grid->width; x++){
            int post_id = get_post(grid, x, y); 
            printf("%3d", post_id); 
        }
        printf("\n");
    }
}

void freeGrid(Grid *grid){
    if(grid == NULL) {
        free(grid);
        grid = NULL;
    }
}

int main(void){
    int width = 5; 
    int height = 9; 

    // initializing the grid
    Grid *grid = create_grid(width, height);

    // adding posts w/ coords
    add_post(grid, 4, 5, 54);
    add_post(grid, 1, 3, 98);
    add_post(grid, 2, 8, 11);

    int x, y;
    index_to_coord(12, grid->width, &x, &y); // Index 12 -> coordinates
    printf("Index 5 corresponds to position (%d, %d)\n", x, y);
    printf("Position (%d, %d) has post ID: %d\n", 4, 5, get_post(grid, 4, 5));

    print(grid); 

    freeGrid(grid);
}