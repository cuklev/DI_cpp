#pragma once

class Shape {
	public:
		virtual double Perimeter() = 0;
		virtual double Area() = 0;
};

class Rect : public Shape {
	private:
		double a, b;

	public:
		Rect(double, double);
		double Perimeter() override;
		double Area() override;
};

class Circle : public Shape {
	private:
		double radius;

	public:
		Circle(double);
		double Perimeter() override;
		double Area() override;
};
