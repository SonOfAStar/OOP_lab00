#ifndef HEXAGON_H_INCLUDED
#define HEXAGON_H_INCLUDED

#include "TFigure.h"
#include "TAllocator.h"
#include <iostream>


class Hexagon : public Figure{
    public:
        char type;
        Hexagon();
        Hexagon(std::istream &is);
        Hexagon(double i_x, double j_x, double k_x, double l_x, double m_x, double n_x, double i_y, double j_y, double k_y, double l_y, double m_y, double n_y);
        Hexagon(const Hexagon& other);

        double Square() override;
        void   Print() override;

        Hexagon& operator = (const Hexagon& orig);
        friend std::ostream& operator<<(std::ostream& os, const Hexagon hexagon);
        friend std::istream& operator>>(std::istream& os, Hexagon &hexagon);

        virtual ~Hexagon();

    private:
        static TAllocator figure_alloc;
        double a_x, a_y;
        double b_x, b_y;
        double c_x, c_y;
        double d_x, d_y;
        double e_x, e_y;
        double f_x, f_y;
};

#endif // HEXAGON_H_INCLUDED
