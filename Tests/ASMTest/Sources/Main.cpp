//
// Created by admin on 2024/8/24.
//

#include <iostream>

using byte = unsigned char;
using word = unsigned short int;
using dword = unsigned int;
using qword = unsigned long long int;

extern "C" dword _add(dword a, dword b);
extern "C" dword _sub(dword a, dword b);
extern "C" dword _mul(dword a, dword b);
extern "C" dword _div(dword a, dword b);

extern "C" void _print_byte(byte value)
{
	printf("%d\n", value);
}

extern "C" void _print_word(word value)
{
	printf("%d\n", value);
}

extern "C" void _print_dword(dword value)
{
	printf("%d\n", value);
}

extern "C" void _print_qword(qword value)
{
	printf("%lld\n", value);
}

extern "C" void _print(const char *str)
{
	puts(str);
}

int main()
{
	std::cout << "51 + 0 = " << _add(51, 0) << std::endl;
	std::cout << "200 - 2 = " << _sub(200, 2) << std::endl;
	std::cout << "5 * 20 = " << _mul(5, 20) << std::endl;
	std::cout << "5 / 1 = " << _div(5, 1) << std::endl;
	
	return 0;
}
