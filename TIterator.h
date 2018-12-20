#ifndef TITERATOR_H_INCLUDED
#define TITERATOR_H_INCLUDED

//#include "TContainer.h"
#include "MyStack.h"

template <class T>
class TIterator
{
public:

    TIterator(MyStack<T>* n, int p)   {

        my_Body = n;
        pos = p;
    }



    MyStack<T>* operator * (){
        return &(my_Body[pos]);
    }

    MyStack<T>* operator -> (){
        return my_Body[pos];
    }

    void operator ++ (){
        ++pos;
    }

    TIterator operator ++ (int){
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator == (TIterator const& i){
        return (my_Body == i.my_Body) && (pos == i.pos);
    }

    bool operator != (TIterator const& i){
        return !(*this == i);
    }

private:

    MyStack<T>*  my_Body;
    int pos;
    //int st_pos;
};



#endif // TITERATOR_H_INCLUDED
