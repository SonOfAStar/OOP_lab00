#ifndef FIGURE_H_INCLUDED
#define	FIGURE_H_INCLUDED

class Figure {
public:
	virtual double Square() = 0;
	virtual void   Print() = 0;
	//virtual void Change() = 0;
	virtual ~Figure() {};
};

#endif	/* FIGURE_H */
