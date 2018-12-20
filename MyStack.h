#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

#include "MyStackElem.h"

template <class T>

class MyStack{

private:



public:
    int msize;
    std::shared_ptr<MyStackElem <T>> head;

    MyStack (){
        head = nullptr;
        msize = 0;
    }

    void Push (T data){

        std::shared_ptr<MyStackElem <T>> newel = std::shared_ptr<MyStackElem <T>>(new MyStackElem<T>(head, data));
        std::shared_ptr<MyStackElem <T>> leftel = head;

        if (!head || ((data->Square()) >= (head->Val()->Square()))){

            head = newel;
            std::cout << "Head set" << std::endl;
        }
        else {
            std::shared_ptr<MyStackElem <T>> rightel = head->GetNext();
            T right;
            while (rightel && (data->Square() >= right->Square())){
                    right = rightel->Val();
                    rightel = rightel->GetNext();
                    leftel = leftel->GetNext();
                    right = rightel->Val();

            }
            if (rightel){
                newel->SetNext(rightel);
            }
            leftel->SetNext(newel);
        }

        ++msize;
    }

    T Pop (){
        std::shared_ptr<MyStackElem <T>> oldel = head;
        head = oldel->GetNext();
        T data = oldel->Val();
        oldel = nullptr;
        --msize;
        return data;
    }

    T Peak(){
        return  head->Val();
    }

    void del(char t){
        std::shared_ptr<MyStackElem <T>> ml = head;
        std::shared_ptr<MyStackElem <T>> rl;
        if (!ml){
            std::cout << "Empty stack!" << std::endl;
            return;
        }

        std::cout << "Checking head: type '" << ml->Val()->type << "'. \n";
        while (ml->Val()->type == t){
            head = ml->GetNext();
            rl = ml->GetNext();
            ml = nullptr;
            std::cout << "Element deleted.\n";
            if (rl == nullptr){
                std::cout << "Stack devastated!\n";
                msize = 0;
                return;
            }
            --msize;
            ml = rl;
        }
        while (ml->GetNext()){
            rl = ml->GetNext();
            T rl_val = rl->Val();
            if (rl_val->type == t){
                ml->SetNext(rl->GetNext());
                rl = nullptr;
                std::cout << "Element deleted.\n";
                continue;
            }
            ml = rl;
        }
    }

    void del(double sq){
        std::shared_ptr<MyStackElem <T>> ml = head;
        std::shared_ptr<MyStackElem <T>> rl;
        if (!ml){
            std::cout << "Empty stack!" << std::endl;
            return;
        }

        double t = 1;

        for (int i = 0; i < 16; i++){
            t /= 2;
        }

        std::cout << "Checking head: square = " << ((ml->Val()->Square() - sq) < t) << "\n";
        while (ml && (ml->Val()->Square() - sq) < t){
            head = ml->GetNext();
            rl = ml->GetNext();
            ml = nullptr;
            std::cout << "Element deleted.\n";
            if (rl == nullptr){
                std::cout << "Stack devastated!\n";
                msize = 0;
                return;
            }
            --msize;
            ml = rl;
        }
        while (ml->GetNext()){
            rl = ml->GetNext();
            T rl_val = rl->Val();
            if (rl_val->Square() - sq < t){
                ml->SetNext(rl->GetNext());
                rl = nullptr;
                --msize;
                std::cout << "Element deleted.\n";
                continue;
            }
            ml = rl;
        }
    }

    const int size(){
        return msize;
    }

    void Print() {
        std::shared_ptr<MyStackElem <T>> focus = head;

        if (!focus){
            std::cout << "Empty stack!" << std::endl;
        }

        while (focus != nullptr){
            std::cout << "Stack Element:\n";
            focus->Print();
            focus = focus->GetNext();
        }
        return;
    }

    MyStack& operator = (const MyStack& orig){
        this->head = nullptr;
        this->head = orig.head;
        this->msize = orig.msize;
        return *this;
    }

    ~ MyStack(){
        while (head != nullptr){
            this->Pop();
        }
    }

};

#endif // MYSTACK_H_INCLUDED
