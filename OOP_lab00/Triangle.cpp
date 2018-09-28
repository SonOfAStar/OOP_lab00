#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : Triangle(0, 0, 0) {
}

Triangle::Triangle(double i, double j, double k) : side_a(i), side_b(j), side_c(k) {
	std::cout << "Triangle created: " << side_a << ", " << side_b << ", " << side_c << std::endl;
}

Triangle::Triangle(std::istream &is) {
	is >> side_a;
	is >> side_b;
	is >> side_c;
}

Triangle::Triangle(const Triangle& orig) {
	std::cout << "Triangle copy created" << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_c = orig.side_c;
}

double Triangle::Square() {
	double p = double(side_a + side_b + side_c) / 2.0;
	return sqrt(p * (p - double(side_a))*(p - double(side_b))*(p - double(side_c)));

}

void Triangle::Print() {
	std::cout << "a=" << side_a << ", b=" << side_b << ", c=" << side_c << std::endl;

}

void Triangle::Set(double n_a, double n_b, double n_c) {
	side_a = n_a;
	side_b = n_b;
	side_c = n_c;
}

/*void Triangle::Change(double a, double b, double c){
	side_a = a;
	side_b = b;
	side_c = c;
}*/

Triangle::~Triangle() {
	std::cout << "Triangle deleted" << std::endl;
}
