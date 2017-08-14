#include "shapes.hpp"
#include <cmath>

Rect::Rect(double a, double b)
	: a(a), b(b) {}

double Rect::Perimeter() {
	return (a + b) * 2;
}

double Rect::Area() {
	return a * b;
}

Circle::Circle(double r)
	: radius(r) {}

double Circle::Perimeter() {
	return 2 * M_PI * radius;
}

double Circle::Area() {
	return M_PI * radius * radius;
}
