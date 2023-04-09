#include <bits/stdc++.h>
using namespace std;

// Node class to represent each element in the linked list
class Node {
public:
    int data;
    Node* next;
};

// Function to add a new node to the linked list
void addNode(Node** headRef, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to perform bubble sort on a linked list
void bubbleSort(Node* head) {
    bool swapped = true;
    Node* ptr;
    Node* last = NULL;
    
    while(swapped) {
        swapped = false;
        ptr = head;
        
        while(ptr->next != last) {
            if(ptr->data > ptr->next->data) {
                swap(ptr->data, ptr->next->data);
                swapped = true;
            }
            ptr = ptr->next;
        }
        last = ptr;
    }
}

// Function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    addNode(&head, 10);
    addNode(&head, 5);
    addNode(&head, 30);
    addNode(&head, 20);
    addNode(&head, 3);
    
    cout << "Original list: ";
    printList(head);
    
    bubbleSort(head);
    
    cout << "Sorted list: ";
    printList(head);
    
    return 0;
}
