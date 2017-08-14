#include <iostream>
#include "definitions.hpp"

int main() {
	auto x = GetInstance<Shape>(4, 6);
	std::cout << x->Area() << '\n';
}
