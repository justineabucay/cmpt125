#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int user_id;
    char username[30];
    char email[50];
    int follower_count;
    int is_verified;
} User; 

typedef struct {
    User *users; 
    int userCount;
    int size;
} UserDatabase;


typedef struct node {
    int id;
    struct node* next;
} node; 
// creating user data base using initial capacity

UserDatabase *create(int initial_size){
    UserDatabase *db = malloc(sizeof(UserDatabase));
    if(db == NULL) return NULL; 

    db->users = malloc(initial_size * sizeof(User));
    if(db->users == NULL){
        free(db);
        db = NULL;
    }

    db->size = initial_size;
    db->userCount = 0; 

    return db;

}

int add_users(UserDatabase *db, int id, const char *username, const char *email){
    if(db == NULL) return 0;
     
    // check if space is already full
    // if full, resize

    if(db->size == db->userCount){
        int new_size = db->size * 2; 
        User *new_users = realloc(db->users, new_size * sizeof(User));
        if(new_users == NULL) return 0;

        db->users = new_users;
        db->size = new_size;
    }

    // adding new user
    User *new_user = &db->users[db->userCount];      // adding at the end (append)

    // setting its field
    new_user->user_id = id; 

    // copying username from another string
    strncpy(new_user->username, username, sizeof(new_user->username)-1); 
    new_user->username[sizeof(new_user->username)-1] = '\0';

    // copying email from another string
    strncpy(new_user->email, email, sizeof(new_user->email)-1);
    new_user->email[sizeof(new_user->email)-1] = '\0';

    new_user->follower_count = 0;
    new_user->is_verified = 0;

    db->userCount++;
    return 1;

}

// finding user by their id through linear search - O(n)
User *find_user(UserDatabase *db, int user_id){
    if(db == NULL) return NULL;

    for(int i = 0; i < db->userCount; i++){
        if(db->users[i].user_id == user_id){
            return &db->users[i];
        }
    }

    return NULL;
}

void print_db(UserDatabase *db)
{
    if (db == NULL)
        return;

    printf("Users: %d/%d\n",
           db->userCount, db->size);
}

// linked lists: insert, delete + traverse
node *add(node *head, int id){
    node *new_node = malloc(sizeof(node)); 
    if(new_node == NULL) return head;
    new_node->id = id;
    new_node->next = head;

    return new_node;
}


node *removeNode(node *head, int id){
    if(head == NULL) return NULL; 

    if(head->id == id){
        node *new_head = head->next;
        free(head); 
        return new_head;
    }

    node *curr = head; 
    while(curr->next != NULL && curr->next->id != id)
        curr = curr->next;

    if(curr->next != NULL){
        node *to_remove = curr->next;
        curr->next = to_remove->next;
        free(to_remove);
    }

    return head;
}


int count(node *head){
    int count = 0; 
    node *curr = head; 
    while(curr != NULL){
        count++;
        curr = curr->next;
    }

    return count;
}

void printData(node *head){
    node *curr = head;
    while(curr != NULL){
        printf("%d", curr->id); 
        if(curr->next != NULL)
            printf(" -> ");
        curr = curr->next;

    }
    printf(" -> NULL\n");
}

void freeAll(node *head){
    while(head != NULL){
        node *next = head->next; 
        free(head);
        head = next; 
    }
}

int main(void){
    int initial_size = 2;
    printf("creating user database...\n");
    UserDatabase *db = create(initial_size); 
    print_db(db);

    printf("\n2️⃣ Adding users...\n");
    add_users(db, 101, "alice_dev", "alice@email.com");
    add_users(db, 102, "bob_coder", "bob@email.com");
    print_db(db);

    add_users(db, 103, "charlie_ai", "charlie@email.com"); // This should trigger resize!
    print_db(db);

    User *alice = find_user(db, 101);
   
    if (alice != NULL)
    {
        alice->is_verified = 1;
        alice->follower_count = 150;
        printf("✅ Found and verified user: %s\n", alice->email);
    }

    // linked lists
    node *alice_followers = NULL;
    alice_followers = add(alice_followers, 102);
    alice_followers = add(alice_followers, 103);
    alice_followers = add(alice_followers, 104);
    printf("\nprinting followers: ");
    printData(alice_followers);

    alice_followers = removeNode(alice_followers, 102);

    printf("\nprinting followers after a user unfollowed: ");
    printData(alice_followers);

    freeAll(alice_followers);

    // memory clean up
    if (db != NULL)
    {
        free(db->users);
        free(db);
    }

    return 0; 
}