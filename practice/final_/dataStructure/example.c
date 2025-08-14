// arrays, dynamic arrays + linked lists
// structs + memory management
// 2d arrays -> 1d
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int user_id; 
    char username[30];
    char email[50];
    int follower_count;
    int is_verified;
} User; 

// dynamic array, where capacity (total space) vs. count (actual items)
typedef struct { 
    User* users; 
    int count;
    int capacity; 
} UserDatabase;

// linked lists: for connections, where each users has a linked list of followers
typedef struct FollowerNode{
    int follower_id;
    struct FollowerNode* next; 
} FollowerNode;

// 2d grid as 1d array, where the user's feed is displayed as a grid
typedef struct {
    int* posts; 
    int width;
    int height; 
    int total_posts; 
} FeedGrid; 

// function 1: dynamic array management
// create user database w/ initial capacity

UserDatabase *create_user_database(int initiial_capacity){
    UserDatabase *db = malloc(sizeof(UserDatabase));
    if(db == NULL) return NULL; 

    // allocate space for user array
    db->users = malloc(initiial_capacity * sizeof(User));
    if(db->users == NULL){
        free(db);
        db = NULL; 
    } 

    db->count = 0;  // no users yet
    db->capacity = initiial_capacity;
    return db;
}

int add_user(UserDatabase *db, int id, const char *username, const char *email){
    if(db == NULL) return 0;

    // check if we need more space
    if(db->count == db->capacity){
        int new_capacity = db->capacity * 2;        // double up the capacity
        User* new_users = realloc(db->users, new_capacity * sizeof(User));
        if(new_users == NULL) return 0; 

        db->users = new_users; 
        db->capacity = new_capacity;
        printf("data resized from %d to %d capacity\n", db->capacity/2, db->capacity);
    }

    // add the new user
    User *new_user = &db->users[db->count];
    new_user->user_id = id; 
    strncpy(new_user->username, username, sizeof(new_user->username)-1); 
    new_user->username[sizeof(new_user->username)-1] = '\0'; 

    strncpy(new_user->email, email, sizeof(new_user->email)-1);
    new_user->email[sizeof(new_user->email)-1] = '\0';
    new_user->follower_count = 0;
    new_user->is_verified = 0; 
    
    db->count++; 
    return 1;

}

// find user by ID (linear search - O(n))
User *find_user_by_id(UserDatabase *db, int user_id){
    if(db == NULL) return NULL; 

    for(int i = 0; i < db->count; i++){
        if(db->users[i].user_id == user_id){
            
            return &db->users[i];       // return pointer to user
        }
    }

    return NULL;        // not found
}

// Print database statistics
void print_db_stats(UserDatabase *db)
{
    if (db == NULL)
        return;

    printf("\n📊 Database Stats:\n");
    printf("   Users: %d/%d (%.1f%% full)\n",
           db->count, db->capacity,
           (float)db->count / db->capacity * 100);
    printf("   Memory usage: %zu bytes\n",
           db->capacity * sizeof(User));
}


// linked list: insert, delete + traverse
FollowerNode *add_follower(FollowerNode *head, int follower_id)
{
    // create new node
    FollowerNode *new_node = malloc(sizeof(FollowerNode));

    if (new_node == NULL)
        return head;

    new_node->follower_id = follower_id;
    new_node->next = head; // insert at beginning

    return new_node;
}

FollowerNode *remove_follower(FollowerNode *head, int follower_id){
    if(head == NULL) return NULL; 

    if(head->follower_id == follower_id){
        FollowerNode *new_head = head->next; 
        free(head);
        return new_head; 
    }

    FollowerNode*curr = head; 
    while(curr->next != NULL && curr->next->follower_id != follower_id)
        curr = curr->next; 

    if(curr->next != NULL){
        FollowerNode *to_remove = curr->next;
        curr->next = to_remove->next; 
        free(to_remove);
    }
    return head; 

}

int count_followers(FollowerNode *head){
    int count = 0; 
    FollowerNode *curr = head; 
    while(curr != NULL){
        count++;
        curr =curr->next;
    }

    return count;
}

// Print all followers
void print_followers(FollowerNode *head)
{
    printf("Followers: ");
    FollowerNode *current = head;
    while (current != NULL)
    {
        printf("%d", current->follower_id);
        if (current->next != NULL)
            printf(" -> ");
        current = current->next;
    }
    printf(" -> NULL\n");
}

// Free entire follower list
void free_followers(FollowerNode *head)
{
    while (head != NULL)
    {
        FollowerNode *next = head->next;
        free(head);
        head = next;
    }
}

// 2d grid -> 1d array

FeedGrid *create_feed_grid(int width, int height){
    // allocating memory for grid
    FeedGrid *grid = malloc(sizeof(FeedGrid)); 

    // check if allocation was successful
    if(grid == NULL) return NULL; 

    // set the fields
    grid->width = width; 
    grid->height = height; 
    grid->total_posts = width * height; 


    // allocate 1d array to represent 2d grid
    grid->posts = malloc(grid->total_posts * sizeof(int));
    // check if allocation was successfull
    if(grid->posts == NULL){
        free(grid); 
        return NULL; 
    }

    // initialize every block with 0
    for(int i = 0; i < grid->total_posts; i++)
        grid->posts[i] = 0; 
    
    return grid;
}

int grid_coord_to_index(int x, int y, int width)
{
    return y * width + x; // Row-major order
}

void grid_index_to_coord(int index, int width, int *x, int *y)
{
    *x = index % width;
    *y = index / width;
}

// Add post at specific grid position
int add_post_at_position(FeedGrid *grid, int x, int y, int post_id)
{
    if (grid == NULL || x < 0 || x >= grid->width || y < 0 || y >= grid->height)
    {
        return 0; // Invalid position
    }

    int index = grid_coord_to_index(x, y, grid->width);
    grid->posts[index] = post_id;
    return 1; // Success
}

// Get post at specific position
int get_post_at_position(FeedGrid *grid, int x, int y)
{
    if (grid == NULL || x < 0 || x >= grid->width || y < 0 || y >= grid->height)
    {
        return -1; // Invalid position
    }

    int index = grid_coord_to_index(x, y, grid->width);
    return grid->posts[index];
}

// Print grid (visualize the 2D structure)
void print_feed_grid(FeedGrid *grid)
{
    if (grid == NULL)
        return;

    printf("\n📱 Feed Grid (%dx%d):\n", grid->width, grid->height);
    for (int y = 0; y < grid->height; y++)
    {
        for (int x = 0; x < grid->width; x++)
        {
            int post_id = get_post_at_position(grid, x, y);
            printf("%3d ", post_id);
        }
        printf("\n");
    }
}

// Free grid memory
void free_feed_grid(FeedGrid *grid)
{
    if (grid != NULL)
    {
        free(grid->posts);
        free(grid);
    }
}

void demonstrate_everything()
{
    printf("🚀 SOCIAL MEDIA PLATFORM DEMO - All Concepts Combined!\n");
    printf("======================================================\n");

    // 1️⃣ CREATE DATABASE (Dynamic Array)
    printf("\n1️⃣ Creating user database...\n");
    UserDatabase *db = create_user_database(2); // Start small to test resizing
    print_db_stats(db);

    // 2️⃣ ADD USERS (Watch array resize!)
    printf("\n2️⃣ Adding users (watch for auto-resize)...\n");
    add_user(db, 101, "alice_dev", "alice@email.com");
    add_user(db, 102, "bob_coder", "bob@email.com");
    print_db_stats(db);

    add_user(db, 103, "charlie_ai", "charlie@email.com"); // This should trigger resize!
    print_db_stats(db);

    // 3️⃣ FIND USERS (Struct manipulation)
    printf("\n3️⃣ Finding and updating users...\n");
    User *alice = find_user_by_id(db, 101);
    if (alice != NULL)
    {
        alice->is_verified = 1;
        alice->follower_count = 150;
        printf("✅ Found and verified user: %s\n", alice->username);
    }

    // 4️⃣ LINKED LISTS (Follower relationships)
    printf("\n4️⃣ Managing follower relationships...\n");
    FollowerNode *alice_followers = NULL;
    alice_followers = add_follower(alice_followers, 102); // Bob follows Alice
    alice_followers = add_follower(alice_followers, 103); // Charlie follows Alice
    alice_followers = add_follower(alice_followers, 104); // User 104 follows Alice

    printf("Alice's ");
    print_followers(alice_followers);
    printf("Alice has %d followers\n", count_followers(alice_followers));

    // Remove a follower
    alice_followers = remove_follower(alice_followers, 103);
    printf("After Charlie unfollowed: ");
    print_followers(alice_followers);

    // 5️⃣ 2D GRID AS 1D (Feed system)
    printf("\n5️⃣ Creating social media feed grid...\n");
    FeedGrid *feed = create_feed_grid(4, 3); // 4x3 grid

    // Add some posts
    add_post_at_position(feed, 0, 0, 501); // Post 501 at top-left
    add_post_at_position(feed, 2, 1, 502); // Post 502 at middle
    add_post_at_position(feed, 3, 2, 503); // Post 503 at bottom-right

    print_feed_grid(feed);

    // Test coordinate conversion
    printf("\nTesting coordinate conversion:\n");
    int x, y;
    grid_index_to_coord(5, feed->width, &x, &y); // Index 5 -> coordinates
    printf("Index 5 corresponds to position (%d, %d)\n", x, y);
    printf("Position (%d, %d) has post ID: %d\n", x, y, get_post_at_position(feed, x, y));

    // 6️⃣ MEMORY CLEANUP (Crucial!)
    printf("\n6️⃣ Cleaning up memory...\n");
    free_followers(alice_followers);
    free_feed_grid(feed);

    // Free user database
    if (db != NULL)
    {
        free(db->users);
        free(db);
    }
    printf("✅ All memory freed successfully!\n");
}

int main(void)
{
    demonstrate_everything();
    return 0;

}