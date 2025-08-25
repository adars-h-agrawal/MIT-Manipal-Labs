#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int pow;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int coeff, int pow) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertEnd(Node** header, int coeff, int pow) {
    Node* newNode = createNode(coeff, pow);
    if (*header == NULL) {
        *header = newNode;
    } else {
        Node* last = (*header)->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = *header;
        (*header)->prev = newNode;
    }
}

void display(Node* header) {
    Node* temp = header;
    if (temp == NULL) return;
    do {
        printf("%dx^%d ", temp->coeff, temp->pow);
        if (temp->next != header) printf("+ ");
        temp = temp->next;
    } while (temp != header);
    printf("\n");
}

void multiplyPolynomials(Node* poly1, Node* poly2, Node** result) {
    Node* temp1 = poly1;
    Node* temp2;
    
    if (poly1 == NULL || poly2 == NULL) return;
    
    do {
        temp2 = poly2;
        do {
            int coeff = temp1->coeff * temp2->coeff;
            int pow = temp1->pow + temp2->pow;
            insertEnd(result, coeff, pow);
            temp2 = temp2->next;
        } while (temp2 != poly2);
        temp1 = temp1->next;
    } while (temp1 != poly1);
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n, coeff, pow;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and pow for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertEnd(&poly1, coeff, pow);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and pow for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertEnd(&poly2, coeff, pow);
    }

    printf("First Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);

    multiplyPolynomials(poly1, poly2, &result);

    printf("Result of Multiplication: ");
    display(result);

    return 0;
}
