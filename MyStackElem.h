#ifndef MYSTACKELEM_H_INCLUDED
#define MYSTACKELEM_H_INCLUDED

#include <cstdlib>
#include <memory>


template <class T>

class MyStackElem {
private:
    T data;
    std::shared_ptr<MyStackElem<T>> next;

public:
    MyStackElem(){
        data = nullptr;
        next = nullptr;
    }

    MyStackElem(std::shared_ptr<MyStackElem<T>> prev, T input){
        next = prev;
        data = input;
    }

    std::shared_ptr<MyStackElem<T>> GetNext(){
        return next;
    }

    void SetNext (std::shared_ptr<MyStackElem<T>> newnext){
        next = newnext;
        return;
    }

    void Print(){
        data->Print();
        return;

    }

    T Val(){
        //std::cout << data;
        //data->Print();
        //std::cout << "returning data from tse\n";

        return data;
    }

    ~MyStackElem(){
        //DELETING
    }
};

#endif // MYSTACKELEM_H_INCLUDED












