#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode *next;
};

struct PolyNode* createNode(int coeff, int exp) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertPoly(struct PolyNode** poly, int coeff, int exp) {
    struct PolyNode* newNode = createNode(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } 
    else {
        struct PolyNode* current = *poly;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        if (current->exp == exp) {
            current->coeff += coeff;  // Combine coefficients if exponents match
            free(newNode);
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

struct PolyNode* addPolynomials(struct PolyNode* p1, struct PolyNode* p2) {
    struct PolyNode* result = NULL;
    while (p1 || p2) {
        int coeff = 0, exp = 0;
        if (p1 && (!p2 || p1->exp > p2->exp)) {
            coeff = p1->coeff;
            exp = p1->exp;
            p1 = p1->next;
        } else if (p2 && (!p1 || p1->exp < p2->exp)) {
            coeff = p2->coeff;
            exp = p2->exp;
            p2 = p2->next;
        } else {
            coeff = p1->coeff + p2->coeff;
            exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        insertPoly(&result, coeff, exp);
    }
    return result;
}

void displayPoly(struct PolyNode* poly) {
    struct PolyNode* current = poly;
    while (current) {
        printf("%dx^%d", current->coeff, current->exp);
        current = current->next;
        if (current) printf(" + ");
    }
    printf("\n");
}

int main() {
    struct PolyNode* poly1 = NULL;
    struct PolyNode* poly2 = NULL;
    struct PolyNode* result = NULL;
    int n, coeff, exp;

    printf("Enter number of terms in polynomial 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertPoly(&poly1, coeff, exp);
    }

    printf("Enter number of terms in polynomial 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertPoly(&poly2, coeff, exp);
    }

    result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPoly(result);

    return 0;
}