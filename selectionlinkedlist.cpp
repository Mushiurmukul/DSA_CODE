#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void push(Node** headRef, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void selectionSort(Node** headRef) {
    Node* temp = *headRef;
    Node* minNode;
    int minData;

    while (temp != NULL) {
        minNode = temp;
        minData = temp->data;

        Node* curr = temp->next;
        while (curr != NULL) {
            if (curr->data < minData) {
                minNode = curr;
                minData = curr->data;
            }
            curr = curr->next;
        }

        minNode->data = temp->data;
        temp->data = minData;

        temp = temp->next;
    }
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 1);
    push(&head, 1);

    cout << "Unsorted list: ";
    printList(head);

    selectionSort(&head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
