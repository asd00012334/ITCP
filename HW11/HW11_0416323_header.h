#include <stdlib.h>
#include <stdio.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* insert(int value, struct Node* head);
struct Node* reverse(struct Node* head);
struct Node* remove_a(struct Node* head);
void traverse(struct Node* temp);
struct Node* reverse_r(struct Node* head);
void insert_r(int value,struct Node* head);

