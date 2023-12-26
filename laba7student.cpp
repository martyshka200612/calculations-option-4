#include <iostream>
#include <cstring>
#include "student.h"

int Student::nextId = 1;

// Конструктор с параметрами
Student::Student(const char* studentName, int studentCourse, const char* studentGroup, int studentRecordBookNumber)
    : id(nextId++), course(studentCourse), recordBookNumber(studentRecordBookNumber) {

    name = new char[strlen(studentName) + 1];
    strcpy(name, studentName);

    group = new char[strlen(studentGroup) + 1];
    strcpy(group, studentGroup);
}

// Деструктор
Student::~Student() {
    delete[] name;
    delete[] group;
}

// Метод для отображения информации
void Student::displayInfo() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Course: " << course << std::endl;
    std::cout << "Group: " << group << std::endl;
    std::cout << "Record Book Number: " << recordBookNumber << std::endl;
}

// Set-метод для имени
void Student::setName(const char* newName) {
    delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

// Get-метод для имени
const char* Student::getName() const {
    return name;
}

// Set-метод для курса
void Student::setCourse(int newCourse) {
    course = newCourse;
}

// Get-метод для курса
int Student::getCourse() const {
    return course;
}

// Set-метод для группы
void Student::setGroup(const char* newGroup) {
    delete[] group;
    group = new char[strlen(newGroup) + 1];
    strcpy(group, newGroup);
}

// Get-метод для группы
const char* Student::getGroup() const {
    return group;
}

// Get-метод для идентификатора
int Student::getId() const {
    return id;
}

// Get-метод для номера зачетки
int Student::getRecordBookNumber() const {
    return recordBookNumber;
}
// Перегрузка оператора вывода в поток для базового класса
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "ID: " << student.getId() << std::endl;
    os << "Name: " << student.getName() << std::endl;
    os << "Course: " << student.getCourse() << std::endl;
    os << "Group: " << student.getGroup() << std::endl;
    os << "Record Book Number: " << student.getRecordBookNumber() << std::endl;
    return os;
}
// Конструктор с параметрами
StudentAfterFirstSession::StudentAfterFirstSession(const char* studentName, int studentCourse, const char* studentGroup, int studentRecordBookNumber,
    int grade1, int grade2, int grade3, int grade4)
    : Student(studentName, studentCourse, studentGroup, studentRecordBookNumber) {

    session1Grades[0] = grade1;
    session1Grades[1] = grade2;
    session1Grades[2] = grade3;
    session1Grades[3] = grade4;
}

// Метод для отображения информации
void StudentAfterFirstSession::displayInfo() const {
    Student::displayInfo();

    std::cout << "Grades after First Session: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << session1Grades[i] << " ";
    }
    std::cout << std::endl;
}
// Set-метод для оценок после первой сессии
void StudentAfterFirstSession::setSession1Grades(int grade1, int grade2, int grade3, int grade4) {
    session1Grades[0] = grade1;
    session1Grades[1] = grade2;
    session1Grades[2] = grade3;
    session1Grades[3] = grade4;
}

// Get-метод для оценок после первой сессии
void StudentAfterFirstSession::getSession1Grades(int& grade1, int& grade2, int& grade3, int& grade4) const {
    grade1 = session1Grades[0];
    grade2 = session1Grades[1];
    grade3 = session1Grades[2];
    grade4 = session1Grades[3];
}
std::ostream& StudentAfterFirstSession::operator<<(std::ostream& os) const {
    os << static_cast<const Student&>(*this);  // Выводим базовую информацию
    os << "Grades after First Session: ";
    for (int i = 0; i < 4; ++i) {
        os << session1Grades[i] << " ";
    }
    os << std::endl;
    return os;
}


// Конструктор с параметрами
StudentAfterSecondSession::StudentAfterSecondSession(const char* studentName, int studentCourse, const char* studentGroup, int studentRecordBookNumber,
    int grade1, int grade2, int grade3, int grade4, int grade5)
    : StudentAfterFirstSession(studentName, studentCourse, studentGroup, studentRecordBookNumber, grade1, grade2, grade3, grade4) {

    session2Grades[0] = grade1;
    session2Grades[1] = grade2;
    session2Grades[2] = grade3;
    session2Grades[3] = grade4;
    session2Grades[4] = grade5;
}

// Метод для отображения информации
std::ostream& StudentAfterFirstSession::operator<<(std::ostream& os) const {
    os << static_cast<const Student&>(*this);  // Выводим базовую информацию
    os << "Grades after First Session: ";
    for (int i = 0; i < 4; ++i) {
        os << session1Grades[i] << " ";
    }
    os << std::endl;
    return os;
}

// Set-метод для оценок после второй сессии
void StudentAfterSecondSession::setSession2Grades(int grade1, int grade2, int grade3, int grade4, int grade5) {
    setSession1Grades(grade1, grade2, grade3, grade4);
    session2Grades[0] = grade5;
}

// Get-метод для оценок после второй сессии
void StudentAfterSecondSession::getSession2Grades(int& grade1, int& grade2, int& grade3, int& grade4, int& grade5) const {
    getSession1Grades(grade1, grade2, grade3, grade4);
    grade5 = session2Grades[0];
}
std::ostream& StudentAfterSecondSession::operator<<(std::ostream& os) const {
    os << static_cast<const StudentAfterFirstSession&>(*this);  // Выводим информацию первого производного класса
    os << "Grades after Second Session: ";
    for (int i = 0; i < 5; ++i) {
        os << session2Grades[i] << " ";
    }
    os << std::endl;
    return os;
}

int main() {
    const int arraySize = 2; // Размер массива (количество студентов)

    // Создаем массив указателей на объекты
    Student* students[arraySize];

    // Создаем объекты и помещаем указатели на них в массив
    students[0] = new StudentAfterFirstSession("Alice", 2, "C3", 12345, 85, 92, 78, 90);
    students[1] = new StudentAfterSecondSession("Bob", 3, "D4", 98765, 75, 88, 92, 79, 84);

    // Выводим информацию о каждом студенте
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Student " << i + 1 << " Info:" << std::endl;
        students[i]->displayInfo();
        std::cout << std::endl;
    }

    // Вычисляем средний балл для массива
    double averageGrade = 0.0;
    for (int i = 0; i < arraySize; ++i) {
        averageGrade += students[i]->calculateAverageGrade();
    }
    averageGrade /= arraySize;

    // Выводим средний балл
    std::cout << "Average Grade for the Array: " << averageGrade << std::endl;

    // Освобождаем память, выделенную для объектов
    for (int i = 0; i < arraySize; ++i) {
        delete students[i];
    }

    return 0;
}
