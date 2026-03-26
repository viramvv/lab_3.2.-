#include "list.h"
#include <iostream>

// Додавання елемента в кінець (ітераційно)
void appendNode(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Створення списку з набору значень
Node* createList(const std::vector<int>& values) {
    Node* head = nullptr;
    for (int val : values) {
        appendNode(head, val);
    }
    return head;
}

// Виведення списку на екран
void printList(const Node* head) {
    const Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Перевірка на сусідні дублікати
bool hasAdjacentDuplicates(const Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    const Node* current = head;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            return true; 
        }
        current = current->next;
    }
    return false;
}

// Видалення списку (звільнення пам'яті)
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}