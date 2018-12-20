#ifndef TSTACKELEM_H_INCLUDED
#define TSTACKELEM_H_INCLUDED


class TStackElem {

public:
    void* data;
    TStackElem* next;

    TStackElem(){
        data = nullptr;
        next = nullptr;
    }

    TStackElem(TStackElem* prev, void* input){
        next = prev;
        data = input;
    }

    ~TStackElem(){
        //DELETING
    }
};

#endif // TSTACKELEM_H_INCLUDED

