#include <iostream>

int main() {
    int x;
    int count = 0;
    std::cin >> x;

    __asm {
        mov eax, x;
        mov ebx, 0; счетчик с 0

        count_bits_loop:
        test eax, eax; Проверяем, не равно ли число нулю
            jz end_loop; eсли число равно нулю, завершаем цикл
            inc ebx; увеличиваем счетчик
            shr eax, 1; сдвигаем число вправо на 1 бит
            jmp count_bits_loop; переходим к следующей итерации цикла

            end_loop :
        mov count, ebx; 
    }

    std::cout << count << std::endl;
    return 0;
}
