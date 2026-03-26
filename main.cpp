#include <iostream>
#include "list.h"

int main() {
    // 1. Формуємо списки (тестові дані)
    Node* listA = createList({10, 20, 20, 30, 40}); // Є дублікати (20, 20)
    Node* listB = createList({1, 2, 3, 2, 1});      // Немає сусідніх дублікатів

    // 2. Роздруковуємо їх
    std::cout << "List A: ";
    printList(listA);

    std::cout << "List B: ";
    printList(listB);

    // 3. Виконуємо дію за варіантом та виводимо результат
    std::cout << "\nAnalysis of List A: ";
    if (hasAdjacentDuplicates(listA)) {
        std::cout << "Found adjacent duplicates!" << std::endl;
    } else {
        std::cout << "No adjacent duplicates." << std::endl;
    }

    std::cout << "Analysis of List B: ";
    if (hasAdjacentDuplicates(listB)) {
        std::cout << "Found adjacent duplicates!" << std::endl;
    } else {
        std::cout << "No adjacent duplicates." << std::endl;
    }

    // 4. Очищення пам'яті
    clearList(listA);
    clearList(listB);

    return 0;
}