#include <iostream>

int main() {
	int x;
	int result;
	int result1;
	int result2;
	int result3;
	std::cin >> x;

	__asm {
		mov eax, x
		imul x
		imul x
		imul x
		imul x
		mov result, eax; первое слагаемое

		mov eax, x
		mov ecx,2
		imul x
		sub eax, 4
		imul ecx
		mov result1, eax; второе слагаемое;
	
		mov eax,result
		mov ecx, result1
		add ecx, eax;
		mov result2, ecx; сумма;

		mov eax, x
			mov ecx, result2
			add ecx, eax
			mov result2, ecx; прибавляем x;

		mov eax, x
			imul x
			imul x
		mov ecx, eax
		
		mov eax, result2
			cdq
			idiv ecx
			mov result3,eax



		
	}

	std::cout << result3;
	return 0;
}
