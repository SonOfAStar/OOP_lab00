#ifndef TSTACK_H_INCLUDED
#define TSTACK_H_INCLUDED

#include "TStackElem.h"

template <class T>

class TStack{

private:
   TStackElem* head;

public:
    TStack (){
        head = nullptr;
    }

    void Push (T* data){
        TStackElem* newel = new TStackElem(head,(void*) data);
        head = newel;
    }

    T* Pop (){
        TStackElem* oldel = head;
        head = oldel->next;
        T* data = (T*)oldel->data;
        delete oldel;
        return data;
    }

    ~ TStack(){
        while (head != nullptr){
            this->Pop();
        }
    }

};

#endif // TSTACK_H_INCLUDED

