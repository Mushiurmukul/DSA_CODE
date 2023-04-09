#include <iostream>
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
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

// Function to get the last node of the linked list
Node* getLastNode(Node* head) {
    while (head != NULL && head->next != NULL)
        head = head->next;
    return head;
}

// Function to partition the linked list and return the pivot node
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL;
    Node* cur = head;
    Node* tail = pivot;
    
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else {
            if (prev)
                prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    
    if ((*newHead) == NULL)
        (*newHead) = pivot;
    
    (*newEnd) = tail;
    return pivot;
}

// Function to implement Quick sort on a linked list
Node* quickSort(Node* head, Node* end) {
    if (!head || head == end)
        return head;
    
    Node* newHead = NULL;
    Node* newEnd = NULL;
    
    Node* pivot = partition(head, end, &newHead, &newEnd);
    
    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        newHead = quickSort(newHead, tmp);
        tmp = getLastNode(newHead);
        tmp->next = pivot;
    }
    
    pivot->next = quickSort(pivot->next, newEnd);
    
    return newHead;
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
    
    Node* sorted = quickSort(head, getLastNode(head));
    
    cout << "Sorted list: ";
    printList(sorted);
    
    return 0;
}
