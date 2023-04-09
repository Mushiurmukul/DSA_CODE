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
// Function to implement Counting sort using linked list
void countingSort(int arr[], int n, int range) {
    Node* count[range + 1] = { NULL }; // Create an array of buckets
    
    // Count the occurrences of each element in the input array
    for (int i = 0; i < n; i++) {
        addNode(&count[arr[i]], arr[i]);
    }   
    // Merge the buckets into the input array
    int index = 0;
    for (int i = 0; i <= range; i++) {
        Node* head = count[i];
        while (head != NULL) {
            arr[index++] = head->data;
            head = head->next;
        }
    }
}
// Function to print the input and output arrays
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr[] = { 4, 2, 2, 8, 3, 3, 1 ,21,2,43,24,2,1,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int range =100;
    
    cout << "Input array: ";
    printArray(arr, n);
    
    countingSort(arr, n, range);
    
    cout << "Output array: ";
    printArray(arr, n);
    
    return 0;
}
