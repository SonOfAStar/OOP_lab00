#ifndef TITERATOR_H_INCLUDED
#define TITERATOR_H_INCLUDED

//#include "TContainer.h"

template <class T>
class TIterator
{
public:

    TIterator(std::shared_ptr<T>* n, int p)   {

        my_Body = n;
        pos = p;
    }

    std::shared_ptr<T> operator * (){
        return my_Body[pos];
    }

    std::shared_ptr<T> operator -> (){
        return my_Body[pos];
    }

    void operator ++ (){
        pos += 1;
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

    std::shared_ptr<T>*  my_Body;
    int pos;
};



#endif // TITERATOR_H_INCLUDED
