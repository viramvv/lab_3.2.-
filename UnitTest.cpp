#include <gtest/gtest.h>
#include "list.h"

// Тест 1: Перевірка списку з сусідніми однаковими елементами
TEST(ListAdjacentTest, HasDuplicates) {
    Node* list = createList({1, 2, 2, 3});
    EXPECT_TRUE(hasAdjacentDuplicates(list));
    clearList(list);
}

// Тест 2: Перевірка списку без сусідніх однакових елементів
TEST(ListAdjacentTest, NoDuplicates) {
    Node* list = createList({1, 2, 3, 2, 1}); // 2 і 2 не сусідні
    EXPECT_FALSE(hasAdjacentDuplicates(list));
    clearList(list);
}

// Тест 3: Перевірка порожнього списку
TEST(ListAdjacentTest, EmptyList) {
    Node* list = nullptr;
    EXPECT_FALSE(hasAdjacentDuplicates(list));
}

// Тест 4: Перевірка списку з одного елемента
TEST(ListAdjacentTest, SingleElement) {
    Node* list = createList({10});
    EXPECT_FALSE(hasAdjacentDuplicates(list));
    clearList(list);
}

// Тест 5: Дублікати на самому початку
TEST(ListAdjacentTest, DuplicatesAtStart) {
    Node* list = createList({5, 5, 1, 2});
    EXPECT_TRUE(hasAdjacentDuplicates(list));
    clearList(list);
}

// Тест 6: Дублікати в самому кінці
TEST(ListAdjacentTest, DuplicatesAtEnd) {
    Node* list = createList({1, 2, 9, 9});
    EXPECT_TRUE(hasAdjacentDuplicates(list));
    clearList(list);
}