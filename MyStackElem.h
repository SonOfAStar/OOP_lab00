#ifndef MYSTACKELEM_H_INCLUDED
#define MYSTACKELEM_H_INCLUDED

class MyStackElem{
public:
    char data;
    MyStackElem* next;

    MyStackElem(){
        data = '\0';
        next = nullptr;
    }

    MyStackElem(MyStackElem* prev, char input){
        next = prev;
        data = input;
    }

    ~MyStackElem(){
        //DELETING
    }
};

#endif // MYSTACKELEM_H_INCLUDED
