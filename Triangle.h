#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include <cstdlib>
#include <iostream>
#include "TFigure.h"

class Triangle : public Figure{
public:
    char type;
    Triangle();
    Triangle(std::istream &is);
    Triangle(double i,double j,double k);
    Triangle(const Triangle& orig);

    double Square() override;
    void   Print() override;
    void    Set(double n_a, double n_b, double n_c);
    //void   Change (double a, double b, double c) override;

    virtual ~Triangle();
private:
    double side_a;
    double side_b;
    double side_c;
};

#endif // TRIANGLE_H_INCLUDED
