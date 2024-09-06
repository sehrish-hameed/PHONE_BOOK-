#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char firstname[210];
    char lastname[210];
    long int number;
    struct node *next;
};

struct node *head = NULL;

struct node *getnode() {
    return (struct node *)malloc(sizeof(struct node));
}

void display(struct node *head) {
    struct node *temp = head;
    if (temp == NULL) {
        printf("Phone book is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("First name: %s\n", temp->firstname);
        printf("Last name: %s\n", temp->lastname);
        printf("Number: %ld\n", temp->number);
        temp = temp->next;
    }
}

void insert() {
    struct node *temp, *newnode;
    newnode = getnode();
    printf("Enter First name:\n");
    scanf("%s", newnode->firstname);
    printf("Enter Last name:\n");
    scanf("%s", newnode->lastname);
    printf("Enter number:\n");
    scanf("%ld", &newnode->number);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Contact added successfully.\n");
}

void search() {
    struct node *temp;
    char first[210], last[210];
    temp = head;
    printf("Enter name to be searched:\n");
    scanf("%s", first);
    scanf("%s", last);
    while (temp != NULL && (strcmp(temp->firstname, first) != 0 || strcmp(temp->lastname, last) != 0)) {
        temp = temp->next;
    }
    if (temp != NULL) {
        printf("First name: %s\n", temp->firstname);
        printf("Last name: %s\n", temp->lastname);
        printf("Number: %ld\n", temp->number);
    } else {
        printf("Contact not found\n");
    }
}

void del() {
    struct node *pretemp = NULL, *temp = head;
    char f[210], l[210];
    printf("Enter name to be deleted:\n");
    scanf("%s", f);
    scanf("%s", l);
    
    // If the list is empty
    if (head == NULL) {
        printf("Contact not found\n");
        return;
    }
    
    // Check if the head is the node to be deleted
    if (strcmp(head->firstname, f) == 0 && strcmp(head->lastname, l) == 0) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Contact deleted successfully.\n");
        return;
    }

    // Traverse the list to find the node
    while (temp != NULL && (strcmp(temp->firstname, f) != 0 || strcmp(temp->lastname, l) != 0)) {
        pretemp = temp;
        temp = temp->next;
    }
    
    if (temp != NULL) {
        pretemp->next = temp->next;
        free(temp);
        printf("Contact deleted successfully.\n");
    } else {
        printf("Contact not found\n");
    }
}

void rename_contact() {
    struct node *temp;
    char first[210], last[210];
    temp = head;
    printf("Enter name to be renamed:\n");
    scanf("%s", first);
    scanf("%s", last);
    
    // If the list is empty
    if (head == NULL) {
        printf("Contact not found\n");
        return;
    }
    
    // Traverse the list to find the node
    while (temp != NULL && (strcmp(temp->firstname, first) != 0 || strcmp(temp->lastname, last) != 0)) {
        temp = temp->next;
    }
    
    if (temp != NULL) {
        printf("Enter new First name:\n");
        scanf("%s", temp->firstname);
        printf("Enter new Last name:\n");
        scanf("%s", temp->lastname);
        printf("Contact renamed successfully\n");
    } else {
        printf("Contact not found\n");
    }
}

int main() {
    int op, ch;
    do {
        printf("-------Welcome--------\n");
        printf("1. Create\n2. Display\n3. Delete\n4. Search\n5. Rename\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insert(); break;
            case 2: display(head); break;
            case 3: del(); break;
            case 4: search(); break;
            case 5: rename_contact(); break;
            default: printf("Invalid choice\n"); break;
        }
        printf("Do you want to quit? 1 for no / 0 for yes:");
        scanf("%d", &op);
    } while (op);
    return 0;
}