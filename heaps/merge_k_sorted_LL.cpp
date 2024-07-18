#include <queue>
#include <vector>

// Definition of the Node class representing each node in the linked list
class Node {
public:
    int data; // Data stored in the node
    Node* next; // Pointer to the next node in the list

    // Default constructor initializes data to 0 and next to NULL
    Node() {
        this->data = 0;
        next = NULL;
    }

    // Constructor initializes data to the given value and next to NULL
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Constructor initializes data and next to the given values
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

// Custom comparator class for the priority queue
class compare {
public:
    // Overloaded operator() to compare two Node pointers based on their data
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // Return true if data in 'a' is greater than in 'b' (min-heap)
    }
};

// Function to merge k sorted linked lists
Node* mergeKLists(std::vector<Node*>& listArray) {
    // Define a priority queue (min-heap) to store Node pointers, ordered by Node data
    std::priority_queue<Node*, std::vector<Node*>, compare> minHeap;

    // Get the number of linked lists
    int k = listArray.size();
    if (k == 0) {
        return NULL; // If there are no lists, return NULL
    }

    // Push the first node of each linked list into the minHeap
    for (int i = 0; i < k; i++) {
        if (listArray[i] != NULL) { // Check if the list is not empty
            minHeap.push(listArray[i]); // Push the first node of the list into the heap
        }
    }

    Node* head = NULL; // Pointer to the head of the merged list
    Node* tail = NULL; // Pointer to the last node in the merged list

    // While there are nodes in the minHeap
    while (!minHeap.empty()) {
        // Get the node with the smallest data
        Node* temp = minHeap.top();
        minHeap.pop();

        // If the extracted node has a next node, push it into the heap
        if (temp->next != NULL) {
            minHeap.push(temp->next);
        }

        // If this is the first node, initialize the head and tail
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            // Otherwise, append the node to the merged list and update the tail
            tail->next = temp;
            tail = temp;
        }
    }

    // Return the head of the merged list
    return head;
}
