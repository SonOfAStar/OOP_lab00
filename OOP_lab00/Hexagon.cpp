#include "Hexagon.h"
#include "Triangle.h"
#include <math.h>

Hexagon::Hexagon() : Hexagon(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) {
}

Hexagon::Hexagon(double i_x, double j_x, double k_x, double l_x, double m_x, double n_x, double i_y, double j_y, double k_y, double l_y, double m_y, double n_y) :
	a_x(i_x), a_y(i_y), b_x(j_x), b_y(j_y), c_x(k_x), c_y(k_y), d_x(l_x), d_y(l_y), e_x(m_x), e_y(m_y), f_x(n_x), f_y(n_y) {
	std::cout << "Hexagon created:  point A: " << a_x << ", " << a_y << std::endl;
	std::cout << "Hexagon created:  point B: " << b_x << ", " << b_y << std::endl;
	std::cout << "Hexagon created:  point C: " << c_x << ", " << c_y << std::endl;
	std::cout << "Hexagon created:  point D: " << d_x << ", " << d_y << std::endl;
	std::cout << "Hexagon created:  point E: " << e_x << ", " << e_y << std::endl;
	std::cout << "Hexagon created:  point F: " << f_x << ", " << f_y << std::endl;
}

Hexagon::Hexagon(std::istream &is) {
	is >> a_x >> a_y;
	is >> b_x >> b_y;
	is >> c_x >> c_y;
	is >> d_x >> d_y;
	is >> e_x >> e_y;
	is >> f_x >> f_y;
}

Hexagon::~Hexagon() {
	std::cout << "Hexagon deleted" << std::endl;
}

double Hexagon::Square() {
	double ab, ac, af, bc, cd, cf, de, df, ef;

	ab = sqrt(pow(a_x - b_x, 2) + pow(a_y - b_y, 2));
	ac = sqrt(pow(a_x - c_x, 2) + pow(a_y - c_y, 2));
	af = sqrt(pow(a_x - e_x, 2) + pow(a_y - e_y, 2));
	bc = sqrt(pow(c_x - b_x, 2) + pow(c_y - b_y, 2));
	cd = sqrt(pow(c_x - d_x, 2) + pow(c_y - d_y, 2));
	cf = sqrt(pow(c_x - f_x, 2) + pow(c_y - f_y, 2));
	de = sqrt(pow(e_x - d_x, 2) + pow(e_y - d_y, 2));
	df = sqrt(pow(d_x - f_x, 2) + pow(d_y - f_y, 2));
	ef = sqrt(pow(e_x - f_x, 2) + pow(e_y - f_y, 2));

	double res = 0;

	Triangle *T = new Triangle(ab, ac, bc);
	res += T->Square();
	T->Set(ac, cf, af);
	res += T->Square();
	T->Set(cd, df, cf);
	res += T->Square();
	T->Set(ef, de, df);
	res += T->Square();
	delete T;
	return res;
}

Hexagon::Hexagon(const Hexagon& orig) {
	std::cout << "Hexagon copy created" << std::endl;
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
	f_x = orig.f_x;
	f_y = orig.f_y;
}

void Hexagon::Print() {
	std::cout << "Point A: " << a_x << ", " << a_y << std::endl;
	std::cout << "Point B: " << b_x << ", " << b_y << std::endl;
	std::cout << "Point C: " << c_x << ", " << c_y << std::endl;
	std::cout << "Point D: " << d_x << ", " << d_y << std::endl;
	std::cout << "Point E: " << e_x << ", " << e_y << std::endl;
	std::cout << "Point F: " << f_x << ", " << f_y << std::endl;
}