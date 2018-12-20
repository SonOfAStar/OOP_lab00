#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED


#include "MyStackElem.h"

class MyStack{

private:
   MyStackElem* head;

public:
    MyStack (){
        head = nullptr;
    }

    void Push (char data){
        MyStackElem* newel = new MyStackElem(head, data);
        head = newel;
    }

    char Pop (){
        MyStackElem* oldel = head;
        head = oldel->next;
        char data = oldel->data;
        delete oldel;
        return data;
    }

    bool Empty(){
        return this->head != nullptr;
    }

    ~ MyStack(){
        while (head != nullptr){
            this->Pop();
        }
    }

};


#endif // MYSTACK_H_INCLUDED
