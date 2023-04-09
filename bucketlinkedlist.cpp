#include <iostream>
#include <vector>
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

// Function to implement Bucket sort using linked list
void bucketSort(int arr[], int n, int numBuckets) {
    // Create an array of vectors to represent the buckets
    vector<Node*> buckets(numBuckets, NULL);
    
    // Distribute the elements of the input array into the buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / numBuckets;
        addNode(&buckets[bucketIndex], arr[i]);
    }
    
    // Sort each bucket using Insertion sort
    for (int i = 0; i < numBuckets; i++) {
        Node* head = buckets[i];
        Node* prev = NULL;
        Node* cur = head;
        
        while (cur != NULL) {
            Node* next = cur->next;
            if (prev == NULL || prev->data <= cur->data) {
                prev = cur;
                cur = next;
            }
            else {
                if (head == cur)
                    head = next;
                else
                    prev->next = next;
                Node* tmp = head;
                Node* prevTmp = NULL;
                while (tmp != next && tmp->data <= cur->data) {
                    prevTmp = tmp;
                    tmp = tmp->next;
                }
                if (prevTmp == NULL)
                    head = cur;
                else
                    prevTmp->next = cur;
                cur->next = tmp;
                prev = cur;
                cur = next;
            }
        }
        
        buckets[i] = head;
    }
    
    // Merge the buckets into the output array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        Node* head = buckets[i];
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
    int arr[] = {21, 17, 13, 19, 15, 11, 27, 23, 29, 25,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int numBuckets = 7;
    
    cout << "Input array: ";
    printArray(arr, n);
    
    bucketSort(arr, n, numBuckets);
    
    cout << "Output array: ";
    printArray(arr, n);
    
    return 0;
}
