#include <iostream>
#include <string>
using namespace std;
// Функция для реализации функции `strcpy()`
char *strcpy (char *dst, char *src) {
    // указатель, указывающий на начало строки назначения
    char *r=dst;
    // копируем строку, на которую указывает источник, в массив
    // указывает пункт назначения
    while (*src!='\0') {
        *dst=*src; dst++; src++;
    }
    // включить завершающий нулевой символ
    *dst='\0';
    // пункт назначения возвращается стандартным `strcpy()`
    return r;
}

int main() {
    const int MAX_LENGTH = 100;
    char strSource[MAX_LENGTH];
    char strDestination[MAX_LENGTH];

    std::cout << "Enter the line to copy: ";
    std::cin.getline(strSource, MAX_LENGTH);

    strcpy(strDestination, strSource);

    std::cout << "Copy result: " << strDestination << std::endl;

    return 0;
}


