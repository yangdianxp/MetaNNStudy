#include <iostream>
#include <type_traits>

template <size_t... values>
constexpr size_t fun()
{
	return (0 + ... + values);
}

constexpr size_t res = fun<1, 2, 3, 4, 5>();

int main()
{
	std::cout << res << std::endl;
}