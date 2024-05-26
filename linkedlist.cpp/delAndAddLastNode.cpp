#include<iostream>
#include <bits/stdc++.h>
using namespace std;
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };
Node *delAddLastNode(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *prev = nullptr;
    Node *ptr = head;

    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    // Move the last node to the front
    ptr->next = head;
    head = ptr;
    return head;
}