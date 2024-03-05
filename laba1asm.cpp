#include <iostream>

int main() {
    short a1, a2, a3;
    short b1, b2, b3;
    short c1, c2, c3;
    long long result;

    std::cin >> a1 >> a2 >> a3;
    std::cin >> b1 >> b2 >> b3;

    __asm {
        mov ax, a1
        add ax, b1
        mov c1, ax

        mov ax, a2
        adc ax, b2
        mov c2, ax

        mov ax, a3
        adc ax, b3
        mov c3, ax
    }

    result = ((static_cast<long long>(c3)) << 32) + ((static_cast<long long>(c2)) << 16) + static_cast<long long>(c1);

    std::cout << "10 c/c: " << '\n';
    std::cout << result << '\n';

    std::cout << "16 c/c: " << '\n';
    std::cout << std::hex << result << '\n';

    return 0;
}
