#include".\HW11_0416323_header.h"

struct Node* insert(int value, struct Node* head){
    if(head==NULL){
        head=(struct Node*)malloc(sizeof(struct Node));
        head->data=value;
        head->next=NULL;
        return head;
    }else if(head->next==NULL){
        head->next=(struct Node*)malloc(sizeof(struct Node));
        head->next->next=NULL;
        head->next->data=value;
    }else{
        insert(value,head->next);
    }
    return head;
}


struct Node* reverse(struct Node* head){
    struct Node* output;
    output=reverse_r(head);
    head->next=NULL;
    return output;
}

struct Node* reverse_r(struct Node* head){
    if(head==NULL)
        return head;
    else if(head->next==NULL)
        return head;
    else {
        struct Node* output;
        output=reverse_r(head->next);
        head->next->next=head;
        return output;
    }
}

struct Node* remove_a(struct Node* head){
    struct Node *del,*latt;
    if(head==NULL)
        return head;
    if(head->next==NULL)
        return head;
    else{
        latt=head->next;
        del=NULL;
    }
    while(1){
        if(latt==NULL)
            break;
        if(head->data!=latt->data)
            break;
        del=latt;
        latt=latt->next;
        head->next=latt;
        free(del);
    }
    remove_a(head->next);
    return head;
}

void traverse(struct Node* temp){
    if(temp==NULL){
        printf("NULL\n");
        return;
    }
    else{
        printf("%d ---> ",temp->data);
        traverse(temp->next);
        return;
    }
}

