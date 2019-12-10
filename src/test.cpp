#include <iostream>
#include <type_traits>

template <int... Vals> struct IntContainer;
template <bool... Vals> struct BoolContainer;
template <typename... Types> struct TypeContainer;
template <template <typename> class...T> struct TemplateCont;
template <template <typename...> class...T> struct TemplateCont2;


int main()
{

}