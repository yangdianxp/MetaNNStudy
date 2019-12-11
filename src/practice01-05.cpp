#include <iostream>
#include <type_traits>


struct test
{
	using type = int;
};

struct test1
{

};

int main()
{
	std::cout << hasType<test>() << std::endl;
	std::cout << hasType<test1>() << std::endl;

	system("pause");
}