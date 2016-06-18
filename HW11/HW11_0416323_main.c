#include".\HW11_0416323_header.h"
int main() {
    struct Node* head = NULL;
    printf("Input the number of data you want to insert: ");
    int N;
    scanf("%d", &N);
    printf("Data: ");
    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        head = insert(t, head);
    }
    printf("After insert: ");
    traverse(head);

    head =reverse(head);

    printf("After reverse: ");
    traverse(head);
    head=remove_a(head);

    printf("After remove: ");
    traverse(head);
    return 0;
}

