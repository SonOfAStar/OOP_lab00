#include "Octagon.h"
#include "Triangle.h"
#include <math.h>

Octagon::Octagon() : Octagon(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0){
}

Octagon::Octagon(double i_x, double j_x, double k_x, double l_x, double m_x, double n_x, double o_x, double p_x, double i_y, double j_y, double k_y, double l_y, double m_y, double n_y, double o_y, double p_y) :
    a_x(i_x), a_y(i_y), b_x(j_x), b_y(j_y), c_x(k_x), c_y(k_y), d_x(l_x), d_y(l_y), e_x(m_x), e_y(m_y), f_x(n_x), f_y(n_y), g_x(o_x), g_y(o_y), h_x(p_x), h_y(p_y) {
    std::cout << "Octagon created:  point A: " << a_x << ", " << a_y << std::endl;
    std::cout << "Octagon created:  point B: " << b_x << ", " << b_y << std::endl;
    std::cout << "Octagon created:  point C: " << c_x << ", " << c_y << std::endl;
    std::cout << "Octagon created:  point D: " << d_x << ", " << d_y << std::endl;
    std::cout << "Octagon created:  point E: " << e_x << ", " << e_y << std::endl;
    std::cout << "Octagon created:  point F: " << f_x << ", " << f_y << std::endl;
    std::cout << "Octagon created:  point G: " << g_x << ", " << g_y << std::endl;
    std::cout << "Octagon created:  point H: " << h_x << ", " << h_y << std::endl;
}

Octagon::Octagon(std::istream &is) {
    is >> a_x >> a_y;
    is >> b_x >> b_y;
    is >> c_x >> c_y;
    is >> d_x >> d_y;
    is >> e_x >> e_y;
    is >> f_x >> f_y;
    is >> g_x >> g_y;
    is >> h_x >> h_y;
}

Octagon::~Octagon(){
    std::cout << "Octagon deleted" << std::endl;
}

double Octagon::Square() {
    double ab, ac, ad, ah, bc, cd, de, dh, dg, ef, eg, fg, gh;

    ab = sqrt(pow(a_x  - b_x, 2) + pow(a_y - b_y, 2));
    ac = sqrt(pow(a_x  - c_x, 2) + pow(a_y - c_y, 2));
    ad = sqrt(pow(a_x  - d_x, 2) + pow(a_y - d_y, 2));
    ah = sqrt(pow(a_x  - h_x, 2) + pow(a_y - h_y, 2));
    bc = sqrt(pow(c_x  - b_x, 2) + pow(c_y - b_y, 2));
    cd = sqrt(pow(c_x  - d_x, 2) + pow(c_y - d_y, 2));
    de = sqrt(pow(e_x  - d_x, 2) + pow(e_y - d_y, 2));
    dh = sqrt(pow(h_x  - d_x, 2) + pow(h_y - d_y, 2));
    dg = sqrt(pow(d_x  - g_x, 2) + pow(d_y - g_y, 2));
    ef = sqrt(pow(e_x  - f_x, 2) + pow(e_y - f_y, 2));
    eg = sqrt(pow(e_x  - g_x, 2) + pow(e_y - g_y, 2));
    fg = sqrt(pow(f_x  - g_x, 2) + pow(f_y - g_y, 2));
    gh = sqrt(pow(g_x  - h_x, 2) + pow(g_y - h_y, 2));

    double res = 0;

    Triangle *T = new Triangle(ab, ac, bc);
    res += T->Square();
    T->Set(ac, cd, ad);
    res += T->Square();
    T->Set(ah, ad, dh);
    res += T->Square();
    T->Set(dh, dg, gh);
    res += T->Square();
    T->Set(de, eg, dg);
    res += T->Square();
    T->Set(ef, fg, eg);
    res += T->Square();
    delete T;
    return res;
}

Octagon::Octagon(const Octagon& orig){
    std::cout << "Octagon copy created" << std::endl;
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
    g_x = orig.g_x;
    g_y = orig.g_y;
    h_x = orig.h_x;
    h_y = orig.h_y;
}

void Octagon::Print(){
    std::cout << "Point A: " << a_x << ", " << a_y << std::endl;
    std::cout << "Point B: " << b_x << ", " << b_y << std::endl;
    std::cout << "Point C: " << c_x << ", " << c_y << std::endl;
    std::cout << "Point D: " << d_x << ", " << d_y << std::endl;
    std::cout << "Point E: " << e_x << ", " << e_y << std::endl;
    std::cout << "Point F: " << f_x << ", " << f_y << std::endl;
    std::cout << "Point G: " << g_x << ", " << g_y << std::endl;
    std::cout << "Point H: " << h_x << ", " << h_y << std::endl;
}

Octagon& Octagon::operator=(const Octagon& orig){
    this->a_x = orig.a_x;
    this->a_y = orig.a_y;
    this->b_x = orig.b_x;
    this->b_y = orig.b_y;
    this->c_x = orig.c_x;
    this->c_y = orig.c_y;
    this->d_x = orig.d_x;
    this->d_y = orig.d_y;
    this->e_x = orig.e_x;
    this->e_y = orig.e_y;
    this->f_x = orig.f_x;
    this->f_y = orig.f_y;
    this->g_x = orig.g_x;
    this->g_y = orig.g_y;
    this->h_x = orig.h_x;
    this->h_y = orig.h_y;
    return *this;
}

std::ostream& operator<<(std::ostream& os,const Octagon octagon){
    os << "Figure: Octagon. Coordinates: " << std::endl;
    os << octagon.a_x << ", " << octagon.a_y << std::endl;
    os << octagon.b_x << ", " << octagon.b_y << std::endl;
    os << octagon.c_x << ", " << octagon.c_y << std::endl;
    os << octagon.d_x << ", " << octagon.d_y << std::endl;
    os << octagon.e_x << ", " << octagon.e_y << std::endl;
    os << octagon.f_x << ", " << octagon.f_y << std::endl;
    os << octagon.g_x << ", " << octagon.g_y << std::endl;
    os << octagon.h_x << ", " << octagon.h_y << std::endl;
    return os;
}

std::istream& operator>>(std::istream& os, Octagon &octagon){
    std::cout << "Reading figure: Octagon. Coordinates: " << std::endl;
    os >> octagon.a_x;
    os >> octagon.a_y;
    os >> octagon.b_x;
    os >> octagon.b_y;
    os >> octagon.c_x;
    os >> octagon.c_y;
    os >> octagon.d_x;
    os >> octagon.d_y;
    os >> octagon.e_x;
    os >> octagon.e_y;
    os >> octagon.f_x;
    os >> octagon.f_y;
    os >> octagon.g_x;
    os >> octagon.g_y;
    os >> octagon.h_x;
    os >> octagon.h_y;
    return os;
}
