#ifndef TFIGURE_H_INCLUDED
#define TFIGURE_H_INCLUDED

class Figure {
public:
    virtual double Square() = 0;
    virtual void   Print() = 0;
    virtual ~Figure() {};
};

#endif // TFIGURE_H_INCLUDED
