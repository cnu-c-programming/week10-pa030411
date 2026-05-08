#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[100];
    int score;
    struct Student* next;
};

void add_student(struct Student** head, char* name, int score) {
    struct Student* new_student = (struct Student*)malloc(sizeof(struct Student));
    struct Student* cur = *head;

    strcpy(new_student->name, name);
    new_student->score = score;
    new_student->next = NULL;

    if (*head == NULL) {
        *head = new_student;
        return;
    }

    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = new_student;
}

void delete_student(struct Student** head, char* name) {
    struct Student* cur = *head;
    struct Student* prev = NULL;

    while (strcmp(cur->name, name) != 0) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        *head = cur->next;
    } else {
        prev->next = cur->next;
    }
    free(cur);
}

void print_students(struct Student* head) {
    while (head != NULL) {
        printf("%s %d\n", head->name, head->score);
        head = head->next;
    }
}

void free_students(struct Student* head) {
    struct Student* next;

    while (head != NULL) {
        next = head->next;
        free(head);
        head = next;
    }
}

int main() {
    struct Student* head = NULL;
    char command[100];
    char name[100];
    int score;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            add_student(&head, name, score);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete_student(&head, name);
        } else if (strcmp(command, "print") == 0) {
            print_students(head);
        } else if (strcmp(command, "quit") == 0) {
            free_students(head);
            break;
        }
    }

    return 0;
}
