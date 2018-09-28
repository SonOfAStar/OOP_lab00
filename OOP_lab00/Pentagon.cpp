#include <cstdlib>
#include <iostream>
#include "Triangle.h"
#include "Pentagon.h"
#include <math.h>

Pentagon::Pentagon() : Pentagon(0, 0, 0, 0, 0, 0, 0, 0, 0, 0) {
}

Pentagon::Pentagon(double i_x, double j_x, double k_x, double l_x, double m_x, double i_y, double j_y, double k_y, double l_y, double m_y) :
	a_x(i_x), a_y(i_y), b_x(j_x), b_y(j_y), c_x(k_x), c_y(k_y), d_x(l_x), d_y(l_y), e_x(m_x), e_y(m_y) {
	std::cout << "Pentagon created:  point A: " << a_x << ", " << a_y << std::endl;
	std::cout << "Pentagon created:  point B: " << b_x << ", " << b_y << std::endl;
	std::cout << "Pentagon created:  point C: " << c_x << ", " << c_y << std::endl;
	std::cout << "Pentagon created:  point D: " << d_x << ", " << d_y << std::endl;
	std::cout << "Pentagon created:  point E: " << e_x << ", " << e_y << std::endl;
}

Pentagon::Pentagon(std::istream &is) {
	is >> a_x >> a_y;
	is >> b_x >> b_y;
	is >> c_x >> c_y;
	is >> d_x >> d_y;
	is >> e_x >> e_y;
}

Pentagon::Pentagon(const Pentagon& orig) {
	std::cout << "Pentagon copy created" << std::endl;
	a_x = orig.a_x;
	a_y = orig.a_y;
	b_x = orig.b_x;
	b_y = orig.b_y;
	c_x = orig.c_x;
	c_y = orig.c_y;
	d_x = orig.d_x;
	d_y = orig.d_y;
	e_x = orig.e_x;
	e_y = orig.e_y;
}

double Pentagon::Square() {
	double ab, ac, ae, bc, ad, cd, de;

	ab = sqrt(pow(a_x - b_x, 2) + pow(a_y - b_y, 2));
	ac = sqrt(pow(a_x - c_x, 2) + pow(a_y - c_y, 2));
	ad = sqrt(pow(a_x - d_x, 2) + pow(a_y - d_y, 2));
	ae = sqrt(pow(a_x - e_x, 2) + pow(a_y - e_y, 2));
	bc = sqrt(pow(c_x - b_x, 2) + pow(c_y - b_y, 2));
	cd = sqrt(pow(c_x - d_x, 2) + pow(c_y - d_y, 2));
	de = sqrt(pow(e_x - d_x, 2) + pow(e_y - d_y, 2));

	double res = 0;

	Triangle *T = new Triangle(ab, ac, bc);
	res += T->Square();
	T->Set(ac, cd, ad);
	res += T->Square();
	T->Set(ad, de, ae);
	res += T->Square();
	delete T;
	return res;
}

void Pentagon::Print() {
	std::cout << "Point A: " << a_x << ", " << a_y << std::endl;
	std::cout << "Point B: " << b_x << ", " << b_y << std::endl;
	std::cout << "Point C: " << c_x << ", " << c_y << std::endl;
	std::cout << "Point D: " << d_x << ", " << d_y << std::endl;
	std::cout << "Point E: " << e_x << ", " << e_y << std::endl;

}

Pentagon::~Pentagon() {
	std::cout << "Pentagon deleted" << std::endl;
}