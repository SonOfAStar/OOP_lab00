#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

class MyStack{

private:
   MyStackElem* head;

public:
    MyStack (){
        head = nullptr;
    }

    void Push (T* data){
        MyStackElem* newel = new MyStackElem(head,(void*) data);
        head = newel;
    }

    T* Pop (){
        MyStackElem* oldel = head;
        head = oldel->next;
        T* data = (T*)oldel->data;
        delete oldel;
        return data;
    }

    ~ MyStack(){
        while (head != nullptr){
            this->Pop();
        }
    }

};

#endif // MYSTACK_H_INCLUDED
