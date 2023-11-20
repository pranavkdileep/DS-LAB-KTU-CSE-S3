#include<stdio.h>

void deleteElement(int A[], int item, int *n) {
    int loc = -1;
    for (int i = 0; i < *n; i++) {
        if (A[i] == item) {
            loc = i;
            break;
        }
    }

    if (loc == -1) {
        printf("Item not found\n");
    } else {
        for (int i = loc; i < *n - 1; i++) {
            A[i] = A[i + 1];
        }
        (*n)--;
        printf("Item deleted\n");
    }
}

void insertElement(int A[], int item, int *n, int loc) {
    for (int i = *n; i > loc; i--) {
        A[i] = A[i - 1];
    }
    A[loc] = item;
    (*n)++;
    printf("Item inserted\n");
}

void display(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[100], n, item, loc, choice;

    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    do {
        printf("Enter your choice\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to be inserted\n");
                scanf("%d", &item);
                printf("Enter the location\n");
                scanf("%d", &loc);
                insertElement(A, item, &n, loc);
                break;
            case 2:
                printf("Enter the item to be deleted\n");
                scanf("%d", &item);
                deleteElement(A, item, &n);
                break;
            case 3:
                display(A, n);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
