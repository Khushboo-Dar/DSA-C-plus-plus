
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

 class Node {
   public:
       int data;
       Node *next;
       Node *child;
       Node() : data(0), next(nullptr), child(nullptr){};
       Node(int x) : data(x), next(nullptr), child(nullptr) {}
       Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};


Node* merge(Node* down, Node* right) {
    if (down == NULL) {
        return right;
    }
    if (right == NULL) {
        return down;
    }
    
    Node* result = new Node(-1); 
    Node* temp = result;
    
    while (down != NULL && right != NULL) {
        if (down->data < right->data) {
            temp->child = down;
            down = down->child;
        } else {
            temp->child = right;
            right = right->child;
        }
        temp = temp->child;
    }
    
    while (down != NULL) {
        temp->child = down;
        down = down->child;
        temp = temp->child;
    }
    
    while (right != NULL) {
        temp->child = right;
        right = right->child;
        temp = temp->child;
    }
    
    result = result->child; 
    return result;
}

Node* flattenLinkedList(Node* head) {
    // Base case
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursively flatten the right side
    Node* right = flattenLinkedList(head->next);
    
    // Ensure the current node's next is null to avoid following the next pointer
    head->next = NULL;
    
    // Merge the current node (down list) with the flattened right list
    Node* ans = merge(head, right);
    
    return ans;
}
