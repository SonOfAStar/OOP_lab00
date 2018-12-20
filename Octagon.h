#ifndef OCTAGON_H_INCLUDED
#define OCTAGON_H_INCLUDED

#include "TFigure.h"
#include "TAllocator.h"
#include <iostream>


class Octagon : public Figure{
    public:
        Octagon();
        Octagon(std::istream &is);
        Octagon(double i_x, double j_x, double k_x, double l_x, double m_x, double n_x, double o_x, double p_x, double i_y, double j_y, double k_y, double l_y, double m_y, double n_y, double o_y, double p_y);
        Octagon(const Octagon& other);

        double Square() override;
        void   Print() override;

        Octagon& operator = (const Octagon& orig);
        void* operator new (size_t size);
        void operator delete (void* p);

        friend std::ostream& operator<<(std::ostream& os, const Octagon octagon);
        friend std::istream& operator>>(std::istream& os, Octagon &octagon);

        virtual ~Octagon();

    private:
        static TAllocator figure_alloc;
        double a_x, a_y;
        double b_x, b_y;
        double c_x, c_y;
        double d_x, d_y;
        double e_x, e_y;
        double f_x, f_y;
        double g_x, g_y;
        double h_x, h_y;
};

#endif // OCTAGON_H_INCLUDED
