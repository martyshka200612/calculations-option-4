#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

class Student {
private:
    static int nextId;
    const int id;
    char* name;
    int course;
    char* group;
    const int recordBookNumber;

public:
    virtual double calculateAverageGrade() const {
        return 0.0;  // Базовый класс, не содержащий оценок
    }
    // Конструктор с параметрами
    Student(const char* studentName, int studentCourse, const char* studentGroup, int studentRecordBookNumber);
    std::ostream& operator<<(std::ostream& os) const;

    // Деструктор
    ~Student();
    // В student.h:

// ...

public:
    // Set-метод для имени
    void setName(const char* newName);

    // Get-метод для имени
    const char* getName() const;

    // Set-метод для курса
    void setCourse(int newCourse);

    // Get-метод для курса
    int getCourse() const;

    // Set-метод для группы
    void setGroup(const char* newGroup);

    // Get-метод для группы
    const char* getGroup() const;

    // Get-метод для идентификатора
    int getId() const;

    // Get-метод для номера зачетки
    int getRecordBookNumber() const;

    // ...


        // Метод для отображения информации
    void displayInfo() const;

    // Set-метод для имени
    void setName(const char* newName);

    // Get-метод для имени
    const char* getName() const;

    // Set-метод для курса
    void setCourse(int newCourse);

    // Get-метод для курса
    int getCourse() const;

    // Set-метод для группы
    void setGroup(const char* newGroup);

    // Get-метод для группы
    const char* getGroup() const;

    // Get-метод для идентификатора
    int getId() const;

    // Get-метод для номера зачетки
    int getRecordBookNumber() const;

    // Конструктор копирования
    Student(const Student& other);

    // Оператор присваивания
    Student& operator=(const Student& other);
};

class StudentAfterFirstSession : public Student {
private:
    int session1Grades[4];

public:
    // Конструктор с параметрами
    StudentAfterFirstSession(const char* studentName, int studentCourse, const char* studentGroup, int studentRecordBookNumber,
        int grade1, int grade2, int grade3, int grade4);
    // Set-метод для оценок после первой сессии

    void setSession1Grades(int grade1, int grade2, int grade3, int grade4);

    // Get-метод для оценок после первой сессии
    void getSession1Grades(int& grade1, int& grade2, int& grade3, int& grade4) const;

    // Метод для отображения информации
    void displayInfo() const;

    // Конструктор копирования
    StudentAfterFirstSession(const StudentAfterFirstSession& other);

    // Оператор присваивания
    StudentAfterFirstSession& operator=(const StudentAfterFirstSession& other);

    std::ostream& operator<<(std::ostream& os) const;
    // Метод для подсчета среднего балла после первой сессии
    double calculateAverageGrade() const {
        double sum = 0.0;
        for (int i = 0; i < 4; ++i) {
            sum += session1Grades[i];
        }
        return sum / 4.0;
    }
};

class StudentAfterSecondSession : public StudentAfterFirstSession {
private:
    int session2Grades[5];
    int session1Grades[4];

public:
   

    // Конструктор с параметрами
    StudentAfterSecondSession(const char* studentName, int studentCourse, const char* studentGroup, int studentRecordBookNumber,
        int grade1, int grade2, int grade3, int grade4, int grade5);

    // Метод для отображения информации
    void displayInfo() const;

    // Set-метод для оценок после второй сессии
    void setSession2Grades(int grade1, int grade2, int grade3, int grade4, int grade5);

    // Get-метод для оценок после второй сессии
    void getSession2Grades(int& grade1, int& grade2, int& grade3, int& grade4, int& grade5) const;

    // Конструктор копирования
    StudentAfterSecondSession(const StudentAfterSecondSession& other);

    // Оператор присваивания
    StudentAfterSecondSession& operator=(const StudentAfterSecondSession& other);

    std::ostream& operator<<(std::ostream& os) const;

    double calculateAverageGrade() const {
        double sum = 0.0;
        // Сначала учитываем оценки после первой сессии
        for (int i = 0; i < 4; ++i) {
            sum += session1Grades[i];
        }
        // Затем добавляем оценки после второй сессии
        for (int i = 0; i < 5; ++i) {
            sum += session2Grades[i];
        }

        return sum / 9.0;  // Общее количество оценок после двух сессий
    }
    std::ostream& operator<<(std::ostream& os) const;
};

#endif // STUDENT_H
