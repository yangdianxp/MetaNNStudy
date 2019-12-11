#include <iostream>
#include <type_traits>

template <typename T, int N>
struct Fun {
	constexpr static bool value = (sizeof(T) == N);
};

int main()
{
	std::cout << Fun<int, 4>::value << std::endl;
	std::cout << Fun<double, 4>::value << std::endl;

	system("pause");
}