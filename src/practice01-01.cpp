#include <iostream>
#include <type_traits>

template <typename T>
struct Fun {
	constexpr static size_t value = sizeof(T);
};

int main()
{
	std::cout << Fun<int>::value << std::endl;
	std::cout << Fun<double>::value << std::endl;

	system("pause");
}