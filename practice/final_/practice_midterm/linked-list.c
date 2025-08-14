#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node_t;

typedef struct
{
    Node_t *head;
    Node_t *tail;
} LinkedList_t;

bool lists_equal(LinkedList_t *list1, LinkedList_t *list2)
{
    // Your implementation - must be O(length of shorter list)
    if(list1 == NULL && list2 == NULL) return true; 
    if(list1 == NULL || list2 == NULL) return false; 

    Node_t *curr1 =list1->head;
    Node_t *curr2 = list2->head;

    while(curr1 != NULL && curr2 != NULL){
        if(curr1->data != curr2->data)
            return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return(curr1 == NULL && curr2 == NULL);
}

void append(LinkedList_t *list, int data){
    Node_t *new_node = malloc(sizeof(Node_t));
    new_node->data = data;
    new_node->next=NULL;

    if(list->head == NULL){ // if the list is empty
        list->head = new_node;  // make the head and tail the new node because the list only has one element
        list->tail = new_node;
    } else {
        list->tail->next = new_node;    // if the list is not empty, make the new_node the new tail
        list->tail = new_node;
    }

}

void prepend(LinkedList_t *list, int data){
    Node_t *new_node = malloc(sizeof(Node_t));
    new_node->data = data; 
    new_node->next = list->head; 

    list->head = new_node; 

    if(list->tail == NULL)
        list->tail = new_node;
}

void set_index(LinkedList_t *list, int index, int data){
    Node_t *curr = list->head;
 
    for(int i = 0; i < index; i++){
        curr = curr->next;
    }

    curr->data = data;
}

void remove_every_other(LinkedList_t *list){
    if(list->head == NULL && list->head->next == NULL)
        return; 

    Node_t *curr = list->head;
    while(curr != NULL && curr->next != NULL){
        Node_t *to_remove = curr->next;
        curr->next = to_remove->next;

        // removing last node
        if(to_remove == list->tail)
            list->tail = curr;
        
        free(to_remove);
        // skip one node
        curr = curr->next;
    }
}

void remove_every_third_node(LinkedList_t *list)
{
    if (list->head == NULL && list->head->next == NULL)
        return;

    Node_t *curr = list->head;
    while (curr != NULL && curr->next != NULL)
    {
        Node_t *to_remove = curr->next;
        curr->next->next = to_remove->next;

        // removing last node
        if (to_remove == list->tail)
            list->tail = curr;

        free(to_remove);
        // skip one node
        curr = curr->next->next;
    }
}
void free(LinkedList_t *list){
    if(list == NULL) return;

    Node_t *curr = list->head;
    if(curr != NULL){
        Node_t *temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(list);
}

LinkedList_t *create_list(){
    LinkedList_t *list = malloc(sizeof(LinkedList_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}