#include <iostream>
#include <cassert>
#include "stack.h"


class Stack {
private:
    int* data;   // Динамический массив для хранения данных
    int size;    // Размер стека
    int capacity; // Вместимость стека

public:
    // Конструктор по умолчанию
    Stack() : data(nullptr), size(0), capacity(0) {}

    // Конструктор с заданной вместимостью
    explicit Stack(int capacity) : data(new int[capacity]), size(0), capacity(capacity) {}

    // Деструктор
    ~Stack() {
        delete[] data;
    }

    // Копирующий конструктор
    Stack(const Stack& other) : data(new int[other.capacity]), size(other.size), capacity(other.capacity) {
        std::copy(other.data, other.data + other.size, data);
    }

    // Оператор присваивания
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] data;
            data = new int[other.capacity];
            size = other.size;
            capacity = other.capacity;
            std::copy(other.data, other.data + other.size, data);
        }
        return *this;
    }

    // Метод добавления элемента в стек
    void push(int value) {
        if (size == capacity) {
            // Если стек заполнен, увеличиваем его размер
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            resize(newCapacity);
        }
        data[size++] = value;
    }

    // Метод изъятия элемента из стека
    void pop() {
        assert(size > 0 && "Trying to pop from an empty stack");
        --size;
    }

    // Оператор вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack) {
        os << "Stack: ";
        for (int i = 0; i < stack.size; ++i) {
            os << stack.data[i] << " ";
        }
        return os;
    }

    // Оператор ввода из потока
    friend std::istream& operator>>(std::istream& is, Stack& stack) {
        int value;
        is >> value;
        stack.push(value);
        return is;
    }

    // Операторы сравнения
    bool operator<(const Stack& other) const {
        return size < other.size;
    }

    bool operator==(const Stack& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    // Оператор доступа к элементу по индексу
    int operator[](int index) const {
        assert(index >= 0 && index < size && "Index out of bounds");
        return data[index];
    }

private:
    // Метод изменения размера стека
    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        std::copy(data, data + size, newData);
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
};

int main() {
    Stack stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    Stack stack2;
    stack2.push(10);
    stack2.push(20);

    std::cout << "Stack 1: " << stack1 << std::endl;
    std::cout << "Stack 2: " << stack2 << std::endl;

    if (stack1 < stack2) {
        std::cout << "Stack 1 is smaller than Stack 2." << std::endl;
    }
    else if (stack1 == stack2) {
        std::cout << "Stack 1 is equal to Stack 2." << std::endl;
    }
    else {
        std::cout << "Stack 1 is larger than Stack 2." << std::endl;
    }

    std::cout << "Element at index 1 in Stack 1: " << stack1[1] << std::endl;

    return 0;
}
