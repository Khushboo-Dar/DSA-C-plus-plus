#include <iostream>

using namespace std;

// Define the Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* newNode(int data) {
    Node* temp = new Node; // Use new operator for dynamic memory allocation
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

// Function to print the linked list (can be modified for your specific needs)
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a circular linked list (example for demonstration)
Node* createCircularList(int arr[], int n) {
    Node* head = newNode(arr[0]);
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = newNode(arr[i]);
        temp = temp->next;
    }
    // Make the last node point back to the head to create a circular list
    temp->next = head;
    return head;
}

// Function to break the circular linked list (improved version)
Node* breakCircular(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        // Handle empty or single-node lists (return the original head)
        return head;
    }

    // Find the middle node (efficient slow-fast pointer approach)
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Break the circular link at the middle node
    Node* secondHead = slow->next;
    slow->next = head;

    // Find the tail of the second list (for proper termination)
    Node* secondTail = secondHead;
    while (secondTail->next != slow) {
        secondTail = secondTail->next;
    }

    // Terminate the second list
    secondTail->next = secondHead;

    // Return the head of the first list
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createCircularList(arr, n);
    cout << "Original circular list: ";
    printList(head);

    // Break the circular list using the breakCircular function
    head = breakCircular(head);

    cout << "List 1 after breaking the circular connection: ";
    printList(head);

    // You can add further logic here to handle the second list if needed

    return 0;
}