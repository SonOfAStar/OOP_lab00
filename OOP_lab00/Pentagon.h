#ifndef PENTAGON_H_INCLUDED
#define	PENTAGON_H_INCLUDED
#include <cstdlib>
#include <iostream>
#include "Figure.h"
#include "Triangle.h"

class Pentagon : public Figure {
public:
	Pentagon();
	Pentagon(std::istream &is);
	Pentagon(double i_x, double j_x, double k_x, double l_x, double m_x, double i_y, double j_y, double k_y, double l_y, double m_y);
	Pentagon(const Pentagon& orig);

	double Square() override;
	void   Print() override;

	virtual ~Pentagon();
private:
	double a_x, a_y;
	double b_x, b_y;
	double c_x, c_y;
	double d_x, d_y;
	double e_x, e_y;
};

#endif	/* Pentagon_H */
