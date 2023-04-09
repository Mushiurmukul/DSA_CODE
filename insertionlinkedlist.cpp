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

void insertionSort(Node** headRef) {
    Node* sorted = NULL;
    Node* curr = *headRef;

    while (curr != NULL) {
        Node* nextNode = curr->next;

        if (sorted == NULL || curr->data < sorted->data) {
            curr->next = sorted;
            sorted = curr;
        }
        else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }

        curr = nextNode;
    }

    *headRef = sorted;
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

    push(&head, 6);
    push(&head, 3);
    push(&head, 8);
    push(&head, 2);
    push(&head, 1);

    cout << "Unsorted list: ";
    printList(head);

    insertionSort(&head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
