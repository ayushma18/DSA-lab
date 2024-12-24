#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int coeff;  // Coefficient
    int power;  // Power
    Node* next;

    Node(int c, int p) {
        coeff = c;
        power = p;
        next = nullptr;
    }
};

// Function to add a new term to the polynomial
void addTerm(Node*& head, int coeff, int power) {
    Node* newNode = new Node(coeff, power);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the polynomial
void displayPolynomial(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->coeff << "x^" << temp->power;
        if (temp->next) {
            cout << " + ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    // Traverse both linked lists
    while (poly1 && poly2) {
        if (poly1->power > poly2->power) {
            addTerm(result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else if (poly1->power < poly2->power) {
            addTerm(result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else {
            // Powers are the same; add coefficients
            int sumCoeff = poly1->coeff + poly2->coeff;
            addTerm(result, sumCoeff, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms of poly1
    while (poly1) {
        addTerm(result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    // Add remaining terms of poly2
    while (poly2) {
        addTerm(result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    // First polynomial: 3x^3 + 5x^2 + 6
    addTerm(poly1, 3, 3);
    addTerm(poly1, 5, 2);
    addTerm(poly1, 6, 0);

    // Second polynomial: 4x^3 + 2x^1 + 3
    addTerm(poly2, 4, 3);
    addTerm(poly2, 2, 1);
    addTerm(poly2, 3, 0);

    cout << "First Polynomial: ";
    displayPolynomial(poly1);

    cout << "Second Polynomial: ";
    displayPolynomial(poly2);

    // Add the two polynomials
    Node* result = addPolynomials(poly1, poly2);

    cout << "Resultant Polynomial: ";
    displayPolynomial(result);

    return 0;
}
