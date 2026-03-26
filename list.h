#ifndef LIST_H
#define LIST_H

#include <vector>

// Структура вузла
struct Node {
    int data;
    Node* next;
};

// Прототипи функцій (згідно з принципом "одна функція - одна роль")
void appendNode(Node*& head, int value);
Node* createList(const std::vector<int>& values);
void printList(const Node* head);
bool hasAdjacentDuplicates(const Node* head); // Основне завдання
void clearList(Node*& head);

#endif