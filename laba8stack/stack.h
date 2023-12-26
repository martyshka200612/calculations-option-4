#pragma once

#include <iostream>
#include <cassert>

class Stack {
private:
    int* data;   // Динамический массив для хранения данных
    int size;    // Размер стека
    int capacity; // Вместимость стека

public:
    // Конструктор по умолчанию
    Stack();

    // Конструктор с заданной вместимостью
    explicit Stack(int capacity);

    // Деструктор
    ~Stack();

    // Копирующий конструктор
    Stack(const Stack& other);

    // Оператор присваивания
    Stack& operator=(const Stack& other);

    // Метод добавления элемента в стек
    void push(int value);

    // Метод изъятия элемента из стека
    void pop();

    // Оператор вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

    // Оператор ввода из потока
    friend std::istream& operator>>(std::istream& is, Stack& stack);

    // Операторы сравнения
    bool operator<(const Stack& other) const;

    bool operator==(const Stack& other) const;

    // Оператор доступа к элементу по индексу
    int operator[](int index) const;

private:
    // Метод изменения размера стека
    void resize(int newCapacity);
};
